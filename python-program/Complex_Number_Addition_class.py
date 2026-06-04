class Complex:
  def __init__(self):
    self.realpart=int(input("Enter the realpart:"))
    self.imagpart=int(input("Enter the imagpart:"))
  def display(self):
    print(self.realpart,"+",imagpart,"i",sep=' ')
  def sum(self,C1,C2):
    self.realpart=C1.realpart + C2.realpart
    self.imagpart=C1.imagpart + C2.imagpart
C1=Complex()
C2=Complex()
C3=Complex()
print("Enter the first complex number:")
C1.__init__()
print("First complex number:","end=")
C1.display()
print("Enter the second complex number:")
C2.__init__()
print("Second complex number:","end=")
C2.display()
print("Sum of the complex number is","end=")
C3.sum(C1,C2)
C3.display()
