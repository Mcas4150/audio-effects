/*
  This code accompanies the textbook:
 
  Digital Audio Effects: Theory, Implementation and Application
  Joshua D. Reiss and Andrew P. McPherson
 
  ---
 
  Tremolo: amplitude modulation using a low-frequency oscillator
  See textbook Chapter 5: Amplitude Modulation
 
  Code by Andrew McPherson, Brecht De Man and Joshua Reiss
 
  ---

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
 
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __PLUGINEDITOR_H_6E48F605__
#define __PLUGINEDITOR_H_6E48F605__

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================

class TremoloAudioProcessorEditor  : public AudioProcessorEditor,
                                   public Slider::Listener,
                                   public ComboBox::Listener,
                                   public Timer
{
public:
    TremoloAudioProcessorEditor (TremoloAudioProcessor* ownerFilter);
    ~TremoloAudioProcessorEditor();

    //==============================================================================
    // This is just a standard Juce paint method...
    void timerCallback();
    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider*);
    void comboBoxChanged (ComboBox *);
    
private:
    Label depthLabel_, frequencyLabel_, waveformLabel_;
    Slider depthSlider_, frequencySlider_;
    ComboBox waveformComboBox_;
    
    ScopedPointer<ResizableCornerComponent> resizer_;
    ComponentBoundsConstrainer resizeLimits_;
    
    TremoloAudioProcessor* getProcessor() const
    {
        return static_cast <TremoloAudioProcessor*> (getAudioProcessor());
    }
};


#endif  // __PLUGINEDITOR_H_6E48F605__
