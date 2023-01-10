#define _CRT_SECURE_NO_WARNINGS 1


#include"Vector.h"
#include<string>
#include<fstream>
#include<iostream>
#include<ctime>
//int main(char argc, char** argv)
//{
//	using namespace std;
//	using VECTOR::Vector;
//	srand(time(0));//seed random num generator
//	double direction;
//	Vector step;
//	Vector result(0.0,0.0);
//	unsigned long steps = 0;
//	double target;
//	double dstep;
//	cout << "enter target distance (q to quite)\n";
//	while (cin>>target)
//	{
//		cout << "enter step length: ";
//		if (!(cin >> dstep))
//		{
//			break;
//		}
//		while (result.magval()<target)
//		{
//			direction = rand() % 360;
//			step.reset(dstep, direction, Vector::POL);
//			result =result+step;
//			steps++;
//		}
//		cout << "after " << steps << "steps,the subject ""has the following location: \n";
//		cout << result << endl;
//		result.polar_mode();
//		cout << "or\n" << result << endl;
//		cout << "Average outward distance per step=" << result.magval() / steps << endl;
//		steps = 0;
//		result.reset(0.0, 0.0);
//		cout << "enter target distance (q to quite)";
//	}
//	cout << "bye.\n";
//	cin.clear();
//	while (cin.get() != '\n')
//	{
//		continue;
//	}
//	return 0;
//}

//write to file
int main(char argc, char** argv)
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));//seed random-num generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dsteps;
	//write to file
	ofstream fout;
	fout.open("walk.txt");
	cout << "输入目标距离 (按q 退出).\n";
	while (cin>>target)
	{
		cout << "输入步长：\n";
		if (!(cin>>dsteps))
		{
			break;
		}
		fout << "target distance: " << target << ",";
		fout << "step size: " << dsteps << endl;
		while (result.magval()<target)
		{
			direction = rand() % 360;
			step.reset(dsteps, direction, Vector::POL);
			result = result + step;
			fout << step << ":" << result << endl;
			steps++;
		}
		cout << "after " << steps << "steps ,the subject has the following location: \n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "输入目标距离 (按q 退出): ";
	}
	cout << "bye.\n";
	return 0;
}