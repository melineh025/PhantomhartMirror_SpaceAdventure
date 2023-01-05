#ifndef __CHARACTER_HPP_
#define __CHARACTER_HPP_
#include <string>
#include "Inventory.hpp"
class Character {
    public:
       Character(){
	   name="";
	   pack=nullptr;
	   damage=max_HP=cur_HP=experience=0;
	} 
       Character(Weapon* wpn, Armor* arm, int dmg, int HP, int exp){
            name="";
	    pack= new Inventory(wpn, arm);
            damage=dmg;
            max_HP=HP;
            cur_HP=max_HP;
            experience=exp;
        }
	Character(std::string n, Weapon* wpn, Armor* arm, int dmg, int HP, int exp){
            name=n;
            pack= new Inventory(wpn, arm);
            damage=dmg;
            max_HP=HP;
            cur_HP=max_HP;
            experience=exp;	
	}
        ~Character(){delete pack;}
        void setName(std::string n){name = n;} 	//Set name of Character post construction
	std::string getName(){return name;}	//Getter for Character name
	int getDamage(){return (damage+pack->getWeaponVal());}  //Getter funtion for Damage
        virtual int getProtection(){return pack->getArmorVal();}        //Getter for Armor Damage Reduction
        int getMaxHP(){return max_HP;}                          //Getter funtion for Max Health
        int getCurHP(){return cur_HP;}                          //Getter funtion for Current Health
        int getExperience(){return experience;}                 //Getter funtion for Experience
        Inventory* getInventory(){return pack;}			//Getter for looting inventory
	int takeDamage(int incoming){
            cur_HP-=(incoming-(this->getProtection()));
            if(cur_HP<=0){
                cur_HP=0;
            }
            return cur_HP;
        }
	protected:
	//Data Members 
	std::string name;   //Character's Name
        Inventory* pack;    //Character's Inventory
        int damage;         //Base Damage Stat
        int max_HP;         //Maximum Health Stat
        int cur_HP;         //Current Health Amount
        int experience;     //Current Experience Amount
};

class Player : public Character {
    private:
	int level;
    public:
	Player(std::string n, Weapon* wpn, Armor* arm, int dmg, int HP){
		name=n;
		damage=dmg;
		cur_HP=max_HP=HP;
		experience = 0;
		level=1;
		pack = new Inventory(wpn, arm, 5);
	}
	int getLevel(){return level;}	//returns level of Player Character
	int getProtection(){
		int prot = level*2;
		prot+=pack->getArmorVal();	
		return prot;}        //Getter for Armor Damage Reduction
	void Heal(){	//Used to heal character using healing item from inventory
		if(cur_HP==max_HP){
			std::cout << "You have no wounds to heal\n\n";
		}else{
			if(pack->getHealing()>=1){
				cur_HP+=20;
				if(cur_HP>max_HP){
					cur_HP=max_HP;
				}
				pack->changeHealing(-1);
				std::cout<< "Healed!!!\nCurrent Health is now: " << cur_HP <<"\\" <<max_HP <<std::endl;
				std::cout<< pack->getHealing()<< " Health Kits Remaining\n\n";
			}
			else{
				std::cout<<"No Health Kits Available!!!"<<std::endl;
			}
		}		
	}
	void swapWeapon(Weapon* wpn){ //Replace equipped weapon with new weapoon
		std::cout << pack->getWeapon()->getName()<< " discarded!" << std::endl <<std::endl;
		delete pack->getWeapon();
		pack->setWeapon(wpn);
		
		std::cout<<pack->getWeapon()->getName() << " is now equipped!" <<std::endl;
	}
	void swapArmor(Armor* arm){  //Replace equipped armor with new armor
                std::cout << pack->getArmor()->getName()<< " discarded!" << std::endl <<std::endl;
		delete pack->getArmor();
                pack->setArmor(arm);
		
		std::cout<<pack->getArmor()->getName() << " is now equipped!" <<std::endl;
	}
	void addHeal(int amt){	      //Used to increase the number of healing items in player inventory
		pack->changeHealing(amt);
	}
	void addXP(int xp){	     //Used to increase amount of experience of player. Handles leveling
		experience += xp;
		while(experience>=50*level){
			experience-=(level*50);
			damage+=(damage/10);
			max_HP+=(5*level);
			cur_HP=max_HP;
			std::cout<<"Congratulations! " << name << " is now level " << ++level << std::endl
					<<"All stats increase\n"
					<<"Health is fully restored\n";
			}
		}
	void checkInventory(){
		std::cout << "=========================================\n";
		std::cout << "**"<< name << "'s Inventory**\n";
		pack->printInventory();
		std::cout << "=========================================\n";
	}
	
};
#endif
