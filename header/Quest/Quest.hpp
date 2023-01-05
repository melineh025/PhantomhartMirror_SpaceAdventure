#ifndef __QUEST_HPP__
#define __QUEST_HPP__
#include <string>
#include <iostream>
#include "../Map/Tile.hpp"
class Quest 
{
private:
std::string intro;
std::string conclude;
std::string objective;
bool active = false;
Tile* Qend;
Tile* Qstart;
public:
Quest(std::string, std::string, std::string, Tile*, Tile*);
~Quest();
bool getStatus();
void toggleStatus();
Tile* getStart();
Tile* getEnd();
std::string getObj();
std::string getIntro();
std::string getConclusion();
};

#endif //__QUEST_HPP__
