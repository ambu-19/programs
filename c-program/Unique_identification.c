#include <stdio.h>
int main() {
int choice;
int inputID;
int PAN_Number = 3466;
int AADHAR_Number = 333313274545;
int APAAR_Id = 11223;
int Driving_License = 44556;
int Passport = 77889;
printf("---KYC verification system---\n");
printf("Select ID type to verify:\n");
printf("1. PAN Number\n");
printf("2. AADHAR Number\n");
printf("3. APAAR Id\n");
printf("4. Driving License\n");
printf("5. Passport\n");
printf("....\n");
printf("Enter your choice (1-5): ");
scanf("%d", &choice);
printf("Enter your Unique Identification Number: ");
scanf("%d", &inputID);
switch(choice){
case 1:
if(inputID==PAN_Number)
  printf("PAN verified: Individual is KYC verified.\n");
else
  printf("PAN not verified:Record not found.\n");
breck;
case 2:
if(inputID==AADHAR_Number)
   printf("AADHAR verified: Individual is KYC verified.\n");
else
  printf("AADHAR not verified:Record not found.\n");
breck;
case 3:
if(inputID==APAAR_Id)
   printf("APAAR verified: Individual is KYC verified.\n");
else
  printf("APAAR not verified:Record not found.\n");
breck;
case 4:
if(inputID==Driving_License)
   printf("Driving_License verified: Individual is KYC verified.\n");
else
  printf("Driving_License not verified:Record not found.\n");
breck;
case 5:
if(inputID==Passport)
   printf("Passport verified: Individual is KYC verified.\n");
else
  printf("Passport not verified:Record not found.\n");
breck;
default:
printf("Invalid choice!Please select between 1 and 5.\n");
}
return 0;
}
  
  
