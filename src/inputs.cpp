#include "inputs.hpp"

Inputs::Inputs()
{
    // Initialize button states to Up regardless of actual state
    for (int i = 0; i < INPUTS; i++){
        currentStates[i] = Up;
    }

    // Map the keyboard buttons to their SFML Keyboard enum counterparts
    buttonMap[A] = sf::Keyboard::A;
    buttonMap[S] = sf::Keyboard::S;
    buttonMap[D] = sf::Keyboard::D;
    buttonMap[F] = sf::Keyboard::F;
    buttonMap[Space] = sf::Keyboard::Space;
}

void Inputs::pollStates()
{
    //Do Something
}
