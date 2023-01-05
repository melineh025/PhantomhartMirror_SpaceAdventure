#ifndef __GEARFACTORY_HPP__
#define __GEARFACTORY_HPP__


#include <string>


#include "Armor.hpp"
#include "Weapon.hpp"

class GearFactory {
	
	public:

		virtual Armor *createArmor (int x) const = 0;
		virtual Weapon *createWeapon(int x) const = 0;
};

class ElfFactory: public GearFactory {

	public:
		Weapon* createWeapon(int x) const override {
			Weapon* newWpn;
			 switch(x){
                                case 0:
					newWpn = new ConcreteW2();
					return newWpn;
                                        break;
                                case 1:
					newWpn = new ConcreteW4();
					return newWpn;
                                        break;
                        }
			return nullptr;
		}

		Armor * createArmor(int x) const override{
			Armor* newArm;
			 switch(x){
                                case 0: 
					newArm = new ConcreteA4();
					return newArm;
                                        break;
                                case 1:
					newArm = new ConcreteA1();
					return newArm;
                                        break;
                        }
			return nullptr;
		}
};

class OrcFactory: public GearFactory {

        public:
                Weapon* createWeapon(int x) const override {
                        Weapon* newWpn;
			switch(x){
				case 0:
					newWpn = new ConcreteW1();
					return newWpn;
					break;
				case 1: 
					newWpn = new ConcreteW3();
					return newWpn;
					break;			
			}
                        return nullptr;
                }

                Armor * createArmor(int x) const override{
                        Armor* newArm;
			 switch(x){
                                case 0:
					newArm = new ConcreteA3();
					return newArm;
                                        break;
                                case 1:
					newArm = new ConcreteA2();
					return newArm;
                                        break;
                        }
                        return nullptr;
                }
};
#endif
