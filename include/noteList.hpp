#ifndef NOTELIST_HPP
#define NOTELIST_HPP

#define NOTE_LIMIT 10 // Number of notes held in d_list before saving

#include <fstream>
#include <deque>
#include <string>
#include <iostream>

class NoteList
{
public:
    NoteList();
    void load(std::string);
    void addNote(char);
    char getNote(unsigned int);    // For testing, I guess
    void saveNotes();              // Saves the notes from d_list to *fileName*
    const std::deque<char>& getList(); // Returns a const reference to the notes
    std::deque<char> d_list;       // Chars that will be played back; new -> old

private:
    std::string fileName;
    //std::deque<char> d_list;       // Chars that will be played back; new -> old
    int counter;
    bool canSave;
};

#endif