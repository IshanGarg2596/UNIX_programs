#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <dirent.h>
#include <libgen.h>
#include <pwd.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FORMAT "%5s %s\t%8s %s\n"
#define MAX_BUF 1024
#define INT_SIZE_BUF 6
#define PID_LIST_BLOCK 32
#define UP_TIME_SIZE 10

int check_if_number (char *str)
{
  int i;
  for (i=0; str[i] != '\0'; i++)
  {
    if (!isdigit (str[i]))
    {
      return 0;
    }
  }
  return 1;
}

const char *getUserName(int uid)
{
  struct passwd *pw = getpwuid(uid);
  if (pw)
  {
    return pw->pw_name;
  }

  return "";
}

void ps(){
	DIR *dir;
	struct dirent *ent;
	int i, fd_self, fd;
	unsigned long time, stime;
	char flag, *tty;
	char cmd[256], tty_self[256], path[256], time_s[256];
  	FILE* file;

  	dir = opendir("/proc");
  	fd_self = open("/proc/self/fd/0", O_RDONLY);
  	sprintf(tty_self, "%s", ttyname(fd_self));
  	printf(FORMAT, "PID", "TTY", "TIME", "CMD");

  	while ((ent = readdir(dir)) != NULL){
  		flag = 1;
  		for (i = 0; ent->d_name[i]; i++)
  		if (!isdigit(ent->d_name[i]))
  		{ 
   		flag = 0;
   		break;
  		}

  		if (flag){
  			sprintf(path, "/proc/%s/fd/0", ent->d_name);
  			fd = open(path, O_RDONLY);
  			tty = ttyname(fd);

			if (tty && strcmp(tty, tty_self) == 0){
				sprintf(path, "/proc/%s/stat", ent->d_name);
   				file = fopen(path, "r");
   				fscanf(file, "%d%s%c%c%c", &i, cmd, &flag, &flag, &flag);
   				cmd[strlen(cmd) - 1] = '\0';
   
   				for (i = 0; i < 11; i++)
   				fscanf(file, "%lu", &time);
   				fscanf(file, "%lu", &stime);
   				time = (int)((double)(time + stime) / sysconf(_SC_CLK_TCK));
   				sprintf(time_s, "%02lu:%02lu:%02lu",
   				(time / 3600) % 3600, (time / 60) % 60, time % 60);
 
   				printf(FORMAT, ent->d_name, tty + 5, time_s, cmd + 1);
   				fclose(file);
  			}
  			close(fd);
		}
	}
	close(fd_self);
}

void ps_u(){
	DIR *dirp;
  FILE *fp;
  struct dirent *entry;
  char path[MAX_BUF], read_buf[MAX_BUF],temp_buf[MAX_BUF];
  char uid_int_str[INT_SIZE_BUF]={0},*line;
  char uptime_str[UP_TIME_SIZE];
  char *user,*command;
  size_t len=0;
  dirp = opendir ("/proc/");
  if (dirp == NULL)
  {
         perror ("Fail");
         exit(0);
  } 
  strcpy(path,"/proc/");
  strcat(path,"uptime");
 
  fp=fopen(path,"r");
  if(fp!=NULL)
  {
	getline(&line,&len,fp);
	sscanf(line,"%s ",uptime_str);
  }
  long uptime=atof(uptime_str);
  long Hertz=sysconf(_SC_CLK_TCK); 
  strcpy(path,"/proc/");
  strcat(path,"meminfo");

  fp=fopen(path,"r");
  unsigned long long total_memory;
  if(fp!=NULL)
  {
	getline(&line,&len,fp);
	sscanf(line,"MemTotal:        %llu kB",&total_memory);
  }	

  while ((entry = readdir (dirp)) != NULL)
  {
    if (check_if_number (entry->d_name))
    {
	strcpy(path,"/proc/");
	strcat(path,entry->d_name);
	strcat(path,"/status");
	unsigned long long memory_rss;
	fp=fopen(path,"r");
	unsigned long long vmsize;

	if(fp!=NULL)
	{
		vmsize=0;
		getline(&line,&len,fp);
		getline(&line,&len,fp);
		getline(&line,&len,fp);
		getline(&line,&len,fp);
		getline(&line,&len,fp);
		getline(&line,&len,fp);
		getline(&line,&len,fp);
		getline(&line,&len,fp);
		sscanf(line,"Uid:    %s ",uid_int_str);
		getline(&line,&len,fp);
                getline(&line,&len,fp);
                getline(&line,&len,fp);
		getline(&line,&len,fp);
                getline(&line,&len,fp);
		sscanf(line,"VmSize:    %llu kB",&vmsize);
                getline(&line,&len,fp);
                getline(&line,&len,fp);
                getline(&line,&len,fp);
		getline(&line,&len,fp);
		sscanf(line,"VmRSS:     %llu kB",&memory_rss);
		
	}
	else
	{
		fprintf(stdout,"FP is NULL\n");
	}
	float memory_usage=100*memory_rss/total_memory;
	strcpy(path,"/proc/");
	strcat(path,entry->d_name);
	strcat(path,"/stat");
	fp=fopen(path,"r");
	getline(&line,&len,fp);
	char comm[10],state;
	unsigned int flags;
	int pid,ppid,pgrp,session,tty_nr,tpgid;
	unsigned long minflt,cminflt,majflt,cmajflt,utime,stime;
	unsigned long long starttime;
	long cutime,cstime,priority,nice,num_threads,itreavalue;
	sscanf(line,"%d %s %c %d %d %d %d %d %u %lu %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld  %ld %llu",&pid,comm,&state,&ppid,&pgrp,&session,&tty_nr,&tpgid,&flags,&minflt,&cminflt,&majflt,&cmajflt,&utime,&stime,&cutime,&cstime,&priority,&nice,&num_threads,&itreavalue,&starttime);
	unsigned long total_time=utime+stime;
	total_time=total_time+(unsigned long)cutime+(unsigned long)cstime;
	float seconds=uptime-(starttime/Hertz);
	float cpu_usage=100*((total_time/Hertz)/seconds);
	if(isnan(cpu_usage))
	{
		cpu_usage=0.0;
	}
	if(isnan(memory_usage))
	{
		memory_usage=0.0;
	}
	strcpy (path, "/proc/");
	strcat (path, entry->d_name);
	strcat (path, "/comm");
	 
      	fp = fopen (path, "r");
      	if (fp != NULL)
      	{
        	fscanf (fp, "%s", read_buf);
		fclose(fp);
      	}
      	char *userName=getUserName(atoi(uid_int_str));
     	if(strlen(userName)<9)
      	{
		user=userName;	
      	}
      	else
      	{
		user=uid_int_str;
      	}
      	fprintf(stdout,"%s %s %0.1f %0.1f %llu %llu %c %s\n",user,entry->d_name,cpu_usage,memory_usage,vmsize,memory_rss,state,read_buf);
     	 
    }
  } 
  closedir (dirp);
}

int main(int argc, char** argv){
    if(argc == 1){
		ps();
	} else if(strcmp( argv[1], '-a') == 0){
		ps();
	} else{
		ps_u();
	}
	return 0;
}