/* PlayList.h declares class PlayList.
    * Student Name: Ian G. Christensen (igc2)
    * Date: February 7, 2017
    * CS 112: lab01
    * Begun by: Joel Adams, for CS 112 at Calvin College.
    */

	#include "PlayList.h"
	#include <fstream>      // ifstream
	#include <cassert>      // assert()
	using namespace std;


   /* PlayList constructor
    * @param: fileName, a string
    * Precondition: fileName contains the name of a playlist file.
    */
   PlayList::PlayList(const string& fileName) {
	      // open a stream to the playlist file
	      ifstream fin( fileName.c_str() );
	      assert( fin.is_open() );

	      // read each song and append it to mySongs
	      Song s;
	      while (true) {
	          s.readFrom(fin);
	          if ( !fin ) { break; }
	          string separator;
	          getline(fin, separator);
	          mySongs.push_back(s);
	      }

	      // close the stream
	      fin.close();
   }

   /* Retrieve length of the playlist
    * Return: the number of songs in the playlist.
    */
   unsigned PlayList::getNumSongs() const {
	      return mySongs.size();
   }

   /* Search by artist
    * @param: artist, a string.
    * Return: a vector containing all the Songs in mySongs by artist.
    */
   vector<Song> PlayList::searchByArtist(const string& artist) const {
      vector<Song> v;

      for (unsigned i = 0; i < mySongs.size(); i++) {
         if ( mySongs[i].getArtist().find(artist) != string::npos ) {
            v.push_back( mySongs[i] );
         }
      }

      return v;
   }
