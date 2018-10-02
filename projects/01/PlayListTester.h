/* PlayListTester.h tests the PlayList class.
 * Student Name: Ian G. Christensen (igc2)
 * Date: February 12, 2017
 * Begun by: Joel Adams, for CS 112 proj01 at Calvin College.
 */

#ifndef PLAYLISTTESTER_
#define PLAYLISTTESTER_
#include "PlayList.h"

   class PlayListTester {
   public:
       void runTests();
       void testConstructors();
       void testSearchByArtist();
       void testSearchByYear();
       void testSearchByTitlePhrase();
       void testAddSong();
       void testRemoveSong();
       void testSaveSong();
       void testSave() const;
   };

   #endif /*PLAYLISTTESTER_*/
