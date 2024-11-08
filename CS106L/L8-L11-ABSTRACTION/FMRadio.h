#ifndef FMRADIO_H
#define FMRADIO_H


class FMRadio {
public:
    FMRadio();
    FMRadio(double freq, int vol);
    double getFrequence();
    void setFrequence(double freq);
    int getVolume();
    void setVolume(int vol);
    double setPreset(int index, double freq);
    bool getPreset(int index);

private:
    void checkFrequence(double freq);
    void checVolume(int vol);
    void checkPreset(int index);
    void init(double freq, int vol);
    double frequence;
    int volume;
    double preserts[6];
};


#endif // FMRADIO_H
