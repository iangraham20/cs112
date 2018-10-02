/* PlayListTester.cpp defines the PlayList test-methods.
 * Student Name: Ian G. Christensen (igc2)
 * Date: February 12, 2017
 * Begun by: Joel Adams, for CS 112 proj01 at Calvin College.
 */

#include "PlayListTester.h"
#include "PlayList.h"
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

void PlayListTester::runTests() {
  cout << "\nTesting class PlayList..." << endl;
  testConstructors();
  testSearchByArtist();
  testSearchByYear();
  testSearchByTitlePhrase();
  testAddSong();
  testRemoveSong();
  testSave();
  cout << "All tests passed!" << endl;
}

void PlayListTester::testConstructors() {
  cout << "- constructors..." << flush;
  PlayList pList("testSongs.txt");
  assert( pList.getNumSongs() == 4 );
  cout << " 0 " << flush;

  cout << " Passed!" << endl;
}

void PlayListTester::testSearchByArtist() {
  cout << "- searchByArtist()... " << flush;
  // load a playlist with test songs
  PlayList pList("testSongs.txt");

  // empty case (0)
  vector<Song> searchResult = pList.searchByArtist("Cream");
  assert( searchResult.size() == 0 );
  cout << " 0 " << flush;

  // case of 1
  searchResult = pList.searchByArtist("Baez");
  assert( searchResult.size() == 1 );
  assert( searchResult[0].getTitle() == "Let It Be" );
  cout << " 1 " << flush;

  // case of 2
  searchResult = pList.searchByArtist("Beatles");
  assert( searchResult.size() == 2 );
  assert( searchResult[0].getTitle() == "Let It Be" );
  assert( searchResult[1].getTitle() == "Penny Lane" );
  cout << " 2 " << flush;

  cout << " Passed!" << endl;
}

void PlayListTester::testSearchByYear() {
	cout << "- searchByYear()... " << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");

	// empty case (0)
	vector<Song> searchResult = pList.searchByYear(2015);
	assert( searchResult.size() == 0 );
	cout << " 0 " << flush;

	// case of 1
	searchResult = pList.searchByYear(2012);
	assert( searchResult.size() == 1 );
	assert( searchResult[0].getTitle() == "Call Me Maybe" );
	cout << " 1 " << flush;

	// case of 2
	searchResult = pList.searchByYear(1967);
	assert( searchResult.size() == 2 );
	assert( searchResult[0].getTitle() == "Let It Be" );
	assert( searchResult[1].getTitle() == "Penny Lane" );
	cout << " 2 " << flush;

	cout << " Passed!" << endl;
   }

void PlayListTester::testSearchByTitlePhrase() {
	cout << "- searchByTitlePhrase()... " << flush;
	// load a playlist with test songs
	PlayList pList("testSongs.txt");

	// empty case (0)
	vector<Song> searchResult = pList.searchByTitlePhrase("Gibberish");
	assert( searchResult.size() == 0 );
	cout << " 0 " << flush;

	// case of 1
	searchResult = pList.searchByTitlePhrase("It Be");
	assert( searchResult.size() == 2);
	assert( searchResult[0].getTitle() == "Let It Be");
	assert( searchResult[1].getTitle() == "Let It Be");
	cout << " 1 " << flush;

	// case of 2
	searchResult = pList.searchByTitlePhrase("e");
	assert( searchResult.size() == 4 );
	assert( searchResult[0].getTitle() == "Call Me Maybe");
	assert( searchResult[1].getTitle() == "Let It Be" );
	assert( searchResult[2].getTitle() == "Let It Be" );
	assert( searchResult[3].getTitle() == "Penny Lane" );
	cout << " 2 " << flush;

	cout << " Passed!" << endl;
}

void PlayListTester::testAddSong() {
	cout << "- AddSong()... " << flush;

	// load a playlist with test songs
	PlayList pList("testSongs.txt");
	assert( pList.getNumSongs() == 4 );

	// add song to playlist
	Song s1("Be My Escape", "Relient K", 2014);
	pList.addSong(s1);

	// test for playlist length and added song
	assert( pList.getNumSongs() == 5 );
	vector<Song> searchResult = pList.searchByTitlePhrase("Be My Escape");
	assert( searchResult.size() == 1 );
	cout << " 0 " << flush;
	cout << " Passed!" << endl;
}

void PlayListTester::testRemoveSong() {
	cout << "- RemoveSong()... " << flush;
	PlayList pList("testSongs.txt");
	assert( pList.getNumSongs() == 4 );

	Song s1("Be My Escape", "Relient K", 2014);
	pList.addSong(s1);

	assert( pList.getNumSongs() == 5 );
	vector<Song> searchResult = pList.searchByTitlePhrase("Be My Escape");
	assert(searchResult.size() == 1);

	pList.removeSong(s1);
	assert( pList.getNumSongs() == 4 );
	searchResult = pList.searchByTitlePhrase("Be My Escape");
	assert(searchResult.size() == 0);
	cout << " 0 " << flush;
	cout << " Passed!" << endl;
}

void PlayListTester::testSave() const {
   cout << "- Save()... " << flush;
   PlayList pList("TestSavePlaylist.txt");

   // Add Songs
   Song s1("TestTitle1", "TestArtist1", 2001);
   pList.addSong(s1);
   Song s2("TestTitle2", "TestArtist2", 2002);
   pList.addSong(s2);
   Song s3("TestTitle3", "TestArtist3", 2003);
   pList.addSong(s3);

   pList.save();

   // read test
   ifstream fin("TestSavePlaylist.txt");
   assert( fin.is_open() );
   Song s4, s5, s6;

   // read and test next song
   s4.readFrom(fin);
   assert( s4.getTitle() == "TestTitle1" );
   assert( s4.getArtist() == "TestArtist1" );
   assert( s4.getYear() == 2001 );
   cout << " 0 " << flush;
   string separator;
   getline(fin, separator);

   // read and test next song
   s5.readFrom(fin);
   assert( s5.getTitle() == "TestTitle2" );
   assert( s5.getArtist() == "TestArtist2" );
   assert( s5.getYear() == 2002 );
   cout << " 1 " << flush;
   getline(fin, separator);
   cout << " Passed!" << endl;

}
