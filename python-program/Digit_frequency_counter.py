n=input("Enter the multi-digit number:\n")
dic={}
for i in n:
  if i not in dic:
    dic[i]=1
  else:
    dic[i]=dic[i]+1
print("Frequency of each digit is:\n",dic)
