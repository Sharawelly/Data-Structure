#include <iostream>

using namespace std;


int main()
{
    // Example array to test algorithm
    int a[] = {8, 2, 7, 4, 5, 1, 9, 3};
    int length = 8;


    // The outer loop examines each 'value' element on the right-hand unsorted
    // portion of the array from the 2nd element on to the end of the array
    for (int i = 1; i < length; i++)
    {
        // The element at the index is the current value value that we'll shift
        // into its correct position in the left-hand sorted portion of the
        // array.  We use the inner loop to do this, using the counter variable
        // j to keep track of our index in the left-hand sorted portion of the
        // array, which is initially j-1, the index one to the left of the
        // current value.
        int key = a[i];
        int j = i - 1;

        // So long as we haven't reached the start of the array, and the value
        // we are currently looking at in the sorted portion of the array is
        // greater than our value, we haven't yet found the correct index to
        // insert the value value.  So we shift over the value stored at the
        // index j one to the right with a[j + 1] = a[j], and then keep looking
        // at the next value to the left in the sorted portion of the array
        // with j = j - 1.
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }

        // The above loop will either stop when j = -1 and we have reached the
        // start of the array (in which case we insert the value here
        // as a[-1 + 1] = a[0] which will be assigned the value), OR the loop above
        // stops when a[j] <= value, in which case the value value should be placed
        // at the index j + 1, i.e. the index one to the right of the value at a[j].
        a[j + 1] = key;
    }


    // Output each array index/value after it has been sorted to confirm the
    // algorithm was successfully implemented
    for (int i = 0; i < length; i++)
    {
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    return 0;
}

/*
Space Complexity of Insertion Sort is O(1)
Best case --> O(N) No Movements/Swapping
Avg case --> O(N²)
Worst case --> O(N²)

The Insertion Sort Algorithm sorts a list by taking one item at a time and putting it in its correct place among those already sorted.
Imagine it like sorting a hand of playing cards: you start with the second card and compare it to the first.
If it's smaller, you move it before the first card. Then, you move to the next card and do the same,
always comparing with the sorted cards and placing it where it fits. This way, bit by bit,
the whole list gets sorted. It's simple and works well when the list is already almost sorted or is short.

Best Case (O(N)): This happens when the array is already sorted. Only one comparison per element is needed, making the process quick.
Average Case (O(N²)): Typically, elements are in a random order, and the algorithm still requires a significant number of comparisons and shifts, similar to the worst case.
Worst Case (O(N²)): This occurs when the array is sorted in reverse order. Each element needs to be compared with all others, leading to a lot of comparisons and shifts.
 */