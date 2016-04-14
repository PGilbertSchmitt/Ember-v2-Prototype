#include "buttons.hpp"

Buttons::Buttons()
{
    currentStates = new buttonState[5];
}

Buttons::~Buttons()
{
    delete[] currentStates;
}

void Buttons::pollStates()
{
    //Do Something
}
