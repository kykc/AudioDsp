#include "IInterpolationProvider.h"

#ifndef TOMATL_LINEAR_INTERPOLATION
#define TOMATL_LINEAR_INTERPOLATION

#include <map>

class LinearInterpolationProvider : public IInterpolationProvider
{
public:
	LinearInterpolationProvider(void);
	~LinearInterpolationProvider(void);
	double interpolate(double value);
	IInterpolationProvider& addPoint(double x, double y);
	IInterpolationProvider& clear(void);
	std::map<double, double> getPointList(void);
	IInterpolationProvider& getInverseCopy(void);
	IInterpolationProvider& invertSelf(void);
	IInterpolationProvider& fillFrom(IInterpolationProvider& subj);
private:
	double makeOutValue(map<double, double>::iterator lower, map<double, double>::iterator upper);
	map<double, double> m_pointList;
	double m_minX;
	double m_maxX;
	map<double, double>::iterator m_it;
	int m_pointCount;
};

#endif