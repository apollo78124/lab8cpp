//
// Created by dldms on 11/15/2018.
//
#include <map>
#include <iterator>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#ifndef LAB8_SPRINGFIELD_HPP
#define LAB8_SPRINGFIELD_HPP
using namespace std;
class Springfield {
private:
    /**
     * Contain everyone in the town.
     */
    map<string, vector<string>> nameAndPlace;

public:
    /**
     * Loop through the text file lien by line,
     * take the first word as name and store it in the map
     * and take the rest of the words in the line to
     * store in the string vector in the second part of the map.
     * @param fileName
     */
    void populateMap(string fileName);

    /**
     * Print any map with a string and a string object.
     * @param n map if string and string vector.
     */
    void sortedPrint(map<string, vector<string>> n);

    /**
     * Loop through the main map and list the people who visited both
     * Krusty burger and Tavern.
     */
    void bothKBandT();

    /**
     * Print the list of people who didnt visit Krusty burger and home.
     */
    void noKBandHome();

    /**
     * List the people who visited Krusty burger and school but
     * Tavern and home.
     */
    void KBandSchoolNotTandH();

    /**
     * List the people who visited to all the places and remove them from the main
     * map.
     */
    void visitedAll();

    /**
     * Take the name of the place and the
     * vector of places from the map of people.
     * Return boolean whether the place is in the vector.
     * @param place
     * @param temp
     * @return ifvisited the place or not.
     */
    bool visited(string place, vector<string> temp);

    /**
     * Only print the name of the passed in map.
     * @param n
     */
    void printName(map<string, vector<string>> n);

};
#endif //LAB8_SPRINGFIELD_HPP
