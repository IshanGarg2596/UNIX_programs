#include <stdio.h>
#include <stdlib.h>

int main(int c, char *argv[])
{
    FILE * file;
    char ch;
    int characters=0, words=0, lines=0;
    file = fopen(argv[1], "r");
    while ((ch = fgetc(file)) != EOF)
    {
	characters++;
	if (ch == '\n')
	    lines++;
	if (ch == ' ' || ch == '\n')
	    words++;
    }
    if (characters > 0)
    {
	words++;
	lines++;
    }
    printf("%d %d %d %s\n", lines-1,words-1,characters,argv[1]);
    fclose(file);

    return 0;
}
