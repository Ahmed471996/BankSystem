#include<stdio.h>
#include<conio.h>

void main(void)
{
  int x=10;
  char ch='C';
  float y=1.3;
  char c;

  clrscr();

  printf("%c\n", ch);  //character format
  printf("%d\n", x);   //int format
  printf("%f\n", y);   //float format
  printf("please enter a character only to get its ASCII code\n");
  scanf("%c",&c); //read from the user and put in c variable
  printf("The ASCII of %c code is %d\n",c,c);
  printf("Hexadecimal value of %d is: %X\n",x,x) ;
  printf("Octal value of %d is: %o\n",x, x);
  getch();

}