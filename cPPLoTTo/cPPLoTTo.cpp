#include <iostream>
using namespace std;


enum
{
	LOTTO_LEN =6
};

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void Sort(int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int minIdx = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[minIdx])
			{
				minIdx = j;
			}
		}
		if (minIdx != i)
		{
			Swap(arr[i], arr[minIdx]);
		}
	}
}


void CreateLotto(int arr[], int size)
{	
	int count = 0;

	while (count < size)
	{
		bool flag = false;
		int random = rand() % 45 + 1;

		if (count == 0)
		{
			arr[0] = random;
			count++;
		}
		else
		{
			for (int i = 0; i < count; i++)
			{
				if (arr[i] == random)
				{
					flag = true;
					break;
				}
			}

			if(!flag)
			{
				arr[count] = random;
				count++;
			}
		}
		
	}

	
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	int arr[LOTTO_LEN] = {};
	
	CreateLotto(arr, LOTTO_LEN);


	Sort(arr, static_cast<int>(LOTTO_LEN));

	for (auto data : arr)
	{
		cout << data << endl;
	}


	return 0;
}
