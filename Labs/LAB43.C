#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int main()
{
 char * str_source,* str_dist;
 int n;

 clrscr();

 printf("Please enter the size of the string\n");
 scanf("%d",&n);
 str_source= (char *) malloc(n * sizeof(char));
 str_dist=(char*) malloc(n *sizeof(char));
 printf("Please enter a string\n");
 scanf("%s",str_source);
 printf("the value of souce string\n");
 puts(str_source);
 strcpy(str_dist,str_source);
 printf("the value of dist. string\n");
 puts(str_dist);
 free(str_dist);
 free(str_source);
 getch();
 return 0;
}