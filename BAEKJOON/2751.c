/* Merge Sort */
#include <stdio.h>
#include <stdlib.h>

int *sorting_data;

void merge(int* data, int left, int mid, int right)
{
	int i, j, k, l;
	i = k = left;
	j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (data[i] <= data[j])
			sorting_data[k++] = data[i++];
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

void merge_sort(int* data, int left, int right)
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
	int N,i;
	int *data;
	scanf("%d", &N);
	data = (int *)malloc(sizeof(data)*N);
	sorting_data = (int *)malloc(sizeof(sorting_data)*N);
	for (i = 0; i < N; i++)
		scanf("%d", &data[i]);
	merge_sort(data, 0, N - 1);

	for (i = 0; i < N; i++)
		printf("%d\n", data[i]);
}