/* main.cpp is the driver for a Conga line simulation.
 * Based on an exercise by Marc LeBlanc from Wheaton College (MS).
 * @author: Joel Adams, for CS 112 project 6at Calvin College.
 * Student name: Ian Graham Christensen (igc2)
 * Date: March 27, 2017
 */

#include "CongaLine.h"
#include "ListTester.h"

int main() {
	ListTester lt;
	lt.runTests();
	CongaLine dance("Ann", "Bob");
	dance.run();
}
