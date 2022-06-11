#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct emp
{
  int code, salary;
  char name[51];
};

int main()
{
  struct emp * ptr, emp;
  int i, n;
  ptr=&emp;
  clrscr();

  printf("please enter the size of the array of structure\n");
  scanf("%d",&n);

  ptr=(struct emp *) malloc (n * sizeof(struct emp));

  if(ptr==NULL)
  {
   printf("error in memory allocation\n");
   exit(0);
  }

  for (i=0;i<n;i++)
  {
   printf("enter the employee code\n");
   scanf("%d",&(ptr+i)->code);
   printf("enter the employee salary\n");
   scanf("%d",&(ptr+i)->salary);
   printf("enter the emloyee name\n");
   scanf("%s",(ptr+i)->name);
  }

  for (i=0;i<n;i++)
  {
   printf("the code of emp %d is %d\n",i,(ptr+i)->code);
   printf("the salary of emp %d is %d\n",i,(ptr+i)->salary);
   printf("the name of emp %d is %s\n",i,(ptr+i)->name);
  }

  getch();
  return 0;
}