/*
  ==============================================================================

    This file was auto-generated by the Jucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef __PLUGINEDITOR_H_A2922F6E__
#define __PLUGINEDITOR_H_A2922F6E__

#include "../JuceLibraryCode/JuceHeader.h"
#include "../JuceLibraryCode/JucePluginCharacteristics.h"
#include "PluginProcessor.h"
#include "InnoCompressorForm.h"

//==============================================================================
/**
*/
class StranglerAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    StranglerAudioProcessorEditor (StranglerAudioProcessor* ownerFilter);
    ~StranglerAudioProcessorEditor();
	StranglerAudioProcessor* getProcessor(void);

    //==============================================================================
    // This is just a standard Juce paint method...
    void paint (Graphics& g);
private:
	StranglerAudioProcessor* m_processor;
	InnoCompressorForm* m_formComp;
};


#endif  // __PLUGINEDITOR_H_A2922F6E__