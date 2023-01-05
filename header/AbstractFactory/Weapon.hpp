#ifndef __WEAPON_HPP
#define __WEAPON_HPP

#include <string>

class Weapon {
        protected:
               std::string name;
	       int attackDamage;
        public:
		Weapon () {}
                virtual ~Weapon(){};
                virtual std::string getName() const = 0;
		virtual int getAttackDmg() const = 0;
};

class ConcreteW1 : public Weapon {
        public:
		ConcreteW1(){this->name = "Phase Axe";
		      this->attackDamage = 7; }
                std::string getName() const override {

                        return name;
                }
		int getAttackDmg() const override {
			return attackDamage;
		}
};

class ConcreteW2 : public Weapon {
	public:
		ConcreteW2() {
		 	this->name = "Light Caster";
			this->attackDamage = 10;
		}

		std::string getName() const override {
			return name;
		 	
		}
		int getAttackDmg() const override {
			return attackDamage;
		}
};

class ConcreteW3 : public Weapon {
        public:
                ConcreteW3(){this->name = "Heavy Repeater";
                      this->attackDamage = 9; }
                std::string getName() const override {

                        return name;
                }
                int getAttackDmg() const override {
                        return attackDamage;
                }
};

class ConcreteW4 : public Weapon {
        public:
                ConcreteW4() {
                        this->name = "Laser Pike";
                        this->attackDamage = 6;
                }

                std::string getName() const override {
                        return name;
                }
                int getAttackDmg() const override {
                        return attackDamage;
                }
};

#endif
