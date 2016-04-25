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
    {seatOrder, 0, "a.txt"},
    {seatOrder, 1, "b.txt"},
    {seatOrder, 2, "c.txt"},
    {seatOrder, 3, "d.txt"},
    {seatOrder, 4, "e.txt"}
};

#endif
