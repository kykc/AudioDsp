#include "ClassicDynamicCompressor.h"
#include "StreamProperties.h"
#include <cmath>

ClassicDynamicCompressor::ClassicDynamicCompressor(StreamProperties& streamProp) 
	: m_envlp(), m_intrpl(), m_lmt(1.0), m_thresold(0.0), m_autoGain(false), m_hardLimit(false), m_streamProp(streamProp)
{
}

ClassicDynamicCompressor::~ClassicDynamicCompressor(void)
{
}

ClassicDynamicCompressor& ClassicDynamicCompressor::setAttackSpeed(double attackMs)
{
	m_envlp.setAttackSpeed(attackMs);

	return *this;
}

ClassicDynamicCompressor& ClassicDynamicCompressor::setReleaseSpeed(double releaseMs)
{
	m_envlp.setReleaseSpeed(releaseMs);

	return *this;
}

ClassicDynamicCompressor& ClassicDynamicCompressor::setThresoldDb(double thresoldDb)
{
	m_thresold = m_streamProp.toSampleVal(thresoldDb);
	fillInterpolationProvider();

	return *this;
}

ClassicDynamicCompressor& ClassicDynamicCompressor::setLimitDb(double limitDb)
{
	m_lmt = m_streamProp.toSampleVal(limitDb);
	fillInterpolationProvider();

	return *this;
}

ClassicDynamicCompressor& ClassicDynamicCompressor::setAutoGain(bool autoGain)
{
	m_autoGain = autoGain;

	return *this;
}

ClassicDynamicCompressor& ClassicDynamicCompressor::setHardLimit(bool hardLimit)
{
	m_hardLimit = hardLimit;

	return *this;
}

bool ClassicDynamicCompressor::hasHardLimit(void)
{
	return m_hardLimit || m_autoGain;
}

bool ClassicDynamicCompressor::hasAutoGain(void)
{
	return m_autoGain;
}

void ClassicDynamicCompressor::fillInterpolationProvider(void)
{
	m_intrpl
			.clear()
			.addPoint(0.0, 0.0)
			.addPoint(m_thresold, m_thresold)
			.addPoint(1.0, m_lmt);
}

double ClassicDynamicCompressor::processSample(double sample)
{
	double sign = sample > 0 ? 1 : -1;
	double curEnvVal = m_envlp.process(sample);
	curEnvVal = std::max(0.0, std::min(1.0, curEnvVal));

	//double inDb = GlobalState::getInstance().convSampleToDb(curEnvVal);
	//double outDb = GlobalState::getInstance().convSampleToDb(m_intrpl.interpolate(curEnvVal));

	//double coef = GlobalState::getInstance().convDbToSample(inDb - outDb);
	double coef = m_intrpl.interpolate(curEnvVal) / curEnvVal;

	double compressed = sample * coef;

	if (hasHardLimit())
	{
		compressed = sign > 0 ? std::min(compressed, m_lmt * sign) : std::max(compressed, m_lmt * sign);
	}

	if (hasAutoGain())
	{
		compressed *= ((1 / m_lmt) * 0.999999);
	}

	return compressed;
}