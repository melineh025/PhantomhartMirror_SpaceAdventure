#ifndef __INVENTORY_HPP_
#define __INVENTORY_HPP_
#include<iostream>
#include<iomanip>
#include"AbstractFactory/Weapon.hpp"
#include "AbstractFactory/Armor.hpp"

class Inventory {
    private:
        Weapon* weapon;
        Armor* armor; 
        int numHealingItems;
    public:
        Inventory(Weapon* wpn, Armor* arm){
            weapon=wpn;
            armor=arm;
            numHealingItems=0;
            }
        Inventory(Weapon* wpn, Armor* arm, int initHeal){
            weapon=wpn;
            armor=arm;
            numHealingItems=initHeal;
            }
        ~Inventory(){
            if(weapon)
		delete weapon;
            if(armor)
		delete armor;
            }
        int getHealing(){return numHealingItems;}
        int getWeaponVal(){return weapon->getAttackDmg();}
        int getArmorVal(){return armor->getProt();}
        Weapon* getWeapon(){return weapon;}
        Armor* getArmor(){return armor;}
        void setWeapon(Weapon* wpn){
            weapon=wpn;
            }
        void setArmor(Armor* arm){
            armor = arm;
            }
        void changeHealing(int amount){
                numHealingItems=numHealingItems+amount;
        }

        void printInventory(){
            std::cout<<"\nWeapon: " << weapon->getName()<< std::endl
            <<"\tDamage: " << weapon->getAttackDmg()<< std::endl;
             std::cout<<"Armor: " << armor->getName()<< std::endl
            <<"\tDamage Reduction: " << armor->getProt()<< std::endl;
            std::cout << "Health Kits: " << numHealingItems << std::endl; 
        }
        
};

#endif
