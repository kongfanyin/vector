#pragma once
#ifndef VECTOR_
#define VECTOR_
#include<iostream>
namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode
		{
			RECT,POL
		};
		//RECT  for rectangel ,POL for Polar modes
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval()const
		{
			return x;//report x
		}
		double yval()const
		{
			return y;//report y
		}
		double magval()const
		{
			return mag;//report magnitude
		}
		double angval()const
		{
			return ang;//report angle
		}
		void polar_mode();//set mode to polar
		void rect_mode();//set mode to angle
		//opreator overloading
		Vector operator+(const Vector &v)const;
		Vector operator-(const Vector &v)const;
		Vector operator-();
		Vector operator*(double n)const;
		//friend
		friend Vector operator*(double n, const Vector &a);
		friend std::ostream& operator<<(std::ostream &os, const Vector &v);

		//conversion function
		operator double()const;

	private:
		double x;
		double y;
		double mag;
		double ang;
		Mode mode_;
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();

	};
}//end  namespace VECTOR
#endif // !VECTOR
