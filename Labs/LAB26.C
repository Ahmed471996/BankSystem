#include<stdio.h>
#include<conio.h>

void main (void)
{
 char nam1[20],nam2[20],nam3[20];
 int i;
 clrscr();
 printf("please enter 3 names\n");
 scanf("%s",&nam1);
 scanf("%s",&nam2);
 scanf("%s",&nam3);
 printf("the 3 names are\n");
 puts(nam1);
 puts(nam2);
 puts(nam3);
 getch();
}
