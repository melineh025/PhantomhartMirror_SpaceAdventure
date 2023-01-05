#ifndef __INVENTORY_TEST_HPP_
#define __INVENTORY_TEST_HPP_

#include "gtest/gtest.h"

#include "../header/Inventory.hpp"
#include "../header/AbstractFactory/Weapon.hpp"
#include "../header/AbstractFactory/Armor.hpp"

TEST(Inventory_Tests, Constructor_1_Health){
    Weapon* wpn = new ConcreteW1();
    Armor* arm = new ConcreteA1();
    Inventory* test = new Inventory(wpn,arm);
    EXPECT_EQ(test->getHealing(),0);}

TEST(Inventory_Tests, Constructor_2_Health){
    Weapon* wpn = new ConcreteW1();
    Armor* arm = new ConcreteA1();
    Inventory* test = new Inventory(wpn,arm,5);
    EXPECT_EQ(test->getHealing(),5);}

TEST(Inventory_Tests,_WeaponVal){
    Weapon* wpn = new ConcreteW1();
    Armor* arm = new ConcreteA1();
    Inventory* test = new Inventory(wpn,arm);
    EXPECT_EQ(test->getWeaponVal(),7);}

TEST(Inventory_Tests,ArmorVal){
    Weapon* wpn = new ConcreteW1();
    Armor* arm = new ConcreteA1();
    Inventory* test = new Inventory(wpn,arm);
    EXPECT_EQ(test->getArmorVal(),10);}

TEST(Inventory_Tests, Changed_Health){
    Weapon* wpn = new ConcreteW1();
    Armor* arm = new ConcreteA1();
    Inventory* test = new Inventory(wpn,arm);
    test->changeHealing(20);
    EXPECT_EQ(test->getHealing(),20);}

#endif
