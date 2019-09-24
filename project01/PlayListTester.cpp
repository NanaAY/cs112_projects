 /* PlayListTester.cpp defines the PlayList test-methods.
    * Student Name:Nana Osei Asiedu Yirenkyi
    * Date:Sept 16 2018
    * project01
    * Begun by: Joel Adams, for CS 112 at Calvin College.
    */

   #include "PlayListTester.h"
   #include "PlayList.h"
   #include <iostream>
   #include <cassert>
   using namespace std;

   void PlayListTester::runTests() {
      cout << "\nTesting class PlayList..." << endl;
      testConstructors();
      testSearchByArtist();
      testSearchByTitlePhrase();
      testaddSongRemoveSong();
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

   //Tester for searching by year
   void PlayListTester::testSearchByYear() {
	   cout << "- searchByYear()... " << flush;
	   // load a playlist with test songs
	   PlayList pList("testSongs.txt");

	   // empty case (0)
	   vector<Song> searchResult = pList.searchByYear(2015);
	   assert( searchResult.size() == 0 );
	   cout << " 0 " << flush;

	   //case 1
	   searchResult = pList.searchByYear(1967);
	   assert( searchResult.size() == 1 );
	   assert( searchResult[0].getTitle() == "Let It Be" );
	   cout << " 1 " << flush;

	   // case of 2
	   searchResult = pList.searchByYear(2012);
	   assert( searchResult.size() == 2 );
	   assert( searchResult[0].getTitle() == "Let It Be" );
	   assert( searchResult[1].getTitle() == "Call Me Maybe" );
	   cout << " 2 " << flush;


	   cout << " Passed!" << endl;

   }


   //Tester for searching by Title Phrase
   void PlayListTester::testSearchByTitlePhrase() {
	   cout << "- searchByTitlePhrase()... " << flush;
	   // load a playlist with test songs
	   PlayList pList("testSongs.txt");

	   // empty case (0)
	   vector<Song> searchResult = pList.searchByTitlePhrase("Cream");
	   assert(searchResult.size() == 0 );
	   cout << " 0 " << flush;

	   // case of 1
	   searchResult = pList.searchByTitlePhrase("Let It");
	   assert(searchResult.size() == 2 );
	   assert(searchResult[0].getTitle() == "Let It Be");
	   cout << " 1 " << flush;

	   // case of 2
	   searchResult = pList.searchByTitlePhrase("Call Me");
	   assert(searchResult.size() == 1 );
	   assert(searchResult[0].getTitle() == "Call Me Maybe");
	   cout << " 2 " << flush;

	   cout << " Passed!" << endl;


   }

   //Tester for adding Song
   void PlayListTester::testaddSongRemoveSong() {
	   cout << "- addSong()... " << flush;
	   // load a playlist with test songs
	   PlayList pList("testSongs.txt");

	   //adding a song
	   Song newSong("Sanufa", "Bas", 2018);
	   pList.addSong(newSong);
	   vector<Song> searchResult = pList.searchByArtist("Bas");
	   assert( searchResult[0].getTitle() == "Sanufa" );
	   cout << " 0 " << flush;

	   //removing song
	   Song Songtoremove("Sanufa", "Bas", 2018);
	   pList.removeSong(Songtoremove);
	   searchResult = pList.searchByArtist("Bas");
	   assert(searchResult.size() == 0);
	   cout << " 1 " << flush;

	   cout << " Passed!" << endl;

   }


   //Tester for Saving Songs
   void PlayListTester::testSave() const {
	   cout << "- Save()... " << flush;

	   // load a playlist that is to be changed
	   PlayList pList("testSongs.txt");

	   //add a song to cause a change in the original playList
	   Song s1("Sanufa", "Bas", 2018);
	   pList.addSong(s1);
	   cout << " 0 " << flush;

	   // write the modified playList back into the original file
	   pList.save();
	   cout << " 1 " << flush;

	   // load the saved file under new file name and test for the added song
	   //PlayList pList2("testSongs.txt");
	   vector<Song> searchResult = pList.searchByArtist("Bas");
	   assert(searchResult.size() == 1);
	   cout << " 2 " << flush;

	   //return the playList to its original
	   pList.removeSong(s1);
	   pList.save();
	   cout << " 3 " << flush;

	   // check that the song has been removed
	   searchResult = pList.searchByArtist("Bas");
	   assert(searchResult.size() == 0);
	   cout << " 4 " << flush;

	   cout << " Passed!" << endl;

   }

