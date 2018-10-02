/* main.cpp tests the classes in our project.
 * Student Name: Ian G. Christensen (igc2)
 * Date: February 12, 2017
 * Begun by: Joel Adams, for CS 112 proj01 at Calvin College.
 */

#include "SongTester.h"
#include "PlayListTester.h"
#include "UserInterface.h"

int main() {
   SongTester sTester;
   sTester.runTests();
   PlayListTester plTester;
   plTester.runTests();
   UserInterface();
}
