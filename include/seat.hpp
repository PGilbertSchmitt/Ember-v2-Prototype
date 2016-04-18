#ifndef SEAT_HPP
#define SEAT_HPP

#include <iostream>
#include <deque>
#include "inputs.hpp"

class Seat {
public:
    Seat(std::deque<int>&, const int);

    int getIndex();
    const Inputs *inputs;

    void update();
private:
    std::deque<int> & seatOrder;
    const int index;
};

#endif
