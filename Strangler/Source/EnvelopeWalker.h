#ifndef TOMATL_ENVELOPE_WALKER
#define TOMATL_ENVELOPE_WALKER

class EnvelopeWalker
{
public:
	EnvelopeWalker(void);
	~EnvelopeWalker(void);

	EnvelopeWalker& setAttackSpeed(double attackMs);
	EnvelopeWalker& setReleaseSpeed(double releaseMs);
	EnvelopeWalker& setSampleRate(double sampleRate);
	double process(double in);
private:
	double m_attackMs;
	double m_releaseMs;
	double m_attackCoef;
	double m_releaseCoef;
	double m_currentValue;
	double m_sampleRate;
};

#endif