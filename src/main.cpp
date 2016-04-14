#include "inputs.hpp"
#include <iostream>
using namespace std;

int main() {
    Inputs inputs;
    while(true){
         // For every iteration of the loop, the currentStates array holds the
         // values of each input. Regardless of the implementation of the input,
         // the update function will constantly check the currentStates for
         // instructions on what to do next
        inputs.pollStates();
    }
    return 0;
}
