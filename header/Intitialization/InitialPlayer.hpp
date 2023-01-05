#ifndef __INITIALPLAYER_HPP__

#define __INITIALPLAYER_HPP__
#include "../Character.hpp"
#include "../CharacterFactory.hpp"



class InitialPlayer {

public:
	Player* createPlayer(CharacterFactory* F) {
        int input = 0;
	      bool done = 0;
		
        std::cout<<"What is your Name" <<std::endl;
        std::string name;
        std::cin.ignore();
	std::getline(std::cin,name);
	std::cout << "=========================================\n";
	while(!done){
        	std::cout<<"Who were you before being recruited to explore?\n"
			<<"1 - A Homeless man, dressed in tattered rags and carrying an old gun given to you by your friend before he passed. A capable fighter, but lacks the fitness to handle longer battles\n       -Medium Armor\n       -Medium Damage\n       -Medium Health\n"
			<<"2 - A Space Ranger, your wreckless nature caused you to crash into a planet resulting in your disgraceful termination. You still wear the bright jacket of your once proud uniform. A crack shot with a rifle, but definitely not prepared for close up fighting\n       -Light Armor\n       -High Damage\n       -Low Health\n"
			<<"3 - A Officer of the law. After years of faithful service quelling riots in the core worlds, you have been reassigned to the Exploration Bureau. The demotion stings your pride, but not as much as being forced to use the heavy riot gear. The shock baton may not do much, but at least you are armored.\n       -Heavy Armor\n       -Low Damage\n       -High Health\n" <<std::endl;
        	std::cin>>input;
        	switch(input){
                	case 1:
                	return	 F->getPlayer(name , 0);
	          		break;
                	case 2:
                 	return	 F->getPlayer(name , 1);
				break;
                	case 3:
                 	return	 F->getPlayer(name , 2);
				break;
                	default:
                		std::cout<<"invalid input"<<std::endl;
				break;
		  	}
		}
		return nullptr;
	std::cout << "=========================================\n";
	}

};


#endif
