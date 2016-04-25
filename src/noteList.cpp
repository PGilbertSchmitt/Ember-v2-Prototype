#include "noteList.hpp"

noteList::noteList(){}

void noteList::load(std::string name){
    fileName = name;
    std::ifstream   fs (name);
    std::string     s;

    if (fs.is_open()){
        fs >> s;
        std::cout << s << std::endl;
    } else {
        std::cout << "File " << name << " not found." << std::endl;
    }
}

void noteList::addNote(char note){
    d_list.push_front(note);
}

char noteList::getNote(int index){
    if (index >= 0 && index < d_list.size()){
        return d_list.at(index);
    } else return '0';
}