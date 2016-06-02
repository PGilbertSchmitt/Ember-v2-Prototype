#include "seat.hpp"

Seat::Seat(std::deque<int> &_seatOrder, const int _index, std::string name)
    : seatOrder(_seatOrder)
    , index(_index)
{
    inputs = NULL;
    name = "histories/" + name;
    history.load(name);
    soundPlayer.open(history.getList(), 1.0f);
}

void Seat::update()
{
    Inputs::buttonState state;
    state = inputs->getState(index);

    if (state == Inputs::Pressed){
        timeOfPress = timer::now();

        // Here, we begin the sound player for this seat
        soundPlayer.resetLoc();
        soundPlayer.play();
    } else if (state == Inputs::Released){
        auto timeOfRelease = timer::now();
        auto diff = timeOfRelease - timeOfPress;
        auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count();
        auto halfSeconds = nanoseconds / HALFBIL; // Divide by half a billion

        // Here, we record the note being played and stop the sound player for this seat
        char toAdd = timeToNote(halfSeconds);
        std::cout << "Time: " << halfSeconds << " links to char: " << toAdd << std::endl;
        history.addNote(toAdd);

        // Proof of getting nanoseconds since press
        /*std::cout << "Seat: " << index << " pressed for: " << halfSeconds << " 1/2 seconds" << std::endl;
        std::cout << "State: " << state << std::endl; */
        soundPlayer.stop();
    }
}

void Seat::save()
{
    history.saveNotes();
}

int Seat::getIndex()
{
    return index;
}

// Definitions for time scale-to-note
#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
#define G 6
#define H 7
char Seat::timeToNote(long int time)
{
    switch (time) {
        case A:
            return 'A';
            break;
        case B:
            return 'B';
            break;
        case C:
            return 'C';
            break;
        case D:
            return 'D';
            break;
        case E:
            return 'E';
            break;
        case F:
            return 'F';
            break;
        case G:
            return 'G';
            break;
        case H:
            return 'H';
            break;
        default:
            return 'I';
            break;
    };
}
