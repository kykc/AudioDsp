#ifndef TOMATL_CLASSIC_DYNAMIC_COMPRESSOR
#define TOMATL_CLASSIC_DYNAMIC_COMPRESSOR

#include "LinearInterpolationProvider.h"
#include "EnvelopeWalker.h"
#include "StreamProperties.h"
#include <map>

class ClassicDynamicCompressor
{
public:
	ClassicDynamicCompressor(void);
	ClassicDynamicCompressor(StreamProperties&);
	~ClassicDynamicCompressor(void);

	double processSample(double sample);
	ClassicDynamicCompressor& setAttackSpeed(double attackMs);
	ClassicDynamicCompressor& setReleaseSpeed(double releaseMs);
	ClassicDynamicCompressor& setThresoldDb(double thresoldDb);
	ClassicDynamicCompressor& setLimitDb(double limitDb);
	ClassicDynamicCompressor& setAutoGain(bool autoGain);
	ClassicDynamicCompressor& setHardLimit(bool hardLimit);
	bool hasHardLimit(void);
	bool hasAutoGain(void);
private:
	double m_thresold;
	double m_lmt;
	bool m_hardLimit;
	bool m_autoGain;
	EnvelopeWalker m_envlp;
	LinearInterpolationProvider m_intrpl;
	void fillInterpolationProvider(void);
	StreamProperties& m_streamProp;
};

#endif