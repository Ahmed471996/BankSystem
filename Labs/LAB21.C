#include<stdio.h>
#include<conio.h>



void main (void)
{
 int cn,row,column,n,i;
 float dx, dy;
 clrscr();
 printf("Please enter the size of the magic square as odd number\n");
 scanf("%d",&n);
 //dx=(80-n)/(n+1);
 //dy=(25-n)/(n+1);
 printf("Please enter the values of dx and dy\n");
 scanf("%f",&dx);
 scanf("%f",&dy);
 cn=1;
 row=0;
 column=n/2;
 clrscr();
// gotoxy((column+1)*dy,(row+1)*dx);
// printf("%d",cn);
 while(cn <= n*n)
 {
  gotoxy((column+1)*dy,(row+1)*dx);
  printf("%d",cn);
   if (cn%n !=0)
	{
	//row check and change
		if((row-1) <0)
		 {
		  row=n-1;

		 }
		 else
		 {
		  row--;
		 }
	//column check and change
		if((column-1)<0)
		{
		 column=n-1;
		}
		else
		{
		  column--;
		}

	}
   else
	{
	  if (row+1>n)
	  {
	   row=0;

	  }
	  else
	  {
	   row++;
	  }

	 }

	//printing each number from 1 to n
   //	printf("%d", cn);
  cn++;
 }
 getch();

}