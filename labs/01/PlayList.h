/* PlayList.h declares class PlayList.
    * Student Name: Ian G. Christensen (igc2)
    * Date: February 7, 2017
    * CS 112: lab01
    * Begun by: Joel Adams, for CS 112 at Calvin College.
    */

	#ifndef PLAYLIST_H_
	#define PLAYLIST_H_

	#include "Song.h"
	#include <vector>   // STL vector
	#include <string>
	using namespace std;

   class PlayList {
   public:
      PlayList(const string& fileName);
      vector<Song> searchByArtist(const string& artist) const;
      unsigned getNumSongs() const;
   private:
      vector<Song> mySongs;
   };

   #endif /*PLAYLIST_H_*/
