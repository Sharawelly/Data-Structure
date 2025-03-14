// C++ implementation of Shell Sort
#include <iostream>
using namespace std;

/* function to sort arr using shellSort */
int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            // put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {90, 80, 70, 60, 50, 40};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before sorting: \n";
    printArray(arr, n);

    shellSort(arr, n);

    cout << "\nArray after sorting: \n";
    printArray(arr, n);

    return 0;
}
/*
Best case --> O(nlogn) When the array is already sorted
Avg case --> O(n^3/2)

Worst case --> O(N²)
Consider an array of size n containing elements arranged in descending order.
In this worst-case scenario, every element in the array needs to move to its correct position.
For each element, we may need to compare it with every other element to find its correct position.
This leads to a total number of comparisons and swaps proportional to n*(n-1)/2 --> N².
The time complexity of each loop depends on the number of iterations it performs.
The outer loop runs for a decreasing sequence of gap sizes, which takes O(logn) time since the gap is halved in each iteration.
The inner loop runs for each element of the array for each gap size. In the worst-case scenario, when the array is completely unsorted, it takes O(n) time for each gap size.
Thus, the overall time complexity of the entire algorithm is O(nlogn) in the average case, although it can degrade to O(N²) in the worst-case scenario.
Note that Total comparisons: n/2 + (n-1)/2 + (n-2)/2 + .......+ 1/2 --> n/2 * n  --> O(N²)
 */