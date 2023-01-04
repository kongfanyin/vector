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
		~Vector();
		double xval()const
		{
			return x;//report x
		}
		double yval()const
		{
			return y;//report y
		}
	private:
		double x;
		double y;
		double radious;
		double angel;
		Mode mode_;
	};

	Vector::Vector()
	{


	}
	Vector::~Vector()
	{


	}
}
#endif // !VECTOR
