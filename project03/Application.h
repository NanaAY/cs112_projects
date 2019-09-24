/*Application.h contains the declarations for the methods defined in application.cpp
 * Student Name:Nana Osei Asiedu Yirenkyi
 * Date: Sept 25 2018
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <iostream>
#include "Vec.h"

using namespace std;

class Application {
public:
	Application();
	Application(const Application& origional);

	void display();
	void displayMenu();
	void updatePos();
	void displayPos();
	void dimIn();
	void getVec();
	virtual ~Application();

private:
	unsigned myDim;
	Vec myPos;
	Vec myVec;
};

#endif /* APPLICATION_H_ */
