#include "seat.hpp"

Seat::Seat(std::deque<int> &_seatOrder, const int _index)
    : seatOrder(_seatOrder)
    , index(_index)
{
    inputs = NULL;
}

void Seat::update()
{
    Inputs::buttonState state;
    if (inputs == NULL){
        std::cout << "inputs ptr doesn't point to input object" << std::endl;
        return;
    } else {
        state = inputs->getState(index);
        // Do something with state
    }
}

int Seat::getIndex(){
    return index;
}
