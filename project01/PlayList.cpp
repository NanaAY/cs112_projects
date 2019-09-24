/* PlayList.cpp defines the PlayList methods.
    *Student Name:Nana Osei Asiedu Yirenkyi
    * Date:Sept 16 2018
    * project01
    * Begun by: Joel Adams, for CS 112 at Calvin College.
    */

   #include "PlayList.h"
   #include <fstream>      // ifstream
   #include <cassert>      // assert()
   #include <vector>
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
      string separator;
      while (true) {
          s.readFrom(fin);
          if ( !fin ) { break; }
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



/* Search by year
  * @param: year, a positve integer.
  * Return: a vector containing all the Songs in mySongs by year.
  */

   vector<Song> PlayList::searchByYear(unsigned year) {
	   vector<Song> v;
	   for (unsigned i = 0; i < mySongs.size(); i++) {
		   if ( mySongs[i].getYear() == year) {
			   v.push_back( mySongs[i] );
		   }
	   }
	   return v;
   }



/* searchByTitlePhrase() searches the PlayList for Songs by a given title phrase.
	* @param: phrase, a string within a title of the song
	* @return: a vector containing all Songs in the playList
	*           for whom title phrase is a substring of myTitle.
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



/* addSong() adds a new song in the playList for Songs by asking for user input.
	*
	* @param: newSong, a string containing a separate Song object created through user input.
	* @return: this does not return anything but appends the newSong class in the memory.
	*/
   void PlayList::addSong(const Song& newSong) {
	   mySongs.push_back(newSong);

   }


/* removeSong() removes a song from the PlayList of songs through user input information.
	* @param: aSong, a string containing an already Song object found through user input information.
	* @return: this does not return a vector but removes a Song object from the PlayList of songs.
	*/

   void PlayList::removeSong(const Song& aSong) {
	   vector<Song>::iterator i = mySongs.begin();
	   while (i != mySongs.end()) {
		   if ( i -> getTitle() == aSong.getTitle() ) {
		   i = mySongs.erase(i);
	   }
	   else { ++i;}
	   }
   }



/* save() saves and writes the Song object created through user input (newSong) into the PlayList for Songs.
	*
	* @param: this method has no parameters
	* @return: this method does not return but writes the appended Songs objected into the testSongs.txt file.
	*/

   void PlayList::save() const {
	   ofstream fileout("testSongs.txt");
	   for ( unsigned i = 0; i < mySongs.size(); ++i) {
		   mySongs[i].writeTo(fileout);
		   fileout << "\n";
	   }
	   fileout.close();

   }
