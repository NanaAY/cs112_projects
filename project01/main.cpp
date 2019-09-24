/* main.cpp tests the classes in our project.
    * Student Name:Nana Osei Asiedu Yirenkyi
    * Date: Sept 11 2018
    * project01
    * Begun by: Joel Adams, for CS 112 at Calvin College.
    */

   #include "SongTester.h"
   #include "PlayListTester.h"
   #include "SongTester.h"
   #include "PlayList.h"
   #include "Song.h"
   #include "Application.h"
   #include <iostream>
   using namespace std;

   int main() {
       SongTester sTester;
       sTester.runTests();
       PlayListTester plTester;
       plTester.runTests();
//       Application();



		cout << "\nWelcome to the PlayList Manager!\n"<< endl;
       	    while ( true ) {
       	    	cout << "\n"
       	    			<< "Please enter an option: " << "\n"
       					<< "1 - to search the PlayList for songs by a given artist\n"
       					<< "2 - to search the PlayList for songs from a given year\n"
       					<< "3 - to search the PlayList for songs with a given phrase in their title\n"
       					<< "4 - to add a new song to the PlayList" << "\n"
       					<< "5 - to remove a song to the PlayList" << "\n"
       					<< "0 - to quit" << endl;
       	       	unsigned choice;
       	    	cin >> choice;
       	    	PlayList pList("testSongs.txt");

       	    	if (choice == 0) {
       				cout << "\nEnding...";
       				break;
       	    		    	}
       	    	else if ( choice == 1) {
       	    		string artist;
       	    		cout << "Please enter name of artist: " << endl;
       	    		cin >> artist;
       	    		vector<Song> v1 = pList.searchByArtist(artist);
       	    		for(unsigned i = 0; i < v1.size(); i++) {
       	    			cout << v1[i].getTitle() << '\n' << v1[i].getYear() << '\n' << endl;
       	    		}
       	    	}


       	    	else if(choice == 2) {
       	    		unsigned year;
       	    		cout << "Please enter the year: " << endl;
       	    		cin >> year;
       	    		vector<Song> v1 = pList.searchByYear(year);
       	    		for(unsigned i = 0; i < v1.size(); i++) {
       	    			cout << v1[i].getTitle() << '\n' << v1[i].getArtist()<< '\n' << endl;
       	    		}
       	    	}
       	    	else if(choice == 3){
       	    		string phrase;
       	    		cout << "Please enter a phrase from the title of the Song: " << endl;
       	    		cin >> phrase;
       	    		vector<Song> v1 = pList.searchByTitlePhrase(phrase);
       	    		for(unsigned i = 0; i < v1.size(); i++) {
       	    			cout << v1[i].getTitle() << '\n' << v1[i].getYear()<< '\n' << endl;
       	    		}
       	    	}
       	    	else if (choice == 4){
       	    		string title;
       	    		unsigned year;
       	    		string artist;
       	    		cin.ignore(256, '\n');
       	    		cout << "Please enter title: " << endl;
       	    		cin >> title;
       	    		cout << "Please enter year: " << endl;
       	    		cin.ignore(256, '\n');
       	    		cin >> year;
       	    		cout << "Please enter name of the artist: " << endl;
       	    		cin >> artist;
       	    		cin.ignore(256, '\n');
       	    		pList.addSong(Song(title, artist, year));
       	    		unsigned save;
       	    		cout << "Do you want to Save? Enter 9." << endl;
       	    		cin >> save;
       	    		if (save == 9) {
       	    			pList.save();
       	    			cout << "saved" << endl;
       	    		}
       	    	}
       	    	else if (choice == 5) {
       	    		string title;
       	    		unsigned year;
       	    		string artist;
       	    		cout << "Please enter title to remove: "<< endl;
       	    		cin.ignore(256, '\n');
       	    		cin >> title;
       	    		cout << "Please enter year to remove: " << endl;
       	    		cin.ignore(256, '\n');
       	    		cin >> year;
       	    		cout << "Please enter artist to remove: "<< endl;
       	    		cin.ignore(256, '\n');
       	    		pList.removeSong(Song(title, artist, year));
       	    		unsigned save;
       	    		cout << "Do you want to Save? Enter 9." << endl;
       	    		cin >> save;
       	    		if (save == 9) {
       	    			pList.save();
       	    			cout << "saved" << endl;
       	    		}
       	    	}
       	    }
       	}




