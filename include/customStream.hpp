#include <SFML/Audio.hpp>
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>

#define TIME_RATIO .75f

class CustomStream : public sf::SoundStream
{
public:
    void open(const std::deque<char>&, float);

private:
    bool onGetData(Chunk&);
    void onSeek(sf::Time);
    sf::SoundBuffer newSample();
    float numToFreq(char);

    std::deque<char> playlist; // The list of 'notes' to be generated
    unsigned int listLoc;      // The current playing position
    float seconds;          // The length of time in seconds to play
    unsigned int channelCount;
    unsigned int sampleRate;
    float phaseAdd;

    // The generated sound buffer that is to be played
    sf::SoundBuffer sampleGen;
};
