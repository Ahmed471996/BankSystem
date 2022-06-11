#include<stdio.h>
#include<conio.h>

void main(void)
{
 int num;
 clrscr();
 printf("Please enter a number to select a function or exit\n");
 printf("1-Add\n2-Display\n3-Exit\n");
 scanf("%d",&num);
 while (num !=3)
 {
 if (num==1)
 {
  printf("Loading the Add function...\n");
 }
 else if (num==2)
 {
  printf("Loading the Display function...\n");
 }
 else if (num==3)
 {
 }
 scanf("%d",&num);
 }
 printf("Exit....\n");
 getch();
}