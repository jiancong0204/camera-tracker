// CameraTracker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Chessboard.h"


int main()
{	
	Chessboard chessboard = Chessboard(9, 7, 19);
	std::cout << chessboard.getGrid() << std::endl;
	
	std::cout << std::endl << "Press any key to exit..." << std::endl;
	std::cin.ignore();
    return 0;
}

