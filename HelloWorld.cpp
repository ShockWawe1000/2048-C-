#include <iostream>
#include <array>
#include <random>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include <string>

using Board = std::array<std::array<int, 4>, 4 >;

// create 4x4 array *
// generate starting board *
//create screen printer to print current screen *
//create controls that will control array *
//check game state *

int randomChance()
{
	static std::mt19937 mt{ static_cast<unsigned int>(time(nullptr)) };
	std::uniform_int_distribution chance{ 100 };
	return chance(mt);
}
int randomTile()
{
	static std::mt19937 mt{ static_cast<unsigned int>(time(nullptr)) };
	std::uniform_int_distribution x{ 0,3 };
	return x(mt);
}

void addRandomTile(Board& board)
{
	bool tileset = false;

	while(tileset==false)
	{
		int x{ randomTile() };
		int y{ randomTile() };
		if (board[x][y] == 0)
		{
			int chance{ randomChance() };
			if (chance <= 11)
			{
				board[x][y] = 4;
				tileset = true;
			}
			else
			{
				board[x][y] = 2;
				tileset = true;
			}
		}
	}

}

void generateBoard(Board& board)
{
	static std::mt19937 mt{ static_cast<unsigned int>(time(nullptr)) };
	std::uniform_int_distribution elements{ 3,4 };
	int a{ elements(mt) };
	for (int i = 0; i <= a; i++)
	{
		addRandomTile(board);
	}


}

void printScreen(Board& board)
{
	system("CLS");
	static int i{ 0 };
	std::cout << "2084 C++ by Edis "  << "\n";
	std::cout << "Previous moves made: " << i++ << "\n\n";


	std::cout << " ____  ____  ____  ____\n";
	std::cout << "|    ||    ||    ||    |\n";
	std::cout << "| "<<board[0][0]<<"  || " << board[0][1] << "  ||  " << board[0][2] << " ||  " << board[0][3] << " |\n";
	std::cout << " ----  ----  ----  ----\n";
	std::cout << "|    ||    ||    ||    |\n";
	std::cout << "| " << board[1][0] << "  || " << board[1][1] << "  ||  " << board[1][2] << " ||  " << board[1][3] << " |\n";
	std::cout << " ----  ----  ----  ----\n";
	std::cout << "|    ||    ||    ||    |\n";
	std::cout << "| " << board[2][0] << "  || " << board[2][1] << "  ||  " << board[2][2] << " ||  " << board[2][3] << " |\n";
	std::cout << " ----  ----  ----  ----\n";
	std::cout << "|    ||    ||    ||    |\n";
	std::cout << "| " << board[3][0] << "  || " << board[3][1] << "  ||  " << board[3][2] << " ||  " << board[3][3] << " |\n";
	std::cout << " ----  ----  ----  ----\n\n";
	std::cout << "  W\nS A D\n";
	std::cout << " Write your next move:";
}

void moveRight(Board& board)
{
	
		for (int x = 0; x < board.size(); x++)
		{
			for (int y = static_cast<int>(board.size()-1); y > 0; y--)
			{
				if (board[x][y] == board[x][y - 1])
				{
					board[x][y] = board[x][y] * 2;
					board[x][y - 1] = 0;
				}
				else if (board[x][y] == 0)
				{if (board[x][y - 1] != 0)
					{
						std::swap(board[x][y], board[x][y - 1]);
					}
				}
					
				
			}
		}
	
}
void moveLeft(Board& board)
{

	for (int x = 0; x < board.size(); x++)
	{
		for (int y = 0; y < static_cast<int>(board.size())-1 ; y++)
		{
			if (board[x][y] == board[x][y + 1])
			{
				board[x][y] = board[x][y] * 2;
				board[x][y + 1] = 0;
			}
			else if (board[x][y] == 0)
			{
				if (board[x][y + 1] != 0)
				{
					std::swap(board[x][y], board[x][y + 1]);
				}
			}


		}
	}

}
void moveUp(Board& board)
{

	for (int y = 0; y < board.size(); y++)
	{
		for (int x = 0; x < board.size()-1; x++)
		{
			if (board[x][y] == board[x + 1][y])
			{
				board[x][y] = board[x][y] * 2;
				board[x + 1][y] = 0;
			}
			else if (board[x][y] == 0)
			{
				if (board[x + 1][y] != 0)
				{
					std::swap(board[x][y], board[x + 1][y]);
				}
			}


		}
	}

}
void moveDown(Board& board)
{

	for (int y = 0; y < board.size(); y++)
	{
		for (int x = (board.size() - 1); x > 0 ; x--)
		{
			if (board[x][y] == board[x - 1][y])
			{
				board[x][y] = board[x][y] * 2;
				board[x - 1][y] = 0;
			}
			else if (board[x][y] == 0)
			{
				if (board[x - 1][y] != 0)
				{
					std::swap(board[x][y], board[x - 1][y]);
				}
			}


		}
	}

}

void playerInput(Board& board)
{
	std::string playerInput;
	std::cin>> playerInput;
	bool valid = false;
	while (valid == false)
	{
		if (playerInput == "Right" || playerInput == "right" || playerInput == "d")
		{
			moveRight(board);
			moveRight(board);
			moveRight(board);
			addRandomTile(board);
			valid = true;
		}
		else if (playerInput == "left" || playerInput == "left" || playerInput == "a")
		{
			moveLeft(board);
			moveLeft(board);
			moveLeft(board);
			addRandomTile(board);
			valid = true;
		}
		else if (playerInput == "Up" || playerInput == "up" || playerInput == "w")
		{
			moveUp(board);
			moveUp(board);
			moveUp(board);
			addRandomTile(board);
			valid = true;
		}
		else if (playerInput == "Down" || playerInput == "down" || playerInput == "s")
		{
			moveDown(board);
			moveDown(board);
			moveDown(board);
			addRandomTile(board);
			valid = true;
		}
		else
		{
			std::cout << "Invalid input\n";
			
			std::cin >> playerInput;
		}

		}
 
}
bool compareBoards(Board& board, Board& board_copy)
{
	bool change = false;
	for (int x = static_cast<int>(board.size())-1; x >= 0; x--)
	{
		for (int y = static_cast<int>(board.size())-1; y >= 0; y--)
		{
			if (board_copy[x][y] != board[x][y])
			{
				return true;
			}
		}
	}
	return false;
}

bool checkGameState(Board& board)
{
	
	Board board_copy{ board };
	moveRight(board_copy);
	moveRight(board_copy);
	moveRight(board_copy);
	if (compareBoards(board, board_copy) == false)
	{
		return false;
	}
	board_copy= board ;
	moveUp(board_copy);
	moveUp(board_copy);
	moveUp(board_copy);
	if (compareBoards(board, board_copy) == false)
	{
		return false;
	}
	board_copy= board ;
	moveDown(board_copy);
	moveDown(board_copy);
	moveDown(board_copy);
	if (compareBoards(board, board_copy) == false)
	{
		return false;
	}
	board_copy= board ;
	moveLeft(board_copy);
	moveLeft(board_copy);
	moveLeft(board_copy);
	if (compareBoards(board, board_copy) == false)
	{
		return false;
	}
	return true;
}
int main()
{

		Board board = { };
		generateBoard(board);
		printScreen(board);
		playerInput(board);
		printScreen(board);
		bool loop = true;
		while (loop = true)
		{
			playerInput(board);
			printScreen(board);
			loop = checkGameState(board);
		}
		std::cout << "Game Ended. Thank you for playing!";
}