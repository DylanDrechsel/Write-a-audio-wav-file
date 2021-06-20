#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

const int sampleRate = 44100;

class SineOscillator {
        float frequency, amplitude, angle = 0.0f, offset = 0.0;
    public:
        SineOscillator(float freq, float amp) : frequency(freq), amplitude(amp) {
            offset = 2 * M_PI * frequency / sampleRate;
        }
        float process() {
            // Asin(2pi(f/sr))
            auto sample = amplitude * sin(angle);
            angle += offset;
            return sample;
        };
};

int main() {
    int duration = 2;
    ofstream audioFile;
    audioFile.open("waveform");
    SineOscillator sineOscillator(440, 0.5);

    for(int i = 0; i < sampleRate * duration; i++) {
        audioFile << sineOscillator.process() << endl;
    };

    audioFile.close();
    return 0;
}