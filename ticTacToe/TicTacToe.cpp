// Winter 2018
// Scenario: Create a Tic Tac Toe program for two players
// Requirements: Variables, constants, arrays, functions, loops, error checking, if statments, switch statements, intuitive display
// and instructional prompts. Check to make sure the spot isn't already taken by someone, keep score for each player.

#include <iostream>

using namespace std;

//global variable
int player1_counter = 0, player2_counter = 0;

//2d array
char squares[3][3] = { { '1' , '2' , '3' },
{ '4' , '5' , '6' },
{ '7' , '8' , '9' } };
//game board
void board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << "Player 1 score: " << player1_counter << "\tPlayer 2 score: " << player2_counter << endl;
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << squares[0][0] << "  |  " << squares[0][1] << "  |  " << squares[0][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << squares[1][0] << "  |  " << squares[1][1] << "  |  " << squares[1][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << squares[2][0] << "  |  " << squares[2][1] << "  |  " << squares[2][2] << endl;
	cout << "     |     |     " << endl << endl;
}
//to clear and reset the board
void clear_board()
{
	squares[0][0] = '1', squares[0][1] = '2', squares[0][2] = '3',
		squares[1][0] = '4', squares[1][1] = '5', squares[1][2] = '6',
		squares[2][0] = '7', squares[2][1] = '8', squares[2][2] = '9';
}
//checks if there is a winner or a draw
int check_for_winner()
{
	if (squares[0][0] == squares[0][1] && squares[0][1] == squares[0][2])
		return 1;
	else if (squares[1][0] == squares[1][1] && squares[1][1] == squares[1][2])
		return 1;
	else if (squares[2][0] == squares[2][1] && squares[2][1] == squares[2][2])
		return 1;
	else if (squares[0][0] == squares[1][0] && squares[1][0] == squares[2][0])
		return 1;
	else if (squares[0][1] == squares[1][1] && squares[1][1] == squares[2][1])
		return 1;
	else if (squares[0][2] == squares[1][2] && squares[1][2] == squares[2][2])
		return 1;
	else if (squares[0][0] == squares[1][1] && squares[1][1] == squares[2][2])
		return 1;
	else if (squares[0][2] == squares[1][1] && squares[1][1] == squares[2][0])
		return 1;
	else if (squares[0][0] != '1' && squares[0][1] != '2' && squares[0][2] != '3' && squares[1][0] != '4'
		&& squares[1][1] != '5' && squares[1][2] != '6' && squares[2][0] != '7' && squares[2][1] != '8'
		&& squares[2][2] != '9')
		return 0; //cat's game
	else
		return -1;//game in progress
}

int main()
{
	//variables
	int choice = 0, check = 0, player = 1, select;
	char play_again = 'y';

	while (choice != 4)
	{	//menu
		cout << "Tic Tac Toe Game" << endl;
		cout << "~~~~~~~~~~~~~~~~" << endl << endl;
		cout << "Choose an option from the menu:" << endl << endl;
		cout << "1. Two players" << endl;
		cout << "2. Score" << endl;
		cout << "3. Reset scoreboard" << endl;
		cout << "4. Exit the program." << endl;
		cout << "\nSelect 1, 2, 3 or 4 to exit: ";
		cin >> choice;

		if (cin.fail() || choice < 1 || choice > 4)
		{
			cout << "Invalid entry! \nPress enter to continue." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin.get();
			system("cls");
		}

		switch (choice)
		{
		case 1:
			//Two player game
			play_again = 'y';
			while (play_again == 'y' || play_again == 'Y')
			{
				do
				{
					board();
					player = (player % 2) ? 1 : 2;
					cout << "Player " << player << ", enter a number: ";
					cin >> select;
					//Constant variable to mark the board with X or O
					const char mark = (player == 1) ? 'X' : 'O';
					if (select == 1 && squares[0][0] == '1')
					{
						squares[0][0] = mark;
					}
					else if (select == 2 && squares[0][1] == '2')
					{
						squares[0][1] = mark;
					}
					else if (select == 3 && squares[0][2] == '3')
					{
						squares[0][2] = mark;
					}
					else if (select == 4 && squares[1][0] == '4')
					{
						squares[1][0] = mark;
					}
					else if (select == 5 && squares[1][1] == '5')
					{
						squares[1][1] = mark;
					}
					else if (select == 6 && squares[1][2] == '6')
					{
						squares[1][2] = mark;
					}
					else if (select == 7 && squares[2][0] == '7')
					{
						squares[2][0] = mark;
					}
					else if (select == 8 && squares[2][1] == '8')
					{
						squares[2][1] = mark;
					}
					else if (select == 9 && squares[2][2] == '9')
					{
						squares[2][2] = mark;
					}
					else
					{
						cout << "That is not a valid move. \nPress enter to continue.";
						player--;
						cin.clear();
						cin.ignore(256, '\n');
						cin.get();
						system("cls");
					}
					check = check_for_winner();
					player++;
				} while (check == -1);

				//refreshes the board
				board();
				if (check == 1)
				{
					cout << "Player " << --player << " wins!!! " << endl << endl;
					//keeping score
					if (player == 2)
					{
						player2_counter++;
					}
					else
					{
						player1_counter++;
					}
					cout << "Score is: " << player1_counter << " vs " << player2_counter << endl << endl;
				}
				else
				{
					cout << "Cat's Game -- Draw" << endl << endl;
				}

				//clears the board
				clear_board();

				//Prompt to play again
				do
				{
					cout << "Play again? [Y/N] ";
					cin >> play_again;
					cin.clear();
					cin.ignore(256, '\n');
					cout << endl << endl;

				}while (play_again != 'y' && play_again != 'Y' && play_again != 'n' && play_again != 'N');

			}
			break;
		case 2:
			//to see scoreboard
			cout << "\nScore is: " << player1_counter << " vs " << player2_counter << endl;
			cout << endl << "\nPress enter to continue.";
			cin.clear();
			cin.ignore(256, '\n');
			cin.get();
			system("cls");
			break;
		case 3:
			//reset the scoreboard
			player1_counter = 0, player2_counter = 0;
			cout << endl << "Score have been reset. \n\nPress enter to continue." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin.get();
			system("cls");
			break;
		case 4:
			//exit
			cout << "\nThe final score is:  " << player1_counter << " vs " << player2_counter << endl << endl;
			cout << "Thank you for using this program!!!" << endl;
		}

	}
	cout << endl << endl;
	system("pause");
	return 0;
}


