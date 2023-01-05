#ifndef __MAP_TEST_HPP__
#define __MAP_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Map/Map.hpp"
TEST(MapTest, MapGetCurrent) {
    Tile* test = new Tile("hi" ,1);
	Map* map = new Map(test);
	map->insertTile(test);
    EXPECT_EQ(map->getCurrent(), test);
	delete test;
};
TEST(MapTest, MapmoveWest)
{
    Tile* test = new Tile("hi" ,1);
    Tile* left = new Tile("left" ,1);
	Map* map = new Map(test);
        test->setAdj(left, nullptr, nullptr, nullptr);
	map->insertTile(test);
	map->insertTile(left);
    EXPECT_TRUE(map->move('W'));
	delete map;
};
TEST(MapTest, MapmoveEast) {
    Tile* test = new Tile("hi" ,1);
    Tile* right = new Tile("right" ,1);
        test->setAdj(nullptr, right, nullptr, nullptr);
	Map* map = new Map(test);
	map->insertTile(test);
        map->insertTile(right);
    EXPECT_TRUE(map->move('E'));
	delete map;
};
TEST(MapTest, MapmoveSouth) {
    Tile* test = new Tile("hi" ,1);
    Tile* Bot = new Tile("Bot" ,1);
        test->setAdj(nullptr, nullptr, nullptr, Bot);
        Map* map = new Map(test);
        map->insertTile(test);
        map->insertTile(Bot);
    EXPECT_TRUE(map->move('S'));
        delete map;

};
TEST(MapTest, MapmoveNorth) {
    Tile* test = new Tile("hi" ,1);
    Tile* Top = new Tile("North" ,1);
        test->setAdj(nullptr, nullptr, Top, nullptr);
        Map* map = new Map(test);
        map->insertTile(test);
        map->insertTile(Top);
    EXPECT_TRUE(map->move('N'));
        delete map;

};
TEST(MapTest, Mapmoveintonullptr) {
    Tile* test = new Tile("hi" ,1);
    Tile* Top = new Tile("North" ,1);
        test->setAdj(nullptr, nullptr, Top, nullptr);
	Top->setAdj(nullptr, nullptr, nullptr, test);
        Map* map = new Map(test);
        map->insertTile(test);
        map->insertTile(Top);
	map->move('N');
	
    EXPECT_FALSE(map->move('N'));
        delete map;

};





#endif //_MAP__TEST_HPP__
