#include <bits/stdc++.h>

using namespace std;

void countingSort(vector<int>& arr) {
    int Max_Element = *max_element(arr.begin(), arr.end());
    int Min_Element = *min_element(arr.begin(), arr.end());
    int range = Max_Element - Min_Element + 1;

    vector<int> count(range, 0), output(arr.size());

    // Count the occurrences of each element
    for (int i = 0; i < arr.size(); ++i)
        count[arr[i] - Min_Element]++;

    // Calculate cumulative count
    for (int i = 1; i < count.size(); ++i)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; --i) {
        output[count[arr[i] - Min_Element] - 1] = arr[i];
        count[arr[i] - Min_Element]--;
        /*
         This line decrements the count of the current element in the count array.
         It's done after placing the current element in its correct position in the output array.
         By decrementing the count, we ensure that the next occurrence of the same element, if any, is placed at the correct position in the output array.
         Decrementing the count ensures that if there are multiple occurrences of the same element, they are placed in the output array in the same order as they appear in the input array.

         By decrementing the count after placing an element in its correct position,
         we ensure that subsequent occurrences of the same element, if any, are placed before it in the output array.
         This maintains the correctness of the sorting process.

         If there are multiple occurrences of the same element in the input array,
         this decrement operation ensures that the next occurrence of that element, if any, will be placed before the current occurrence in the output array.
         By decrementing the count, we reserve the correct position for the next occurrence.

         Counting Sort is a stable sorting algorithm, meaning it preserves the relative order of equal elements.
         By decrementing the count after placing an element, we ensure that subsequent occurrences of the same element, if any, are placed before it in the output array, thus maintaining stability.
         */
    }

    // Copy the output array to the original array
    for (int i = 0; i < arr.size(); ++i)
        arr[i] = output[i];
}

int main() {
    vector<int> arr = {4, 2, -6, 8, 3, -8, 1, 0, 1, 1};

    cout << "Before sorting:\n";
    for (int num : arr)
        cout << num << " ";
    cout << "\n";

    countingSort(arr);

    cout << "After sorting:\n";
    for (int num : arr)
        cout << num << " ";
    cout << "\n";

    return 0;
}
