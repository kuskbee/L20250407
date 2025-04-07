#include <iostream>
#include <set>
#include <conio.h>

using namespace std;


int main()
{
	srand((unsigned int)time(NULL));
	int SelectedBalls[52] = { 0, };

	for (int i = 0; i < 52; i++)
	{
		int Ball = rand() % 52 + 1;

		bool IsSame = false;
		do
		{
			IsSame = false;
			for (int j = 0; j < i; j++)
			{
				if (SelectedBalls[j] == Ball) {
					IsSame = true;
					Ball = rand() % 52 + 1;
					break;
				}
			}
		}
		while(IsSame);

		SelectedBalls[i] = Ball;

		cout << "Selected " << Ball << "." << endl << endl;

		cout << "Please Enter Any key. " << endl;

		_getch();

	}

	cout << "Finished" << endl;

	for (int i = 0; i < 52; i++) {
		cout << SelectedBalls[i] << " ";
	}
	cout << endl;

	return 0;
}