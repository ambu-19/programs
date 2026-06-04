class Student:
  def __init__(self):
    self.name=""
    self.usn=""
    self.marks=[]
    self.total=[]
  def getMarks(self):
    print("Enter the name of student:")
    self.name=input()
    print("Enter the usn of student:")
    self.usn=input()
    for i in range(3):
      print(f"Enter the marks of subject{i+1}:")
      mark=int(input())
      self.marks.append(mark)
    self.total.append(sum(self.marks))
  def display(self):
    percentage=self.total[0]/3
    print("Score card details:")
    print(f"{self.name} got {self.marks} total is: [{self.total[0]}] percentage: {percentage:.1f}")
S=Student()
S.getMarks()
S.display()
