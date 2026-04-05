name=input("Enter student name:")
USN=input("Enter student USN:")
marks1=int(input("enter student marks1:"))
marks2=int(input("enter student marks2:"))
marks3=int(input("enter student marks3:"))
total=marks1+marks2+marks3
percentage=(total/300)*100
print("Student details\n")
print("Name:",name)
print("USN:",USN)
print(f"Total marks obtained:{total:.2f}")
print(f"Percentage is:{percentage:.2f}")

