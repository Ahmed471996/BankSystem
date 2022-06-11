#include<stdio.h>
#include<conio.h>
struct emp
{
 int code;
 char name[51];
 float salary;
}e1;


int  main()
{ //delcaration of variables

  clrscr();

  printf("Please enter the employee's code\n");
  scanf("%d",&e1.code);
  printf("Please enter the employee's name\n");
  scanf("%s",&e1.name);
  printf("Please enter the employee's salary\n");
  scanf("%f",&e1.salary);
  printf("The employee's code is %d, the employee's name is %s, the employee's salary is %.2f",e1.code,e1.name,e1.salary);
  getch();
  return 0;
}