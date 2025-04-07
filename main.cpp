#include <iostream>
#include <set>
#include <conio.h>

using namespace std;



int main()
{
	srand((unsigned int)time(NULL));
	int SelectedBallsSorted[52] = { 0, };
	int SelectedBalls[52] = { 0, };

	for (int i = 0; i < 52; i++)
	{
		int Ball = rand() % 52;

		bool IsSame = false;
		while (SelectedBallsSorted[Ball] > 0) {
			Ball = rand() % 52;
		}

		SelectedBallsSorted[Ball] = Ball + 1;
		SelectedBalls[i] = Ball + 1;

		cout << "Selected " << Ball << "." << endl << endl;

		cout << "Please Enter Any key. " << endl;

		//_getch();

	}

	cout << "Finished" << endl;

	for (int i = 0; i < 52; i++) {
		cout << SelectedBallsSorted[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 52; i++) {
		cout << SelectedBalls[i] << " ";
	}
	cout << endl;

	return 0;
}