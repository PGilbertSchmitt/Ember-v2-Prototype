#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <map>

#define INPUTS 5

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

    buttonState currentStates[INPUTS];
};
