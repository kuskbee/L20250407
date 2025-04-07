#include <iostream>
#include <random>
#include <conio.h>

#define CARD_COUNT		52

void Initialize(int* Deck);
void Shuffle(int* Deck);
void PlayBlackJack(int* Deck);
void PrintCard(int TrumpCard);
int GetCardScore(int TrumpCard);

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

void Initialize(int* Deck)
{
	for (int Index = 0; Index < CARD_COUNT; Index++)
	{
		Deck[Index] = Index;
	}
}

void Shuffle(int* Deck)
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

void PlayBlackJack(int* Deck)
{
	int ComputerSum = 0;
	int PlayerSum = 0;
	int turn = 0;

	int Index = 0;
	bool GameOver = false;
	while (true)
	{
		if (Index + 1 > 52)
		{
			cout << "Game Over" << endl;
			break;
		}

		// Computer Turn
		if (turn % 2 == 0)
		{
			cout << "(Computer's Turn) ";
			ComputerSum += GetCardScore(Deck[Index]);
			PrintCard(Deck[Index]);
			cout << ", ";

			ComputerSum += GetCardScore(Deck[Index + 1]);
			PrintCard(Deck[Index + 1]);
			cout << " => " << ComputerSum;
			cout << endl;
		}
		// Player Turn
		else
		{
			cout << "(Player's Turn) ";
			PlayerSum += GetCardScore(Deck[Index]);
			PrintCard(Deck[Index]);
			cout << ", ";

			PlayerSum += GetCardScore(Deck[Index + 1]);
			PrintCard(Deck[Index + 1]);
			cout << " => " << PlayerSum;
			cout << endl;
		}
		//line
		cout << "==================" << endl;

		//Check
		if (turn % 2 == 1) {
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
				if (ComputerSum > 21 && PlayerSum > 21)
				{
					cout << "¹«½ÂºÎ" << endl;
				}
				else if (ComputerSum > 21)
				{
					cout << "Computer Lose!!" << endl;
				}
				else
				{
					cout << "Player Lose!!" << endl;
				}
				break;
			}
		}

		Index += 2;
		turn++;
	}


}

// TrumpCard : (0 ~ 51)
void PrintCard(int TrumpCard)
{
	cout << " (" << TrumpCard << ")";
	int shape = TrumpCard / 13;

	switch (shape)
	{
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
	if (Number == 1)
	{
		cout << 'A';
	}
	else if (Number == 11)
	{
		cout << "J";
	}
	else if (Number == 12)
	{
		cout << "Q";
	}
	else if (Number == 13)
	{
		cout << "K";
	}
	else
	{
		cout << Number;
	}
}

int GetCardScore(int TrumpCard)
{
	int Number = TrumpCard % 13 + 1;
	if (Number > 10) {
		Number = 10;
	}
	return Number;
}

void BlackJack()
{
	srand((unsigned int)time(NULL));

	int Deck[CARD_COUNT] = { 0, };

	Initialize(Deck);
	Shuffle(Deck);
	PlayBlackJack(Deck);
	return;
}

int Add(int A, int B)
{
	return A + B;
}

int Subtract(int A, int B)
{
	return A - B;
}

int main()
{
	//SelectRandomBalls_Kusk();

	BlackJack();

	//cout << Add(10, 20) << endl;
	//cout << Subtract(10, 20) << endl;

	return 0;
}