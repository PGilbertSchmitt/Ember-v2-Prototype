#include "seat.hpp"

Seat::Seat(std::deque<int> &_seatOrder, const int _index, std::string name)
    : seatOrder(_seatOrder)
    , index(_index)
{
    inputs = NULL;
    name = "histories/" + name;
    history.load(name);
}

void Seat::update()
{
    Inputs::buttonState state;
    state = inputs->getState(index);

    switch(state){
        case Inputs::Pressed:
            timeOfPress = timer::now();
            break;
        case Inputs::Released:
            auto timeOfRelease = timer::now();
            auto diff = timeOfRelease - timeOfPress;
            auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count();
            std::cout << "Seat: " << index << " pressed for: " << nanoseconds << "ns" << std::endl;
            std::cout << "State: " << state << std::endl;
            break;
    };
}

int Seat::getIndex(){
    return index;
}
