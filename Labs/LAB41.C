#include<stdio.h>
#include<conio.h>

void swap (int *, int *);

int main()
{
 int a, b;
 clrscr();
 printf("Please enter the two numbers that you want to swap\n");
 printf("enter a\n");
 scanf("%d",&a);
 printf("enter b\n");
 scanf("%d",&b);
 swap(&a,&b);
 printf("a is %d, b is %d\n",a,b);
 getch();
 return 0;
}
void swap(int * a, int * b )
{
 int temp;
 temp = *a;
 *a=*b;
 *b=temp;
}