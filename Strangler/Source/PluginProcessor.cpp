/*
  ==============================================================================

    This file was auto-generated by the Jucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include "IInterpolationProvider.h"
#include "IPluginPropertyConsumer.h"
#include "PluginProcessor.h"
#include "PluginProperty.h"
#include "PluginEditor.h"
#include "LinearInterpolationProvider.h"
#include "StreamProperties.h"
#include "ClassicDynamicCompressor.h"
#include <algorithm>
#include <cstring>

//#include "PropertyList.h"

using std::string;

//==============================================================================
StranglerAudioProcessor::StranglerAudioProcessor() : m_streamProp(StreamProperties()), m_propsInvalidated(true), m_comp(ClassicDynamicCompressor(m_streamProp))
{
	m_propList[this->attackSpeed] = new PluginProperty(string("attack"), string("Attack Speed (ms)"), 0.0, 0.1, 1000, new LinearInterpolationProvider(), *this);
	m_propList[this->releaseSpeed] = new PluginProperty(string("release"), string("Release Speed (ms)"), 0.0, 1.0, 10000, new LinearInterpolationProvider(), *this);
	m_propList[this->thresold] = new PluginProperty(string("thresold"), string("Thresold (dB)"), 0.0, -75.0, 0.0, new LinearInterpolationProvider(), *this);
	m_propList[this->limit] = new PluginProperty(string("limit"), string("Limit (dB)"), 0.0, -75.0, 0.0, new LinearInterpolationProvider(), *this);
	m_propList[this->hardLimit] = new PluginProperty(string("hardLimit"), string("Hard Limit"), 0.0, -1.0, 1.0, new LinearInterpolationProvider(), *this);
	m_propList[this->autoGain] = new PluginProperty(string("autoGain"), string("Auto Gain"), 0.0, -1.0, 1.0, new LinearInterpolationProvider(), *this);
}

StranglerAudioProcessor::~StranglerAudioProcessor()
{
	map<int, PluginProperty*>::iterator i;

	for (i = m_propList.begin(); i != m_propList.end(); ++i)
	{
		delete i->second;
	}

	m_propList.clear();
}

PluginProperty* StranglerAudioProcessor::getProp(int index)
{
	map<int, PluginProperty*>::iterator i = m_propList.find(index);

	if (i != m_propList.end())
	{
		return i->second;
	}
	else
	{
		return 0;
	}
}

void StranglerAudioProcessor::invalidateProperties(void)
{
	m_propsInvalidated = true;
}

//==============================================================================
const String StranglerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int StranglerAudioProcessor::getNumParameters()
{
	return m_propList.size();
}

float StranglerAudioProcessor::getParameter (int index)
{
	map<int, PluginProperty*>::iterator i = m_propList.find(index);

	if (i != m_propList.end())
	{
		return i->second->getValue();
	}
	else
	{
		return 0.0f;
	}
}

void StranglerAudioProcessor::setParameter (int index, float newValue)
{
	map<int, PluginProperty*>::iterator i = m_propList.find(index);

	if (i != m_propList.end())
	{
		i->second->setValue(newValue);
	}
}

const String StranglerAudioProcessor::getParameterName (int index)
{
	map<int, PluginProperty*>::iterator i = m_propList.find(index);

	if (i != m_propList.end())
	{
		return i->second->getIntName().c_str();
	}
	else
	{
		return String::empty;
	}
}

const String StranglerAudioProcessor::getParameterText (int index)
{
	map<int, PluginProperty*>::iterator i = m_propList.find(index);

	if (i != m_propList.end())
	{
		return String(i->second->getValue(), 2);
	}
	else
	{
		return String::empty;
	}
}

const String StranglerAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String StranglerAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool StranglerAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool StranglerAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool StranglerAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool StranglerAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

int StranglerAudioProcessor::getNumPrograms()
{
    return 0;
}

int StranglerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void StranglerAudioProcessor::setCurrentProgram (int index)
{
}

const String StranglerAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void StranglerAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void StranglerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	m_streamProp.setSampleRate(sampleRate);
	m_propsInvalidated = true;
}

void StranglerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void StranglerAudioProcessor::handlePropsInvalidation(void)
{
	if (m_propsInvalidated)
	{
		m_propsInvalidated = false;

		m_comp.setAttackSpeed(m_propList[this->attackSpeed]->getScaledValue());
		m_comp.setReleaseSpeed(m_propList[this->releaseSpeed]->getScaledValue());
		m_comp.setThresoldDb(m_propList[this->thresold]->getScaledValue());
		m_comp.setLimitDb(m_propList[this->limit]->getScaledValue());
		m_comp.setHardLimit(m_propList[this->hardLimit]->getScaledValue() > 0);
		m_comp.setAutoGain(m_propList[this->autoGain]->getScaledValue() > 0);
	}
}

void StranglerAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	handlePropsInvalidation();
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        float* channelData = buffer.getSampleData (channel);

		for (int i = 0; i < buffer.getNumSamples(); ++i)
		{
			channelData[i] = m_comp.processSample(channelData[i]);
		}
        // ..do something to the data...
    }

    // In case we have more outputs than inputs, we'll clear any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    {
        buffer.clear (i, 0, buffer.getNumSamples());
    }
}

//==============================================================================
bool StranglerAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* StranglerAudioProcessor::createEditor()
{
    return new StranglerAudioProcessorEditor(this);
}

//==============================================================================
void StranglerAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void StranglerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new StranglerAudioProcessor();
}
