// Winter 2018
// Scenario: Write a program to play a variation of the Craps game.
// Requirement: roll two dice (6 faces). Check sum of both dice. If sum is 2, 3, 12 then craps you lose;
// if sum is 7 or 11 call natural, you win; if sum is another value, establish point and continue to roll
// until 7, lose, or same point value, win!.

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	//variables
	int dice1, dice2, roll = 0, point = 0;
	srand(time(0));
	char repeat = 'y';

	cout << "\nWelcome to the computerized version of the Craps game." << endl << endl;
	
	while (repeat == 'y' || repeat == 'Y')
	{

		//Total of two random dice.
		dice1 = rand() % 6 + 1;
		dice2 = rand() % 6 + 1;
		roll = dice1 + dice2;

		cout << endl << dice1 << " + " << dice2 << " = " << roll << endl;

		if (roll == 2 || roll == 3 || roll == 12)
		{
			cout << "\nCRAPS!! You lose." << endl;
		}
		else if (roll == 7 || roll == 11)
		{
			cout << "\nYou rolled a natural. You WIN!!!" << endl;
		}
		else
		{
			point = roll;
			cout << "\nPoint value establisted: " << point << endl << endl;

			
			roll = 0;
			while (roll != 7 && roll != point)
			{
				dice1 = rand() % 6 + 1;
				dice2 = rand() % 6 + 1;
				roll = dice1 + dice2;
				cout << dice1 << " + " << dice2 << " = " << roll << endl;

				if (roll == point)
				{
					cout << "\nRolled same as your point. You WIN!!!" << endl;
					//break;
				}
				else if (roll == 7)
				{
					cout << "\nYou lose." << endl;
					//break;
				}
			}
		}
		cout << "\nAnother game [Y/N] ";
		cin >> repeat;

	}
	cout << endl << endl;
	system("pause");
	return 0;
}
