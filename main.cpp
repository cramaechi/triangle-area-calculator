//Program that computes and outputs the area of an arbitrary triangle.
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
using namespace std;

void input(int& s1, int& s2, int& s3);
//Prompts the user for input.

void areaAndPerimeter(int s1, int s2, int s3, double& area, int& perimeter);
//Precondition: s1, s2, s3, area, and perimeter are >0.
//Computes the area of an arbitrary triangle.

void output(double area, int perimeter);
//Outputs the area of the aribitrary triangle.

bool sidesOK(int s1, int s2, int s3);
//Returns true if s1, s2, and s3 are all non-zero values and false they're not.

int main()
{
	int s1, s2, s3, perimeter;
	double area;

	input(s1,s2,s3);
	areaAndPerimeter(s1,s2,s3,area,perimeter);
	output(area,perimeter);

	return 0;
}

void input(int& s1, int& s2, int& s3)
{
	cout<<"Enter three sides of an arbitrary triangle: ";
	cin>>s1>>s2>>s3;

    if (sidesOK(s1,s2,s3))
	{
		s1 = abs(s1);
	    s2 = abs(s2);
	    s3 = abs(s3);
	}
	else
	{
		cout<<"Fatal Error: Illegal input. Aborting program.";
		exit(1);
	}
}
void areaAndPerimeter(int s1,int s2, int s3, double& area, int& perimeter)
{
	perimeter = s1 + s2 + s3;
	double s = perimeter/2.0;
	area = sqrt((s*(s - s1)*(s - s2)*(s - s3)));
}

void output(double area, int perimeter)
{
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(1);
    if (area > 0)
    {
	    cout<<"The area of the triangle is: "<<area<<endl;
	    cout<<"The perimeter of the triangle is: "<<perimeter<<endl;
    }
    else
        cout<<"The area of the triange could not be computed."<<endl;
}

bool sidesOK(int s1, int s2, int s3)
{
	return (s1 > 0 && s2 > 0  && s3 > 0);
}
