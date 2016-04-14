#include <SFML/Window/Keyboard.hpp>

class Buttons {
public:
    void Buttons();
    void ~Buttons();

    void pollStates();

private:
    enum buttonState
    {
        Up = 0,
        Pressed,
        Down,
        Released
    };

    enum buttons {
        A = 0,
        S,
        D,
        F,
        Space
    };

    buttonState currentStates[5];
};
