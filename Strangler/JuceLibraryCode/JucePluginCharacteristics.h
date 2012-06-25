/*

    IMPORTANT! This file is auto-generated each time you save your
    project - if you alter its contents, your changes may be overwritten!

    This header file contains configuration options for the plug-in. If you need to change any of
    these, it'd be wise to do so using the Jucer, rather than editing this file directly...

*/

#ifndef __PLUGINCHARACTERISTICS_OMKKQE__
#define __PLUGINCHARACTERISTICS_OMKKQE__

#define JucePlugin_Build_VST    1  // (If you change this value, you'll also need to re-export the projects using the Jucer)
#define JucePlugin_Build_AU     1  // (If you change this value, you'll also need to re-export the projects using the Jucer)
#define JucePlugin_Build_RTAS   0  // (If you change this value, you'll also need to re-export the projects using the Jucer)

#define JucePlugin_Name                 "Strangler"
#define JucePlugin_Desc                 "Classic Dynamic Compressor"
#define JucePlugin_Manufacturer         "Tomatl Inc."
#define JucePlugin_ManufacturerCode     'Manu'
#define JucePlugin_PluginCode           'Plug'
#define JucePlugin_MaxNumInputChannels  2
#define JucePlugin_MaxNumOutputChannels 2
#define JucePlugin_PreferredChannelConfigurations   {1, 1}, {2, 2}
#define JucePlugin_IsSynth              0
#define JucePlugin_WantsMidiInput       0
#define JucePlugin_ProducesMidiOutput   0
#define JucePlugin_SilenceInProducesSilenceOut  0
#define JucePlugin_TailLengthSeconds    0
#define JucePlugin_EditorRequiresKeyboardFocus  0
#define JucePlugin_VersionCode          0x10000
#define JucePlugin_VersionString        "0.1.0"
#define JucePlugin_VSTUniqueID          JucePlugin_PluginCode
#define JucePlugin_VSTCategory          kPlugCategEffect
#define JucePlugin_AUMainType           kAudioUnitType_Effect
#define JucePlugin_AUSubType            JucePlugin_PluginCode
#define JucePlugin_AUExportPrefix       TomatlStranglerAU
#define JucePlugin_AUExportPrefixQuoted "TomatlStranglerAU"
#define JucePlugin_AUManufacturerCode   JucePlugin_ManufacturerCode
#define JucePlugin_CFBundleIdentifier   com.Tomatl.Strangler
#define JucePlugin_AUCocoaViewClassName TomatlStranglerAU_V1
#define JucePlugin_RTASCategory         ePlugInCategory_None
#define JucePlugin_RTASManufacturerCode JucePlugin_ManufacturerCode
#define JucePlugin_RTASProductId        JucePlugin_PluginCode
#define JUCE_USE_VSTSDK_2_4             1

#endif   // __PLUGINCHARACTERISTICS_OMKKQE__
