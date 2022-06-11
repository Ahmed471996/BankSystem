#include<stdio.h>
#include<conio.h>
#include<string.h>

struct emp{
  int code, salary;
  char name[10];
 };

int main (){

  int i=0;
  struct emp e[5];

  clrscr();
  printf("please enter the 5 employees info...\n");
  for(i=0;i<5;i++)
  {
	 clrscr();
	 printf("\n enter the employee code\n");
	 scanf("%d",&e[i].code);
	 printf("enter name\n");
	 scanf(" %s",&e[i].name);
	 printf("enter salary\n");
	 scanf(" %d",&e[i].salary);
  }
  for (i=0;i<5;i++)
  {
   printf("Code is %d,Name is %s,Salary is %d\n",e[i].code,e[i].name,e[i].salary);
  }
  getch();
  return 0;
  }