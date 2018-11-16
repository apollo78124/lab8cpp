#include <iostream>
#include "springfield.hpp"

/**
 * Runs all the methods.
 * @return
 */
int main() {
    Springfield s;
    s.populateMap("../peoplePlaces.txt");
    s.bothKBandT();
    s.noKBandHome();
    s.KBandSchoolNotTandH();
    s.visitedAll();
    return 0;
}