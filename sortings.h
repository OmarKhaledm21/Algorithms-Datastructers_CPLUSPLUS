#pragma once
#include <iostream>
using namespace std;

class sortings
{
public:
	static void print_arr(int nums[], int length) {
		for (int i = 0; i < length; i++) {
			cout << nums[i] << " ";
		}
		cout << endl;
	}

	static void insertionSort(int arr[],int len) { // 2 4 6 8 3
		int element;
		for (int i = 1,j; i < len; i++) {
			element = arr[i];
			for (j = i; j > 0 && arr[j - 1] > element; j--) {
				arr[j] = arr[j - 1];
			}
			arr[j] = element;
			print_arr(arr, len);
		}
		
	}

	static void selectionSort(int arr[], int len) {
		int ind=0, val=0;
		for (int i = 0; i < len - 1; i++) {
			ind = i;
			val = arr[i];
			for (int j = i+1; j < len; j++) {
				if (arr[j] < val) {
					ind = j;
					val = arr[j];
				}
			}
			swap(arr[i],arr[ind]);
			print_arr(arr, len);
		}
		print_arr(arr, len);
	}

	static void bubbleSort(int arr[], int len) {
		for (int i = 0; i < len; i++) {
			bool loop = false;
			for (int j = 0; j < len - 1 - i; j++) {
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
					loop = true;
				}
			}

			if (!loop) {
				break;
			}
			print_arr(arr, len);
		}

		print_arr(arr, len);
	}

	static void shellSort(int arr[],int len) {
		for (int interval = len / 2; interval > 0; interval /= 2) {
			for (int i = interval; i < len; i++) {
				int key = arr[i];
				int j = i;

				while (j >= interval && arr[j - interval] > key) {
					arr[j] = arr[j - interval];
					j -= interval;
				}
				arr[j] = key;	
			}
		}
		print_arr(arr, len);
	}

	static void merge(int nums[], int start, int mid, int end) {
		int leftLength = mid - start + 1;
		int rightLength = end - mid;

		int* left = new int[leftLength];
		int* right = new int[rightLength];

		for (int i = 0; i < leftLength; i++) {
			left[i] = nums[start + i];
		}

		for (int j = 0; j < rightLength; j++) {
			right[j] = nums[mid + 1 + j];
		}

		int i = 0, j = 0, k = start;

		while (i < leftLength && j < rightLength) {
			if (left[i] < right[j]) {
				nums[k] = left[i];
				i++;
			}
			else {
				nums[k] = right[j];
				j++;
			}

			k++;
		}

		while (i < leftLength) {
			nums[k] = left[i];
			i++;
			k++;
		}

		while (j < rightLength) {
			nums[k] = right[j];
			j++;
			k++;
		}
		delete[] left;
		delete[] right;
	}


	static void mergeSort(int nums[], int start, int end) {
		if (start < end) {
			int mid = (start + end) / 2;
			mergeSort(nums, start, mid);

			mergeSort(nums, mid + 1, end);

			merge(nums, start, mid, end);

		}
	}


	static void mergeSort(int nums[], int length) {
		mergeSort(nums, 0, length - 1);
		cout << "Sorted By Merge Sort: ";
		print_arr(nums, length);
	}

	static int partitionMiddle(int arr[],int l,int r,int pivot) {
		while (l <= r) {
			while (arr[l] < pivot) {
				l++;
			}

			while (arr[r] > pivot) {
				r--;
			}


			if (l <= r) {
				swap(arr[l], arr[r]);
				l++;
				r--;
			}
		}
		return l;
	}

	static void quickSortMiddlePivot(int arr[],int l,int r) {
		if (l < r) {
			int pivot = arr[ (l+r) / 2 ];
			
			int pivotInRightPlaceIndex = partitionMiddle(arr,l,r,pivot);
			
			quickSortMiddlePivot(arr, l, pivotInRightPlaceIndex - 1);
			quickSortMiddlePivot(arr, pivotInRightPlaceIndex, r);
		}
	}

	static void quickSort(int arr[],int len) {
		quickSortMiddlePivot(arr, 0, len - 1);
		print_arr(arr, len);
	}

	static int partitionEnd(int arr[],int l,int r) {
		int pivot = arr[r];
		int i = l;
		for (int j = l; j < r; j++) {
			if (arr[j] <= pivot) {
				swap(arr[i], arr[j]);
				i++;
			}
		}
		
		swap(arr[i], arr[r]);

		return i;
	}

	static void quickSortEndPivot(int arr[],int l,int r) {
		if (l < r) {
			
			int pivotinRightPlaceIndex = partitionEnd(arr,l,r);

			quickSortEndPivot(arr,l,pivotinRightPlaceIndex-1);
			quickSortEndPivot(arr,pivotinRightPlaceIndex+1,r);

		}
	}

	static void quickSortEnd(int arr[],int len) {
		quickSortEndPivot(arr,0,len-1);
		print_arr(arr, len);
	}

	static void heapify(int arr[], int n, int i)
	{
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int max = i;
		if (l < n && arr[l] > arr[max])
			max = l;
		if (r < n && arr[r] > arr[max])
			max = r;

		if (max != i) {
			swap(arr[i], arr[max]);
			heapify(arr, n, max);
		} 
	}

	static void buildHeap(int arr[], int n)
	{
		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(arr, n, i);
	}

	static void heapSort(int arr[], int n)
	{
		buildHeap(arr, n);
		for (int i = n - 1; i >= 0; i--)
		{
			swap(arr[0], arr[i]);
			heapify(arr, i, 0);
		}
		cout << "Heap sort: ";
		print_arr(arr, n);
	}
};
