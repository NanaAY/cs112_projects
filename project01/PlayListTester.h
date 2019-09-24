/* PlayListTester.h tests the PlayList class.
    * Student Name:Nana Osei Asiedu Yirenkyi
    * Date:Sept 16 2018
    * project01
    * Begun by: Joel Adams, for CS 112 at Calvin College.
    */

   #ifndef PLAYLISTTESTER_
   #define PLAYLISTTESTER_

   class PlayListTester {
   public:
       void runTests();
       void testConstructors();
       void testSearchByArtist();
       void testSearchByYear();
       void testSearchByTitlePhrase();
       void testaddSongRemoveSong();
       void testSave() const;
   };

   #endif /*PLAYLISTTESTER_*/
