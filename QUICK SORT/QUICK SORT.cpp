#include<iostream>
using namespace std;

void quickSort(int arr[], int, int);
int partition(int arr[], int, int);

int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };

	quickSort(arr, 0, 5);

	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << ", ";
	}

	return 0;
}

void quickSort(int arr[], int first, int last)
{
	if (first >= last)
	{
		return;
	}

	int pos = partition(arr, first, last);

	quickSort(arr, first, pos - 1);
	quickSort(arr, pos + 1, last);
}

int partition(int arr[], int first, int last)
{
	int i = first, j = last, pos = first;
	int temp;

	while (1)
	{
		while ((arr[pos] <= arr[j]) && (pos != j))
		{
			j = j - 1;
		}

		if (pos == j)
			return pos;

		if (arr[pos] > arr[j])
		{
			temp = arr[pos];
			arr[pos] = arr[j];
			arr[j] = temp;

			pos = j;
		}

		while ((arr[pos] >= arr[i]) && (pos != i))
		{
			i = i + 1;
		}

		if (pos == i)
			return pos;

		if (arr[pos] < arr[i])
		{
			temp = arr[pos];
			arr[pos] = arr[i];
			arr[i] = temp;

			pos = i;
		}
	}
}