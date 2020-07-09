#include <string>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <map>
#include "GildedRose.h"

TEST(gildedRoseComponents, isBrie) {
    vector<Item> items;
    Item item = Item("Aged Brie", 10, 30);

    items.push_back(item);
    GildedRose app(items);

    EXPECT_EQ(app.isBrie(item), true);
}

TEST(gildedRoseComponents, isConcert) {
    vector<Item> items;
    Item item = Item("Backstage passes to a TAFKAL80ETC concert", 10, 30);

    items.push_back(item);
    GildedRose app(items);

    EXPECT_EQ(app.isConcert(item), true);
}

TEST(gildedRoseComponents, isSulfuras) {
    vector<Item> items;
    Item item = Item("Sulfuras, Hand of Ragnaros", 10, 30);

    items.push_back(item);
    GildedRose app(items);

    EXPECT_EQ(app.isSulfuras(item), true);
}

TEST(gildedRoseComponents, regularDegradeBrie) {
    vector<Item> items;
    Item item = Item("Aged Brie", 10, 30);

    items.push_back(item);
    GildedRose app(items);
    
    EXPECT_EQ(app.qualityDegradesNormally(item),false);
}

TEST(gildedRoseComponents, regularDegradeConcert) {
    vector<Item> items;
    Item item = Item("Backstage passes to a TAFKAL80ETC concert", 10, 30);
    
    items.push_back(item);
    GildedRose app(items);

    EXPECT_EQ(app.qualityDegradesNormally(item), false);
}

TEST(gildedRoseComponents, regularDegradeSulfuras) {
    vector<Item> items;
    Item item = Item("Sulfuras, Hand of Ragnaros", 10, 30);

    items.push_back(item);
    GildedRose app(items);

    EXPECT_EQ(app.qualityDegradesNormally(item), false);
}

TEST(gildedRoseComponents, regularDegradeCustomItem) {
    vector<Item> items;
    Item item = Item("Foo", 10, 30);

    items.push_back(item);
    GildedRose app(items);

    EXPECT_EQ(app.qualityDegradesNormally(item), true);
}

TEST(gildedRoseComponents, sellByDateExpired) {
    vector<Item> items;
    Item item = Item("Item", -3, 30);

    items.push_back(item);
    GildedRose app(items);

    EXPECT_EQ(app.pastSellByDate(item), true);
}

TEST(gildedRoseComponents, sellByDateStillGood) {
    vector<Item> items;
    Item item = Item("Item", 20, 30);

    items.push_back(item);
    GildedRose app(items);

    EXPECT_EQ(app.pastSellByDate(item), false);
}

TEST(gildedRoseComponents, updateQualityTest) {
    vector<Item> items;
    Item item = Item("Item", 20, 30);

    items.push_back(item);
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(app.updateQuality(), true);
}

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
