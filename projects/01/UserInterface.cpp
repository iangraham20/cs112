/* UserInterface.cpp
 * Student Name: Ian G. Christensen (igc2)
 * Date: February 12, 2017
 * Begun by: Joel Adams, for CS 112 proj01 at Calvin College.
 */

#include "UserInterface.h"
#include "PlayList.h"
#include "Song.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

/* UserInterface constructor
 */

UserInterface::UserInterface() {
	PlayList pList("testSongs.txt");
	int menuSelection = -1;
	while ( true ) {
		menuSelection = -1;
		cout << "\nWelcome to the PlayList Manager!\n"
				"\nPlease enter:\n"
				"1 - to search the playlist for songs by a given artist\n"
				"2 - to search the playlist for songs from a given year\n"
				"3 - to search the playlist for songs with a given phrase in their title\n"
				"4 - to add a new song to the playlist\n"
				"5 - to remove a song from a playlist\n"
				"6 - to save a playlist\n"
				// ... other options ...
				"0 - to quit\n"
				"--->\n" << flush;


		cin >> menuSelection;

		// searchByArtist
		if ( menuSelection == 1 ) {
			cout << "Please enter an artist:\n" << flush;
			string artist;
			cin >> artist;
			string temp;
			cin >> temp;
			cout << "\nThe playlist contains the following songs from the given artist:\n" << flush;

			vector<Song> searchResults = pList.searchByArtist(artist);
			for ( unsigned i=0; i < searchResults.size(); i++ ) {
				searchResults[i].writeTo(cout);
			}
		}

		// searchByYear
		else if ( menuSelection == 2 ) {
			cout << "Please enter a year:\n" << flush;
			unsigned year;
			cin >> year;
			cout << "\nThe playlist contains the following songs the given year:\n" << flush;

			vector<Song> searchResults = pList.searchByYear(year);
			for ( unsigned i=0; i < searchResults.size(); i++ ) {
				searchResults[i].writeTo(cout);
			}
		}

		// searchByTitlePhrase
		else if ( menuSelection == 3 ) {
			cout << "Please enter a phrase:\n" << flush;
			string phrase;
			cin >> phrase;
			string temp;
			cin >> temp;
			cout << "\nThe playlist contains the following songs with the given phrase:\n" << flush;

			vector<Song> searchResults = pList.searchByTitlePhrase(phrase);
			for ( unsigned i=0; i < searchResults.size(); i++ ) {
				searchResults[i].writeTo(cout);
			}
		}

		// addSong
		else if ( menuSelection == 4 ) {

			string title;
			string artist;
			string yearString;
			cout << "Please enter a song title:\n" << flush;
			getline( cin, title );
			getline( cin, title );
			cout << "Please enter an artist name:\n" << flush;
			getline( cin, artist );
			cout << "Please enter a year:\n" << flush;
			getline( cin, yearString );
			unsigned year = atoi( yearString.c_str() );
			Song s( title, artist, year );

			pList.addSong(s);
			cout << "The song was added to the playlist" << endl;
		}

		// removeSong
		else if ( menuSelection == 5 ) {

			string title;
			string artist;
			string yearString;

			cout << "Please enter a song title:\n" << flush;
			getline( cin, title );
			getline( cin, title );
			cout << "Please enter an artist name:\n" << flush;
			getline( cin, artist );
			cout << "Please enter a year:\n" << flush;
			getline( cin, yearString );
			unsigned year = atoi(yearString.c_str());
			Song input(title, artist, year);

			pList.removeSong( input );
			cout << "The song was added to the playlist." << endl;
		}

		// SavePlaylist
		else if ( menuSelection == 6 ) {
			pList.save();
			cout << "\nSaved" << endl;
		}

		// QuitProgram
		else if ( menuSelection == 0 ) {
			cout << "\nQuiting...";
			break;
		}
	}
}

