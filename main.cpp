#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/FL_Button.H>
#include <FL/Fl_Slider.H>
#include <RtAudio.h>

#include "synth.cpp"

synth *s = new synth();

int audio( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames, double streamTime, RtAudioStreamStatus status, void *userData ){
    unsigned int i, j;
    double *buffer = (double *) outputBuffer;
    if ( status ){
        std::cout << "Stream underflow detected!" << std::endl;
    }
    // Write interleaved audio data.
    for ( i=0; i<nBufferFrames; i++ ) {
        *buffer++ = s->getNextValue();
    }
    return 0;
}

int main(int argc, char **argv) {
    RtAudio dac;
    if ( dac.getDeviceCount() < 1 ) {
        std::cout << "\nNo audio devices found!\n";
        exit( 0 );
    }
    RtAudio::StreamParameters parameters;
    parameters.deviceId = dac.getDefaultOutputDevice();
    parameters.nChannels = 1;
    parameters.firstChannel = 0;
    unsigned int sampleRate = 44100;
    unsigned int bufferFrames = 256; // 256 sample frames
    double data[2];
    try {
        dac.openStream( &parameters, NULL, RTAUDIO_FLOAT64,
                        sampleRate, &bufferFrames, &audio, (void *)&data );
        dac.startStream();
    }
    catch ( RtAudioError& e ) {
        e.printMessage();
        exit( 0 );
    }

    Fl_Window *window = new Fl_Window(340,180);
    Fl_Box *box = new Fl_Box(10,10,130,20,"Symon N. Theosizer");
    Fl_Slider *volume = new Fl_Slider(10, 40, 15, 100, "V");
    volume->callback(synth::setVolume_static, s);
    Fl_Slider *cutoff = new Fl_Slider(30, 40, 15, 100, "C");
    cutoff->callback(synth::setCutoff_static, s);
    Fl_Slider *resonance = new Fl_Slider(50, 40, 15, 100, "R");
    resonance->callback(synth::setResonance_static, s);
    Fl_Slider *attack = new Fl_Slider(70, 40, 15, 100, "A");
    attack->callback(synth::setAttack_static, s);
    Fl_Slider *decay = new Fl_Slider(90, 40, 15, 100, "D");
    decay->callback(synth::setDecay_static, s);
    Fl_Slider *sustain = new Fl_Slider(110, 40, 15, 100, "S");
    sustain->callback(synth::setSustain_static, s);
    Fl_Slider *release = new Fl_Slider(130, 40, 15, 100, "R");
    release->callback(synth::setRelease_static, s);
    box->box(FL_UP_BOX);
    box->labelsize(12);
    window->end();
    window->show(argc, argv);
    return Fl::run();
}