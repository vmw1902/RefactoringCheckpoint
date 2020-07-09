#include "GildedRose.h"
#include <map>
#include <string>
using namespace std;

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}

bool GildedRose::qualityDegradesNormally(Item item) {
    if (item.name == "Aged Brie" || item.name == "Backstage passes to a TAFKAL80ETC concert" || item.name == "Sulfuras, Hand of Ragnaros") {
        return false;
    }
    else {
        return true;
    }
}

bool GildedRose::isConcert(Item item) {
    return item.name == "Backstage passes to a TAFKAL80ETC concert";
}

bool GildedRose::isSulfuras(Item item) {
    return item.name == ("Sulfuras, Hand of Ragnaros");
}

bool GildedRose::isBrie(Item item) {
    return item.name == "Aged Brie";
}

bool GildedRose::pastSellByDate(Item item) {
    if (item.sellIn < 0) {
        return true;
    }
    else {
        return false;
    }
}

bool GildedRose::updateQuality() 
{
    for (Item item : items)
    {
        if (item.quality < 50 && item.quality > 0) {            
            if (qualityDegradesNormally(item))
            {
                item.quality--;
            }         
            else
            {
                item.quality++;
            }           
            if (pastSellByDate(item)) {
                item.quality--;
            }           
            else if (pastSellByDate(item) && isBrie(item)) {
                item.quality++;
            }           
            else if (pastSellByDate(item) && isConcert(item)) {
                item.quality = 0;
            }
            if (!isSulfuras(item))
            {
                item.sellIn = item.sellIn - 1;
            }
        }
    }
    return true;
}