#pragma once

#include <iostream>
using namespace std;

class Sorts
{
public:

    void printArray(int array[], int size) {
        for (int i = 0; i < size; i++)
            cout << array[i] << " ";
        cout << endl;
    }

    void insertion(int arr[], int s) {
        for (int i = 1, j; i < s; i++) {
            int tmp = arr[i];
            for (j = i; j > 0 && tmp < arr[j - 1]; j--) {
                arr[j] = arr[j - 1];
            }
            arr[j] = tmp;
        }
    }

    void selection(int arr[], int s) {
        for (int i = 0, j, min; i < s - 1; i++) {
            for (j = i + 1, min = i; j < s; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            swap(arr[min], arr[i]);
        }
    }

    void bubble(int arr[], int s) {
        for (int i = 0; i < s - 1; i++) {
            for (int j = s - 1; j > i; j--) {
                if (arr[j] < arr[j - 1]) {
                    swap(arr[j], arr[j - 1]);
                }
            }
        }
    }

    void shell(int arr[], int n) {
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap, j; i < n; i++) {
                int temp = arr[i];
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];
                arr[j] = temp;
            }
            printArray(arr, 6);
        }
    }


    void merge(int arr[], int l, int m, int r) //O(n) time and O(n) space
    {
        int n1 = m - l + 1;
        int n2 = r - m;
        int* L = new int[n1], * R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        int i = 0;
        int j = 0;
        int k = l;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
        delete[]L;
        delete[]R;
    }

    void mergeSort(int arr[], int l, int r) { //O(nlogn)
        if (l >= r) {
            return;
            //returns recursively
        }
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }

    int partition(int arr[], int l, int r)
    {
        int pivot = arr[l];    // pivot
        int i = l;  // Index of smaller element

        for (int j = l + 1; j <= r; j++)
        {
            if (arr[j] < pivot)
            {
                i++;    // increment index of smaller element
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i], arr[l]);
        return i;
    }

    void QuickSort(int arr[], int l, int r) {
        if (l >= r) {
            return;
        }
        int m = partition(arr, l, r);
        QuickSort(arr, l, m - 1);
        QuickSort(arr, m + 1, r);
    }

    void countSort(int array[], int size) {
        int output[10];
        int count[10];
        int max = array[0];

        for (int i = 1; i < size; i++) {
            if (array[i] > max)
                max = array[i];
        }

        for (int i = 0; i <= max; ++i) {
            count[i] = 0;
        }

        for (int i = 0; i < size; i++) {
            count[array[i]]++;
        }

        for (int i = 1; i <= max; i++) {
            count[i] += count[i - 1];
        }

        for (int i = size - 1; i >= 0; i--) {
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--;
        }

        for (int i = 0; i < size; i++) {
            array[i] = output[i];
        }
    }

};

