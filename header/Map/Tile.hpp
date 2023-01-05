#ifndef __TILE_HPP__
#define __TILE_HPP__
#include <string>
class Tile 
{
	protected:
	Tile* left;
	Tile* right;
	Tile* top;
	Tile* bottom;
	private: 
	std::string description;
	bool enemy,quest;
	//enemy object
	public:
	Tile();
	Tile* getNext(char);
	Tile(std::string,bool); //enemy object
	std::string getdescription();
	void setAdj(Tile* ,Tile*, Tile* ,Tile*);
	~Tile();
};

#endif //__TILE_HPP__
