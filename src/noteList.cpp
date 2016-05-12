#include "noteList.hpp"

NoteList::NoteList(){
    counter = 0;
    canSave = false;
}

void NoteList::load(std::string name)
{
    fileName = name;
    std::ifstream   fs (fileName);
    std::string     s;

    if (fs.is_open()){
        fs >> s;
        std::string::reverse_iterator it = s.rbegin();

        for (unsigned int i = 0; i < NOTE_LIMIT; ++i){
            d_list.push_back(*it);
            it++;
        }
        fs.close();
    } else {
        std::cout << "File " << name << " not found." << std::endl;
    }

}

void NoteList::addNote(char note)
{
    if (counter % NOTE_LIMIT == 0 && !canSave){
        canSave = true;
    } else if (counter % NOTE_LIMIT == 0 && canSave){
        saveNotes();
    }
    d_list.push_front(note);
    d_list.pop_back();
    counter++;
}

char NoteList::getNote(unsigned int index)
{
    if (index < d_list.size()){
        return d_list.at(index);
    } else return '0';
}

void NoteList::saveNotes()
{
    std::cout << "Saving notes to " << fileName << "..." << std::endl;

    std::fstream fs (fileName, std::ios::app );

    if (fs.is_open()){
        std::cout << "Success!" << std::endl;
    } else {
        std::cout << "Failure!" << std::endl;
    }

    int numOfNotes;
    if (counter % NOTE_LIMIT == 0){
        numOfNotes = NOTE_LIMIT;
    } else {
        numOfNotes = counter % NOTE_LIMIT;
    }

    for (int i = 0; i < numOfNotes; i++){
        fs.put(d_list.at(numOfNotes - i - 1));
    }

    fs.close();
}

const std::deque<char>& NoteList::getList()
{
    return d_list;
}