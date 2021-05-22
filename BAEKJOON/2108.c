#include<stdio.h>
#include<stdlib.h>

/* 퀵정렬 자체 구현(타임아웃)
void quickSort(int *arr, int left, int right)
{
	int pivot, left_temp, right_temp;
	left_temp = left;
	right_temp = right;
	pivot = arr[left];
	while (left < right) {
		while (arr[right] >= pivot && (left < right)) {
			right--;
		}
		if (left != right) {
			arr[left] = arr[right];
		}
		while (arr[left] <= pivot && (left < right)) {
			left++;
		}
		if (left != right) {
			arr[right] = arr[left];
			right--;
		}
	}
	arr[left] = pivot;
	pivot = left;
	left = left_temp;
	right = right_temp;
	if (left < pivot) quickSort(arr, left, pivot - 1);
	if (right > pivot) quickSort(arr, pivot + 1, right);
}
*/

int compare(void *first, void *second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int issign(int x)
{
	if (x > 4000)
		return (x - 4000)*-1;
	return x;
}

int main(void)
{
	int *data, count[8001] = { 0 }, *freq_data;
	int N;
	int i;
	int min = 4001, max = -4001, sum = 0, freq = 0, k = 0;
	scanf("%d", &N);
	data = (int*)malloc(sizeof(data)*N);
	freq_data = (int*)malloc(sizeof(freq_data)*N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &data[i]);
		min = min > data[i] ? data[i] : min;
		max = max < data[i] ? data[i] : max;
		sum += data[i];
		if (data[i] < 0) { count[-data[i]+4000]++; }
		else { count[data[i]]++; }
	}
	qsort(data, N, sizeof(int), compare);
	for (i = 0; i <= 8000; i++)
	{
		if (freq != 0 && freq == count[i])
			freq_data[k++] = issign(i);
		else if (count[i] > freq)
		{
			k = 0;
			freq_data[k++] = issign(i);
			freq = count[i];
		}
	}
	if (k > 1)
	{
		qsort(freq_data, k, sizeof(int), compare);
		freq = freq_data[1];
	}
	else
		freq = freq_data[0];

	printf("%d\n%d\n%d\n%d\n", sum >= 0 ? (int)((double)sum / N + 0.5) : (int)((double)sum / N - 0.5), data[N / 2], freq, max - min);
}