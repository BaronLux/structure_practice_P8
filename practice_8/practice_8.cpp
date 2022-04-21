#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int VisibleCount(vector<int> stack)
{
	int f = stack[0]; // f самое первое здание
	// первое здание всегда видно
	// изначально оно же самое высокое
	int count = 1, highest = f;

	for (int i = 1; i < stack.size(); i++)
	{
		// если i ое здание выше первого и выше самого высокого
		if (f < stack[i] && highest < stack[i])
		{
			// то оно становится самым высоким и количество видимых зданий увеличивается на 1
			count++;
			highest = stack[i];
		}
	}
	return count;
}


/*
6
8 2 3 11 11 10

5
12 20 39 45 89
*/
int main()
{
	setlocale(0, "");
	int count, height, building_number;
	cin >> count;
	auto buildings = vector<int>();
	for (building_number = 0; building_number < count; building_number++)
	{
		cin >> height;
		buildings.push_back(height); // добавление в конец стека здание
	}
	cout << VisibleCount(buildings);
}