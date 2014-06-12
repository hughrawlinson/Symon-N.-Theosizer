#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/FL_Button.H>
#include <FL/Fl_Slider.H>

#include "./maximilian.cpp"

class synth{
    float volume;
    float cutoff;
    float resonance;
    float attack;
    float decay;
    float sustain;
    float release;
    float frequency;
    int envTrigger;
    maxiOsc osc;
    maxiFilter filter;
    maxiEnv env;

public:
    synth(){
        this->volume = 0.5f;
        this->cutoff = 0.0f;
        this->resonance = 0.0f;
        this->attack = 1000.0f;
        this->decay = 500.0f;
        this->sustain = 0.5f;
        this->release = 1000.0f;
        this->frequency = 440.0;
    }

    ~synth(){
        
    }
    static void setVolume_static(Fl_Widget *w, void *f) {
        Fl_Valuator *wid = (Fl_Valuator *)w;
        printf("Value Changed To: %f\n", wid->value());
        ((synth *)f)->setVolume(wid->value());
    }
    static void setCutoff_static(Fl_Widget *w, void *f) {
        Fl_Valuator *wid = (Fl_Valuator *)w;
        printf("Value Changed To: %f\n", wid->value());
        ((synth *)f)->setCutoff(wid->value());
    }
    static void setResonance_static(Fl_Widget *w, void *f) {
        Fl_Valuator *wid = (Fl_Valuator *)w;
        printf("Value Changed To: %f\n", wid->value());
        ((synth *)f)->setResonance(wid->value());
    }
    static void setAttack_static(Fl_Widget *w, void *f) {
        Fl_Valuator *wid = (Fl_Valuator *)w;
        printf("Value Changed To: %f\n", wid->value());
        ((synth *)f)->setAttack(wid->value());
    }
    static void setSustain_static(Fl_Widget *w, void *f) {
        Fl_Valuator *wid = (Fl_Valuator *)w;
        printf("Value Changed To: %f\n", wid->value());
        ((synth *)f)->setVolume(wid->value());
    }
    static void setDecay_static(Fl_Widget *w, void *f) {
        Fl_Valuator *wid = (Fl_Valuator *)w;
        printf("Value Changed To: %f\n", wid->value());
        ((synth *)f)->setVolume(wid->value());
    }
    static void setRelease_static(Fl_Widget *w, void *f) {
        Fl_Valuator *wid = (Fl_Valuator *)w;
        printf("Value Changed To: %f\n", wid->value());
        ((synth *)f)->setRelease(wid->value());
    }
    void setVolume(double volume) { this->volume = (1-volume);}
    void setCutoff(double cutoff) { this->cutoff = (1-cutoff)*5000; }
    void setResonance(double resonance) { this->resonance = (1-resonance)*30; }
    void setAttack(double attack) { this->attack = attack; }
    void setDecay(double decay) { this->decay = decay; }
    void setSustain(double sustain) { this->sustain = sustain; }
    void setRelease(double release) { this->release = release; }
    void setFrequency(double frequency) { this->frequency = frequency; }

    void noteOn(double freq);
    void noteOff();

    double getNextValue();
};