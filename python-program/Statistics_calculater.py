n=int(input("hoe many numbers in the :\n"))
list=[]
for i in range(n):
  number=int(input("Enter the number:"))
  list.append(number)
print(f"The numbers in list are:\n{list}")
sum=0
for number in list:
  sum = sum + number
print("Sum is:",sum)
for number in list:
  mean=sum/n
print(f"mean is :{mean:.1f}")
variance_sum=0
for number in list:
  variance_sum+=(number-mean)**2
variance=variance_sum/n
print("Veriance is:",variance)
std_dev=variance**0.5
print("The standard deviation is:",std_dev)
