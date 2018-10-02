/* main file
 * Joel Adams, for CS 112, lab 9 at Calvin College.
 * Student Name: Ian Graham Christensen (igc2)
 * Date: April 18, 2017
 */

#include "BST_Tester.h"
#include "BSTapp.h"

int main() {
	BST_Tester bstt;
	bstt.runTests();
	BSTapp bstapp01("/home/cs/112/proj/09/randomInts01.txt");
	BSTapp bstapp02("/home/cs/112/proj/09/randomInts02.txt");
	BSTapp bstapp03("/home/cs/112/proj/09/randomInts03.txt");
	BSTapp bstapp04("/home/cs/112/proj/09/randomInts04.txt");
	BSTapp bstapp05("/home/cs/112/proj/09/randomInts05.txt");
	BSTapp bstapp06("/home/cs/112/proj/09/randomInts06.txt");
	BSTapp bstapp07("/home/cs/112/proj/09/randomInts07.txt");
	BSTapp bstapp08("/home/cs/112/proj/09/randomInts08.txt");
	BSTapp bstapp09("/home/cs/112/proj/09/randomInts09.txt");
	BSTapp bstapp10("/home/cs/112/proj/09/randomInts10.txt");
}
