//
// Created by dldms on 11/15/2018.
//

#include "springfield.hpp"

/**
 * Loop through the text file lien by line,
 * take the first word as name and store it in the map
 * and take the rest of the words in the line to
 * store in the string vector in the second part of the map.
 * @param fileName
 */
void Springfield::populateMap(string fileName) {
    ifstream ifile(fileName, ios::in);
    string temp;
    string line;
    if (!ifile.is_open()) {
        cerr << "There was a problem opening the input file!\n";
    }

    while (getline(ifile, line)) {
        istringstream iss(line);
        vector<string> v;
        string word = "";
        string name = "";
        int count = 0;
        while(iss >> word) {
            if (count == 0) {
                name = word;
            } else {
                v.push_back(word);}
            count++;
        }
        nameAndPlace.insert(make_pair(name, v));
    }
    cout<<"Everybody in the city"<<endl;
    sortedPrint(nameAndPlace);
}

/**
 * Compare the map elements only by names.
 * @param a
 * @param b
 * @return
 */
bool cmp(const pair<string, vector<string>>& a, const pair<string, vector<string>>& b)
{
    return a.first<b.first;
}

/**
 * Print any map with a string and a string object.
 * @param n map if string and string vector.
 */
void Springfield::sortedPrint(map<string, vector<string>> n) {
    map<string, vector<string>>::iterator it;
    //sort(n.begin(), n.end(), cmp);
    for (it = n.begin(); it != n.end(); it++)
    {
        cout<<(*it).first<<" : ";
        vector<string> a = (*it).second;
        sort(a.begin(), a.end());
        vector<string>::iterator i;
        for (i = a.begin(); i != a.end(); i++) {
            cout<<(*i)<<" ";
        }
        cout<<endl;
    }
}

/**
 * Only print the name of the passed in map.
 * @param n
 */
void Springfield::printName(map<string, vector<string>> n) {
    map<string, vector<string>>::iterator it;
    //sort(n.begin(), n.end(), cmp);
    for (it = n.begin(); it != n.end(); it++)
    {
        cout<<(*it).first<<endl;
    }
}

/**
 * Take the name of the place and the
 * vector of places from the map of people.
 * Return boolean whether the place is in the vector.
 * @param place
 * @param temp
 * @return ifvisited the place or not.
 */
bool Springfield::visited(string place, vector<string> temp) {
    vector<string>::iterator i;
    for (i = temp.begin(); i != temp.end(); i++) {
       if ((*i)==place) {
           return true;
       }
    }
    return false;
}

/**
 * Loop through the main map and list the people who visited both
 * Krusty burger and Tavern.
 */
void Springfield::bothKBandT() {
    map<string, vector<string>> bothKT;
    map<string, vector<string>>::iterator it;
    //sort(n.begin(), n.end(), cmp);
    for (it = nameAndPlace.begin(); it != nameAndPlace.end(); it++)
    {
        if (visited("Krusty-Burger", (*it).second) && visited("Tavern", (*it).second)) {
            bothKT.insert((*it));
        }
    }

    cout<<"\nVisited both Krusty-Burger and Tavern"<<endl;
    printName(bothKT);
}

/**
 * Print the list of people who didnt visit Krusty burger and home.
 */
void Springfield::noKBandHome() {
    map<string, vector<string>> bothKT;
    map<string, vector<string>>::iterator it;
    //sort(n.begin(), n.end(), cmp);
    for (it = nameAndPlace.begin(); it != nameAndPlace.end(); it++)
    {
        if (!visited("Krusty-Burger", (*it).second) && !visited("Home", (*it).second)) {
            bothKT.insert((*it));
        }
    }

    cout<<"\nDid NOT visit Krusty-Burger and Home"<<endl;
    printName(bothKT);
}

/**
 * List the people who visited Krusty burger and school but
 * Tavern and home.
 */
void Springfield::KBandSchoolNotTandH() {
    map<string, vector<string>> bothKT;
    map<string, vector<string>>::iterator it;
    for (it = nameAndPlace.begin(); it != nameAndPlace.end(); it++)
    {
        if (visited("Krusty-Burger", (*it).second) && visited("School", (*it).second)
            && !visited("Tavern", (*it).second)&& !visited("Home", (*it).second)) {
            bothKT.insert((*it));
        }
    }

    cout<<"\nVisited Krusty-Burger and School but did NOT visit Tavern and Home"<<endl;
    printName(bothKT);
}

/**
 * List the people who visited to all the places and remove them from the main
 * map.
 */
void Springfield::visitedAll() {
    map<string, vector<string>>::iterator it;
    map<string, vector<string>> bothKT;
    for (it = nameAndPlace.begin(); it != nameAndPlace.end(); it++)
    {
        if (visited("Krusty-Burger", (*it).second) && visited("School", (*it).second)
            && visited("Tavern", (*it).second)&& visited("Home", (*it).second)) {
            bothKT.insert(*it);
        }
    }
    cout<<"\nRemoving visited all locations"<<endl;
    printName(bothKT);


    it = nameAndPlace.begin();
    while (it != nameAndPlace.end()) {
        if (visited("Krusty-Burger", (*it).second) && visited("School", (*it).second)
            && visited("Tavern", (*it).second)&& visited("Home", (*it).second))
            it = nameAndPlace.erase(it);
        else
            it++;
    }
    cout<<"\nEverybody in the city after removing people who visited all locations"<<endl;
    printName(nameAndPlace);
}



