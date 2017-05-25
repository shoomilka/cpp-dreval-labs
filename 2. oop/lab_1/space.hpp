#ifndef __SPACE_HPP

#define __SPACE_HPP

#include <stdlib.h>
#include <iostream>
#include "space.hpp"
#include <string>

using namespace std;

class Position
{
	public:
	int X, Y;

	Position() {X = Y = 0;}

	Position(int CoordX, int CoordY) {
		X = CoordX;
		Y = CoordY;
	}

	void Init(int CoordX, int CoordY) {
		X = CoordX;
		Y = CoordY;
	}

	int GetX() {return X;}
	int GetY() {return Y;}
};

class Ball : public Position
{
	
	public:
	Ball(int CoordX, bool CoordY){
		if(CoordX>2) CoordX = 2;
		if(CoordX<0) CoordX = 0;
		X = CoordX;
		Y = CoordY;
	}

	virtual ~Ball() {}

	virtual bool Hit(int Coord){
		Y = !Y;
		X = rand() % 3;
		if(X == Coord) return true;
		return false;
	}

};

class Game
{
	protected:
		int hit;
		int scr1;
		int scr2;
		bool y;
		string smbody1, smbody2;
		
	public:
		
	Game(){
		scr1 = 0;
		scr2 = 0;
		y = 1;
		cout << "Enter first name:" << endl;
		cin >> smbody1;
		cout << "Enter second name:" << endl;
		cin >> smbody2;
		play();
	}
	
	~Game() {}
	
	void play(){
		do{
			cout << "Podacha mjacha " << (y?smbody1:smbody2) << endl << "0 - left, 1 - mid, 2 - right" << endl;
			cin >> hit;
			Ball ball = Ball(hit, y);
		
			do{
				cout << "Pomenjat poziciju " << (!ball.Y?smbody1:smbody2) << endl << "0 - left, 1 - mid, 2 - right" << endl;
				cin >> hit;
			} while (ball.Hit(hit));
		
			!ball.Y?scr1++:scr2++;
		
			if(scr1 >= 10 && scr2 >= 10){
				y = !y;
			} else if((scr1+scr2)%2 == 0){
				y = !y;
			}
			
			printScore();
			
		} while (!((max(scr1, scr2) > 10) && (abs(scr1-scr2) > 1)));
	
		cout << (scr1>scr2?smbody1:smbody2) << " win!";
	}
	
	void printScore();
	
	void getScore(){
		cout << scr1 << ":" << scr2;
	}
};

#endif
