#ifndef SEAT_HPP
#define SEAT_HPP

#include <iostream>
#include <deque>
#include <string>
#include <chrono> //for time keeping
#include "noteList.hpp"
#include "inputs.hpp"

using ns = std::chrono::time_point<std::chrono::steady_clock>;
using timer = std::chrono::steady_clock;

class Seat {
public:
    Seat(std::deque<int>&, const int, std::string);

    int getIndex();
    const Inputs *inputs;

    void update();
private:
    std::deque<int> & seatOrder;
    const int index;
    noteList history;
    ns timeOfPress;
};

#endif
