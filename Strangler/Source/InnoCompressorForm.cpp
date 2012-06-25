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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "InnoCompressorForm.h"
#include "PluginProperty.h"
#include "PluginProcessor.h"

//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
InnoCompressorForm::InnoCompressorForm (StranglerAudioProcessor* processor)
    : groupComponent3 (0),
      groupComponent (0),
      groupComponent2 (0),
      m_attackSpeed (0),
      label (0),
      m_releaseSpeed (0),
      label2 (0),
      m_thresold (0),
      m_limit (0),
      label3 (0),
      label4 (0),
      m_hardLimit (0),
      m_autoGain (0),
	  m_processor(processor)
{
    addAndMakeVisible (groupComponent3 = new GroupComponent (L"new group",
                                                             String::empty));

    addAndMakeVisible (groupComponent = new GroupComponent (L"new group",
                                                            String::empty));

    addAndMakeVisible (groupComponent2 = new GroupComponent (L"new group",
                                                             String::empty));

    addAndMakeVisible (m_attackSpeed = new Slider (L"new slider"));
    m_attackSpeed->setRange (0.1, 1000, 0.1);
    m_attackSpeed->setSliderStyle (Slider::LinearVertical);
    m_attackSpeed->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    m_attackSpeed->addListener (this);

    addAndMakeVisible (label = new Label (L"new label",
                                          L"Attack (ms)"));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (m_releaseSpeed = new Slider (L"new slider"));
    m_releaseSpeed->setRange (0.1, 1000, 0.1);
    m_releaseSpeed->setSliderStyle (Slider::LinearVertical);
    m_releaseSpeed->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    m_releaseSpeed->addListener (this);

    addAndMakeVisible (label2 = new Label (L"new label",
                                           L"Release (ms)"));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (m_thresold = new Slider (L"new slider"));
    m_thresold->setRange (-75, 0, 0.1);
    m_thresold->setSliderStyle (Slider::LinearVertical);
    m_thresold->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    m_thresold->addListener (this);

    addAndMakeVisible (m_limit = new Slider (L"new slider"));
    m_limit->setRange (-75, 0, 0.1);
    m_limit->setSliderStyle (Slider::LinearVertical);
    m_limit->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    m_limit->addListener (this);

    addAndMakeVisible (label3 = new Label (L"new label",
                                           L"Thresold (dB)"));
    label3->setFont (Font (15.0000f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label4 = new Label (L"new label",
                                           L"Limit (dB)"));
    label4->setFont (Font (15.0000f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (m_hardLimit = new ToggleButton (L"new toggle button"));
    m_hardLimit->setButtonText (L"Hard Limit");
    m_hardLimit->addListener (this);

    addAndMakeVisible (m_autoGain = new ToggleButton (L"new toggle button"));
    m_autoGain->setButtonText (L"Auto Gain");
    m_autoGain->addListener (this);


    //[UserPreSize]
	PluginProperty* m_asc = getPlugin()->getProp(getPlugin()->attackSpeed);
	m_attackSpeed->setRange(m_asc->getMinVal(), m_asc->getMaxVal(), 0.1);

	PluginProperty* m_rsc = getPlugin()->getProp(getPlugin()->releaseSpeed);
	m_releaseSpeed->setRange(m_rsc->getMinVal(), m_rsc->getMaxVal(), 0.1);

	m_attackSpeed->setValue(getPlugin()->getProp(getPlugin()->attackSpeed)->getScaledValue());
	m_releaseSpeed->setValue(getPlugin()->getProp(getPlugin()->releaseSpeed)->getScaledValue());

	m_thresold->setValue(getPlugin()->getProp(getPlugin()->thresold)->getScaledValue());
	m_limit->setValue(getPlugin()->getProp(getPlugin()->limit)->getScaledValue());

	m_hardLimit->setToggleState(getPlugin()->getProp(getPlugin()->hardLimit)->getScaledValue() > 0, true);
	m_autoGain->setToggleState(getPlugin()->getProp(getPlugin()->autoGain)->getScaledValue() > 0, true);
    //[/UserPreSize]

    setSize (500, 320);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

InnoCompressorForm::~InnoCompressorForm()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (groupComponent3);
    deleteAndZero (groupComponent);
    deleteAndZero (groupComponent2);
    deleteAndZero (m_attackSpeed);
    deleteAndZero (label);
    deleteAndZero (m_releaseSpeed);
    deleteAndZero (label2);
    deleteAndZero (m_thresold);
    deleteAndZero (m_limit);
    deleteAndZero (label3);
    deleteAndZero (label4);
    deleteAndZero (m_hardLimit);
    deleteAndZero (m_autoGain);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void InnoCompressorForm::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void InnoCompressorForm::resized()
{
    groupComponent3->setBounds (16, 248, 224, 72);
    groupComponent->setBounds (16, 0, 224, 256);
    groupComponent2->setBounds (256, 0, 224, 256);
    m_attackSpeed->setBounds (32, 16, 80, 208);
    label->setBounds (32, 224, 95, 24);
    m_releaseSpeed->setBounds (144, 16, 80, 208);
    label2->setBounds (144, 224, 96, 24);
    m_thresold->setBounds (272, 16, 80, 208);
    m_limit->setBounds (384, 16, 80, 208);
    label3->setBounds (272, 224, 96, 24);
    label4->setBounds (392, 224, 79, 24);
    m_hardLimit->setBounds (72, 264, 150, 24);
    m_autoGain->setBounds (72, 288, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void InnoCompressorForm::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_attackSpeed)
    {
        //[UserSliderCode_m_attackSpeed] -- add your slider handling code here..
		getPlugin()->getProp(getPlugin()->attackSpeed)->setScaledValue(m_attackSpeed->getValue());
        //[/UserSliderCode_m_attackSpeed]
    }
    else if (sliderThatWasMoved == m_releaseSpeed)
    {
        //[UserSliderCode_m_releaseSpeed] -- add your slider handling code here..
		getPlugin()->getProp(getPlugin()->releaseSpeed)->setScaledValue(m_releaseSpeed->getValue());
        //[/UserSliderCode_m_releaseSpeed]
    }
    else if (sliderThatWasMoved == m_thresold)
    {
        //[UserSliderCode_m_thresold] -- add your slider handling code here..
		getPlugin()->getProp(getPlugin()->thresold)->setScaledValue(m_thresold->getValue());
        //[/UserSliderCode_m_thresold]
    }
    else if (sliderThatWasMoved == m_limit)
    {
        //[UserSliderCode_m_limit] -- add your slider handling code here..
		getPlugin()->getProp(getPlugin()->limit)->setScaledValue(m_limit->getValue());
        //[/UserSliderCode_m_limit]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void InnoCompressorForm::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_hardLimit)
    {
        //[UserButtonCode_m_hardLimit] -- add your button handler code here..
		getPlugin()->getProp(getPlugin()->hardLimit)->setScaledValue(m_hardLimit->getToggleState() ? 1.0 : -1.0);
        //[/UserButtonCode_m_hardLimit]
    }
    else if (buttonThatWasClicked == m_autoGain)
    {
        //[UserButtonCode_m_autoGain] -- add your button handler code here..
		getPlugin()->getProp(getPlugin()->autoGain)->setScaledValue(m_autoGain->getToggleState() ? 1.0 : -1.0);
        //[/UserButtonCode_m_autoGain]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="InnoCompressorForm" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="500" initialHeight="320">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GROUPCOMPONENT name="new group" id="710cbea17921494" memberName="groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="16 248 224 72" title=""/>
  <GROUPCOMPONENT name="new group" id="d6df0286a3287cf" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="16 0 224 256" title=""/>
  <GROUPCOMPONENT name="new group" id="f1cbe83d79533f15" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="256 0 224 256" title=""/>
  <SLIDER name="new slider" id="47321be4c1f36ca7" memberName="m_attackSpeed"
          virtualName="" explicitFocusOrder="0" pos="32 16 80 208" min="0.1"
          max="1000" int="0.1" style="LinearVertical" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="eaf3144581de4bbf" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="32 224 95 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack (ms)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="51b9b09318a8d5e3" memberName="m_releaseSpeed"
          virtualName="" explicitFocusOrder="0" pos="144 16 80 208" min="0.1"
          max="1000" int="0.1" style="LinearVertical" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="89abb381fa6e3545" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="144 224 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Release (ms)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="54015e77cbb46ffc" memberName="m_thresold"
          virtualName="" explicitFocusOrder="0" pos="272 16 80 208" min="-75"
          max="0" int="0.1" style="LinearVertical" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="42299613d40f2d14" memberName="m_limit"
          virtualName="" explicitFocusOrder="0" pos="384 16 80 208" min="-75"
          max="0" int="0.1" style="LinearVertical" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="663e81f4fb03d3f4" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="272 224 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Thresold (dB)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="fc27e061639cd5e0" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="392 224 79 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Limit (dB)" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="448acf3c63075dfc" memberName="m_hardLimit"
                virtualName="" explicitFocusOrder="0" pos="72 264 150 24" buttonText="Hard Limit"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="c64f01538890b837" memberName="m_autoGain"
                virtualName="" explicitFocusOrder="0" pos="72 288 150 24" buttonText="Auto Gain"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
