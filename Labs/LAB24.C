#include<stdio.h>
#include<conio.h>

void main (void)
{
 int i,n;
 for (i=1;i<11;++i)
 {
  for (n=1;n<11;++n)
  {
   printf("%d * %d = %d\n",i,n,i*n);
  }
  printf("****************************\n");

  }
 getch();
}