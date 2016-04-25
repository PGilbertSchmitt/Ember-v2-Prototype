#include "inputs.hpp"

Inputs::Inputs()
{
    // Initialize button states to Up regardless of actual state
    for (int i = 0; i < NUM_OF_INPUTS; i++){
        currentStates[i] = Up;
    }

    // Map the keyboard buttons to their SFML Keyboard enum counterparts
    buttonMap[A] = sf::Keyboard::A;
    buttonMap[S] = sf::Keyboard::S;
    buttonMap[D] = sf::Keyboard::D;
    buttonMap[F] = sf::Keyboard::F;
    buttonMap[Q] = sf::Keyboard::Q;
    buttonMap[Space] = sf::Keyboard::Space;
}

void Inputs::pollStates()
{
    for (int i = 0; i < NUM_OF_INPUTS; i++){
        sf::Keyboard::Key key = buttonMap.at(static_cast<buttonIndex>(i));
        bool keyDown = sf::Keyboard::isKeyPressed(key);
        setState(i, keyDown);
    }
}

Inputs::buttonState Inputs::getState(int index) const
{
    if (index >= NUM_OF_INPUTS || index < 0){
        std::cout << "Out of bounds" << std::endl;
        return Up;
    } else {
        return currentStates[index];
    }
}

void Inputs::setState(int index, bool keyState)
{
    /* Regardless of the keyState, if the state of an input is transitional
     * (ie Pressed or Released), then it must continue the transition
     *
     * Transitions per step (represented as ->):
     * Up (if pressed) -> Pressed -> Down
     * Down (if not pressed) -> Released -> Up
     */
    if (currentStates[index] == Pressed){
        currentStates[index] = Down;
    } else
    if (currentStates[index] == Released){
        currentStates[index] = Up;
    } else {
        // Now to set the transition if it isn't currently so
        if (currentStates[index] == Up && keyState){
            currentStates[index] = Pressed;
        } else
        if (currentStates[index] == Down && !keyState){
            currentStates[index] = Released;
        }
    }
}
