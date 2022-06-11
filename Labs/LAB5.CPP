#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>  //with fabs function to get absolute of a number

class complex
 {
 private:
	 float real;
	 float imag;
 public:
	 complex();
	 complex(float r);
	 complex(float r, float i);
	 ~complex();
	 void setreal(float r);
	 void setreal();
	 void setimag(float i);
	 void setimag();
	 void setall(float r, float i);
	 void setall();
	 float getreal();
	 float getimag();
	 complex add(complex c);
	 complex sub(complex c);
	 void print ();
 };

 complex::complex()
  {
  real = imag =0;
  cout<<"constructor with no parameters was called"<<endl;
  }

 complex::complex(float r, float i)
  {
  real=r;
  imag=i;
  cout<<"constructor with 2 parameters was called"<<endl;
  }

 complex::complex(float r)
  {
  real=imag=r;
  cout<<"constructor with 1 parameter was called"<<endl;
  }

 void complex::setreal(float r)
  {
  real=r;
  cout<<"real setter with 1 parameter was called"<<endl;
  }

 void complex::setreal()
  {
  real=0;
  cout<<"real setter with 0 parameters was called"<<endl;
  }

 void complex::setimag(float i)
  {
  imag=i;
  cout<<"img setter with 1 parameter was called"<<endl;
  }

 void complex::setimag()
  {
  imag=0;
  cout<<"img setter with 0 parameters was called"<<endl;
  }

 void complex::setall(float r, float i)
  {
  real=r;
  imag=i;
  cout<<"setall setter with 2 paramters was called"<<endl;
  }
 void complex::setall()
  {
   imag=real=0;
   cout<<"setall setter with 0 parameters was called"<<endl;
  }

 float complex::getreal()
  {
  return real;
  }

 float complex::getimag()
  {
  return imag;
  }

 complex complex::add(complex c)
  {
  complex temp;
  temp.real=real+c.real;
  temp.imag=imag+c.imag;
  return temp;
  }

 complex complex::sub(complex c)
  {
  complex temp;
  temp.real=real-c.real;
  temp.imag=imag-c.imag;
  return temp;
  }

 complex::~complex()
  {
  cout<<"destructor was called"<<endl;
  }

 void complex::print()
  {
  if(real!=0&&imag!=0)
   {
   if(imag<0)
	{
	cout<<real<<"-"<<fabs(imag)<<"i"<<endl;
	}
   else
	{
	cout<<real<<"+"<<imag<<"i"<<endl;
	}
   }
  else if (real==0&&imag!=0)
   {
   if (imag<0)
   {
	cout<<"-"<<fabs(imag)<<"i"<<endl;
   }
   else
   {
	cout<<"+"<<imag<<"i"<<endl;
   }
   }
  else if (real!=0&&imag==0)
  {
   cout<<real;
  }
  else if (real==0&&imag==0)
  {
   cout<<"0"<<endl;
  }
  }

int main()
 {
 complex comp1, comp2, resultcomp;
 float rnum1,rnum2,inum1,inum2;
 int num,num1;
 clrscr();
 cout<<"do you wanna use setters or constructor"<<endl;
 cout<<"1.constructor"<<endl<<"2.setters"<<endl;
 cin>>num1;
 if (num1==1)
 {
 cout<<"which constructor do you wanna use?"<<endl;
 cout<<"1.constructor with no parameters"<<endl<<"2.constructor with 1 parameters"<<endl<<"3.constructor with 2 parameters"<<endl;
 cin>>num;
 if (num==1)
  {
  comp1=complex();
  comp2=complex();
  }
 else if (num==2)
  {
  cout<<"please enter the first complex number"<<endl;
  cout<<"enter the real or the imag part"<<endl;
  cin>>rnum1;
  comp1=complex(rnum1);
  cout<<"please enter the second complex number"<<endl;
  cout<<"enter the real or the imag part"<<endl;
  cin>>rnum2;
  comp2=complex(rnum2);
  }
 else if (num==3)
  {
  cout<<"please enter the first complex number"<<endl;
  cout<<"enter the real part"<<endl;
  cin>>rnum1;
  cout<<"enter the imaginary part"<<endl;
  cin>>inum1;
  cout<<"please enter the second complex number"<<endl;
  cout<<"please enter the real part"<<endl;
  cin>>rnum2;
  cout<<"please enter the imag part"<<endl;
  cin>>inum2;
  comp1=complex(rnum1,inum1);
  comp2=complex(rnum2,inum2);
  }
 }
 else if (num1==2)
  {
   cout<<"which setter do you wanna use?"<<endl;
   cout<<"1.set parts"<<endl<<"2.setall"<<endl;
   cin>>num;
   if(num==1)
	{
	cout<<"please enter the first complex number"<<endl;
	cout<<"enter the real part"<<endl;
	cin>>rnum1;
	cout<<"enter the imaginary part"<<endl;
	cin>>inum1;
	cout<<"please enter the second complex number"<<endl;
	cout<<"please enter the real part"<<endl;
	cin>>rnum2;
	cout<<"please enter the imag part"<<endl;
	cin>>inum2;
	comp1.setreal(rnum1);
	comp1.setimag(inum1);
	comp2.setreal(rnum2);
	comp2.setimag(inum2);
	}
   else if (num==2)
   {
	cout<<"1.set with no parameters"<<endl<<"2.set with 2 paramters"<<endl;
	cin>>num;
	if (num==1)
	{
	comp1.setall();
	comp2.setall();
	}
	else if (num==2)
	{
	cout<<"please enter the first complex number"<<endl;
	cout<<"enter the real part"<<endl;
	cin>>rnum1;
	cout<<"enter the imaginary part"<<endl;
	cin>>inum1;
	cout<<"please enter the second complex number"<<endl;
	cout<<"please enter the real part"<<endl;
	cin>>rnum2;
	cout<<"please enter the imag part"<<endl;
	cin>>inum2;
	comp1.setall(rnum1,inum1);
	comp2.setall(rnum2,inum2);
	}
   }
  }
 cout<<"do you wanna add or sub these 2 numbers"<<endl;
 cout<<"1.add"<<endl<<"2.sub"<<endl;
 cin>>num;
 if (num==1)
  {
  resultcomp=comp1.add(comp2);
  cout<<"the add is"<<endl;
  resultcomp.print();
  }
 else if(num==2)
  {
  resultcomp=comp1.sub(comp2);
  cout<<"the sub is"<<endl;
  resultcomp.print();
  }
 getch();
 return 0;
}