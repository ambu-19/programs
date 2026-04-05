n=int(input("Enter the length of fibonacci sequence\n"))
n1=0
n2=1
if n==1:
  print(0)
elif n==0:
  print("Enter the number above zero")
elif n==2:
  print(0,1)
else:
  i=0
  print(n1)
  print(n2)
  while i<n-2:
    count=n1+n2
    n1=n2
    n2=count
    i+=1
    print(count)
