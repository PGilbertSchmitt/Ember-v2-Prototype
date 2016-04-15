#include "seat.hpp"

Seat::Seat(std::deque<int> &_seatOrder, const int _index)
    : seatOrder(_seatOrder)
    , index(_index)
{
    inputs = NULL;
}

int Seat::getIndex(){
    return index;
}
