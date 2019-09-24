/* PlayList.h declares class PlayList.
    * Student Name:Nana Osei Asiedu Yirenkyi
    * Date:Sept 16 2018
    * project01
    * Begun by: Joel Adams, for CS 112 at Calvin College.
    */

   #ifndef PLAYLIST_H_
   #define PLAYLIST_H_

   #include <string>
   #include "Song.h"
   #include <vector> // STL vector
   using namespace std;

   class PlayList {
   public:
      PlayList(const string& fileName);
      unsigned getNumSongs() const;
      vector<Song> searchByArtist(const string& artist) const;
      vector<Song> searchByYear(unsigned year);
      vector<Song> searchByTitlePhrase(const string& phrase);
      void addSong(const Song& newSong);
      void removeSong(const Song& aSong);
      void save() const;
   private:
      vector<Song> mySongs;
   };

   #endif /*PLAYLIST_H_*/
