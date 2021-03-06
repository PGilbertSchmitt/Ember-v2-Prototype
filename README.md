# Ember-v2-Prototype

## Introduction
Project Ember is the brainchild of SF artist Jason Rasmussen. Most of the code was written by P. Gilbert Schmitt.

## Concept
The physical form of Ember is a circular arrangement of five seats on a wooden platform. When a seat is sat upon, music is played where the notes are based off of the length of time that prior occupants had stayed on the seat. When the current occupant leaves the seat, the length of time that they had stayed is recorded as a new note that will be added to the music the next time someone sits in that seat.

When multiple seats are simultaneously occupied, the seats play back their note histories at different tempos, depending on the order upon which they were sat.

The program will be run on a Raspberry Pi running underneath the platform.

## Artist's Disclaimer
Many of the smaller details and some of the principle implementation is likely to change. As is the case art, even the most specific vision can change with seemingly no reason. This prototype represents the current idea and it's implementation.

## Running the Project
Currently, the project is run from the command line of a Linux environment. The prettiness of the output is done with printed escape codes. The output of pressed keys is stifled by using a script to call `stty -echo`, running main, then calling `stty echo` to return character output to the keyboard. I don't know enough about Linux terminal output to fix the stifled output from echoing onto the command line after program execution, but this is a minor detail.

## Contact
If there are any questions regarding the project's technical aspects, or if you have any advice or recommendations, please feel free to send me an email at:
*PGilbertSchmitt@gmail.com*
