#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <map>

#define NUM_OF_INPUTS 5

class Inputs {
public:
    Inputs();

    void pollStates();

private:
    enum buttonState
    {
        Up = 0,
        Pressed,
        Down,
        Released
    };

    enum buttonIndex {
        A = 0,
        S,
        D,
        F,
        Space,
        keyCount
    };

    std::map<buttonIndex,sf::Keyboard::Key> buttonMap;

    buttonState currentStates[NUM_OF_INPUTS];
    void setState(int,bool); // Sets values in currentStates at index
};
