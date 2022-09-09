class Student:
    def __init__(self, name):
        self.name = name
        self.subjects = []
        self.gpa = None

class Subject:
    def __init__(self, name, assign, test, lab):
        self.name = name
        self.assign = assign
        self.test = test
        self.lab = lab
        self.score = None
        self.grade = None
    
    def calcGrade(self):
        self.score = 0.1*float(assign) + 0.7*float(test) + 0.2*float(lab)
        if  self.score >= 95:
            self.grade = "A"
        elif self.score >= 80:
            self.grade = "B"
        elif self.score >= 65:
            self.grade = "C"
        elif self.score >= 50:
            self.grade = "D"
        else:
            self.grade = "F"
        return self.grade
    

if __name__  == "__main__":
    n = int(input("Enter no of Students:"))
    n_sub = int(input("Enter no of Subjects: "))

    for i in range(n):
        st_name = input("Enter name of Students:")
        st = Student(st_name)
        for j in range(n_sub):
            sub_name = input("Enter name of Subject: ")
            assign = input("Enter assignment marks: ")
            test = input("Enter test marks: ")
            lab = input("Enter lab marks: ")
            sub = Subject(sub_name, assign, test, lab)
            print("Subject", sub_name, " grade is", sub.calcGrade())
            print("Total marks in subject: ", sub.score)
            st.subjects.append(sub)
