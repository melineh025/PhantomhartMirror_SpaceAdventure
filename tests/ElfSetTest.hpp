#ifndef __ELFSETTEST_HPP__
#define __ELFSETTEST_HPP__



#include "gtest/gtest.h"
#include "../header/AbstractFactory/GearFactory.hpp"

TEST(ElfGearCreation, CheckWeaponName)  {

	GearFactory *gearByClass;
	gearByClass = new ElfFactory();

	Weapon *firstWeapon = gearByClass->createWeapon(0);	
	EXPECT_EQ(firstWeapon->getName(), "Light Caster");
}

TEST(ElfGearCreation, CheckArmorName) {

	GearFactory *gearByClass;
	gearByClass = new ElfFactory();

	Armor *firstArmor = gearByClass->createArmor(0);

	EXPECT_EQ(firstArmor->getName(), "Light Camouflage Armor");


}

TEST(ElfGearCreation, CheckWeaponStat) {

	GearFactory *gearByClass;
	gearByClass = new ElfFactory();
	
	Weapon *firstWeapon = gearByClass->createWeapon(0);

	EXPECT_EQ(firstWeapon->getAttackDmg(), 10);

}

TEST(ElfGearCreation, CheckArmorStat) {

        GearFactory *gearByClass;
        gearByClass = new ElfFactory();

        Armor *firstArmor = gearByClass->createArmor(0);

        EXPECT_EQ(firstArmor->getProt(), 3);




}



#endif
