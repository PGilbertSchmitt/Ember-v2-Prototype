#include "customStream.hpp"

/* PUBLIC FUNCTIONS */
void CustomStream::open(const std::deque<char>& list, float _seconds)
{
    playlist = list;
    seconds = _seconds;
    channelCount = 1;
    sampleRate = 44100;
    listLoc = 0;
    phaseAdd = 0;

    initialize(channelCount, sampleRate);
}

void CustomStream::resetLoc()
{
    listLoc = 0;
}

/* PRIVATE FUNCTIONS */
bool CustomStream::onGetData(Chunk& data)
{
    if (listLoc < playlist.size()){
        sampleGen = newSample();
        data.samples = sampleGen.getSamples();
        data.sampleCount = sampleGen.getSampleCount();
        listLoc++;

        return true;
    } else {
        std::cout << "No more to play." << std::endl;
        listLoc = 0;
        return false;
    }
}

// Unnecessary
void CustomStream::onSeek(sf::Time timeOffset) {}

// Given a note to play from 1 - ..., returns a
sf::SoundBuffer CustomStream::newSample()
{
    double const TAU = 8 * atan(1);
	short map = 32760;
    sf::SoundBuffer buffer;
    int currentNote = playlist.at(listLoc);
    float freq = numToFreq(currentNote);
    std::size_t buf_size = seconds * sampleRate;
    std::vector<sf::Int16> v_samples (buf_size);

    if (listLoc < (playlist.size() - 1)){ // there is another note to play
        std::size_t buf_note = buf_size * TIME_RATIO;
        std::size_t buf_trans = buf_size - buf_note;

        // Fill v_samples with note
        for (unsigned int i = 0; i < buf_size; i++){
            v_samples.at(i) = map * sin(((TAU * freq) / float(sampleRate)) * i + phaseAdd);
        }

        phaseAdd += freq * buf_note / float(sampleRate);

        int secNote = playlist.at(listLoc + 1);
        float secFreq = numToFreq(secNote);
        float interval = seconds - (seconds * TIME_RATIO);
        float B = log(secFreq/freq) * interval;
        float A = TAU * freq / B;

        // Fill v_samples with transition
        for (unsigned int i = 0; i < buf_trans; i++){
            float delta = i / float(buf_trans);
            float t = interval * delta;
            float g_t = A * exp(t * B);
            v_samples.at(i + buf_note) = map * sin(g_t + phaseAdd);
        }

        phaseAdd += secFreq * buf_trans / float(sampleRate);

    } else { // This is the last note
        // Fill v_samples with note
        for (unsigned int i = 0; i < buf_size; i++){
            v_samples.at(i) = map * sin(((TAU * freq) / float(sampleRate)) * i);
        }
    }

    buffer.loadFromSamples(&v_samples[0], buf_size, channelCount, sampleRate);

    return buffer;
}

float CustomStream::numToFreq(char note)
{
    float freq;
    switch(note){
        case '0':   // C4
            freq = 261.63f;
            break;
        case '1':   // E4
            freq = 329.63f;
            break;
        case '2':   // G4
            freq = 392.f;
            break;
        case '3':   // C5
            freq = 523.25f;
            break;
        case '4':   // E5
            freq = 659.25f;
            break;
        case '5':   // G5
            freq = 783.99;
            break;
        default:    // default to C4
            freq = 261.63f;
            break;
    };
    return freq;
}
