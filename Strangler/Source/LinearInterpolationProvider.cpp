#include "LinearInterpolationProvider.h"
#include <cmath>
#include <map>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::iterator;

LinearInterpolationProvider::LinearInterpolationProvider(void) : m_pointList(), m_it(m_pointList.end())
{
	clear();
}

IInterpolationProvider& LinearInterpolationProvider::addPoint(double x, double y)
{
	m_pointList[x] = y;
	m_pointCount = m_pointList.size();
	m_minX = m_pointList.begin()->first;
	m_maxX = m_pointList.rbegin()->first;

	return *this;
}

LinearInterpolationProvider::~LinearInterpolationProvider(void)
{

}

IInterpolationProvider& LinearInterpolationProvider::getInverseCopy(void)
{
	LinearInterpolationProvider& result = LinearInterpolationProvider();

	for (map<double, double>::iterator i = m_pointList.begin(); i != m_pointList.end(); ++i)
	{
		result.addPoint(i->second, i->first);
	}

	return result;
}

IInterpolationProvider& LinearInterpolationProvider::clear(void)
{
	m_pointList.clear();
	m_pointCount = 0;
	m_minX = 0;
	m_maxX = 0;

	return *this;
}

std::map<double, double> LinearInterpolationProvider::getPointList(void)
{
	return m_pointList;
}

IInterpolationProvider& LinearInterpolationProvider::invertSelf(void)
{
	map<double, double> copy = map<double, double>(m_pointList);
	m_pointList.clear();
	map<double, double>::iterator i;

	for (i = copy.begin(); i != copy.end(); ++i)
	{
		addPoint(i->second, i->first);
	}

	return *this;
}

IInterpolationProvider& LinearInterpolationProvider::fillFrom(IInterpolationProvider& subject)
{
	m_pointList = subject.getPointList();
	return *this;
}

double LinearInterpolationProvider::makeOutValue(std::map<double, double>::iterator lower, std::map<double, double>::iterator upper)
{
	return 0.0;
}

double LinearInterpolationProvider::interpolate(double value)
{
	//std::map<double, double>::iterator upperIter = m_pointList.upper_bound(value);
	//std::map<double, double>::iterator lowerIter = m_pointList.lower_bound(value);

	if (m_pointCount == 0)
	{
		return 0.0;
	}
	else if (m_pointCount == 1)
	{
		return m_pointList[m_minX];
	}
	else if (value < m_minX)
	{
		return m_pointList[m_minX];
	}
	else if (value > m_maxX)
	{
		return m_pointList[m_maxX];
	}
	else
	{
		for (m_it = m_pointList.begin(); m_it != m_pointList.end(); ++m_it)
		{
			if (value == m_it->first)
			{
				double x = m_it->first;
				m_it = m_pointList.end();

				return m_pointList[x];
			}
			else if (value > m_it->first)
			{
				break;
			}
		}
		
		double x1 = m_it->first;
		double y1 = m_it->second;
		++m_it;
		double x0 = m_it->first;
		double y0 = m_it->second;
		
		m_it = m_pointList.end();
		return y0 + (((value - x0) * (y1 - y0)) / (x1 - x0));
	}

	if (m_pointList.find(value) != m_pointList.end())
	{
		return m_pointList[value];
	}

	return 0.0;
	
	/*if (lowerIter == m_pointList.end() || upperIter == m_pointList.end())
	{
		if (m_pointList.size() > 0)
		{
			if (value < m_pointList.begin()->first)
			{
				return m_pointList.begin()->second;
			}
			else if (value > m_pointList.rbegin()->first)
			{
				return m_pointList.rbegin()->second;
			}
			else
			{
				return 0.0;
			}
		}
		else
		{
			return 0.0;
		}
	}
	else
	{
		--upperIter;

		double x0 = upperIter->first;
		double y0 = upperIter->second;
		double x1 = lowerIter->first;
		double y1 = lowerIter->second;

		return y0 + (((value - x0) * (y1 - y0)) / (x1 - x0));
	}*/
}