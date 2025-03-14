#include <iostream>

using namespace std;

void selection_sort(int a[], int length);

int main()
{
    // A test array and array length
    int a[] = {1, 3, 1, 2, 5, 2};
    int length = 6;

    // Call the function to perform the selection sort algorithm
    selection_sort(a, length);

    // Print out the array so we can be sure it is sorted correctly
    for (int i = 0; i < length; i++)
    {
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    return 0;
}

// Sorts array a with the provided length using the selection sort algorithm.
void selection_sort(int a[], int length)
{
    // Loop through each index of the array, as we do so the elements < i are
    // considered the sorted portion of the array, and the elements >= i are
    // considered the unsorted portion of the array.  The algorithm repeatedly
    // finds the minimum element in the unsorted portion of the array and if
    // necessary swaps it with the element at index i, increasing the portion
    // of the sorted array with each iteration.
    for (int i = 0; i < (length - 1); i++)
    {
        // find the position of the minimum element in the unsorted portion of
        // the array
        int min_pos = i;
        for (int j = i + 1; j < length; j++)
        {
            if (a[j] < a[min_pos])
            {
                min_pos = j;
            }
        }

        // if that element is NOT the element at index i, then swap that element
        // with the element at index i
        if (min_pos != i)
        {
            int temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
        }
    }
}
/*
The space complexity of Selection Sort is O(1)
Worst case --> O(N²)
Best case --> O(N²)
Avg case --> O(N²)

The time complexity of the selection sort depends upon the iteration and then finding the minimum element in each iteration.
In each iteration, we find the minimum element from the sub-array and bring it to the right position using swapping.

The time complexity of finding the minimum element in a sub-array takes O(N) time
where N is the number of elements in the unsorted sub-array.
As we will need to traverse the entire unsorted sub-array of size N for finding the minimum element
so the time complexity of searching comes out to be O(N).
Now, after the searching, we will be performing the swapping (if needed) but the swapping is a constant time operation i.e. it takes only O(1) time hence it will not affect the overall time complexity of the selection sort.

Now, for each of the N iterations, we perform the searching and swapping so the time complexity of the selection sort becomes N∗N i.e. O(N²)
Let us look at the best, average, and worst-case time complexity of selection sort.

The best case is when the array is already sorted.
So even if the array is already sorted, we will traverse the entire array for checking, and in each iteration or traversal,
we will perform the searching operation. Only the swapping will not be performed as the elements will be at the correct position.
Since the swapping only takes a constant amount of time i.e. O(1)the best time complexity of selection sort comes out to be O(N²)

The worst case is when the array is completely unsorted or sorted in descending order.
So, we will traverse the entire array for checking, and in each iteration, we will perform the searching operation.
After searching, we will swap the element at its correct position.
As we know that the swapping only takes a constant amount of time i.e. O(1) so the worst time complexity of selection sort also comes out to be O(N²).

The average case is when some part of the array is sorted.
So, as we have seen earlier in the best and worst cases, we will need to perform the searching, and swapping in each iteration.
So, the average time complexity of the selection sort is O(N²) as well.



 */