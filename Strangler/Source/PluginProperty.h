#ifndef TOMATL_PLUGIN_PROPERTY
#define TOMATL_PLUGIN_PROPERTY

#include <map>
#include <cstring>

using std::string;
using std::map;

class PluginProperty
{
public:
	PluginProperty(void);

	PluginProperty(string intName, string extName, float value, double minVal, double maxVal, IInterpolationProvider* scale, IPluginPropertyConsumer& parent) 
		: m_intName(intName), m_extName(extName), m_value(value), m_scale(scale), m_parent(parent)
	{
		m_scale->addPoint(0.0, minVal);
		m_scale->addPoint(1.0, maxVal);
	}

	~PluginProperty(void)
	{
		delete m_scale;
	}
	
	string getIntName(void)
	{
		return m_intName;
	}

	string getExtName(void)
	{
		return m_extName;
	}

	float getValue(void)
	{
		return m_value;
	}

	double getMinVal(void)
	{
		return m_scale->interpolate(0.0);
	}

	double getMaxVal(void)
	{
		return m_scale->interpolate(1.0);
	}

	PluginProperty& setValue(float value)
	{
		m_value = value;
		m_parent.invalidateProperties();

		return *this;
	}

	double getScaledValue(void)
	{
		return m_scale->interpolate(m_value);
	}

	PluginProperty& setScaledValue(double value)
	{
		//m_value = (float)m_scale->getInverseCopy().interpolate(value);
		m_value = (float)(LinearInterpolationProvider().fillFrom(*m_scale).invertSelf().interpolate(value));
		//m_value = (float)(LinearInterpolationProvider(m_scale).invertSelf().interpolate(value));
		m_parent.invalidateProperties();

		return *this;
	}

private:
	string m_intName;
	string m_extName;
	float m_value;
	IInterpolationProvider* m_scale;
	IPluginPropertyConsumer& const m_parent;
};

#endif