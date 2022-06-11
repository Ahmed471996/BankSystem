#include<iostream.h>
#include<stdio.h>
#include<conio.h>

class GeoShape
   {
	protected:

	  float dim1, dim2;

	public:

	  GeoShape()      //default constructor
		{
		 dim1=dim2=0;
		 cout<<"GoeShape default constructor was called"<<endl;
		}
	  GeoShape(float x) //constructor with 1 parameter
		{
		 dim1=dim2=x;
		 cout<<"Geoshape constructor with 1 parameter was called"<<endl;
		}
	  GeoShape(float x, float y)  //constructor with 2 parameters
		{
		 dim1=x;
		 dim2=y;
		 cout<<"GoeShape cpnstructor with 2 parameters was called"<<endl;
		}
	  void setdim1(float x)
		{
		 dim1=x;
		}
	  void setdim2(float y)
		{
		 dim2=y;
		}
	  float getdim1()
		{
		 return dim1;
		}
	  float getdim2()
		{
		 return dim2;
		}
	  virtual float calcarea()
		{
		 cout<<"calcarea of GoeShape was called"<<endl;
		 return 0;
		}
   };

//////////////////////////////////////////////////////////////////
class Rect: protected GeoShape   //was public
  {
   public:

	Rect(float x, float y): GeoShape(x, y)   //redirection
	 {
	  cout<<"Rect constructor with 2 parameters was called"<<endl;
	 }

   //	float calcarea()
   //	 {
   //	  return dim1*dim2;
   //	 }

	//after edit
	void setside(int length)
	 {
	   dim1=dim2=length;
	 }
	virtual float calcarea()
	 {
	   return dim1*dim2;
	 }
  };
//////////////////////////////////////////////////////////////////
class Square: protected Rect
   {
	public:

	  Square(float x): Rect(x,x)
	   {
		cout<<"Square constructor with 1 parameter was called"<<endl;
	   }
	//we can use the same function of rect area with square as square is a special case of rect
	//after edit
	  void setside(int length)
		{
		 dim1=dim2=length;
		}
	  virtual float calcarea()
		{
		 return dim1*dim2;
		}
   };
//////////////////////////////////////////////////////////////////
class Traingle: public GeoShape
   {
	public:

	  Traingle(float b, float h): GeoShape(b,h)
		 {
		  cout<<"Triangle constructor with 2 parameters was called"<<endl;
		 }
	  virtual float calcarea()
		 {
		  return .5 * dim1 * dim2;
		 }
   };
//////////////////////////////////////////////////////////////////
class Circle: protected GeoShape  //was public
   {
	public:

	Circle(float r):GeoShape(r)
	   {
		cout<<""<<endl;
	   }
	virtual float calcarea()
	   {
		return 22.0/7 * dim1 * dim2;  //dim1 must equal dim2
	   }
	//after edit
	 void setrad(float rad)
	   {
		dim1=dim2=rad;
	   }
   };
 float sumareas(GeoShape *p1, GeoShape *p2, GeoShape *p3)
	{
	 return p1->calcarea()+p2->calcarea()+p3->calcarea();
	}

int main()
 {
 clrscr();
 Traingle myt(20,10);
 cout<<"the area of the triangle ="<<myt.calcarea()<<endl;
 Circle myc(7);
 cout<<"the area of the circle ="<<myc.calcarea()<<endl;
 Rect myr(2,5);
 cout<<"the area of the rectangle ="<<myr.calcarea()<<endl;
 Square mys(5);
 cout<<"the area of the square ="<<mys.calcarea()<<endl;
 //cout<<"if we violating the square and circle constraints constraint"<<endl;
 //mys.setdim2(4);
 //myc.setdim2(3);
 mys.setside(4);   //after edit
 myc.setrad(5);    //after edit
 cout<<"the area of the s"<<endl;
 cout<<"the area of the square"<<mys.calcarea()<<endl;
 cout<<"the area of the circle"<<myc.calcarea()<<endl;
 clrscr();
 GeoShape *ptr;
 Traingle t(4,5);
 ptr= &t;
 cout<<ptr->calcarea()<<endl;
 Circle c(2);
 //ptr=&c;
 Rect r(2,5);
 cout<<ptr->calcarea()<<endl;
 cout<<"sumofareas"<<sumareas((GeoShape *) &r,(GeoShape *) &c, &t)<<endl; // upcasting
 delete ptr;                                                              // the same for all protected members 
 //downcasting is the process of coverting from a base pointer to a child pointer  (child *) parent (unsafe operation)
 //upcasting is the process of converting from a child pointer to a base pointer   (parent *) child         
 getch();
 return 0;
 }