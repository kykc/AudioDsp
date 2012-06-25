#ifndef TOMATL_INTERPOLATION_PROVIDER_INTERFACE
#define TOMATL_INTERPOLATION_PROVIDER_INTERFACE

#include <map>

using std::map;

class IInterpolationProvider
{
public:
	virtual double interpolate(double value) = 0;
	virtual IInterpolationProvider& addPoint(double x, double y) = 0;
	virtual IInterpolationProvider& clear(void) = 0;
	virtual map<double, double> getPointList(void) = 0;
	virtual IInterpolationProvider& invertSelf(void) = 0;
	virtual IInterpolationProvider& fillFrom(IInterpolationProvider& subj) = 0;
	//virtual IInterpolationProvider& getInverseCopy(void) = 0;
};

#endif