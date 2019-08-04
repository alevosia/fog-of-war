// _________________________________
//|                                 |
//|  Coded by: Alexandrinne Levi    |
//|		SE Student of iAcademy		|
//|_________________________________|
//For recreational use only. Share to your friends and have fun.
//Not for retail, selling or any ways of creating income.

#include <iostream>
#include <string>
#define NOMINMAX
#include <Windows.h>
#include <mmsystem.h>
#include <time.h>
#include <stdlib.h>
#include <limits>
using namespace std;
int player_ships = 12, enemy_ships = 12;
float hit = 0, missiles_launched, missed = 0;
double accuracy;

string user = { 'H','a','c','k','e','t','t' };
string coordinates;

char sqa[67] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
				 ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
				 ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
char sqb[67] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
				 ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
				 ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
char truesqb[67] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
					 ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
					 ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' };
void real(string text)
{
	srand(time(NULL));
	int song;

	for (int i = 0; i < (int)text.size(); i++)
	{
		song = rand() % 4 + 1;
		switch (song)
		{
		case 1:
			PlaySoundW(L"sounds/key1.wav", NULL, SND_FILENAME | SND_ASYNC);
			break;
		case 2:
			PlaySoundW(L"sounds/key2.wav", NULL, SND_FILENAME | SND_ASYNC);
			break;
		case 3:
			PlaySoundW(L"sounds/key3.wav", NULL, SND_FILENAME | SND_ASYNC);
			break;
		case 4:
			PlaySoundW(L"sounds/key4.wav", NULL, SND_FILENAME | SND_ASYNC);
			break;
		}
		cout << text[i];
		Sleep(rand() % 70 + 30);
	}
}

void username()
{
	real("\n Admiral! I am Saschia Slova."); Sleep(500); real(" What shall I call you? ");
	cin >> user; 
	system("CLS"); cout << endl;
	real(" Welcome to Fog of War, Admiral "); real(user); real("."); Sleep(500); cout << endl;
	real(" I suggest you maximize or enlarge the console and turn up the sound before we begin."); Sleep(2000); cout << endl;
	real(" Done, Admiral? "); Sleep(1000); real("Press ENTER so we can start.");
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}
void guide()
{
	char guide;
	cout << endl << endl;
	real(" Would you like to learn the way of war first, Admiral? "); cout << "[Y/N] ";
	cin >> guide;

	while (guide != 'Y' && guide != 'y' && guide != 'N' && guide != 'n')
	{
		cout << endl << endl;
		real(" Invalid response, Admiral. Please try again. [Y/N] ");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> guide;
	}

	if (guide == 'y' || guide == 'Y')
	{
		system("CLS");
		cout << endl;
		real(" Alright, sir."); Sleep(500); real(" This should be quick as we don't have much time before the enemy breaches our defenses.");
		Sleep(500);
		cout << endl << endl;
		real(" There will be two boards--yours and the enemy's."); Sleep(500); real(" The one at the bottom shall be yours."); Sleep(500); cout << endl;
		real(" You shall be able to deploy 12 destroyers in this skirmish."); Sleep(500); cout << endl;
		real(" The enemy will also be able to deploy the same number of ships, and you are to destroy them all."); Sleep(500); cout << endl;
		real(" You can not see where the enemy have deployed their ships and they can not see yours."); Sleep(500); cout << endl;
		real(" The coordinates for deploying and attacking ships should be in row-column format."); Sleep(500); cout << endl;
		real(" Therefore, if your target is on row 4 and column 6, the coordinates should be 46."); Sleep(500); cout << endl << endl;
		real(" The first one to annihilate the other shall be declared the winner of the battle."); Sleep(1000);
		cout << "\n\n Press ENTER to exit tutorial";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
		system("CLS");
	}
	cout << endl;
	real(" Ready, Admiral?"); Sleep(500); real(" Let's not waste any more time and get to action!");
	Sleep(1000);
	system("CLS");
}

void board_b()
{
	cout << endl;
	cout << "                                             Fog of War by Alev\n\n";
	cout << "                                  ---1-----2-----3-----4-----5-----6---\n";
	cout << "                                   _____ _____ _____ _____ _____ _____" << endl;
	cout << "                                  |     |     |     |     |     |     |" << endl;
	cout << "                               1  |  " << sqb[11] << "  |  " << sqb[12] << "  |  " << sqb[13] << "  |  " << sqb[14] << "  |  " << sqb[15] << "  |  " << sqb[16] << "  |  " << endl;
	cout << "                                  |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                  |     |     |     |     |     |     |" << endl;
	cout << "                               2  |  " << sqb[21] << "  |  " << sqb[22] << "  |  " << sqb[23] << "  |  " << sqb[24] << "  |  " << sqb[25] << "  |  " << sqb[26] << "  |  " << endl;
	cout << "                                  |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                  |     |     |     |     |     |     |" << endl;
	cout << "                               3  |  " << sqb[31] << "  |  " << sqb[32] << "  |  " << sqb[33] << "  |  " << sqb[34] << "  |  " << sqb[35] << "  |  " << sqb[36] << "  |  " << "           Enemy Ships: " << enemy_ships << endl;
	cout << "                                  |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                  |     |     |     |     |     |     |" << endl;
	cout << "                               4  |  " << sqb[41] << "  |  " << sqb[42] << "  |  " << sqb[43] << "  |  " << sqb[44] << "  |  " << sqb[45] << "  |  " << sqb[46] << "  |  " << endl;
	cout << "                                  |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                  |     |     |     |     |     |     |" << endl;
	cout << "                               5  |  " << sqb[51] << "  |  " << sqb[52] << "  |  " << sqb[53] << "  |  " << sqb[54] << "  |  " << sqb[55] << "  |  " << sqb[56] << "  |  " << endl;
	cout << "                                  |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                  |     |     |     |     |     |     |" << endl;
	cout << "                               6  |  " << sqb[61] << "  |  " << sqb[62] << "  |  " << sqb[63] << "  |  " << sqb[64] << "  |  " << sqb[65] << "  |  " << sqb[66] << "  |  " << endl;
	cout << "                                  |_____|_____|_____|_____|_____|_____|" << endl << endl;
	cout << "                                -X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-\n";
}
void board_bhit1()
{
	cout << endl;
	cout << "                                             Fog of War by Alev\n\n";
	cout << "                                  ---1-----2-----3-----4-----5-----6---\n";
	cout << "                                      _____ _____ _____ _____ _____ _____" << endl;
	cout << "                                     |     |     |     |     |     |     |" << endl;
	cout << "                               1     |  " << sqb[11] << "  |  " << sqb[12] << "  |  " << sqb[13] << "  |  " << sqb[14] << "  |  " << sqb[15] << "  |  " << sqb[16] << "  |  " << endl;
	cout << "                                     |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                     |     |     |     |     |     |     |" << endl;
	cout << "                               2     |  " << sqb[21] << "  |  " << sqb[22] << "  |  " << sqb[23] << "  |  " << sqb[24] << "  |  " << sqb[25] << "  |  " << sqb[26] << "  |  " << endl;
	cout << "                                     |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                     |     |     |     |     |     |     |" << endl;
	cout << "                               3     |  " << sqb[31] << "  |  " << sqb[32] << "  |  " << sqb[33] << "  |  " << sqb[34] << "  |  " << sqb[35] << "  |  " << sqb[36] << "  |  " << "        Enemy Ships: " << enemy_ships << endl;
	cout << "                                     |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                     |     |     |     |     |     |     |" << endl;
	cout << "                               4     |  " << sqb[41] << "  |  " << sqb[42] << "  |  " << sqb[43] << "  |  " << sqb[44] << "  |  " << sqb[45] << "  |  " << sqb[46] << "  |  " << endl;
	cout << "                                     |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                     |     |     |     |     |     |     |" << endl;
	cout << "                               5     |  " << sqb[51] << "  |  " << sqb[52] << "  |  " << sqb[53] << "  |  " << sqb[54] << "  |  " << sqb[55] << "  |  " << sqb[56] << "  |  " << endl;
	cout << "                                     |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                     |     |     |     |     |     |     |" << endl;
	cout << "                               6     |  " << sqb[61] << "  |  " << sqb[62] << "  |  " << sqb[63] << "  |  " << sqb[64] << "  |  " << sqb[65] << "  |  " << sqb[66] << "  |  " << endl;
	cout << "                                     |_____|_____|_____|_____|_____|_____|" << endl << endl;
	cout << "                                -X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-\n";
}
void board_bhit2()
{
	cout << endl;
	cout << "                                             Fog of War by Alev\n\n";
	cout << "                                  ---1-----2-----3-----4-----5-----6---\n";
	cout << "                                _____ _____ _____ _____ _____ _____" << endl;
	cout << "                               |     |     |     |     |     |     |" << endl;
	cout << "                              1|  " << sqb[11] << "  |  " << sqb[12] << "  |  " << sqb[13] << "  |  " << sqb[14] << "  |  " << sqb[15] << "  |  " << sqb[16] << "  |  " << endl;
	cout << "                               |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                               |     |     |     |     |     |     |" << endl;
	cout << "                              2|  " << sqb[21] << "  |  " << sqb[22] << "  |  " << sqb[23] << "  |  " << sqb[24] << "  |  " << sqb[25] << "  |  " << sqb[26] << "  |  " << endl;
	cout << "                               |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                               |     |     |     |     |     |     |" << endl;
	cout << "                              3|  " << sqb[31] << "  |  " << sqb[32] << "  |  " << sqb[33] << "  |  " << sqb[34] << "  |  " << sqb[35] << "  |  " << sqb[36] << "  |  " << "        Enemy Ships: " << enemy_ships << endl;
	cout << "                               |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                               |     |     |     |     |     |     |" << endl;
	cout << "                              4|  " << sqb[41] << "  |  " << sqb[42] << "  |  " << sqb[43] << "  |  " << sqb[44] << "  |  " << sqb[45] << "  |  " << sqb[46] << "  |  " << endl;
	cout << "                               |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                               |     |     |     |     |     |     |" << endl;
	cout << "                              5|  " << sqb[51] << "  |  " << sqb[52] << "  |  " << sqb[53] << "  |  " << sqb[54] << "  |  " << sqb[55] << "  |  " << sqb[56] << "  |  " << endl;
	cout << "                               |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                               |     |     |     |     |     |     |" << endl;
	cout << "                              6|  " << sqb[61] << "  |  " << sqb[62] << "  |  " << sqb[63] << "  |  " << sqb[64] << "  |  " << sqb[65] << "  |  " << sqb[66] << "  |  " << endl;
	cout << "                               |_____|_____|_____|_____|_____|_____|" << endl << endl;
	cout << "                                -X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-\n";
}
void board_a()
{
	cout << "                                   _____ _____ _____ _____ _____ _____" << endl;
	cout << "                                  |     |     |     |     |     |     |" << endl;
	cout << "                                  |  " << sqa[11] << "  |  " << sqa[12] << "  |  " << sqa[13] << "  |  " << sqa[14] << "  |  " << sqa[15] << "  |  " << sqa[16] << "  |  1" << endl;
	cout << "                                  |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                  |     |     |     |     |     |     |" << endl;
	cout << "                                  |  " << sqa[21] << "  |  " << sqa[22] << "  |  " << sqa[23] << "  |  " << sqa[24] << "  |  " << sqa[25] << "  |  " << sqa[26] << "  |  2" << endl;
	cout << "                                  |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                  |     |     |     |     |     |     |" << endl;
	cout << "                                  |  " << sqa[31] << "  |  " << sqa[32] << "  |  " << sqa[33] << "  |  " << sqa[34] << "  |  " << sqa[35] << "  |  " << sqa[36] << "  |  3" << "          Player Ships: " << player_ships << endl;
	cout << "                                  |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                  |     |     |     |     |     |     |" << endl;
	cout << "                                  |  " << sqa[41] << "  |  " << sqa[42] << "  |  " << sqa[43] << "  |  " << sqa[44] << "  |  " << sqa[45] << "  |  " << sqa[46] << "  |  4" << endl;
	cout << "                                  |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                  |     |     |     |     |     |     |" << endl;
	cout << "                                  |  " << sqa[51] << "  |  " << sqa[52] << "  |  " << sqa[53] << "  |  " << sqa[54] << "  |  " << sqa[55] << "  |  " << sqa[56] << "  |  5" << endl;
	cout << "                                  |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                  |     |     |     |     |     |     |" << endl;
	cout << "                                  |  " << sqa[61] << "  |  " << sqa[62] << "  |  " << sqa[63] << "  |  " << sqa[64] << "  |  " << sqa[65] << "  |  " << sqa[66] << "  |  6" << endl;
	cout << "                                  |_____|_____|_____|_____|_____|_____|" << endl << endl;
	cout << "                                  ---1-----2-----3-----4-----5-----6---\n";
}
void board_ahit1()
{
	cout << "                                      _____ _____ _____ _____ _____ _____" << endl;
	cout << "                                     |     |     |     |     |     |     |" << endl;
	cout << "                                     |  " << sqa[11] << "  |  " << sqa[12] << "  |  " << sqa[13] << "  |  " << sqa[14] << "  |  " << sqa[15] << "  |  " << sqa[16] << "  |  1" << endl;
	cout << "                                     |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                     |     |     |     |     |     |     |" << endl;
	cout << "                                     |  " << sqa[21] << "  |  " << sqa[22] << "  |  " << sqa[23] << "  |  " << sqa[24] << "  |  " << sqa[25] << "  |  " << sqa[26] << "  |  2" << endl;
	cout << "                                     |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                     |     |     |     |     |     |     |" << endl;
	cout << "                                     |  " << sqa[31] << "  |  " << sqa[32] << "  |  " << sqa[33] << "  |  " << sqa[34] << "  |  " << sqa[35] << "  |  " << sqa[36] << "  |  3" << "       Player Ships: " << player_ships << endl;
	cout << "                                     |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                     |     |     |     |     |     |     |" << endl;
	cout << "                                     |  " << sqa[41] << "  |  " << sqa[42] << "  |  " << sqa[43] << "  |  " << sqa[44] << "  |  " << sqa[45] << "  |  " << sqa[46] << "  |  4" << endl;
	cout << "                                     |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                     |     |     |     |     |     |     |" << endl;
	cout << "                                     |  " << sqa[51] << "  |  " << sqa[52] << "  |  " << sqa[53] << "  |  " << sqa[54] << "  |  " << sqa[55] << "  |  " << sqa[56] << "  |  5" << endl;
	cout << "                                     |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                                     |     |     |     |     |     |     |" << endl;
	cout << "                                     |  " << sqa[61] << "  |  " << sqa[62] << "  |  " << sqa[63] << "  |  " << sqa[64] << "  |  " << sqa[65] << "  |  " << sqa[66] << "  |  6" << endl;
	cout << "                                     |_____|_____|_____|_____|_____|_____|" << endl << endl;
	cout << "                                  ---1-----2-----3-----4-----5-----6---\n";
}
void board_ahit2()
{
	cout << "                                _____ _____ _____ _____ _____ _____" << endl;
	cout << "                               |     |     |     |     |     |     |" << endl;
	cout << "                               |  " << sqa[11] << "  |  " << sqa[12] << "  |  " << sqa[13] << "  |  " << sqa[14] << "  |  " << sqa[15] << "  |  " << sqa[16] << "  |  1" << endl;
	cout << "                               |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                               |     |     |     |     |     |     |" << endl;
	cout << "                               |  " << sqa[21] << "  |  " << sqa[22] << "  |  " << sqa[23] << "  |  " << sqa[24] << "  |  " << sqa[25] << "  |  " << sqa[26] << "  |  2" << endl;
	cout << "                               |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                               |     |     |     |     |     |     |" << endl;
	cout << "                               |  " << sqa[31] << "  |  " << sqa[32] << "  |  " << sqa[33] << "  |  " << sqa[34] << "  |  " << sqa[35] << "  |  " << sqa[36] << "  |  3" << "             Player Ships: " << player_ships << endl;
	cout << "                               |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                               |     |     |     |     |     |     |" << endl;
	cout << "                               |  " << sqa[41] << "  |  " << sqa[42] << "  |  " << sqa[43] << "  |  " << sqa[44] << "  |  " << sqa[45] << "  |  " << sqa[46] << "  |  4" << endl;
	cout << "                               |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                               |     |     |     |     |     |     |" << endl;
	cout << "                               |  " << sqa[51] << "  |  " << sqa[52] << "  |  " << sqa[53] << "  |  " << sqa[54] << "  |  " << sqa[55] << "  |  " << sqa[56] << "  |  5" << endl;
	cout << "                               |_____|_____|_____|_____|_____|_____|" << endl;
	cout << "                               |     |     |     |     |     |     |" << endl;
	cout << "                               |  " << sqa[61] << "  |  " << sqa[62] << "  |  " << sqa[63] << "  |  " << sqa[64] << "  |  " << sqa[65] << "  |  " << sqa[66] << "  |  6" << endl;
	cout << "                               |_____|_____|_____|_____|_____|_____|" << endl << endl;
	cout << "                                  ---1-----2-----3-----4-----5-----6---\n";
}

void player_deploy()
{
	player_ships = 12;
	int plot, message, count;

	for (; player_ships > 0; --player_ships)
	{
		board_b();
		board_a();

		srand(time(NULL));

		cout << "\n\n You have " << player_ships << " destroyers left. Where do you want to deploy them? ";
		cin >> plot;

		count = 0;
		//Checks if out of bounds
		while (plot < 11 || plot > 66 || (plot > 16 && plot < 21) || (plot > 26 && plot < 31) || (plot > 36 && plot < 41) 
				|| (plot > 36 && plot < 41) || (plot > 46 && plot < 51) || (plot > 56 && plot < 61) )
		{
			++count;
			message = (count % 5) + 1;
			coordinates = to_string(plot);

			cout << endl;

			switch (message) 
			{
			case 1:
				real(" Invalid coordinates. Please try again, Admiral "); real(user); real(". ");
				break;
			case 2:
				real(" Coordinates given are out of bounds. Try again, Admiral "); real(user); real(". ");
				break;
			case 3:
				real(" Out of bounds. Try again, Admiral "); real(user); real(". ");
				break;
			case 4:
				real(" Coordinates "); real(coordinates); real(" are outside the war map, Admiral "); real(user); real(". ");
				break;
			case 5:
				real(" Invalid. Awaiting new coordinates, Admiral "); real(user); real(". ");
				break;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> plot;
		}

		message = 0;
		while (sqa[plot] == '^') //Checks if coordinates are already taken
		{
			coordinates = to_string(plot);
			message = (count % 5) + 1;
			cout << endl;
			switch (message)
			{
			case 1:
				real(" A destroyer is already deployed on those coordinates. Please try again, Admiral. ");
				break;
			case 2:
				real(" Negative, Admiral "); real(user); real("."); Sleep(300);
				real(" Coordinates ");
				real(coordinates);
				real(" are already taken. ");
				break;
			case 3:
				real(" Invalid. A destroyer has already been deployed there, Admiral. ");
				break;
			case 4:
				real(" Coordinates unavailable. Please try again, Admiral. ");
				break;
			case 5:
				real(" Invalid. Coordinates "); Sleep(300); real(coordinates); real(" are already taken, Admiral "); real(user); real(". ");
				break;
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> plot;
			count++;

			//Checks if out of bounds AFTER checking availability
			while (plot < 11 || plot > 66 || (plot > 16 && plot < 21) || (plot > 26 && plot < 31) || (plot > 36 && plot < 41)
				|| (plot > 36 && plot < 41) || (plot > 46 && plot < 51) || (plot > 56 && plot < 61))
			{
				message = (count % 5) + 1;
				coordinates = to_string(plot);

				cout << endl;

				switch (message)
				{
				case 1:
					real(" Invalid coordinates. Please try again, Admiral "); real(user); real(". ");
					break;
				case 2:
					real(" Coordinates given are out of bounds. Try again, Admiral "); real(user); real(". ");
					break;
				case 3:
					real(" Out of bounds. Try again, Admiral "); real(user); real(". ");
					break;
				case 4:
					real(" Coordinates "); real(coordinates); real(" are outside the war map, Admiral "); real(user); real(". ");
					break;
				case 5:
					real(" Invalid. Awaiting new coordinates, Admiral "); real(user); real(". ");
					break;
				}

				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> plot;
				count++;
			}
		}

		cout << endl;
		message = rand() % 5 + 1;
		coordinates = to_string(plot);
		switch (message) //message after successful deployment
		{
		case 1:
			real(" Deploying a destroyer on coordinates "); real(coordinates); real(".");
			break;
		case 2:
			real(" Copy that, Admiral "); real(user); real(".");
			break;
		case 3:
			real(" Destroyer being deployed to "); real(coordinates); real(".");
			break;
		case 4:
			real(" Affirmative.");
			break;
		case 5:
			real(" Destroyer is on their way, Admiral.");
		}

		Sleep(1000);
		system("CLS");

		switch (plot)
		{
		case 11:
			sqa[11] = '^';
			break;
		case 12:
			sqa[12] = '^';
			break;
		case 13:
			sqa[13] = '^';
			break;
		case 14:
			sqa[14] = '^';
			break;
		case 15:
			sqa[15] = '^';
			break;
		case 16:
			sqa[16] = '^';
			break;
		case 21:
			sqa[21] = '^';
			break;
		case 22:
			sqa[22] = '^';
			break;
		case 23:
			sqa[23] = '^';
			break;
		case 24:
			sqa[24] = '^';
			break;
		case 25:
			sqa[25] = '^';
			break;
		case 26:
			sqa[26] = '^';
			break;
		case 31:
			sqa[31] = '^';
			break;
		case 32:
			sqa[32] = '^';
			break;
		case 33:
			sqa[33] = '^';
			break;
		case 34:
			sqa[34] = '^';
			break;
		case 35:
			sqa[35] = '^';
			break;
		case 36:
			sqa[36] = '^';
			break;
		case 41:
			sqa[41] = '^';
			break;
		case 42:
			sqa[42] = '^';
			break;
		case 43:
			sqa[43] = '^';
			break;
		case 44:
			sqa[44] = '^';
			break;
		case 45:
			sqa[45] = '^';
			break;
		case 46:
			sqa[46] = '^';
			break;
		case 51:
			sqa[51] = '^';
			break;
		case 52:
			sqa[52] = '^';
			break;
		case 53:
			sqa[53] = '^';
			break;
		case 54:
			sqa[54] = '^';
			break;
		case 55:
			sqa[55] = '^';
			break;
		case 56:
			sqa[56] = '^';
			break;
		case 61:
			sqa[61] = '^';
			break;
		case 62:
			sqa[62] = '^';
			break;
		case 63:
			sqa[63] = '^';
			break;
		case 64:
			sqa[64] = '^';
			break;
		case 65:
			sqa[65] = '^';
			break;
		case 66:
			sqa[66] = '^';
			break;
		}
	}
}
void afterplayer_deploy()
{
	system("CLS");
	board_b(); board_a();
	cout << endl << endl;
	real(" It is now the enemy's turn to deploy their destroyers."); Sleep(500);
	real(" Please wait a moment, Admiral "); real(user); real("."); Sleep(1000);
	
}
void ai_deploy()
{
	enemy_ships = 12;
	int plot, random;

	for (; enemy_ships > 0; --enemy_ships)
	{
		system("CLS");
		board_b();
		board_a();
		cout << " \n\n The enemy has " << enemy_ships << " destroyers left to deploy. ";

		if (enemy_ships == 12)
			Sleep(3000);

		do
		{
			srand(time(NULL));
			plot = rand() % 66 + 11;
			random = rand() % 6 + 1;
			coordinates = to_string(plot);

			if (plot > 66)
			{
				plot = 0;
				continue;
			}

			else if ((plot > 16 && plot < 21) || (plot > 26 && plot < 31) || (plot > 36 && plot < 41) || (plot > 46 && plot < 51) || (plot > 56 && plot < 61))
			{
				if (random == 1)
					plot = plot + 4;
				else if (random == 2)
					plot = plot - 4;
				else if (random == 3)
					plot = plot + 5;
				else if (random == 4)
					plot = plot - 5;
				else if (random == 5)
					plot = plot + 6;
				else if (random == 6)
					plot = plot - 6;
			}

			if (truesqb[plot] == 'v')
			{
				plot = 0;
			}
			else
				if (truesqb[plot] == ' ')
				{
					truesqb[plot] = 'v';
				}
				else
					real("\n Glitch! Report to Dev! Thank!");
			
		} while (plot == 0);

		coordinates = to_string(plot);
		//real("\n Enemy deployed a destroyer to "); real(coordinates); real("."); Sleep(1000);
	}
	system("CLS");
	board_b(); board_a();
	cout << " \n\n The enemy has " << enemy_ships << " destroyers left to deploy. ";
	real("\n Enemy's finished deploying their destroyers, Admiral."); Sleep(500);
}
void player_fire()
{
	int plot, count, message;

	system("CLS");
	board_b(); board_a();
	cout << endl << endl;
	real(" It is now your turn to fire, Admiral "); real(user); real("."); cout << endl; Sleep(500);
	cout <<" Awaiting for coordinates: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> plot;

	srand(time(NULL));
	count = 0;
	//Checks if out of bounds
	while (plot < 11 || plot > 66 || (plot > 16 && plot < 21) || (plot > 26 && plot < 31) || (plot > 36 && plot < 41)
		|| (plot > 36 && plot < 41) || (plot > 46 && plot < 51) || (plot > 56 && plot < 61))
	{
		++count;
		message = (count % 5) + 1;
		coordinates = to_string(plot);

		cout << endl;

		switch (message)
		{
		case 1:
			real(" Invalid coordinates. Please try again, Admiral "); real(user); real(". ");
			break;
		case 2:
			real(" Coordinates given are out of bounds. Try again, Admiral "); real(user); real(". ");
			break;
		case 3:
			real(" Out of bounds. Try again, Admiral "); real(user); real(". ");
			break;
		case 4:
			real(" Coordinates "); real(coordinates); real(" are outside the war map, Admiral "); real(user); real(". ");
			break;
		case 5:
			real(" Invalid. Awaiting new coordinates, Admiral "); real(user); real(". ");
			break;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> plot;
	}

	while (truesqb[plot] == 'X' || truesqb[plot] == 'O') //Checks if coordinates are already fired upon (hit/missed)
	{
		coordinates = to_string(plot);
		message = (count % 5) + 1;
		cout << endl;
		switch (message)
		{
		case 1:
			real(" Missiles have already been fired on those coordinates, Admiral. ");
			break;
		case 2:
			real(" Negative, Admiral "); real(user); real("."); Sleep(300);
			real(" Coordinates ");
			real(coordinates);
			real(" were already fired upon. ");
			break;
		case 3:
			real(" Invalid. Missiles have already been fired there. ");
			break;
		case 4:
			real(" Coordinates unavailable. Please try again, Admiral. ");
			break;
		case 5:
			real(" Invalid coordinates. "); Sleep(300); real(" Awaiting new orders. ");
			break;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> plot;
		count++;

		//Checks if out of bounds AFTER checking availability
		while (plot < 11 || plot > 66 || (plot > 16 && plot < 21) || (plot > 26 && plot < 31) || (plot > 36 && plot < 41)
			|| (plot > 36 && plot < 41) || (plot > 46 && plot < 51) || (plot > 56 && plot < 61))
		{
			message = (count % 5) + 1;
			coordinates = to_string(plot);

			cout << endl;

			switch (message)
			{
			case 1:
				real(" Invalid coordinates. Please try again, Admiral "); real(user); real(". ");
				break;
			case 2:
				real(" Coordinates given are out of bounds. Try again, Admiral "); real(user); real(". ");
				break;
			case 3:
				real(" Out of bounds. Try again, Admiral "); real(user); real(". ");
				break;
			case 4:
				real(" Coordinates "); real(coordinates); real(" are outside the war map, Admiral "); real(user); real(". ");
				break;
			case 5:
				real(" Invalid. Awaiting new coordinates, Admiral "); real(user); real(". ");
				break;
			}

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> plot;
			count++;
		}
	}

	cout << endl;
	message = rand() % 5 + 1;
	coordinates = to_string(plot);
	
	switch (message) //message after successful deployment
	{
	case 1:
		real(" Firing missiles on coordinates "); real(coordinates); real(".");
		break;
	case 2:
		real(" Copy that, Admiral "); real(user); real(".");
		break;
	case 3:
		real(" Missiles fired to "); real(coordinates); real(".");
		break;
	case 4:
		real(" Affirmative.");
		break;
	case 5:
		real(" Fire away. ");
	}

	PlaySoundW(L"sounds/fire.wav", NULL, SND_FILENAME | SND_SYNC);
	Sleep(500);

	if (truesqb[plot] == ' ')
	{
		system("COLOR 0B");
		PlaySoundW(L"sounds/missed.wav", NULL, SND_FILENAME | SND_ASYNC);
		Sleep(350);
		system("COLOR 07");
		Sleep(2500);
		sqb[plot] = 'O';
		truesqb[plot] = 'O';
		real(" Missed.");
	}
	else if (truesqb[plot] == 'v')
	{
		system("COLOR 0C");
		PlaySoundW(L"sounds/exp.wav", NULL, SND_FILENAME | SND_ASYNC);
		Sleep(100);
		system("CLS");
		board_bhit1();
		board_a();
		Sleep(100);
		system("CLS");
		board_b();
		board_a();
		Sleep(100);
		system("CLS");
		board_bhit2();
		board_a();
		Sleep(100);
		system("CLS");
		board_b();
		board_a();
		Sleep(100);
		system("CLS");
		board_bhit1();
		board_a();
		Sleep(100);
		system("CLS");
		board_b();
		board_a();
		Sleep(350);
		system("COLOR 07");
		Sleep(2000);
		system("COLOR 07");
		
		sqb[plot] = 'X';
		truesqb[plot] = 'X';
		real(" Hit!");
		--enemy_ships;
		hit++;
	} 
	Sleep(500);
}
void enemy_fire()
{
	int plot, random;
	
	system("CLS");
	board_b();
	board_a();
	cout << endl << endl;
	real(" Enemy's turn to fire, please wait. ");
	Sleep(500);

	do
	{
		srand(time(NULL));
		plot = rand() % 66 + 11;
		random = rand() % 6 + 1;
		coordinates = to_string(plot);

		if (plot > 66)
		{
			plot = 0;
			continue;
		}

		else if ((plot > 16 && plot < 21) || (plot > 26 && plot < 31) || (plot > 36 && plot < 41) || (plot > 46 && plot < 51) || (plot > 56 && plot < 61))
		{
			if (random == 1)
				plot = plot + 4;
			else if (random == 2)
				plot = plot - 4;
			else if (random == 3)
				plot = plot + 5;
			else if (random == 4)
				plot = plot - 5;
			else if (random == 5)
				plot = plot + 6;
			else if (random == 6)
				plot = plot - 6;
		}

		if (sqa[plot] == 'X' || sqa[plot] == 'O')
		{
			plot = 0;
			continue;
		}

		cout << endl;
		real(" The enemy fired on coordinates "); cout << plot; real(".");
		PlaySoundW(L"sounds/enemyfire.wav", NULL, SND_FILENAME | SND_SYNC);
		Sleep(250);

		if (sqa[plot] == ' ')
		{
			system("COLOR 0B");
			PlaySoundW(L"sounds/splash.wav", NULL, SND_FILENAME | SND_ASYNC);
			Sleep(350);
			system("COLOR 07");
			Sleep(2100);
			sqa[plot] = 'O';
			real(" Missed.");
		}
		else
			if (sqa[plot] == '^')
			{
				system("COLOR 0C");
				PlaySoundW(L"sounds/enemyhit.wav", NULL, SND_FILENAME | SND_ASYNC);
				system("CLS");
				board_b();
				board_ahit1();
				Sleep(100);
				system("CLS");
				board_b();
				board_a();
				Sleep(100);
				system("CLS");
				board_b();
				board_ahit2();
				Sleep(100);
				system("CLS");
				board_b();
				board_a();
				Sleep(350);
				system("COLOR 07");
				Sleep(5500);
				sqa[plot] = 'X';
				real(" Hit!"); Sleep(200); real(" We lost destroyer "); cout << plot; real(".");
				player_ships--;
			}
			else
			{
				real(" Bug! Report to Dev! Thank you! ");
				cin.get();
			}

		Sleep(500);
	} while (plot == 0);
}
void endgame()
{
	system("CLS");
	board_b();
	board_a();

	accuracy = hit / missiles_launched * 100.0;
	missed = missiles_launched - hit;

	cout << endl << endl;
	if (enemy_ships == 0)
	{
		real(" Congratulations, Admiral "); real(user); real("! You won the war!");
	}
	else
		real(" You Lost, Admiral "); real(user); real(".");

	Sleep(500); cout << endl << endl << endl;

	cout << "                       Player Statistics" << endl;
	cout << " Missiles Launched: " << missiles_launched << "   Hits: " << hit << "   Missed: " << missed << "   Accuracy: " << accuracy << "%";
	Sleep(1000);

	cout << "\n\n\n\n\n\n\n";
	cout << "     __________________________________" << endl;
	cout << "    |                                  |" << endl;
	cout << "    |    Coded by: Alexandrinne Levi   |" << endl;
	cout << "    |       exactfalse@gmail.com       |" << endl;
	cout << "    |__________________________________|" << endl << endl;
	cout << "       For recreational use only." << endl;
	cout << "       Not for retail, reselling or" << endl;
	cout << "       any ways of creating income.";
	cout << "\n\n\n\n";

	cout << " Press ENTER to exit";
	cin.ignore();
	cin.get();
}

int main()
{
	
	username();
	guide();
	player_deploy();
	afterplayer_deploy();
	ai_deploy();

	player_ships = 12, enemy_ships = 12;
	missiles_launched = 0;

	do
	{
		player_fire();
		missiles_launched++;
		if (enemy_ships == 0)
			continue;
		enemy_fire();
	} while (player_ships > 0 && enemy_ships > 0);
	
	endgame();
	
	return 0;
}

//Planned Updates:
//Sound Effects!
//intercept coordinates
//Moveable ships, Hit streaks bonus, Scanner (bonus move)
//Different versions of ships, different ammunitions
//Bigger war map
//2 Player Mode