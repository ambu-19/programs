def factorial(n):
  if n==0 or n==1:
    return 1
  else:
    return n*factorial(n-1)
def bi_no(n,r):
  b=factorial(n)//(factorial(n-r)*factorial(r))
  return b
n=int(input("Enter value for n:"))
r=int(input("Enter value for r:"))
print("Binomial coefficient is:",bi_no(n,r))
