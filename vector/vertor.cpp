#define _CRT_SECURE_NO_WARNINGS 1
#include"Vector.h"
#include<cmath>
using std::cout;
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
namespace VECTOR
{
	const double Rad_to_deg = 360 / 6.28;
	//computer degree in one radian
	//private methods 
	void Vector::set_mag()
	{
		mag = sqrt(x*x + y * y);
	}
	void Vector::set_ang()
	{
		if (x == 0 && y == 0)
		{
			ang = 0;
		}
		else
		{
			ang = atan2(y, x);
		}
	}
	//set x from polar coordinate
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}
	//set y from polar coordinate
	void Vector::set_y()
	{
		y = mag * sin(ang);
	}
	//public methods

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode_ = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector()--";
			cout << "vector get to 0\n";
			x = y = mag = ang = 0;
			mode_ = RECT;
		}
	}
	//reset vector form rectangular coordinates if form is RECT or else from polar coordinates if form is POL
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode_ = form;
		if (form==RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if(form==POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector()--";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0;
			mode_ = RECT;
		}
	}
	void Vector::polar_mode()
	{
		mode_ = POL;
	}
	void Vector::rect_mode()
	{
		mode_ = RECT;
	}
	//operator overloading
	Vector Vector::operator+(const Vector &v)const
	{
		return Vector(x + v.x, y + v.y);
	}

	Vector Vector::operator-(const Vector &v)const
	{
		return Vector(x-v.x,y-v.y);
	}
	//reverse sign of vector
	Vector Vector::operator-()
	{
		return Vector(-x, -y);
	}
	//multiply vector by n
	Vector Vector::operator*(double n)const
	{
		return Vector(x*n, y*n);
	}
	Vector operator*(double n, const Vector &a)
	{
		return a * n;
	}

	//display rectangular coordinate if mode is RECT else display polar coordinate
	std::ostream& operator<<(std::ostream &os, const Vector &v)
	{
		if (v.mode_==Vector::RECT)
		{
			os << "(x,y)=(" << v.x << "," << v.y << ")";
		}
		else if (v.mode_==Vector::POL)
		{
			os << "(m,a)=(" << v.mag << "," << v.ang*Rad_to_deg << ")";
		}
		else
		{
			os << "vector object mode is invalid";
		}
		return os;
	}
	Vector::Vector()//default constructor
	{
		x = y = mag = ang = 0.0;
		mode_ = RECT;
	}
	Vector::~Vector()
	{
	}
}//end namespace vector

