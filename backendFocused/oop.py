class Student:
    def __init__(self, name, cgpa): #self = current object
        self.name = name
        self.cgpa = cgpa

    def is_eligible(self):
        return self.cgpa >= 2.5

class CSStudent(Student): #CSStudent inherits from Student
    def role(self):
        return "Computer Science Student"

s1 = CSStudent("Sir", 2.6)
#implementing methods on s1
print(s1.name)
print("Eligible:", s1.is_eligible())
print("Role:", s1.role())
