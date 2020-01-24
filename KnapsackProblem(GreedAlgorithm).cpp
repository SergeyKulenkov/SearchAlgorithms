// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "fstream"
#include "stdlib.h"

using namespace std;

const int N = 15;

void OutAll(int Q, int sum)
{
	cout  << "total price" << Q << endl;
	cout << "total weight" << sum << endl << endl;
}

int main()
{
	int currentWeight = 0, summaryWeight = 0, Solution[N], maxWeight = 0, maxPrice = 0, Quality = 0, Price[N], Weight[N];
	int index, price, weight;
	ifstream text("C:\\Users\\Elen\\Desktop\\visual\\file9.txt");

	while (text >> index >> price >> weight)
	{
		Price[index - 1] = price;
		Weight[index - 1] = weight;
		summaryWeight += Weight[index - 1];
		cout << index << " " << price << " " << weight << " " << endl;
	}

	cout << "enter maxWeight";
	cin >> maxWeight;
	while (maxWeight > summaryWeight)
	{
		cout << "maxWeight is too big" << endl;
		cout << "enter maxWeight";
		cin >> maxWeight;
	}
	
	for (int i = 0; i < N; i++)
	{
		Solution[i] = 0;
	}

	for (int j = 0; j < N; j++)
	{
		cout << "step number - " << j + 1 << endl;
		int e = 0;
		for (int i = 0; i < N; i++)
		{
			if (maxPrice < Price[i])
			{
				e = i;
				maxPrice = Price[i];
			}
		}
		Price[e] = 0;

		if (currentWeight + Weight[e] <= maxWeight)
		{
			Quality += maxPrice;
			currentWeight += Weight[e];
			Solution[e] = 1;

			cout << "number of the element - " << e + 1 << endl;
			cout << "price of this element - " << maxPrice << endl;
			OutAll(Quality, currentWeight);
		}

		maxPrice = 0;
	}

	cout << endl << endl;
	OutAll(Quality, currentWeight);
	for (int i = 0; i < N; i++)
	{
		cout << Solution[i] << " ";
	}
	cout << endl << endl;

	return 0;
}
