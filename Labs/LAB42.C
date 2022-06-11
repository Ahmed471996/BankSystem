#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>

void read_arr(int * ptr, int n);
void print_arr(int * ptr,int s);

int main()
{
 int *ptr, n, num, s;
 clrscr();
 printf("Please enter the size of the array as intger number\n");
 scanf("%d",&n);
 ptr = (int *) malloc(n* sizeof(int));
 printf("1.read\n2.print\n3.exit\n");
 scanf("%d",&num);
 while (num!=3)
 {
 if (num==1)
 {
 read_arr(ptr, n);
 }
 else if (num==2)
 {
 printf("please enter the size you want to print\n");
 scanf("%d",&s);
 print_arr(ptr, s);
 }
 printf("1.read\n2.print\n3.exit\n");
 scanf("%d",&num);
 }
 getch();
 return 0;
}

void read_arr(int *ptr, int n)
{
 int i;
 printf("Please enter the data as intger values\n");
 for (i=0;i<n; i++)
 {
 scanf("%d",&ptr[i]);
 printf("next number\n");
 }
}
void print_arr(int *ptr, int s)
{
 int i;
 printf("your data is\n");
 for (i=0;i<s;i++)
 {
 printf("element no. %d = %d\n",i+1 , ptr[i]);
 }
}