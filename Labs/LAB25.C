#include<stdio.h>
#include<conio.h>

void main(void)
{
 int i,n;
 for (i=1;i<11;++i)
 {
  for (n=10;n>0;--n)
  {
   printf("%d * %d = %d\n",i,n,i*n);

  }
  printf("***********************\n");

 }
 getch();

}