#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int main()
{
  char description[400];
char key_word[MAX];
printf("Enter the course description :\n");
gets(description);
printf("Enter the keyword:\n");
scanf("%s",keyword);
if(strstr(description,key_word))
{
printf("key-word %s found in %s description....\n",keyword,description);
}
else
{
printf("Key-word not found....");
}
return 0;
}
