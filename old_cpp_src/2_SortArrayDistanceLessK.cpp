#if 0
/*
已知一个几乎有序的数组。几乎有序是指，如果把数组排好顺序的话，每个元素移动的距离一定不超过k
k相对于数组长度来说是比较小的。请选择一个合适的排序策略，对这个数组进行排序。
*/
#include <queue>
#include "ShowArray.h"

using namespace std;

void sortedArrDistanceLessK(int arr[], int size, int k);

int main()
{
	int arr[] = { 2,3,0,1,6,7,4,5,99,88 }; //k = 2
	int size = sizeof(arr) / sizeof(int);
	showArray(arr, size);
	sortedArrDistanceLessK(arr, size, 2);
	showArray(arr, size);
	return 0;
}

void sortedArrDistanceLessK(int arr[], int size, int k)
{
	// 默认大根堆,要声明成小根堆
	priority_queue<int, vector<int>, greater<int>> heap;
	int index = 0;
	for (; index <= min(size - 1, k - 1); ++index)
	{
		heap.push(arr[index]);
	}
	int i = 0;
	for (; index < size; ++i, ++index)
	{
		heap.push(arr[index]);
		arr[i] = heap.top();
		heap.pop();
	}
	while (!heap.empty())
	{
		arr[i++] = heap.top();
		heap.pop();
	}

}
#endif