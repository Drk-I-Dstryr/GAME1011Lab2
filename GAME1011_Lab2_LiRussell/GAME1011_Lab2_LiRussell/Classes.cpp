#include <iostream>
#include <string>
#include "Classes.h"
using namespace std;

/*
  Program Created by: Russell Li
  Date: Sunday February 8, 2021
  Purpose: To create a custom character creation menu
 */

int main()
{
	// All the variables
	const int NUM_SLOTS = 1;
	Human list[NUM_SLOTS];
	Bearman slots[NUM_SLOTS];
	Xada shrooms[NUM_SLOTS];
	bool human = false;
	bool bearman = false;
	bool xada = false;
	bool checker = false;
	int playerChoice;
	int numOfchar = 0;
	string Hchoice = "";
	string Bchoice = "";
	int Xchoice = 0;
	string plName = "";
	int plHealth = 0;
	int WeaponChoice = 0;
	const int NUM_WEAPONS = 3;
	const int NUM_CHAR = 3;
	string wind[3], stick[3], destroyer[3];
	Character *characters[NUM_CHAR];
	Weapon starterWeapons[NUM_WEAPONS];
	string charName;
	int charHealth;
	bool lols = false;
	string huSong = "";
	string beName = "";
	int xaHealth = 0;
	int sacrifice = 0;
	int lamb = 0;
	int exiter = 0;
	bool exit = false;

	// Filling the arrays
	characters[0] = new Human();
	characters[1] = new Bearman();
	characters[2] = new Xada();


	wind[0] = "Shoots wind.";
	wind[1] = "Cost no mana.";
	wind[2] = "Is very common.";
	
	stick[0] = "Is strong.";
	stick[1] = "Can be found anywhere.";
	stick[2] = "Does piercing damage.";

	destroyer[0] = "Shoots rays of anti-matter.";
	destroyer[1] = "Disintigrates anything it blasts.";
	destroyer[2] = "Makes it's user go mad with power.";

	starterWeapons[0] = Weapon(1, "Wind Breaker", "Can make wind break.", 2, wind);
	starterWeapons[1] = Weapon(2, "Strong stick", "Brown and sticky.", 3, stick);
	starterWeapons[2] = Weapon(3, "Destroyer", "Can destroy worlds.", 10000000000, destroyer);

	// Menu start
	do
	{
		cout << "\n\nHello user! Welcome to the character creater!" << endl << endl;
		for (int a = 0; checker != true; a++)
		{
			cout << "How many characters do you want to create? (Up to 3 characters)" << endl;
			cin >> numOfchar;
			if (numOfchar == 1 || numOfchar == 2 || numOfchar == 3)
			{
				checker = true;
			}
			else
			{
				cout << "That is not a valid option" << endl << endl;
			}
		}
		for (int i = 0; i < numOfchar; i++)
		{
			human = false;
			bearman = false;
			xada = false;
			cout << "\nWhat do you want you character to be?:\n1. Human\n2. Bearman\n3. Xada\n";
			cout << "Enter the number beside the one you want to be:" << endl;
			cin >> playerChoice;

			if (playerChoice == 1)
			{
				human = true;
				cout << "What song do you sing?: ";
				cin >> huSong;
			}
			else if (playerChoice == 2)
			{
				bearman = true;
				cout << "What will be your prefix for your name?: ";
				cin >> beName;
			}
			else if (playerChoice == 3)
			{
				xada = true;
				cout << "What will be your health modifier?: ";
				cin >> xaHealth;
			}

			cout << "\nWhat is your character's name?: ";
			cin >> charName;
			lols = false;
			for (int d = 0; lols != true; d++)
			{
				cout << "\nWhat starter weapon do you want?: ";
				for (int p = 0; p < NUM_WEAPONS - 1; p++)
				{
					cout << starterWeapons[p].WeaponInfo();
				}
				cout << "\n\nType in the id of the weapon you want: ";
				cin >> WeaponChoice;
				if (WeaponChoice == 3)
				{
					cout << "\nSorry this weapon is only avaliable to premium users." << endl << endl;
				}
				else if (WeaponChoice == 2)
				{
					lols = true;
				}
				else if (WeaponChoice == 1)
				{
					lols = true;
				}
			}

			cout << "\nHow much health does you character have? ";
			cin >> charHealth;

			if (human == true)
			{
				characters[i] = new Human(charName, charHealth, starterWeapons[WeaponChoice - 1], huSong);
			}
			else if (bearman == true)
			{
				characters[i] = new Bearman(charName, charHealth, starterWeapons[WeaponChoice - 1], beName);
			}
			else if (xada == true)
			{
				characters[i] = new Xada(charName, charHealth, starterWeapons[WeaponChoice - 1], xaHealth);
			}
		}

		cout << "\n\nYour characters are:";

		for (int a = 0; a < numOfchar; a++)
		{
			cout << "ID Num:" << (a + 1);
			characters[a]->DisplayInfo();
		}

		cout << "Do you want to delete one of your characters for good luck?\n1 = yes, 2 = no" << endl;
		cin >> sacrifice;
		if (sacrifice == 1)
		{
			cout << "type in the ID Num of the character you want to sacrifice to The Hooded Figures: \n";
			cin >> lamb;
			characters[lamb - 1] = new Human();
			cout << "\nThank you for you service \n-The Faceless Old Woman Who Secretly Lives In Your Home ( )/" << endl;
		}

		cout << "\n\ndO yOU WaNt To ExIt?" << endl;
		cout << "1 = yes, 2 = no" << endl;
		cin >> exiter;

		if (exiter == 1)
		{
			exit = true;
		}

	} while (exit != true);

	return 0;
}