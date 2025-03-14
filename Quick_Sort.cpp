#include<iostream>

using namespace std;

int partition1(int arr[], int l, int h) {
    int p = arr[l];
    int i = l;
    int j = h;
    while (i < j) {
        do {
            i++;
        } while (arr[i] <= p);
        do {
            j--;
        } while (arr[j] > p);

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

void quickSort1(int arr[], int l, int h) {

    if (l < h) {
        int piv = partition1(arr, l, h);
        quickSort1(arr, l, piv);
        quickSort1(arr, piv + 1, h);
    }

}


int partition2(int arr[], int iBegin, int jEnd) {
    int i = iBegin;
    int j = jEnd;
    int pivLoc = i;
    while (true) {
        while (arr[pivLoc] <= arr[j] && pivLoc != j) {
            j--;
        }
        if (pivLoc == j)
            break;
        swap(arr[j], arr[pivLoc]);
        pivLoc = j;


        while (arr[pivLoc] >= arr[i] && pivLoc != i) {
            i++;
        }
        if (pivLoc == i)
            break;
        swap(arr[i], arr[pivLoc]);
        pivLoc = i;

    }
    return pivLoc;
}


void quickSort2(int arr[], int l, int h) {

    if (l < h) {
        int piv = partition2(arr, l, h);
        quickSort2(arr, l, piv - 1);
        quickSort2(arr, piv + 1, h);
    }

}


int main() {
    int arr[] = {5, 3, 8, 9, 1, 7, 0, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort2(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
As the name suggests, a quick sort algorithm is known to sort an array of elements much faster (twice or thrice times) than various sorting algorithms.

Quick sort uses the divide and conquer technique where we partition the array around an element known as the pivot element,
which is chosen randomly from the array. We solve the partitions to achieve an ordered array.
Due to this reason, it is also known as the Partition Exchange Algorithm. A similar algorithmn to Quick Sort is Merge Sort.

Best case --> O(nlogn)
Avg case --> O(nlogn)
Worst case --> O(N²) but it never reached
To know how read this!!!
https://www.scaler.com/topics/quick-sort-in-cpp/
*/