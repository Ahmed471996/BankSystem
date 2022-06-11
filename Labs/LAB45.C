#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
 char **pptr;
 int i=0, j=0, n, m;
 clrscr();
 printf("please enter the size of pointer to array\n");
 scanf("%d",&n);
 pptr=(char **) malloc(n * sizeof(char*));

 if (pptr==NULL)
 {
  printf("allocation error\n");
  exit(0);
 }

 for(i=0;i<n;i++)
 {
  printf("Please enter the size of this pointer to string\n");
  scanf("%d",&m);
  pptr[i] = (char *) malloc (m * sizeof(char));

  if(pptr[i]==NULL)
  {
  printf("allocation error\n");
  exit(0);
  }
 }

 for (i=0;i<n;i++)
 {
   printf("Please enter a string\n");
   scanf("%s",pptr[i]);
 }

 for(i=0;i<n;i++)
 {
   puts(pptr[i]); //puts takes add.
 }

 getch();
 return 0;

 }