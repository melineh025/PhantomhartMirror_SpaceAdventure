#ifndef __CHARACTER_FACTORY_HPP_
#define __CHARACTER_FACTORY_HPP_

#include <string>
#include "AbstractFactory/GearFactory.hpp"
#include "StarterGear.hpp"
#include "Character.hpp"

class CharacterFactory {
	private:
		GearFactory* ElfFact;
		GearFactory* OrcFact;
	public:
		CharacterFactory(){
			ElfFact = new ElfFactory();
			OrcFact = new OrcFactory();}
		~CharacterFactory(){
			delete ElfFact;
			delete OrcFact;}
		Character* getEnemy(int x,int y, int scale){
			Character* enemy;
			switch(x){
				case 0:
					switch(y){
						case 0:
							enemy= new Character("Elf Scout", ElfFact->createWeapon(y), ElfFact->createArmor(y),(10+(2*scale)),(50+(10*scale)),(20+(20*scale)));
							break;
						default:
							enemy= new Character("Elf Warrior", ElfFact->createWeapon(y), ElfFact->createArmor(y),(7+(2*scale)),(80+(10*scale)),(25+(25*scale)));
                                                        break;
						};
					break;	
				case 1:
                                        switch(y){
                                                case 0:
                                                        enemy= new Character("Orc Scourge", OrcFact->createWeapon(y), OrcFact->createArmor(y),(8+(3*scale)),(40+(15*scale)),(15+(30*scale)));
                                                        break;
                                                default:
                                                        enemy= new Character("Orc Destroyer", OrcFact->createWeapon(y), OrcFact->createArmor(y),(11+(3*scale)),(75+(15*scale)),(20+(35*scale)));
                                                        break;
                                        };
                                        break;
				}
			return enemy;
			}
		Player* getPlayer(std::string n, int x){
			Player* player;
			switch(x){
				case 0:	player=new Player(n, new StarterW1(), new StarterA1(), 15, 120);
					return player;
					break;
				case 1: player=new Player(n, new StarterW2(), new StarterA2(), 30, 80);
					return player;
					break;
				default: player=new Player(n, new StarterW3(), new StarterA3(), 8, 160);
					return player;
					break;
				}		
		}	
};


#endif
