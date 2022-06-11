#include<stdio.h>
#include<conio.h>

struct emp
{
 int code;
 char name[51];
 float salary;
}e1 ;

int enter_data();
int read_data();

int main ()
{
  int num;
  clrscr();
  printf("1.enter_data\n2.read data\n3.exit\n");
  scanf("%d",&num);
  while(num!=3)
  {
  if (num==1)
  enter_data();
  else if(num==2)
  read_data();
  printf("1.enter_data\n2.read_data\n3.exit\n");
  scanf("%d",&num);
  }
  return 0;
}

int enter_data()
{
 printf("Please enter the employee data\n");
 printf("Please enter the employee's code\n");
 scanf("%d",&e1.code);
 printf("Please enter the employee's name\n");
 scanf("%s",&e1.name);
 printf("please enter the employee's salary\n");
 scanf("%f",&e1.salary);
}
int read_data()
{
 printf("the name is %s , the net salary is %.2f\n",e1.name,e1.salary);
}