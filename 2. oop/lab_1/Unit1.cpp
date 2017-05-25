#include "space.hpp"
#include <windows.h>

	void Game::printScore(){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, 12);
		cout << "********************  Current score: ";
		this->getScore();
		cout << endl;
		SetConsoleTextAttribute(hConsole, 13);
	}

int main(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);
	Game game = Game();
	
	return 0;
}

