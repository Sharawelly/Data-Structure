#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[] = {4, 1, 5, 8, 9, 0, 2, 7, 3, 6};
    int length = 10;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length - 1; ++j) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    for (auto &x: arr) {
        cout << x << ' ';
    }
}
/*
The space complexity for the bubble sort algorithm is O(1).
Best case --> O(N²)
Avg case --> O(N²)
Worst case --> O(N²)




Bubble sort is a simple sorting algorithm that works on the repeatedly swapping of adjacent elements until they are not in the sorted order.
It is called bubble sort because the movement of array elements is similar to the movement of air bubbles in the water
as these bubbles rise to the surface. Similarly, the array elements in bubble sort move to the end after each iteration.

Best Case - Irrespective of whether the array is sorted fully or partially or not at all,
Bubble Sort takes O(N²) comparisons. Hence, the best-case time complexity is O(N²).

Average Case - This occurs when elements in the array are in some random order, i.e.,
neither ascending nor descending. Hence the average case time complexity is O(N²).

Worst Case - This occurs when the array to be sorted has elements in reverse order. Hence worst, the case time complexity is O(N²).

 */