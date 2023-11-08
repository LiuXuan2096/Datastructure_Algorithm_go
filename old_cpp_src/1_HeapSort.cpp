#if 0
#include <iostream>

using namespace std;

void heapSort(int arr[], int size);
void heapInsert(int arr[], int index);
void heapify(int arr[], int index, int heapSize);

int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(arr) / sizeof(int);
	cout << "[";
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
	heapSort(arr, size);
	cout << "[";
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
	return 0;
}

// ���������
void heapInsert(int arr[], int index)
{
	while (arr[index] > arr[(index - 1) / 2])
	{
		swap(arr[index], arr[(index - 1) / 2]);
	}
	index = (index - 1) / 2;
}

// arr[index]λ�õ������ܷ������ƶ�
void heapify(int arr[], int index, int heapSize)
{
	int left = (index << 1) + 1;
	while (left < heapSize)
	{
		// �·����к��ӵ�ʱ��
		// ���������У�˭��ֵ�󣬰��±��largest
		// 1��ֻ�����ӣ�left -> largest
		// 2) ͬʱ�����Ӻ��Һ��ӣ��Һ��ӵ�ֵ<= ���ӵ�ֵ��left -> largest
		// 3) ͬʱ�����Ӻ��Һ��Ӳ����Һ��ӵ�ֵ> ���ӵ�ֵ�� right -> largest
		int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
		// ���ͽϴ�ĺ���֮�䣬˭��ֵ�� ���±��largest
		largest = arr[largest] > arr[index] ? largest : index;
		if (largest == index)
		{
			break;
		}
		swap(arr[largest], arr[index]);
		index = largest;
		left = (index << 1) + 1;
	}
}

void heapSort(int arr[], int size)
{
	if (size <= 1)
	{
		return;
	}
	// O(N*logN)
//		for (int i = 0; i < arr.length; i++) { // O(N)
//			heapInsert(arr, i); // O(logN)
//		}
	// O(N)
	for (int i = size - 1; i >= 0; --i)
	{
		heapify(arr, i, size);
	}
	int heapSize = size;
	swap(arr[0], arr[--heapSize]);
	// O(N*logN)
	while (heapSize > 0)
	{
		heapify(arr, 0, heapSize);
		swap(arr[0], arr[--heapSize]);
	}

}
#endif

