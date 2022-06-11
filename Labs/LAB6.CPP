#include<iostream.h>
#include<stdio.h>
#include<conio.h>

class stack
{
 private:
  int top;
  int size;
  int *ptr;
  static int counter;
 public:
  int isfull();
  int isempty();
  int push(int n);
  int pop(int &n);
  static int getcounter()
  {
   return counter;
  }
  stack()
  {
   top =0;
   size= 10;
   ptr= new int[size];
   cout<<"default stack was called"<<endl;
  }
  stack (int n)
  {
   top=0;
   size=n;
   ptr=new int [size];
   cout<<"stack with 1 paramter was called"<<endl;
  }
  ~stack()
  {
   delete[] ptr;
   size=0;
   counter--;
   cout<<"destructor was called"<<endl;
  }
  friend void viewcontent(stack s);
  };
  void viewcontent (stack s)
   {
	int i;               //we can access private paramters of the stack
	for (i=0;i<s.top;i++)
	{
	cout<<"element no."<<i+1<<endl;
	cout<<s.ptr[i]<<endl;
	}
   }
 int stack::push(int n)
  {
   if (isfull())
   {
	return 0;
   }
   ptr[top]=n;
   top++;
   counter++;
   return 1;
   }
 int stack::pop(int &n)
   {
	if (isempty())
	{
	 return 0;
	}
	top--;
	counter--;
	n=ptr[top];
	return 1;
   }
 int stack::isfull()
  {
   return (top==size);
  }
 int stack::isempty()
  {
   return (top==0);
  }

int stack::counter=0;

int main()
{
  clrscr();
  int num, size,i,n1;
  cout<<"Please enter the size of the stack"<<endl;
  cin>>size;
  stack s1(size);
  cout<<"1.add member"<<endl<<"2.remove last member"<<endl<<"3.view the content of the stack"<<endl<<"4.total number of elements"<<endl<<"5.exit"<<endl;
  cin>>i;
  while (i!=5)
	{
	 if(i==1)
	  {
	   cout<<"Please enter the an integer number"<<endl;
	   cin>>n1;
	   s1.push(n1);
	   cout<<"1.add member"<<endl<<"2.remove last member"<<endl<<"3.view the contnet of the stack"<<endl<<"4.total number of elements"<<endl<<"5.exit"<<endl;
	   cin>>i;
	  }
	 else if(i==2)
	  {
	   if(s1.pop(num))
		{
		 cout<<"the last number entered "<<num<<" was removed"<<endl;
		}
		cout<<"1.add member"<<endl<<"2.remove last member"<<endl<<"3.view the content of the stack"<<endl<<"4.total number of elements"<<endl<<"5.exit"<<endl;
		cin>>i;
	  }
	 else if (i==3)
	  {
	   cout<<"the content of the stack"<<endl;
	   viewcontent(s1);
	   cout<<endl;
	   cout<<"1.add member"<<endl<<"2.remove last member"<<endl<<"3.view the content of the stack"<<endl<<"4.total number of elements"<<endl<<"5.exit"<<endl;
	   cin>>i;
	  }
	 else if(i==4)
	  {
	   cout<<"the number of members creaed"<<endl<<stack::getcounter()<<endl;
	   cout<<"1.add member"<<endl<<"2.remove last member"<<endl<<"3.view the content of the stack"<<endl<<"4.total number of elements"<<endl<<"5.exit"<<endl;
	   cin>>i;
	  }
	}
  getch();
  return 0;
}