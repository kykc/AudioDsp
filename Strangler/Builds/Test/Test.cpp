// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinearInterpolationProvider.h"
#include "LinearInterpolationProvider.cpp"
#include <iostream>

using std::cout;
using std::endl;

class A
{
public:
	A(LinearInterpolationProvider& l) : m_l(l)
	{

	}

	LinearInterpolationProvider& getL(void)
	{
		return m_l;
	}
private:
	LinearInterpolationProvider& m_l;
};

int _tmain(int argc, _TCHAR* argv[])
{
	LinearInterpolationProvider l;
	l.addPoint(0.0, -75.0);
	l.addPoint(1.0, 0.0);

	//A a = A(LinearInterpolationProvider());
	///a.getL().addPoint(0.0, -75.0);
	//a.getL().addPoint(1.0, 0.0);

	cout << l.interpolate(0.5) << endl;
	//cout << a.getL().interpolate(0.5) << endl;


	system("PAUSE");
	return 0;
}

