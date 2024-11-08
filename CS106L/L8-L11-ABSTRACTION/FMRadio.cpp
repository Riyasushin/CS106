
/// why "", but not <>       <> is for stl,which should be setted on the prefence
#include "FMRadio.h"
#include <assert.h>
class FMRadio {

    // FMRadio myRadio yes!!!
    // FMRadio myRadio() oh,no!!!
    void FRMRadio::init(double freq, int vol) {
        for (size_t i = 0; i < 6; ++i) {
            presets[i] = 0.0;
        }
        frequence = freq;
        volume = vol;
    }
    FMRadio::FMRadio() {
        init(87.5, 5);
    }
    FMRadio::FMRadio(double freq, int vol) {
        checkFrequence(freq);
        checkVolume(vol);

        init(freq, vol);
    }
    void FMRadio::checkFrequence(double freq) {
        /// if false, stop the exe
        assert(freq >= 87.5 && freq <= 108.8);
    }
    void FMRadio::checkVolume(int vol) {
        /// lazy man should rest
    }
    void FMRadio::setFrequence(int vol) {
        volume = vol;
    }
};
