#include<stdio.h>
#include<conio.h>

void main (void)
{
 float num;
 int sum=0;
 clrscr();
 while(sum<=100)
 {
   printf("please enter a number\n");
   scanf("%f",&num);
   sum+=num;
 }
 printf("the sum is %d",sum);
 getch();
}