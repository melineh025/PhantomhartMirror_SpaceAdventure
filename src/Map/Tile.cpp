#ifndef __TILE_CPP__
#define __TILE_CPP__
#include <iostream>
#include "../../header/Map/Tile.hpp"
Tile::Tile()
{
}
Tile::Tile(std::string description_input, bool quest_input)
{
//add enemy object
quest =quest_input;
description = description_input;
}
std::string Tile::getdescription()
{
	return description;
}
void Tile::setAdj(Tile* left_input, Tile* right_input , Tile* top_input, Tile* bottom_input)
{
left = left_input;
right = right_input;
top = top_input;
bottom = bottom_input;
}
Tile* Tile::getNext(char input)
{
if(input == '1')
return left;
if(input == '2')
return right;
if(input == '3')
return top;
if(input == '4')
return bottom;

}
Tile::~Tile()
{
description.clear();
quest =0;
}
#endif //__TILE_CPP__
