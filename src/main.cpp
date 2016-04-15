#include "main.hpp"

int main() {
    // Make sure all seats point to the same inputs object
    for (int i = 0; i < NUM_OF_SEATS; i++){
        seatlist[i].inputs = &inputs;
    }


    while(true){
         // For every iteration of the loop, the currentStates array holds the
         // values of each input. Regardless of the implementation of the input,
         // the update function will constantly check the currentStates for
         // instructions on what to do next
        inputs.pollStates();
    }
    return 0;
}
