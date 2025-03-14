#include<iostream>

using namespace std;

void merge(int arr[], int l, int m, int r)//m = l + (r - l) / 2;
{
    int i, j, k;
    int n1 = m - l + 1;// First subarray is arr[l..m]
    int n2 = r - m;// Second subarray is arr[m+1..r]
    int *L = new int[n1], *R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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
}


void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;// (l + r) / 2  ==  l + (r - l) / 2

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

int main() {

    int arr[] = {60, 10, 20, 5, 50, 70, 2, -8};
    int n = sizeof(arr) / sizeof(arr[0]);//24/4=6

    mergeSort(arr, 0, n - 1);
    print(arr, n);
    return 0;

}

/*
Best case --> O(nlogn)
Avg case --> O(nlogn)
Worst case --> O(nlogn)


The merge sort algorithm is an algorithm based on the divide and conquers strategy of solving problems.
In this, we divide a problem into several sub-problems, each of which is solved individually, and after that,
all of them are combined to give the final solution.
We can visualize it as a recursive algorithm that continuously breaks the array into half until the array is left with only 1 element, i.e.,
this is the base condition to stop the recursion, and then each call returns to its parent and is arranged to return the sorted array finally.
 */