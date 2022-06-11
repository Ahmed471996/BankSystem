#include<stdio.h>
#include<conio.h>
// Problem 7
void main (void)
{
 int arr[10], i, max, min;
 clrscr();
 printf("Please enter only 10 numbers\n");
 //reading elements from user
 for (i=0; i<10;++i)
 {
  scanf("%d",&arr[i]);
 }
 max=min=arr[0];
 //iterating over the array elements
 for (i=0; i<10;++i)
 {
  if (min>arr[i])
  {
   min=arr[i];
  }
  else if (max < arr[i])
  {
   max=arr[i];
  }
 }

 printf("The max is %d and The min is %d\n",max,min);

 getch();
}