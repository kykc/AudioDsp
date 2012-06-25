#ifndef TOMATL_PLUGIN_PROPERTY_CONSUMER_INTERFACE
#define TOMATL_PLUGIN_PROPERTY_CONSUMER_INTERFACE

class IPluginPropertyConsumer
{
public:
	virtual void invalidateProperties(void) = 0;
};

#endif