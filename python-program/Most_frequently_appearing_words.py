import os,itertools
os.chdir("/home/chef/workspace/")
fname=input("Enter the File name:\n")
f1=open(fname)
d={}
for l in f1:
  words=l.split()
  for w in words:
    d.setdefault(w,0)
    d[w]+=1
print("Dictionary is\n",d)
li=list(d.values())
li.sort(reverse=True)
n={}
for i in li:
  for k in d:
    if d[k]==i:
      n.setdefault(k,i)
print("Reversed sorted list\n",n)
print(dict(itertools.islice(n.items(),10)))
