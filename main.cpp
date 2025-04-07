#include <iostream>
#include <random>
#include <conio.h>

#define CARD_COUNT		52

void Initialize(int  Deck[CARD_COUNT]);
void Shuffle(int  Deck[CARD_COUNT]);
void Print(int  Deck[CARD_COUNT]);
int PrintCard(int TrumpCard);

using namespace std;

//void SelectRandomBalls_Kusk()
//{
//	random_device rd;
//	mt19937 mt(rd());
//	uniform_int_distribution<unsigned int> dist(0, 99);
//	unsigned int random = dist(mt);
//
//	srand((unsigned int)time(NULL));
//	int SelectedBallsSorted[CARD_COUNT] = { 0, };
//	int SelectedBalls[CARD_COUNT] = { 0, };
//
//	for (int i = 0; i < CARD_COUNT; i++)
//	{
//		int Ball = rand() % CARD_COUNT;
//
//		bool IsSame = false;
//		while (SelectedBallsSorted[Ball] > 0) {
//			Ball = rand() % CARD_COUNT;
//		}
//
//		SelectedBallsSorted[Ball] = Ball + 1;
//		SelectedBalls[i] = Ball + 1;
//
//		cout << "Selected " << Ball << "." << endl << endl;
//	}
//
//	cout << "Finished" << endl;
//
//	for (int i = 0; i < CARD_COUNT; i++) {
//		cout << SelectedBallsSorted[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < CARD_COUNT; i++) {
//		cout << SelectedBalls[i] << " ";
//	}
//	cout << endl;
//}

void Initialize(int  Deck[CARD_COUNT])
{
	for (int Index = 0; Index < CARD_COUNT; Index++)
	{
		Deck[Index] = Index + 1;
	}
}

void Shuffle(int  Deck[CARD_COUNT])
{
	int temp = 0;
	for (int Count = 0; Count < CARD_COUNT * 100; Count++)
	{
		int First = rand() % CARD_COUNT;
		int Second = rand() % CARD_COUNT;
		temp = Deck[First];
		Deck[First] = Deck[Second];
		Deck[Second] = temp;
	}
}

void Print(int  Deck[CARD_COUNT])
{
	int ComputerSum = 0;
	int PlayerSum = 0;
	int turn = 0;

	int Index = 0;
	bool GameOver = false;
	while (true)
	{
		if (Index + 1 > 52) {
			cout << "Game Over" << endl;
			break;
		}

		// Computer Turn
		if (turn % 2 == 0)
		{
			cout << "(Computer's Turn) ";
			ComputerSum += PrintCard(Index);
			cout << ", ";
			ComputerSum += PrintCard(Index + 1);
			cout << " => " << ComputerSum;
			cout << endl;
		}
		// Player Turn
		else
		{
			cout << "(Player's Turn) ";
			PlayerSum += PrintCard(Deck[2]);
			cout << ", ";
			PlayerSum += PrintCard(Deck[3]);
			cout << " => " << PlayerSum;
			cout << endl;
		}
		//line
		cout << "==================" << endl;

		//Check
		if (ComputerSum == 21) 
		{
			cout << "Computer's Win!!" << endl;
			GameOver = true;
			break;
		}
		else if (PlayerSum == 21)
		{
			cout << "Player's Win!!" << endl;
			GameOver = true;
			break;
		}
		else if (ComputerSum > 21 || PlayerSum > 21)
		{
			if (ComputerSum > 21 && PlayerSum > 21) {
				cout << "¹«½ÂºÎ" << endl;
			}
			else if (ComputerSum > 21) {
				cout << "Computer Lose!!" << endl;
			}
			else {
				cout << "Player Lose!!" << endl;
			}
			break;
		}

		Index += 2;
		turn++;
	}


}

// TrumpCard : (0 ~ 51)
int PrintCard(int TrumpCard) {
	int shape = TrumpCard / 13;
	
	switch (shape) {
	case 0: 
		cout << "¢¼";
		break;
	case 1:
		cout << "¢À";
		break;
	case 2:
		cout << "¡ß";
		break;
	case 3:
		cout << "¢¾";
		break;
	}
	
	int Number = TrumpCard % 13 + 1;
	if (Number == 1) {
		cout << 'A';
	}
	else if (Number == 11) {
		cout << "J";
	}
	else if (Number == 12) {
		cout << "Q";
	}
	else if (Number == 13) {
		cout << "K";
	}
	else {
		cout << Number;
	}

	return Number;
}

void SelectRandomBalls_Lecture()
{
	srand((unsigned int)time(NULL));

	int Deck[CARD_COUNT] = { 0, };

	Initialize(Deck);
	Shuffle(Deck);
	Print(Deck);
	return;
}

int Add(int A, int B) {
	return A + B;
}

int Subtract(int A, int B) {
	return A - B;
}

int main()
{
	//SelectRandomBalls_Kusk();

	SelectRandomBalls_Lecture();

	//cout << Add(10, 20) << endl;
	//cout << Subtract(10, 20) << endl;

	return 0;
}