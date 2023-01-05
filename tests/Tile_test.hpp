#ifndef __TILE_TEST_HPP__
#define __TILE_TEST_HPP__

#include "gtest/gtest.h"

#include "../header/Map/Tile.hpp"

TEST(TileTest, Tiledescription) {
    Tile* test = new Tile("hi" ,1);
    EXPECT_EQ(test->getdescription(), "hi");
	delete test;
}
TEST(TileTest, TilesetAdjTop) {
    Tile* test = new Tile("hi" ,1);
    Tile* Top = new Tile("top" ,1);
	test->setAdj(nullptr, nullptr, Top, nullptr);
    EXPECT_EQ(test->getNext('3'),Top );
        delete test;
	delete Top;
}
TEST(TileTest, TilesetAdjleft) {
    Tile* test = new Tile("hi" ,1);
    Tile* left = new Tile("left" ,1);
        test->setAdj(left, nullptr, nullptr, nullptr);
    EXPECT_EQ(test->getNext('1'),left );
        delete test;
	delete left;
}
TEST(TileTest, TilesetAdjright) {
    Tile* test = new Tile("hi" ,1);
    Tile* right = new Tile("right" ,1);
        test->setAdj(nullptr, right, nullptr, nullptr);
    EXPECT_EQ(test->getNext('2'),right );
        delete test;
	delete right;
}
TEST(TileTest, TilesetAdjBot) {
    Tile* test = new Tile("hi" ,1);
    Tile* Bot = new Tile("Bot" ,1);
        test->setAdj(nullptr, nullptr, nullptr, Bot);
    EXPECT_EQ(test->getNext('4'),Bot );
        delete test;
	delete Bot;
}



#endif //_Tile__TEST_HPP__
