#include <iostream>
#include <ctime>

char Position[49] = {};
char ComputerStaticPosition[49] = {};
char NonStaicCompPosition[49] = {};

char Output[49] = {'+','-','+','-','+','-','+',
				   '|',' ','|',' ','|',' ','|',
				   '+','-','+','-','+','-','+',
				   '|',' ','|',' ','|',' ','|',
				   '+','-','+','-','+','-','+',
				   '|',' ','|',' ','|',' ','|',
				   '+','-','+','-','+','-','+',
				  };

void ComputerPosition()
{
	int ComputerX, ComputerY;

	ComputerX = (std::rand() % 3) + 1;
	ComputerY = (std::rand() % 3) + 1;
	
	if (ComputerX == 1 && ComputerY == 1)
	{
		ComputerStaticPosition[8] = 'O';
	}
	else
	{
		if (ComputerX == 1 && ComputerY == 2)
		{
			ComputerStaticPosition[10] = 'O';
		}
		else if (ComputerX == 1 && ComputerY == 3)
		{
			ComputerStaticPosition[12] = 'O';
		}
		else if (ComputerX == 2 && ComputerY == 1)
		{
			ComputerStaticPosition[22] = 'O';
		}
		else if (ComputerX == 2 && ComputerY == 2)
		{
			ComputerStaticPosition[24] = 'O';
		}
		else if (ComputerX == 2 && ComputerY == 3)
		{
			ComputerStaticPosition[26] = 'O';
		}
		else if (ComputerX == 3 && ComputerY == 1)
		{
			ComputerStaticPosition[36] = 'O';
		}
		else if (ComputerX == 3 && ComputerY == 2)
		{
			ComputerStaticPosition[38] = 'O';
		}
		else if (ComputerX == 3 && ComputerY == 3)
		{
			ComputerStaticPosition[40] = 'O';
		}
	}

}

void BoardGenerate(int PlayerX, int PlayerY)
{

	if (PlayerX == 1 && PlayerY == 1)
	{
		Position[8] = 'X';
	}
	else
	{
		if (PlayerX == 1 && PlayerY == 2)
		{
			Position[10] = 'X';
		}
		else if (PlayerX == 1 && PlayerY == 3)
		{
			Position[12] = 'X';
		}
		else if (PlayerX == 2 && PlayerY == 1)
		{
			Position[22] = 'X';
		}
		else if (PlayerX == 2 && PlayerY == 2)
		{
			Position[24] = 'X';
		}
		else if (PlayerX == 2 && PlayerY == 3)
		{
			Position[26] = 'X';
		}
		else if (PlayerX == 3 && PlayerY == 1)
		{
			Position[36] = 'X';
		}
		else if (PlayerX == 3 && PlayerY == 2)
		{
			Position[38] = 'X';
		}
		else if (PlayerX == 3 && PlayerY == 3)
		{
			Position[40] = 'X';
		}
	}

	for (int i = 8; i <= 40; i+=2)
	{
		if (Output[i] == ' ' && Position[i] == 'X')
		{
			Output[i] = Position[i];
		}
		else
		{
			continue;
		}
	}

	bool Reserve = false;

	
	while (!Reserve)
	{
		ComputerPosition();

		for (int i = 8; i <= 40; i += 2) 
		{

			if (Output[i] == ' ' && ComputerStaticPosition[i] == 'O' && Reserve == false)
			{
				Output[i] = ComputerStaticPosition[i];
				Reserve = true;
			}
			else if (Output[i] != ' ' && ComputerStaticPosition[i] == 'O')
			{
				ComputerStaticPosition[i] = ' ';
				break;
			}
			else
			{
				continue;
			}

		}
	}
	

}

void BoardOutput()
{

	for (int i = 1; i <= 50; i++)
	{
		if (i % 7 == 0)
		{
			std::cout << Output[i - 1] << std::endl;
		}
		else
		{
			if (i == 50)
			{
				std::cout << "        ^\n    <Y  X" << std::endl;
			}
			else
			{
				std::cout << Output[i - 1];
			}
		}
	}

}

bool IsGameEnded()
{
	int FreePlace = 0;
	bool PlayerWin = false, ComputerWin = false;

	for (int i = 0; i < 49; i++)
	{
		if (Output[i] == ' ')
		{
			FreePlace++;
		}
		else
		{
			continue;
		}
	}



	if (Output[8] == 'X' && Output[24] == 'X' && Output[40] == 'X')
	{
		PlayerWin = true;
	}
	else if (Output[12] == 'X' && Output[24] == 'X' && Output[36] == 'X')
	{
		PlayerWin = true;
	}
	else if (Output[8] == 'X' && Output[10] == 'X' && Output[12] == 'X')
	{
		PlayerWin = true;
	}
	else if (Output[26] == 'X' && Output[24] == 'X' && Output[22] == 'X')
	{
		PlayerWin = true;
	}
	else if (Output[40] == 'X' && Output[38] == 'X' && Output[36] == 'X')
	{
		PlayerWin = true;
	}
	else if (Output[8] == 'X' && Output[22] == 'X' && Output[36] == 'X')
	{
		PlayerWin = true;
	}
	else if (Output[10] == 'X' && Output[24] == 'X' && Output[38] == 'X')
	{
		PlayerWin = true;
	}
	else if (Output[12] == 'X' && Output[26] == 'X' && Output[40] == 'X')
	{
		PlayerWin = true;
	}


	if (Output[8] == 'O' && Output[24] == 'O' && Output[40] == 'O')
	{
		ComputerWin = true;
	}
	else if (Output[12] == 'O' && Output[24] == 'O' && Output[36] == 'O')
	{
		ComputerWin = true;
	}
	else if (Output[8] == 'O' && Output[10] == 'O' && Output[12] == 'O')
	{
		ComputerWin = true;
	}
	else if (Output[26] == 'O' && Output[24] == 'O' && Output[22] == 'O')
	{
		ComputerWin = true;
	}
	else if (Output[40] == 'O' && Output[38] == 'O' && Output[36] == 'O')
	{
		ComputerWin = true;
	}
	else if (Output[8] == 'O' && Output[22] == 'O' && Output[36] == 'O')
	{
		ComputerWin = true;
	}
	else if (Output[10] == 'O' && Output[24] == 'O' && Output[38] == 'O')
	{
		ComputerWin = true;
	}
	else if (Output[12] == 'O' && Output[26] == 'O' && Output[40] == 'O')
	{
		ComputerWin = true;
	}


	
	if (PlayerWin == true)
	{
		std::cout << "\nWygrales!" << std::endl;
		return true;
	}
	else if (ComputerWin == true)
	{
		std::cout << "\nPrzegrales!" << std::endl;
		return true;
	}
	else if (FreePlace == 0)
	{
		std::cout << "\nRemis!" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{

	int ChoiceX, ChoiceY;
	bool endGame;

	srand(time(NULL));

	std::cout << "Aby wykonac ruch, nalezy wpisac swoja pozycje.\nNajpierw wybieramy wiersz (oznaczony \"X^\"),\na nastepnie kolumne (oznaczona \"<Y\").\nW przypadku wyboru wiersza, wpisujemy\nliczbe od 1 do 3 (gdzie 1 oznacza gorny wiersz,\na 3 oznacza dolny).\nW przypadku wyboru kolumn jest podobnie\n - 1 jest pierwsze od lewej, a 3 jest jest pierwsze od prawej.\n\n" << std::endl;

	BoardGenerate(0, 0);	//grę zaczyna komputer, dlatego gracz nie wykonuje ruchu (0, 0)
	BoardOutput();

	std::cout << "\nGrasz jako 'X'\n\n";

	std::cout << "Wpisz pozycje x (1-3) swojego 'X': "; std::cin >> ChoiceX;
	std::cout << "Wpisz pozycje y (1-3) swojego 'X': "; std::cin >> ChoiceY;

	while (true)
	{

		system("CLS");

		BoardGenerate(ChoiceX, ChoiceY);	
		BoardOutput();

		endGame = IsGameEnded();

		if (endGame == true)
		{
			break;
		}

		std::cout << "Wpisz pozycje x (1-3) swojego 'X': "; std::cin >> ChoiceX;
		std::cout << "Wpisz pozycje y (1-3) swojego 'X': "; std::cin >> ChoiceY;

	}

	getchar();
	return 0;

}

