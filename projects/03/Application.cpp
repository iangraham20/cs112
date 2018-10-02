/*
 * Application.cpp
 * Student Name: Ian Graham Christensen (igc2)
 * Date: February 21, 2017
 */

#include "Application.h"
#include "Vec.h"
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

void Application::runApplication() {
	vector<Vec> userVec;
	cout << "Welcome to the application\n" << endl;

	cout << "Please enter the number of dimensions for your vector" << endl;
	unsigned dimensions = 0;
	cin >> dimensions;
	if ( dimensions > 0 ) {
		cout << "Please enter the starting position of your vector" << endl;
		Vec start(dimensions);
		start.readFrom(cin);
		userVec.push_back(start);

		while (true) {
		cout << "Enter a movement vector: " << endl;
		Vec moveVec(dimensions);
		moveVec.readFrom(cin);
		userVec.push_back(moveVec);
		cout << "add another? [y/n]" << endl;
		char answer;
		cin >> answer;
		if ( answer != 'y' ) {
			break;
		}

		Vec finalLocation(dimensions);
		while ( userVec.size() > 0 ) {
			finalLocation = finalLocation + userVec.back();
			userVec.pop_back();
		}

		cout << "The final location is as follows: " << endl;
		finalLocation.writeTo(cout);
		}
	} else {
		cout << "A vector must have a range greater than zero." << endl;
		}
	cout << "\nProgram has been closed" << flush;
	}
