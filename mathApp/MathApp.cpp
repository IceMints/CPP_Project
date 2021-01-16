// Winter 2018
// Scenario: Create a program that will help kids with Addition, Subtraction, Multiplication and Division
// Create a menu, randomly pick two numbers from 1-100, prompt user for the correct answer, exit back to menu
// Requirements: use random numbers, error check selection, while loops, if statements, switch, variables
// allow exit of menu

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
	//Starting variables
	int num1, num2, highnum, lownum, answer, choice, count, remainder, quot;
	srand(time(0));
	answer = 0;
	highnum = 0;
	lownum = 0;
	choice = 0;
	count = 0;
	quot = 0;
	remainder = 0;
	
	while (choice != 5)
	{
		//Menu
		cout << " \n |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
		cout << " |                                                                            |" << endl;
		cout << " |                         Basic Math Program                                 |" << endl;
		cout << " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
		cout << " |                                                                            |" << endl;
		cout << " |              Which operation would you like to choose?                     |" << endl;
		cout << " |                                                                            |" << endl;
		cout << " |         (1) + Addition +                                                   |" << endl;
		cout << " |                                                                            |" << endl;
		cout << " |         (2) - Subtraction -                                                |" << endl;
		cout << " |                                                                            |" << endl;
		cout << " |         (3) x Multiplication x                                             |" << endl;
		cout << " |                                                                            |" << endl;
		cout << " |         (4) / Division /                                                   |" << endl;
		cout << " |                                                                            |" << endl;
		cout << " |         (5) Quit                                                           |" << endl;
		cout << " |                                                                            |" << endl;
		cout << " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
		cout << " \nPlease select either 1, 2, 3, 4, or 5: ";
		cin >> choice;

		/*cout << endl << "Basic Math Program" << endl << endl;
		cout << "Which operation would you like to choose?" << endl;
		cout << "1. Addition (+)" << endl;
		cout << "2. Subtration (-)" << endl;
		cout << "3. Multiplication (x)" << endl;
		cout << "4. Division (/)" << endl;
		cout << "5. Quit" << endl;
		cout << "Please select either 1, 2, 3, 4, or 5: ";
		cin >> choice;*/

		//If choice is an invalid entry
		if (cin.fail() || choice < 1 || choice > 5)
		{
			cout << "Invalid entry!" << endl;
			//cout << "Please select either 1, 2, 3, 4, or 5: ";
			cin.clear();
			cin.ignore(256, '\n');
			//cin >> choice;
			system("pause");
			system("CLS");
		}

		//Random 2 numbers
		num1 = rand() % 100 + 1;
		num2 = rand() % 100 + 1;
		highnum = num1 > num2 ? num1 : num2;
		lownum = num1 < num2 ? num1 : num2;

		/*if (num1 < num2)
		 {
			 int temp = num1;
			 num1 = num2;
			 num2 = temp;
		 }*/

		//Calculations for choices 1, 2, 3, 4, 5 = exit and displays
		switch (choice)
		{
			//Addition
		case 1:
			cout << endl << "You have chosen addition." << endl;
			while (answer != num1 + num2)
			{
				cout << endl << "What is the sum? " << endl << endl;
				cout << setw(13) << num1 << endl << setw(11) << " + " << num2 << endl;
				cout << setw(13) << "-----" << endl << setw(10) << " ";
			
				//cout << endl << "What is " << num1 << " + " << num2 << " = ? ";
				cin >> answer;
				cin.clear();
				cin.ignore(256, '\n');

				if (answer != num1 + num2)
				{
					cout << endl << "Not quite correct. Try again." << endl;
				}
				else
				{
					cout << endl << "Congratulations! That is correct!!" << endl << endl;
					count++;
					system("pause");
					system("CLS");
				}
			}
			break;

			//Subtraction
		case 2:
			cout << endl << "You have chosen subtraction." << endl;
			while (answer != highnum - lownum)
			{
				cout << endl << "What is the difference? " << endl << endl;
				cout << setw(13) << highnum << endl << setw(11) << " - " << lownum << endl;
				cout << setw(13) << "-----" << endl << setw(11) << " ";
				//cout << endl << "What is " << highnum << " - " << lownum << " = ? ";
				cin >> answer;
				cin.clear();
				cin.ignore(256, '\n');

				if (answer != highnum - lownum)
				{
					cout << endl << "Close. Try again." << endl;
				}
				else
				{
					cout << endl << "Congratulations! That is correct!!" << endl << endl;
					count++;
					system("pause");
					system("CLS");
				}
			}
			break;

			//Multiplication
		case 3:
			cout << endl << "You have chosen multiplication." << endl;
			while (answer != highnum * lownum)
			{
				cout << endl << "What is the product? " << endl << endl;
				cout << setw(13) << highnum << endl << setw(11) << " x " << lownum << endl;
				cout << setw(13) << "-----" << endl << setw(10) << " ";
				//cout << endl << "What is "<< num1 << " x " << num2 << " = ? ";
				cin >> answer;
				cin.clear();
				cin.ignore(256, '\n');

				if (answer != num1 * num2)
				{
					cout << endl << "Almost there. Try again." << endl;
				}
				else
				{
					cout << endl << "Congratulations! That is correct!!" << endl << endl;
					count++;
					system("pause");
					system("CLS");
				}
			}
			break;

			//Division
		case 4:
			cout << endl << "You have chosen division." << endl;
			while (quot != highnum / lownum || remainder != highnum % lownum)
			{
				cout << endl << "What is " << highnum << " / " << lownum << " = ? ";
				cout << endl << endl << "What is the quotient? ";
				cin >> quot;
				cin.clear();
				cin.ignore(256, '\n');	

				if (quot != highnum / lownum)
				{
					cout << endl << "Quotient is not quite right. Try again." << endl;
				}
				else
				{
				 cout << "What is the remainder? ";
				 cin >> remainder;
				 cin.clear();
				 cin.ignore(256, '\n');
					
						if (remainder != highnum % lownum)
						{
						cout << endl << "Remainder is not correct. Try again" << endl;
						}

						else
						{
						cout << endl << "Congratulations! That is correct!!" << endl << endl;
						count++;
						system("pause");
						system("CLS");
						}
				}
			}
			break;
			//Exit
		case 5:
			cout << "\nYou've completed a total of " << count << " math problems." << endl << endl;
			cout << "Thank you for using this program!!" << endl;
		}
	}
	cout << endl << endl;
	system("pause");
	return 0;
}
