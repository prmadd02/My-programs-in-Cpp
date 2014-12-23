//Paul Maddox
//Rectangle



#include <iostream>    
#include <vector>
#include <stdlib.h>
using namespace std;  


template <typename Comparable>
const Comparable & findMax( const vector<Comparable> & a )
{
    int maxElement = 0;

    for( unsigned i = 1; i < a.size( ); i++ )
        if( a[ maxElement ] < a[ i ] )
            maxElement = i;

    return a[ maxElement ];
}



template <class Object, class Comparator>
const Object & findMax( const vector<Object> & a, Comparator LessThan )
{
    int maxElement = 0;
	
    for( int i = 1; i < a.size( ); i++ )
        if( LessThan( a[ maxElement ], a[ i ] ) )
            maxElement = i;

    return a[ maxElement ];
}


class Rectangle
{
  public:
    void
	 setElement( string n, int  l, int  w )
      { name = n; length = l; width = w; }
    	const int & getlength( ) const // length getter
      		{ return length; }
		const int getwidth() const // width getter
		{
			return width;
		}
		const int getarea() const // area getter
		{
			return (length*width);
		}
		const int getperimeter() const //perimeter getter
		{
			return ((2*length) + (2*width));
		}
    	void print( ostream & out ) const // print function
      	{ 
		  	out << length <<  " X " << width << endl; 
		}
    
		bool operator< ( const Rectangle & rhs ) const
      	{ 
		  	return width < rhs.width; 
		}

  private:
    int length;
    int width;
    string name;
};



ostream & operator<< ( ostream & out, const Rectangle & rhs )
{
    rhs.print( out );
    return out;
}


class RectangleAreaCompare // compare area
{
  public:
  bool operator () ( const Rectangle & lhs, const Rectangle & rhs) const
    { 
		return (lhs.getarea() < rhs.getarea());
	}
};

class RectanglePerimeterCompare //compare perimeter
{
  public:
  bool operator () ( const Rectangle & lhs, const Rectangle & rhs) const
    { 
		return (lhs.getperimeter() < rhs.getperimeter());
	}
};




int main( )
{
    vector<Rectangle> v(3);


//set values
    v[0].setElement("R1",30,5);
    v[1].setElement("R2",15,10);
    v[2].setElement("R3",20,15);
    for (unsigned i = 0; i < v.size(); i++)
        v[i].print(cout); 
    
	
	system ("PAUSE");

	cout << endl << "The max Area using findMax" << endl;  	
	cout << findMax(v, RectangleAreaCompare()) << endl;
    
	system ("PAUSE");

	cout << endl << "The max Perimeter using findMax" << endl;  	
	cout << findMax(v, RectanglePerimeterCompare()) << endl;

	return 0;
}
