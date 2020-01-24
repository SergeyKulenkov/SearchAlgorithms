// metod 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "stdlib.h"
#include "time.h"

using namespace std;

const int n = 15;

int main()
{
	int Distance[n][n], minimalDistance = 0, i = 0, Solution[n], Indexes[n], elements = n, summaryDistance = 0;
	srand(time(0));
	int r = rand() % n, r2 = n;

	for (int j = 0; j < n; j++)
	{
		Solution[j] = 0;
		Indexes[j] = j;
		for (int k = 0; k < n; k++)
		{
			Distance[j][k] = rand() % r2 + 1;
			if (k == j) Distance[j][k] = 0;
			cout << Distance[j][k] << " ";
		}
		cout << endl;
	}
	minimalDistance = 20;

	Solution[i] = Indexes[r];
	cout << "first city - " << Solution[i] + 1 << endl << endl;
	Indexes[r] = -1;
	elements -= 1;
	i++;

	while(elements != 0)
	{
		int el = 0;
		for (int j = 0; j < n; j++)
		{
			if (minimalDistance > Distance[Solution[i-1]][j] && Indexes[j] != -1)
			{
				el = j;
				minimalDistance = Distance[Solution[i - 1]][j];
			}
		}
		Solution[i] = Indexes[el];
		Indexes[el] = -1;
		summaryDistance += minimalDistance;
		cout << "step - " << i << endl;
		cout << "elements in X - " << elements << endl;
		cout << "distance - " << minimalDistance << endl;
		cout << "number - " << Solution[i] + 1<< endl;
		cout << "total distance " << summaryDistance << endl;
		elements -= 1;
		i++;
		minimalDistance = r2;
	}

	cout << endl << endl;
	summaryDistance += Distance[Solution[n-1]][Solution[0]];
	cout << "total distance - " << summaryDistance << endl;
	for (int j = 0; j < n; j++) cout << Solution[j] + 1	<< " ";

	return 0;
}