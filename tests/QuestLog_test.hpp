#ifndef __QUESTLOG_TEST_HPP__
#define __QUESTLOG_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Quest/Questlog.hpp"

TEST(QuestLogTest, QuestLoggetCurrent) {
        Tile* test1 = new Tile();
        Tile* test2 = new Tile();
    Quest* Quests = new Quest("hi1" , "hi2" , "hi3" ,test1, test2 );
	QuestLog* Questlog = new QuestLog();
Questlog->addQuest(Quests);
    EXPECT_EQ(Questlog->getCurrent(), Quests );
        delete test1;
        delete test2;
        delete Questlog;
}
TEST(QuestLogTest, QuestLogcheckQuest) {
        Tile* test1 = new Tile();
        Tile* test2 = new Tile();
    Quest* Quests = new Quest("hi1" , "hi2" , "hi3" ,test1, test2 );
        QuestLog* Questlog = new QuestLog();
Questlog->addQuest(Quests);
    EXPECT_EQ(Questlog->checkQuest(), "hi2" );
        delete test1;
        delete test2;
        delete Questlog;
}

TEST(QuestLogTest, QuestLogupdateQuest) {
        Tile* test1 = new Tile();
        Tile* test2 = new Tile();
    Quest* Quests1 = new Quest("hi1" , "hi2" , "hi3" ,test1, test2 );
    Quest* Quests2 = new Quest("hi1" , "hi2" , "hi3" ,test1, test2 );
	
        QuestLog* Questlog = new QuestLog();
Questlog->addQuest(Quests1);
Questlog->addQuest(Quests2);
Questlog->updateQuest();
    EXPECT_EQ(Questlog->getCurrent(), Quests2 );
        delete test1;
        delete test2;
        delete Questlog;
}
TEST(QuestLogTest, QuestLogcompareQuest) {
        Tile* test1 = new Tile();
        Tile* test2 = new Tile();
	Tile* test3 = new Tile();
    Quest* Quests1 = new Quest("hi1" , "hi2" , "hi3" ,test1, test2 );
    Quest* Quests2 = new Quest("hi1" , "hi2" , "hi3" ,test2, test3 );
        QuestLog* Questlog = new QuestLog();
Questlog->addQuest(Quests1);
Questlog->addQuest(Quests2);
Questlog->compareQuest(test2);
    EXPECT_EQ(Questlog->getCurrent(), Quests2 );
        delete test1;
        delete test2;
        delete Questlog;
};
TEST(QuestLogTest, QuestLogcompareQuestSTART) {
	QuestLog* Questlog = new QuestLog();
        Tile* test1 = new Tile();
        Tile* test2 = new Tile();
	Quest* Quests1 = new Quest("hi1" , "hi2" , "hi3" ,test1, test2 );
	Questlog->addQuest(Quests1);
	EXPECT_FALSE(Questlog->compareQuest(test1));
	delete test1;
        delete test2;
        delete Questlog;

};
TEST(QuestLogTest, QuestLogcompareQuestEND) {
        QuestLog* Questlog = new QuestLog();
        Tile* test1 = new Tile();
        Tile* test2 = new Tile();
        Quest* Quests1 = new Quest("hi1" , "hi2" , "hi3" ,test1, test2 );
        Questlog->addQuest(Quests1);
        EXPECT_TRUE(Questlog->compareQuest(test2));
	delete test1;
        delete test2;
        delete Questlog;

};






#endif //QUESTLOG_HPP
