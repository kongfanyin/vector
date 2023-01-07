#define _CRT_SECURE_NO_WARNINGS 1


#include"Vector.h"
#include<string>
#include<fstream>
#include<iostream>
#include<ctime>
int main(char argc, char** argv)
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));//seed random num generator
	double direction;
	Vector step;
	Vector result(0.0,0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "enter target distance (q to quite)\n";
	while (cin>>target)
	{
		cout << "enter step length: ";
		if (!(cin >> dstep))
		{
			break;
		}
		while (result.magval()<target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result =result+step;
			steps++;
		}
		cout << "after " << steps << "steps,the subject ""has the following location: \n";
		cout << result << endl;
		result.polar_mode();
		cout << "or\n" << result << endl;
		cout << "Average outward distance per step=" << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "enter target distance (q to quite)";
	}
	cout << "bye.\n";
	cin.clear();
	while (cin.get() != '\n')
	{
		continue;
	}
	return 0;
}