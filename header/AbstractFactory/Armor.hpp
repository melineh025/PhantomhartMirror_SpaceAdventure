#ifndef __ARMOR_HPP__
#define __ARMOR_HPP__

#include <string>

class Armor {
        protected:
               
              
                std::string name;
		int protection;
        public:
		Armor() {}
                virtual ~Armor() {};
                virtual std::string getName () const = 0;
		virtual int getProt () const = 0;



};

class ConcreteA1 : public Armor {
	
	public:
		ConcreteA1() {
			this->name = "Sturdy Jacket";
			this->protection = 10;
		}
		std::string getName() const override {return name;}
		int getProt() const override {return protection;}
};

class ConcreteA2 : public Armor {

        public:
                ConcreteA2() {
                        this->name = "Berserker Vest";
                        this->protection = 5;
                }
                std::string getName() const override {return name;}
                int getProt() const override {return protection;}
};


class ConcreteA3 : public Armor {

        public:
                ConcreteA3() {
                        this->name = "Heavy Tech Suit";
                        this->protection = 13;
                }
                std::string getName() const override {return name;}
                int getProt() const override {return protection;}
};


class ConcreteA4 : public Armor {

        public:
                ConcreteA4() {
                        this->name = "Light Camouflage Armor";
                        this->protection = 3;
                }
                std::string getName() const override {return name;}
                int getProt() const override {return protection;}
};





#endif
