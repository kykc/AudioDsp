#include "EnvelopeWalker.h"
#include <cmath>


EnvelopeWalker::EnvelopeWalker(void) : m_currentValue(0.0), m_sampleRate(44100.0)
{
	setAttackSpeed(1);
	setReleaseSpeed(10);
}

EnvelopeWalker::~EnvelopeWalker(void)
{
}

EnvelopeWalker& EnvelopeWalker::setSampleRate(double sampleRate)
{
	m_sampleRate = sampleRate;
	setAttackSpeed(m_attackMs);
	setReleaseSpeed(m_releaseMs);

	return *this;
}

EnvelopeWalker& EnvelopeWalker::setAttackSpeed(double attackMs)
{
	m_attackMs = attackMs;
	m_attackCoef = exp(log(0.01) / (m_attackMs * m_sampleRate * 0.001));

	return *this;
}

EnvelopeWalker& EnvelopeWalker::setReleaseSpeed(double releaseMs)
{
	m_releaseMs = releaseMs;
	m_releaseCoef = exp(log(0.01) / (m_releaseMs * m_sampleRate * 0.001));

	return *this;
}

double EnvelopeWalker::process(double in)
{
	double tmp = fabs(in); 
	
	if (tmp > m_currentValue) 
    {
		m_currentValue = m_attackCoef * (m_currentValue - tmp) + tmp;
	}
	else
	{
		m_currentValue = m_releaseCoef * (m_currentValue - tmp) + tmp;
	}

	return m_currentValue;
}