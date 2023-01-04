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
		~Vector();

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
