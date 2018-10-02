/* ListTester.h declares the test-class for class List.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * 3/11/17
 * Additional Tests by:
 *  Carolyn Lindemulder: ==, readFrom(istream), writeTo(string), prepend, insert
 *  Ian Christensen: !=, writeTo(ostream), readFrom(string), getIndexOf, remove
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testReadFromStream();
	void testWriteToFile();
	void testPrepend();
	void testInsert();
	void testInequality();
	void testWriteToStream();
	void testReadFromString();
	void testGetIndexOf();
	void testRemove();
	void testInsertAfter();
	void testInsertBefore();
	void testOutput();
};

#endif /*LISTTESTER_H_*/
