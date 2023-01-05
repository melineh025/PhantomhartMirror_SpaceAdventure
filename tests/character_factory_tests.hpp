#ifndef __CHARACTER_FACTORY_TESTS_HPP
#define __CHARACTER_FACTORY_TESTS_HPP


#include "gtest/gtest.h"

#include "../header/CharacterFactory.hpp"

TEST(Generate_Enemy_Tests, Generate_Race1_Set1_Level1_Stat1){
	CharacterFactory* fact=new CharacterFactory();
	Character* test = fact->getEnemy(0,0,1);
	EXPECT_EQ(test->getDamage(),22);
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race1_Set1_Level1_Stat2){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(0,0,1);
	EXPECT_EQ(test->getProtection(),3);
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race1_Set1_Level1_Stat3){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(0,0,1);
        EXPECT_EQ(test->getMaxHP(), 60);
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race1_Set1_Level1_Stat4){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(0,0,1);
        EXPECT_EQ(test->getCurHP(), 60);
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race1_Set1_Level1_Stat5){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(0,0,1);
        EXPECT_EQ(test->getExperience(), 40);
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race1_Set1_Name){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(0,0,1);
        EXPECT_EQ(test->getName(), "Elf Scout");
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race2_Set1_Level1_Stat1){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(1,0,1);
        EXPECT_EQ(test->getDamage(),18);
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race2_Set1_Level1_Stat2){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(1,0,1);
        EXPECT_EQ(test->getProtection(),13);
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race2_Set1_Level1_Stat3){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(1,0,1);
        EXPECT_EQ(test->getMaxHP(), 55);
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race2_Set1_Level1_Stat4){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(1,0,1);
        EXPECT_EQ(test->getCurHP(), 55);
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race2_Set1_Level1_Stat5){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(1,0,1);
        EXPECT_EQ(test->getExperience(), 45);
        delete test;
        delete fact;}

TEST(Generate_Enemy_Tests, Generate_Race2_Set1_Name){
        CharacterFactory* fact=new CharacterFactory();
        Character* test = fact->getEnemy(1,0,1);
        EXPECT_EQ(test->getName(), "Orc Scourge");
        delete test;
        delete fact;}

TEST(Player_Factory_Tests, Standard_Damage){
	CharacterFactory* fact=new CharacterFactory();
        Player* test = fact->getPlayer("Explorer Dan",0);
        EXPECT_EQ(test->getDamage(),24);
        delete test;
        delete fact;}

TEST(Player_Factory_Testing, Standard_Protection){
        CharacterFactory* fact=new CharacterFactory();
        Player* test = fact->getPlayer("Explorer Dan",0);
        EXPECT_EQ(test->getProtection(),8);
        delete test;
        delete fact;}

TEST(Player_Factory_Testing, Standard_Health){
        CharacterFactory* fact=new CharacterFactory();
        Player* test = fact->getPlayer("Explorer Dan",0);
        EXPECT_EQ(test->getMaxHP(),120);
        delete test;
        delete fact;}

TEST(Player_Factory_Testing, Standard_Name){
        CharacterFactory* fact=new CharacterFactory();
        Player* test = fact->getPlayer("Explorer Dan",0);
        EXPECT_EQ(test->getName(),"Explorer Dan");
        delete test;
        delete fact;}


TEST(Player_Factory_Tests, Sniper_Damage){
        CharacterFactory* fact=new CharacterFactory();
        Player* test = fact->getPlayer("Ranger Rick",1);
        EXPECT_EQ(test->getDamage(),42);
        delete test;
        delete fact;}

TEST(Player_Factory_Testing, Sniper_Protection){
        CharacterFactory* fact=new CharacterFactory();
        Player* test = fact->getPlayer("Ranger Rick",1);
        EXPECT_EQ(test->getProtection(),4);
        delete test;
        delete fact;}

TEST(Player_Factory_Testing, Sniper_Health){
        CharacterFactory* fact=new CharacterFactory();
        Player* test = fact->getPlayer("Ranger Rick",1);
        EXPECT_EQ(test->getMaxHP(),80);
        delete test;
        delete fact;}

TEST(Player_Factory_Testing, Sniper_Name){
        CharacterFactory* fact=new CharacterFactory();
        Player* test = fact->getPlayer("Ranger Rick",1);
        EXPECT_EQ(test->getName(),"Ranger Rick");
        delete test;
        delete fact;}

TEST(Player_Factory_Tests,Tank_Damage){
        CharacterFactory* fact=new CharacterFactory();
        Player* test = fact->getPlayer("Officer Steve",2);
        EXPECT_EQ(test->getDamage(),14);
        delete test;
        delete fact;}

TEST(Player_Factory_Testing, Tank_Protection){
        CharacterFactory* fact=new CharacterFactory();
        Player* test = fact->getPlayer("Officer Steve",2);
        EXPECT_EQ(test->getProtection(),10);
        delete test;
        delete fact;}

TEST(Player_Factory_Testing, Tank_Health){
        CharacterFactory* fact=new CharacterFactory();
        Player* test = fact->getPlayer("Officer Steve",2);
        EXPECT_EQ(test->getMaxHP(),160);
        delete test;
        delete fact;}

TEST(Player_Factory_Testing, Tank_Name){
        CharacterFactory* fact=new CharacterFactory();
        Player* test = fact->getPlayer("Officer Steve",2);
        EXPECT_EQ(test->getName(),"Officer Steve");
        delete test;
        delete fact;}


#endif
