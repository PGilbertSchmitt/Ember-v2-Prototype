#ifndef SEAT_HPP
#define SEAT_HPP

#include <iostream>
#include <deque>

class Seat {
public:
    Seat(std::deque<int> &_seatOrder, const int _index)
        : seatOrder(_seatOrder)
        , index(_index)
        {}

    int getIndex();

private:
    std::deque<int> & seatOrder;
    const int index;
};

#endif
