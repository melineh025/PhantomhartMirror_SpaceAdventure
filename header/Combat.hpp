#ifndef __COMBAT_HPP__
#define __COMBAT_HPP__

#include "../header/Menu.hpp"
#include "../header/Character.hpp"
#include "../header/CharacterFactory.hpp"
//#include ""


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>


class Combat {

	private:
		CombatMenu *cMenu;
		Character* enemy;
		Player* player;
		int damage; //damage dealt to allow some variance
	public:
		Combat(CharacterFactory *c, Player *p) {
			player = p;
			enemy = c->getEnemy(rand()%2,rand()%2,player->getLevel());
			cMenu = new CombatMenu(enemy,player);
			damage = 0;
		}
		~Combat(){
			delete enemy;
			delete cMenu;
		}
		void startCombat() {
			std::cout << "=========================================\n";
			std::cout << player->getName() << " is ambushed by an " << enemy->getName() << std::endl;
			do{
				std::cout << "=========================================\n";
				this->displayStatus();
				cMenu->menu();
				std::cout << "=========================================\n";
				if(enemy->getCurHP()<=0){
					victory();
					loot();
					return;}
			        std::cout << "=========================================\n";
				//enemies turn
				enemyAttack();
				if(player->getCurHP()<=0){
					return;}
			}while(!cMenu->getFlag());
			return;
		}
		
		
		void displayStatus(){
			std::cout << enemy->getName() << ": " << enemy->getCurHP() << std::endl;
			std::cout << player->getName()<< ": " << player->getCurHP() << "/" << player->getMaxHP() << std::endl;
		}
		void enemyAttack() {
			
			std::cout << enemy->getName() << " tries to attack you!...\n";
				if(rand()%7<5){
					damage = enemy->getDamage()+(rand()%7-3);
					std::cout << "... and hits for " << damage << " damage!" << std::endl;
					player->takeDamage(damage);
				}else
					std::cout << "... but they missed!\n";

		}
		void victory() {
			std::cout << "The " << enemy->getName() << " was defeated! " << player->getName() << " gained "<< enemy->getExperience() << "XP!"<< std::endl;
			player->addXP(enemy->getExperience());
		}
		void loot(){
			char choice = 0;
			std::cout << "=========================================\n";
			std::cout << "***CHECKING FOR LOOT***\n";
			std::cout << "Current Inventory:\n";
			player->checkInventory();
			std::cout << "LOOKING FOR ARMOR" << std::endl;
			if(rand()%5>=3){
				std::cout << "Armor found: " << enemy->getInventory()->getArmor()->getName() << std::endl 
					<< "Protection : " <<  enemy->getInventory()->getArmorVal() << std::endl;
				while(choice < '1' || choice > '2'){
					std::cout << "Would you like to equip? (Current Armor will be discarded!!!)\n1 - HECK YES!!!!\n2 - NO WAY!\n";
					std::cin >> choice;
					switch(choice){
						case '1':player->swapArmor(enemy->getInventory()->getArmor());
							enemy->getInventory()->setArmor(nullptr);
							break;
						case '2':std::cout << "Loot discarded\n";
							break;
						default:std::cout << "Invalid Selection!\n";
							break;
						}
					}
			}
			else {
				std::cout << "\nThis Armor is too damaged...\n";
			}
			std::cout << std::endl << std::endl;
			std::cout << "LOOKING FOR WEAPONS" << std::endl;
			if(rand()%5>=3){
				choice = 0;
                                std::cout << "Weapon found: " << enemy->getInventory()->getWeapon()->getName() << std::endl
                                       << "Damage : " <<  enemy->getInventory()->getWeaponVal() << std::endl;
				while(choice < '1' || choice > '2'){
                                        std::cout << "Would you like to equip? (Current Weapon will be discarded!!!)\n1 - HECK YES!!!!\n2 - NO WAY!\n";
                                        std::cin >> choice;
                                        switch(choice){
                                                case '1':player->swapWeapon(enemy->getInventory()->getWeapon());
                                                        enemy->getInventory()->setWeapon(nullptr);
                                                        break;
                                                case '2':std::cout << "Loot discarded\n";
                                                        break;
                                                default:std::cout << "Invalid Selection!\n";
                                                        break;
                                                }
                                        }

            }
			else {
				std::cout << "\nThe weapon broke when it dropped...\n";
			}
			std::cout << std::endl << std::endl;
			std::cout << "LOOKING FOR HEALTH KITS" << std::endl;
			if(rand()%10>=5){
				std::cout << player->getLevel()+2<< " Health Kits added!" << std::endl;
				player->addHeal(player->getLevel()+2);
				}
			else {
				std::cout << "\nNot even a bandage...\n";
			}
		}
		


};




#endif
