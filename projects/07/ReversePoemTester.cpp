/* ReversePoemTester.cpp defines test-methods for the reverse poem class
 * Ian Christensen, for CS 112 project 7 at Calvin College.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: April 3, 2017
 */

#include "ReversePoem.h" 		// class being tested
#include "ReversePoemTester.h"	// file header
#include <iostream> 			// cout, cerr, ...
#include <cassert> 				// assert()
#include <cstdlib> 				// exit()
#include <stdexcept>			//
using namespace std;

void ReversePoemTester::runTests() {
	cout << "Testing ReversePoem class..." << endl;
	testConstructor();
	testGetTitle();
	testGetAuthor();
	testGetBody();
	testGetBodyReversed();
	cout << "All tests passed!" << endl;
}

void ReversePoemTester::testConstructor() {
	cout << "- Testing constructor... " << flush;
	// valid filename
	ReversePoem rp1("poems/cats.txt");
	cout << " 0 " << flush;
	cout << " Passed!" << endl;
}

void ReversePoemTester::testGetTitle() {
	cout << "- Testing getTitle... " << flush;
	// short poem
	ReversePoem rp0("poems/cats.txt");
	assert( rp0.getTitle() == "Cats" );
	cout << " 0 " << flush;
	// medium poem
	ReversePoem rp1("poems/anorexia.txt");
	assert( rp1.getTitle() == "Anorexia" );
	cout << " 1 " << flush;
	// long poem
	ReversePoem rp2("poems/theKiss.txt");
	assert( rp2.getTitle() == "The Kiss" );
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

void ReversePoemTester::testGetAuthor() {
	cout << "- Testing getAuthor... " << flush;
	// short poem
	ReversePoem rp0("poems/cats.txt");
	assert( rp0.getAuthor() == "Leo J. Smada" );
	cout << " 0 " << flush;
	// medium poem
	ReversePoem rp1("poems/anorexia.txt");
	assert( rp1.getAuthor() == "Anonymous" );
	cout << " 1 " << flush;
	// long poem
	ReversePoem rp2("poems/theKiss.txt");
	assert( rp2.getAuthor() == "R. Lamoureux" );
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

void ReversePoemTester::testGetBody() {
	cout << "- Testing getBody... " << flush;
	// short poem
	ReversePoem rp0("poems/cats.txt");
	assert( rp0.getBody() == "I love it when cats rub against me.\n"
							 "I could never say\n"
							 "I hate those purring felines.\n" );
	cout << " 0 " << flush;
	// medium poem
	ReversePoem rp1("poems/anorexia.txt");
	assert( rp1.getBody() == "I hate the girl in the mirror\n"
							 "so you'll never hear me say that\n"
							 "I'm good enough\n"
							 "I know in my heart that\n"
							 "the number on the scale defines my worth\n"
							 "and that\n"
							 "being thin will make me happy\n"
							 "I refuse to believe that there is hope\n"
							 "I'm ashamed of my body\n"
							 "No longer can I say\n"
							 "I am worth fighting for.\n" );
	cout << " 1 " << flush;
	// long poem
	ReversePoem rp2("poems/theKiss.txt");
	assert( rp2.getBody() == "When you kissed me\n"
							 "A fool fell in love\n"
							 "I became weak in the knees\n"
							 "The world revolved around your halo\n"
							 "Angel eyes captured my imagination\n"
							 "Like Einstein I discovered relativity\n"
							 "Wisdom had been my lonely pathway\n"
							 "Drunk on independent thought\n"
							 "Wondering if those lips would part for me\n"
							 "Wanting to breathe your breath\n"
							 "Gazing longingly\n"
							 "I looked towards you\n"
							 "So quickly\n"
							 "You looked away\n"
							 "my heart sank\n"
							 "When you kissed another boy\n" );
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

void ReversePoemTester::testGetBodyReversed() {
	cout << "- Testing getBodyReversed... " << flush;
	// short poem
	ReversePoem rp0("poems/cats.txt");
	assert( rp0.getBodyReversed() == "I hate those purring felines.\n"
									 "I could never say\n"
									 "I love it when cats rub against me.\n" );
	cout << " 0 " << flush;
	// medium poem
	ReversePoem rp1("poems/anorexia.txt");
	assert( rp1.getBodyReversed() == "I am worth fighting for.\n"
									 "No longer can I say\n"
									 "I'm ashamed of my body\n"
									 "I refuse to believe that there is hope\n"
									 "being thin will make me happy\n"
									 "and that\n"
									 "the number on the scale defines my worth\n"
									 "I know in my heart that\n"
									 "I'm good enough\n"
									 "so you'll never hear me say that\n"
									 "I hate the girl in the mirror\n" );
	cout << " 1 " << flush;
	// long poem
	ReversePoem rp2("poems/theKiss.txt");
	assert( rp2.getBodyReversed() == "When you kissed another boy\n"
									 "my heart sank\n"
									 "You looked away\n"
									 "So quickly\n"
									 "I looked towards you\n"
									 "Gazing longingly\n"
									 "Wanting to breathe your breath\n"
									 "Wondering if those lips would part for me\n"
									 "Drunk on independent thought\n"
									 "Wisdom had been my lonely pathway\n"
									 "Like Einstein I discovered relativity\n"
									 "Angel eyes captured my imagination\n"
									 "The world revolved around your halo\n"
									 "I became weak in the knees\n"
									 "A fool fell in love\n"
									 "When you kissed me\n" );
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}
