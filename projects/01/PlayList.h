/* PlayList.h declares class PlayList.
 * Student Name: Ian G. Christensen (igc2)
 * Date: February 12, 2017
 * Begun by: Joel Adams, for CS 112 proj01 at Calvin College.
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
      vector<Song> searchByYear(unsigned year) const;
      vector<Song> searchByTitlePhrase(const string& phrase);
      void addSong(const Song& newSong);
      void removeSong(const Song& aSong);
      void save() const;
      unsigned getNumSongs() const;
   private:
      string myFileName;
      vector<Song> mySongs;
   };

   #endif /*PLAYLIST_H_*/
