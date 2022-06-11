#include<stdio.h>
#include<conio.h>

void main(void)
{
 int arr[3][4],sum=0, i,j;
 float avg;
 clrscr();
 printf("enter the array numbers\n");
 //to enter the arr elements
 for(i=0;i<3;++i)
 {
  for(j=0;j<4;++j)
  {
   scanf("%d",&arr[i][j]);
  }
 }
 //to calculate the sum
 for(i=0;i<3;++i)
 {
   for(j=0;j<4;++j)
   {
	sum=sum+arr[i][j];
   }
   printf("The sum of row %d is %d\n",i,sum);
   sum=0;
 }
 //to calculate avg
 for(j=0;j<4;++j)
 {
  for(i=0;i<3;++i)
  {
   sum=sum+arr[i][j];
  }
  avg= (float) sum/3;
  printf("the avg of column %d is %.2f\n",j,avg);
  sum=0;
  avg=0;
 }
 getch();
}