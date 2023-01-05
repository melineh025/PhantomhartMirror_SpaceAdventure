#ifndef __CHARACTER_TEST_HPP_
#define __CHARACTER_TEST_HPP_

#include "gtest/gtest.h"

#include "../header/Character.hpp"
#include "../header/AbstractFactory/Weapon.hpp"
#include "../header/AbstractFactory/Armor.hpp"

TEST(Character_Getter_Tests, CharacterDamage){
    Weapon* wpn = new ConcreteW1();
    Armor* arm = new ConcreteA3();
    Character* test = new Character("",wpn,arm,50,200,0);
    EXPECT_EQ(test->getDamage(),57);
    delete test;
}

TEST(Character_Getter_Tests, CharacterProtection){
    Weapon* wpn = new ConcreteW1();
    Armor* arm = new ConcreteA3();
    Character* test = new Character("",wpn,arm,50,200,0);
    EXPECT_EQ(test->getProtection(),13);
    delete test;
}

TEST(Character_Getter_Tests, CharacterMaxHealth){
    Weapon* wpn = new ConcreteW1();
    Armor* arm = new ConcreteA3();
    Character* test = new Character("",wpn,arm,50,200,0);
    EXPECT_EQ(test->getMaxHP(),200);
    delete test;
}

TEST(Character_Getter_Tests, CharacterCurHealth){
    Weapon* wpn = new ConcreteW1();
    Armor* arm = new ConcreteA3();
    Character* test = new Character("",wpn,arm,50,200,0);
    EXPECT_EQ(test->getCurHP(),200);
    delete test;
}

TEST(Character_Getter_Tests, CharacterExperience){
    Weapon* wpn = new ConcreteW1();
    Armor* arm = new ConcreteA3();
    Character* test = new Character("",wpn,arm,50,200,10);
    EXPECT_EQ(test->getExperience(),10);
    delete test;
}

TEST(Character_Damage_Tests, Take_Damage_Light){
    Weapon* wpn = new ConcreteW1();
    Armor* arm = new ConcreteA3();
    Character* test = new Character("",wpn,arm,50,200,0);
    test->takeDamage(30);
    EXPECT_EQ(test->getCurHP(),183);
    delete test;
}

TEST(Character_Damage_Tests, Take_Damage_Medium){
    Weapon* wpn = new ConcreteW1();
    Armor* arm = new ConcreteA3();
    Character* test = new Character("",wpn,arm,50,200,0);
    test->takeDamage(70);
    EXPECT_EQ(test->getCurHP(),143);
    delete test;
}

TEST(Character_Damage_Tests, Take_Damage_Heavy){
    Weapon* wpn = new ConcreteW1();
    Armor* arm = new ConcreteA3();
    Character* test = new Character("",wpn,arm,50,200,0);
    test->takeDamage(150);
    EXPECT_EQ(test->getCurHP(),63);
    delete test;
}

TEST(Character_Damage_Tests, Take_Damage_Excessive){
    Weapon* wpn = new ConcreteW1();
    Armor* arm = new ConcreteA3();
    Character* test = new Character(wpn,arm,50,200,0);
    test->takeDamage(500);
    EXPECT_EQ(test->getCurHP(),0);
    delete test;
}

TEST(Character_Name_Tests, No_Name){
    Character* test = new Character(new ConcreteW1(), new ConcreteA1(), 20, 100, 1);
    EXPECT_EQ(test->getName(),"");
    delete test;
}

TEST(Character_Name_Tests, Set_Name){
    Character* test = new Character(new ConcreteW1(), new ConcreteA1(), 20, 100, 1);
    test->setName("Roger Dodger");
    EXPECT_EQ(test->getName(),"Roger Dodger");
    delete test;
}

TEST(Character_Name_Tests, Construct_with_Name){
    Character* test = new Character("Steve Rogers",new ConcreteW1(), new ConcreteA1(), 20, 100, 1);
    EXPECT_EQ(test->getName(),"Steve Rogers");
    delete test;
}

TEST(Player_Level_Tests, InitialLevel){
        Player* test= new Player("John Smith", new ConcreteW1(), new ConcreteA1(), 20, 100);
	EXPECT_EQ(test->getLevel(), 1);
	delete test;}

TEST(Player_Level_Tests, LevelUp1_CheckLevel){
        Player* test= new Player("John Smith", new ConcreteW1(), new ConcreteA1(), 20, 100);
        test->addXP(50);
	EXPECT_EQ(test->getLevel(), 2);
        delete test;}

TEST(Player_Level_Tests, LevelUp1_CheckXP){
        Player* test= new Player("John Smith", new ConcreteW1(), new ConcreteA1(), 20, 100);
        test->addXP(50);
        EXPECT_EQ(test->getExperience(), 0);
        delete test;}

TEST(Player_Level_Tests, LevelUp2_CheckLevel){
        Player* test= new Player("John Smith", new ConcreteW1(), new ConcreteA1(), 20, 100);
        test->addXP(200);
        EXPECT_EQ(test->getLevel(), 3);
        delete test;}

TEST(Player_Level_Tests, LevelUp2_CheckXP){
        Player* test= new Player("John Smith", new ConcreteW1(), new ConcreteA1(), 20, 100);
        test->addXP(200);
        EXPECT_EQ(test->getExperience(), 50);
        delete test;}

TEST(Player_Health_Tests, Initial_Health){
        Player* test= new Player("John Smith", new ConcreteW1(), new ConcreteA1(), 20, 100);
	test->Heal();
	EXPECT_EQ(test->getCurHP(),100);
	delete test;}

TEST(Player_Health_Tests, Full_Heal){
        Player* test= new Player("John Smith", new ConcreteW1(), new ConcreteA1(), 20, 100);
        test->takeDamage(20);
	test->Heal();
        EXPECT_EQ(test->getCurHP(),100);
        delete test;}

TEST(Player_Health_Tests, Partial_Heal){
        Player* test= new Player("John Smith", new ConcreteW1(), new ConcreteA1(), 20, 100);
        test->takeDamage(50);
	test->Heal();
        EXPECT_EQ(test->getCurHP(),82);
        delete test;}

TEST(Player_Health_Tests, Insufficient_Heal){
        Player* test= new Player("John Smith", new ConcreteW1(), new ConcreteA1(), 20, 200);
        test->takeDamage(200);
        test->Heal();
        test->Heal();
        test->Heal();
        test->Heal();
        test->Heal();
        test->Heal();
        EXPECT_EQ(test->getCurHP(),112);
        delete test;}

TEST(Player_Health_Tests, Add_Heal){
        Player* test= new Player("John Smith", new ConcreteW1(), new ConcreteA1(), 20, 100);
        test->takeDamage(35);
        test->addHeal(10);
        test->Heal();
        EXPECT_EQ(test->getCurHP(),97);
	delete test;}

TEST(Player_Reequip_Tests, Change_Weapon){
        Player* test= new Player("John Smith", new ConcreteW1(), new ConcreteA1(), 20, 10);
        test->swapWeapon(new ConcreteW2());
	EXPECT_EQ(test->getDamage(),30);
        delete test;}

TEST(Player_Reequip_Tests, Change_Armor){
        Player* test= new Player("John Smith", new ConcreteW1(), new ConcreteA1(), 20, 10);
        test->swapArmor(new ConcreteA2());
        EXPECT_EQ(test->getProtection(),7);
        delete test;}


#endif
