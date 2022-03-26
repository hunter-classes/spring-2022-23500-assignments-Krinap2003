#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    bool foundSpellBook, foundPotion, foundWand = false;

    for(int i = 0; i < moves.length(); i++){

        if(start->whatsHere == Item::SPELLBOOK){
            foundSpellBook = true;
        }
        if(start->whatsHere == Item::POTION){
            foundPotion = true;
        }
        if(start->whatsHere == Item::WAND){
            foundWand = true;
        }

        if(moves.at(i) == 'N'){
            if(start->north == nullptr){
                return false;
            }
            start = start->north;
        }
        else if(moves.at(i) == 'E'){
            if(start->east == nullptr){
                return false;
            }
            start = start->east;
        }else if(moves.at(i) == 'S'){
            if(start->south == nullptr){
                return false;
            }
            start = start->south;
        }
        else if(moves.at(i) == 'W'){
            if(start->west == nullptr){
                return false;
            }
            start = start->west;
        }

        if(start->whatsHere == Item::SPELLBOOK){
            foundSpellBook = true;
        }
        if(start->whatsHere == Item::POTION){
            foundPotion = true;
        }
        if(start->whatsHere == Item::WAND){
            foundWand = true;
        }

        if(foundPotion && foundSpellBook && foundWand)
        {
            return true;
        }


    }
    if(foundPotion && foundSpellBook && foundWand)
    {
            return true;
    }
    return false;
}
