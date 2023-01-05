#ifndef __MENU_HPP__
#define __MENU_HPP__

#include "Quest/Questlog.hpp"

#include <string>
#include "Character.hpp"
#include "Map/Map.hpp"
#include <iostream>


class Menu {
        public:
                virtual void menu() = 0;
	        virtual bool getFlag() = 0;
        protected:
                char choice;
                bool flag;
};
class MoveMenu : public Menu {
        private:
	Map* map;
	public:
		MoveMenu(Map* m){
			this->map=m;
			choice= 0;
			flag=false;
			}
						
                bool getFlag(){
			if(flag){
				flag=false;
				return true;}
			else return false;
			}
                void menu(){
			std::cout << "=========================================\n";
				std::cout << "Where would you like to go?\n"
					<<"1 - West\n"
					<<"2 - East\n"
					<<"3 - North\n"
					<<"4 - South\n"
					<<"5 - Cancel Movement\n";
				std::cin >> choice;
				switch(choice){
					case '1':
					case '2':
					case '3':
					case '4':
						map->move(choice);
						flag = true; 	//just trying to move sets flag
						break;
					case '5':		//A quit choice to leave this menu
						break;
					default:		//invalid choice 
						std::cout<<"Invalid Choice\n";
						break;					
				}
			}
					
		
};

class CombatMenu : public Menu {
        private:
		Player* p;
		Character* e;
	public:
		CombatMenu(Character *enemy, Player *player){
			choice = 0;
			flag = false;
			this->p=player;
			this->e=enemy;
		}
                void menu(){
				int damage=0;
				choice=0;
				while(choice <'1' || choice >'3'){
					std::cout <<"What do you do?\n"
						<<"1 - Attack " << e->getName() <<std::endl 
						<<"2 - Heal\n"
						<<"3 - Flee\n";
					std::cin >> choice;
					switch(choice){
						case '1':
								std::cout << p->getName() << " attacks " << e->getName() <<"!...\n";
								if(rand()%7<5){
								damage = p->getDamage()+(rand()%7-3);
								std::cout << "... and hits for " << damage << " damage!" << std::endl;
								e->takeDamage(damage);
							}else
								std::cout << "... but missed!\n";
							break;
						case '2':
							std::cout <<"Attempting to Heal 20 HP...\n";
							p->Heal();
							break;
						case '3':
							std::cout << "Only cowards run from a fight!\n";
							flag=true;
							break;
						default: 
							std::cout << "Invalid\n";
							break;
					}
				}	
		}
                bool getFlag(){
			if(flag){
				flag=false;
				return true;}
			else return false;	
			}
};
class CoreMenu : public Menu {
        private:
		bool moved;
		MoveMenu *move;	
		Map* map;
		Player* player;
		QuestLog* quests;
	public:
		CoreMenu (Map* m, QuestLog * q, Player *p) {
				move = new MoveMenu(m);
				this->map = m;
				this->quests = q;
				this->player = p;
				flag = true;
				moved = false;
				}
		~CoreMenu(){delete move;}

                void menu(){
			std::cout << map->getCurrent()->getdescription()<<std::endl;
                        std::cout << "=========================================\n";
			std::cout << "What would you like to do?\n1 - Move \n2 - Check Objective\n3 - Check Inventory\n4 - Quit Game" << std::endl;
			  std::cin >> choice;
				  switch(choice) {
					case '1':
						move->menu();
						if(move->getFlag()){
							moved = true;
						}									
						break;
					case '2':
						std::cout << "=========================================\n";
						std::cout << "**Current Objective**\n";
						std::cout << quests->getCurrent()->getObj() << std::endl;
						break;
					case '3':
					       	player->checkInventory();
						break;
					case '4':
						flag = false;
						break;
					}

				}
		
		
                bool getFlag(){
			if(player->getCurHP()<=0){
				return false;	
			}else if(quests->compareQuest(map->getCurrent())) {
				return false;
			}else if(moved){
				return false;
			}else if(!flag){
				flag = true;
				return false;
			}else return true;
		}
		
		bool getMoveFlag(){
			if(moved){
				moved=false;
				return true;}
			else{
				return false;}	
		}
};

#endif
