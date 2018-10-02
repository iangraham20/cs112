/* ReversePoemTester.h declares a test-class for the reverse poem class
 * Ian Christensen, for CS 112 project 7 at Calvin College.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: April 3, 2017
 */

#ifndef REVERSEPOEMTESTER_H_
#define REVERSEPOEMTESTER_H_

class ReversePoemTester {
public:
	void runTests();
	void testConstructor();
	void testGetTitle();
	void testGetAuthor();
	void testGetBody();
	void testGetBodyReversed();
};

#endif /* REVERSEPOEMTESTER_H_ */
