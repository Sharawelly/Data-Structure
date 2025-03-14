#include<iostream>

using namespace std;

void heapify(int arr[], int n, int i)// To convert a complete binary tree into a max heap O(log n)
{
    int l = 2 * i + 1;// left child
    int r = 2 * i + 2;// right child
    int max = i;// position of parent (root of subtree)

    // If the left child is larger than the root.
    if (l < n && arr[l] > arr[max])// you can convert > into < to print in descending order
        max = l;

    // If the right child is larger.
    if (r < n && arr[r] > arr[max])// you can convert > into < to print in descending order
        max = r;

    // If the root is not the largest.
    if (max != i) {
        swap(arr[i], arr[max]);

        // Heapifying the sub-tree repeatedly.
        heapify(arr, n, max);
        /*
         The benefit of calling the heapify function again after performing a swap is to ensure that the subtree rooted at the node (arr[i]) at position max maintains the max heap property.
         */
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n) {

    buildHeap(arr, n);
    // Extracting element from the heap.
    for (int i = n - 1; i >= 0; i--) {

        // Moving the current root to the last element of the array.
        swap(arr[0], arr[i]);

        // Calling max heapify on the shrink heap.
        heapify(arr, i, 0);
    }
    /*
     Notice that after performing a swap, the size of the array being heapified decreases by 1 because I move the largest element to the end.
     Then, I heapify the entire array except for the last element since I've ensured it's in its correct position.
     After performing heapify and first iteration of the loop is done, I perform a swap between the largest element in root (arr[0]) and the element before the last. Following this pattern,
     I continue heapifying the elements of the array except for the last two elements. This process repeats until the loop finishes.
     */

}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

// Time --> O(nlogn) for best, avg, worst
// Space --> O(1) 3l4an mesh me7tagen ay extra space
int main() {
    int arr[] = {8, 19, 5, 15, 4, 13, 12, 8, 24, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);
    print(arr, n);

    return 0;
}
