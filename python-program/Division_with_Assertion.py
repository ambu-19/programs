def DivExp(a,b):
  assert a>0,"a should be greater than zero"
  if b==0:
    raise Exception("Division by zero error")
  c=a/b
  return c
x=int(input("Enter the first number\n"))
y=int(input("Enter the second number\n"))
try:
  result=DivExp(x,y)
  print(result)
except Exception as err:
  print(f"An Exception happened:{err}")
