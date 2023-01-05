#ifndef __QUEST_CPP__
#define __QUEST_CPP__
#include "../../header/Quest/Quest.hpp"
Quest::Quest(std::string start, std::string Obj, std::string comp, Tile* startTile, Tile* endTile)
{
objective = Obj;
intro = start;
conclude = comp;
Qstart = startTile;
Qend = endTile;
}
Quest::~Quest()
{
objective.clear();
intro.clear();
conclude.clear();
Qstart = nullptr;
Qend = nullptr;
}
bool Quest::getStatus()
{
return active;
}
void Quest::toggleStatus()
{
if(active)
active =false;
else
active = true;
}
Tile* Quest::getStart()
{
return Qstart;
}
Tile* Quest::getEnd()
{
return Qend;
}
std::string Quest::getObj()
{
return objective;
}
std::string Quest::getIntro()
{
return intro;
}
std::string Quest::getConclusion()
{
return conclude;
}

#endif //__QUEST_CPP__
