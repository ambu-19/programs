name=input("Enter your name:")
form datetime import date
current_date=date.today()
current_year=current_date.year
Birthyear=int(input("Enter your birth year:"))
age=current_year-Birthyear
print("The age is:",age)
if age>60:
  print("The person is senior citizen")
else:
  print("The person is not senior citizen")
