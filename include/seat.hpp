#ifndef SEAT_HPP
#define SEAT_HPP

#define HALFBIL 500000000

#include <iostream>
#include <deque>
#include <string>
#include <chrono> //for time keeping
#include "noteList.hpp"
#include "inputs.hpp"
#include "customStream.hpp"

using ns = std::chrono::time_point<std::chrono::steady_clock>;
using timer = std::chrono::steady_clock;

class Seat {
public:
    Seat(std::deque<int>&, const int, std::string);

    int getIndex();
    const Inputs *inputs;

    void update();
    void save();
private:
    std::deque<int> & seatOrder;    // To determine play speed, or other variables
    const unsigned int index;
    NoteList history;               // For notes and file operations
    ns timeOfPress;                 // Measuring length of time of a press
    char timeToNote(long int);      // Converts time into a note
    CustomStream soundPlayer;
};

#endif
