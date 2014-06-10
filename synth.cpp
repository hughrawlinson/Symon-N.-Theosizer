#include "synth.h"

double synth::getNextValue(){
    double outval = this->osc.sawn(this->frequency)*this->volume;
    return this->filter.lores(outval,this->cutoff,this->resonance);
}