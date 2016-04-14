#ifndef MAIN_HPP
#define MAIN_HPP
#define NUM_OF_SEATS 5

#include "inputs.hpp"
#include "seat.hpp"
#include <iostream>
#include <deque>
using namespace std;

Inputs inputs;          // Starts up the input reader
deque<int> seatOrder;   // Stores the order in which current seats are pressed
Seat seatlist[] = {     // Stores the actual seats themselves
    {seatOrder, 0},
    {seatOrder, 1},
    {seatOrder, 2},
    {seatOrder, 3},
    {seatOrder, 4}
};

#endif
