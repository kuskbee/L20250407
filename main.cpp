#include <iostream>
#include <set>
#include <conio.h>

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	set<int> selectedBalls;

	for (int i = 0; i < 52; i++) {

		int ball = rand() % 52 + 1;
		while (selectedBalls.count(ball) > 0) {
			ball = rand() % 52 + 1;
		}

		selectedBalls.insert(ball);

		cout << "Selected " << ball << "." << endl << endl;

		cout << "Please Enter Any key. " << endl;

		_getch();

	}

	cout << "Finished" << endl;

	return 0;
}