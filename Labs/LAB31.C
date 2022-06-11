#include<stdio.h>
#include<conio.h>

float power(int n1, int n2);  //function prototype
int main ()
{
 //variables declaration
 int base, a;
 float result;

 clrscr();

 printf("Enter the base number: \n");
 scanf("%d",&base);
 printf("Enter the power number\n");
 scanf("%d",&a);
 if (a>0)
 {
 result= power(base,a);
 printf("%d ^%d = %.2f", base, a, result);
 }
 else if (a<0)
 {
 result=power(base,-a);
 printf("%d ^%d = %.2f",base, a, (float) 1/result);
 }

 getch();
 return 0;

}
float power (int base, int a)
{ if(a>0)
  {
   return (base * power (base, a-1));
  }
  else if (a==0)
  {
   return 1;
  }
}