#ifndef __QUEST_TEST_CPP__
#define __QUEST_TEST_CPP__

#include "gtest/gtest.h"

#include "../header/Quest/Quest.hpp"

TEST(QuestTest, Questintro) {
	Tile* test1 = new Tile();	
	Tile* test2 = new Tile();
    Quest* Quests = new Quest("hi1" , "hi2" , "hi3" ,test1, test2 );
    EXPECT_EQ(Quests->getIntro(), "hi1" );
	delete test1;
	delete test2;
	delete Quests;
}
TEST(QuestTest, QuestObj) {
        Tile* test1 = new Tile();
        Tile* test2 = new Tile();
    Quest* Quests = new Quest("hi1" , "hi2" , "hi3" ,test1, test2 );
    EXPECT_EQ(Quests->getObj(), "hi2" );
        delete test1;
        delete test2;
        delete Quests;
}
TEST(QuestTest, QuestConclusion) {
        Tile* test1 = new Tile();
        Tile* test2 = new Tile();
    Quest* Quests = new Quest("hi1" , "hi2" , "hi3" ,test1, test2 );
    EXPECT_EQ(Quests->getConclusion(), "hi3" );
        delete test1;
        delete test2;
        delete Quests;
}
TEST(QuestTest, QuestBeg) {
        Tile* test1 = new Tile();
        Tile* test2 = new Tile();
    Quest* Quests = new Quest("hi1" , "hi2" , "hi3" ,test1, test2 );
    EXPECT_EQ(Quests->getStart(), test1 );
        delete test1;
        delete test2;
        delete Quests;
}
TEST(QuestTest, QuestEnd) {
        Tile* test1 = new Tile();
        Tile* test2 = new Tile();
    Quest* Quests = new Quest("hi1" , "hi2" , "hi3" ,test1, test2 );
    EXPECT_EQ(Quests->getEnd(), test2 );
        delete test1;
        delete test2;
        delete Quests;
}
TEST(QuestTest, QuestStatus) {
        Tile* test1 = new Tile();
        Tile* test2 = new Tile();
    Quest* Quests = new Quest("hi1" , "hi2" , "hi3" ,test1, test2 );
	Quests->toggleStatus();
    EXPECT_TRUE(Quests->getStatus());
        delete test1;
        delete test2;
        delete Quests;
}



#endif //_Quest__TEST_CPP__
