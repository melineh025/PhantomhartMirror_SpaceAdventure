#ifndef __QUESTLOG_CPP__
#define __QUESTLOG_CPP__
#include "../../header/Quest/Questlog.hpp"
#include <iostream>
QuestLog::QuestLog()
{
currQuest =0;
}
QuestLog::~QuestLog()
{
//delete everything
for(auto i:quests){
	delete i;
        }
}


Quest* QuestLog::getCurrent()
{
if(quests.size()<=currQuest)
{
	return nullptr;
}
return quests.at(currQuest);
}
void QuestLog::addQuest(Quest* input)
{
quests.push_back(input);
}
void QuestLog::updateQuest()
{
currQuest = currQuest+1;
}
std::string QuestLog::checkQuest()
{
return quests.at(currQuest)->getObj();
}
bool QuestLog::compareQuest(Tile* Tile)
{
if(this->getCurrent() == nullptr)
{
        return true;
}
if(Tile == this->getCurrent()->getEnd())
{
	std::cout << "=========================================\n";
	std::cout << "**Quest Update**\n";
        std::cout<<this->getCurrent()->getConclusion()<<std::endl;
        updateQuest();
}
if(this->getCurrent() == nullptr)
{
        return true;
}
//check quest start
if(Tile == this->getCurrent()->getStart() && this->getCurrent()->getStatus() != true )
{
        this->getCurrent()->toggleStatus();
	std::cout << "=========================================\n";
        std::cout << "**Quest Update**\n";
        std::cout<<this->getCurrent()->getIntro()<<std::endl;
}
return false;
}
#endif //__QUESTLOG_CPP__
