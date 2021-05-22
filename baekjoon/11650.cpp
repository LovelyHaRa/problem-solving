#include<iostream>
#include<cstdlib>

using namespace std;

int **sorting_data;

void merge(int** data, int left, int mid, int right)
{
	int i, j, k, l;
	i = k = left;
	j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (data[i][0] < data[j][0])
			sorting_data[k++] = data[i++];
		else if (data[i][0] == data[j][0])
		{
			if (data[i][1] <= data[j][1])
				sorting_data[k++] = data[i++];
			else
				sorting_data[k++] = data[j++];
		}
		else
			sorting_data[k++] = data[j++];
	}

	if (i > mid)
	{
		for (l = j; l <= right; l++)
			sorting_data[k++] = data[l];
	}
	else
	{
		for (l = i; l <= mid; l++)
			sorting_data[k++] = data[l];
	}

	for (i = left; i <= right; i++)
		data[i] = sorting_data[i];
}

void merge_sort(int** data, int left, int right)
{
	int mid = (left + right) / 2;
	if (left < right)
	{
		merge_sort(data, left, mid);
		merge_sort(data, mid + 1, right);
		merge(data, left, mid, right);
	}
}

int main(void)
{
	int n;
	cin >> n;
	int **data;
	data = (int**)malloc(sizeof(data)*n);
	sorting_data = (int**)malloc(sizeof(sorting_data)*n);
	for (int i = 0; i < n; i++)
	{
		data[i] = (int*)malloc(sizeof(data)*2);
		sorting_data[i] = (int*)malloc(sizeof(sorting_data)*2);
		cin >> data[i][0] >> data[i][1];
	}
	merge_sort(data, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << data[i][0] << ' ' << data[i][1] << '\n';
}
