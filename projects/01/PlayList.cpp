/* PlayList.h declares class PlayList.
 * Student Name: Ian G. Christensen (igc2)
 * Date: February 12, 2017
 * Begun by: Joel Adams, for CS 112 proj01 at Calvin College.
 */

#include "PlayList.h"
#include "Song.h"
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

	      myFileName = fileName;

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

   /* Search by year
    * @param: year, a string.
    * Return: a vector containing all the Songs in mySongs by year.
    */
   vector<Song> PlayList::searchByYear(unsigned year) const {
	   vector<Song> v;

	   for (unsigned i = 0; i < mySongs.size(); i++) {
		   if ( mySongs[i].getYear() == year ) {
			   v.push_back( mySongs[i] );
		   }
	   }
	   return v;
   }

   /* Search by title phrase
    * @param: phrase, a string.
    * Return: a vector containing all the Songs in mySongs by phrase.
    */
   vector<Song> PlayList::searchByTitlePhrase(const string& phrase) {
	   vector<Song> v;
		for (unsigned i = 0; i < mySongs.size(); i++) {
			if ( mySongs[i].getTitle().find(phrase) != string::npos ) {
				v.push_back( mySongs[i] );
		   }
	   }
	   return v;
   }

   /* Add a song to the playlist
    * @param: Song, a string.
    */
   void PlayList::addSong(const Song& newSong) {
	   mySongs.push_back(newSong);
   }

   /* Remove a song from the playlist
    * @param: Song, a string.
    * Precondition: song must exist in playlist.
    */
   void PlayList::removeSong(const Song& aSong) {
	   for ( unsigned i=0; i < mySongs.size(); i++ ) {
		   if ( aSong == mySongs[i] )
			   mySongs.erase( mySongs.begin() + i);
	   }
   }

   void PlayList::save() const {
	   ofstream fout ( myFileName.c_str() );
	   assert( fout.is_open() );
	   for ( unsigned i=0; i < mySongs.size(); i++ ) {
		   mySongs[i].writeTo(fout);
		   fout << "\n";
	   }
	   fout.close();
   }
