#ifndef NOTELIST_HPP
#define NOTELIST_HPP

#include <fstream>
#include <deque>
#include <string>
#include <iostream>

class noteList
{
public:
    noteList();
    void load(std::string);
    void addNote(char);
    char getNote(int);

private:
    std::string fileName;
    std::deque<char> d_list;       // Chars that will be played back
    std::deque<char> d_toBeSaved;  // Overflowed notes from d_list
};

#endif