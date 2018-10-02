/* CongaLine.h declares class CongaLine, a Conga line dance simulation.
 * Based on an exercise by Marc LeBlanc from Wheaton College (MS).
 * @author: Joel Adams, for CS 112 project 6at Calvin College.
 * Student name: Ian Graham Christensen (igc2)
 * Date: March 27, 2017
 */


#ifndef CONGALINE_H_
#define CONGALINE_H_

#include "List.h"
#include <string>
using namespace std;

class CongaLine {
public:
	CongaLine(const string& person1, const string& person2);
	void run();

private:
	List<string> myLine;

	string MY_MENU;
	string myFirstPerson;
	string mySecondPerson;
};

#endif /* CONGALINE_H_ */
