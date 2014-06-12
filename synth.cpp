#include "synth.h"

double synth::getNextValue(){
    double outval = this->osc.sawn(this->frequency)*this->volume;\
    outval = this->env.ar(outval, 0.1, 0.9999, 1, this->envTrigger);
    outval = this->filter.lores(outval,this->cutoff,this->resonance);
    this->envTrigger = 0;
    return outval;
}

void synth::noteOn(double freq){
    this->setFrequency(freq);
    this->envTrigger = 1;
}

void synth::noteOff(){
    printf("note off");
}