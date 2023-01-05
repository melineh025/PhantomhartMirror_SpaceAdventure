#ifndef __QUESTLOG_HPP__
#define __QUESTLOG_HPP__
#include "Quest.hpp"
#include <vector>
class QuestLog 
{
private:
std::vector<Quest*> quests;
int currQuest;
public:
QuestLog();
~QuestLog();
Quest* getCurrent();
void addQuest(Quest*);
void updateQuest();
std::string checkQuest();
bool compareQuest(Tile*);
};

#endif //__QUESTLOG_HPP___
