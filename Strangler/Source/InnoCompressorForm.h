/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  21 Jun 2012 6:40:20pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_INNOCOMPRESSORFORM_INNOCOMPRESSORFORM_6D47E715__
#define __JUCER_HEADER_INNOCOMPRESSORFORM_INNOCOMPRESSORFORM_6D47E715__

//[Headers]     -- You can add your own extra header files here --
//#include "juce.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include "../JuceLibraryCode/JucePluginCharacteristics.h"
//#include "PluginEditor.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class InnoCompressorForm  : public Component,
                            public SliderListener,
                            public ButtonListener
{
public:
    //==============================================================================
    InnoCompressorForm(StranglerAudioProcessor* processor);
    ~InnoCompressorForm();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	//void consumeParent(Vst_templateAudioProcessorEditor* parent);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	StranglerAudioProcessor* m_processor;
	StranglerAudioProcessor* getPlugin(void)
	{
		return m_processor;
	}
	//Vst_templateAudioProcessorEditor* parent;
    //[/UserVariables]

    //==============================================================================
    GroupComponent* groupComponent3;
    GroupComponent* groupComponent;
    GroupComponent* groupComponent2;
    Slider* m_attackSpeed;
    Label* label;
    Slider* m_releaseSpeed;
    Label* label2;
    Slider* m_thresold;
    Slider* m_limit;
    Label* label3;
    Label* label4;
    ToggleButton* m_hardLimit;
    ToggleButton* m_autoGain;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    InnoCompressorForm (const InnoCompressorForm&);
    const InnoCompressorForm& operator= (const InnoCompressorForm&);
};


#endif   // __JUCER_HEADER_INNOCOMPRESSORFORM_INNOCOMPRESSORFORM_6D47E715__
