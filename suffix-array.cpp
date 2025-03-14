#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For formatted output

using namespace std;

// Function to perform merge sort on suffix indices
// Function to perform merge sort on suffix indices
void mergeSortOnSuffixIndices(vector<int> &suffixArray, vector<int> &r, int k, int left, int right, vector<int> &result) {
    if (left >= right) return;

    int mid = left + ((right - left) >> 1);

    mergeSortOnSuffixIndices(suffixArray, r, k, left, mid, result);
    mergeSortOnSuffixIndices(suffixArray, r, k, mid + 1, right, result);

    int i = left, j = mid + 1, idx = left;

    // Merge the two halves
    while (i <= mid && j <= right) {
        int x = suffixArray[i];
        int y = suffixArray[j];


        if (r[x] < r[y] || (r[x] == r[y] && ((x + k < r.size() ? r[x + k] : -1) < (y + k < r.size() ? r[y + k] : -1)))) {
            result[idx++] = x;
            i++;
        } else {
            result[idx++] = y;
            j++;
        }
    }

    // Copy remaining elements
    while (i <= mid) {
        result[idx] = suffixArray[i];
        idx++, i++;
    }
    while (j <= right) {
        result[idx] = suffixArray[j];
        idx++, j++;
    }

    // Update the suffix array
    for (int l = left; l <= right; ++l) {
        suffixArray[l] = result[l];
    }
}


// Function to build the suffix array with merge sort and prefix doubling
vector<int> constructSuffixArray(string str, int size) {
    vector<int> suffixArray(size), r(size), suffixArrayTempRank(size), result(size);





    // Initialize suffix array and ranks for k=0
    // abba$
    // 0 1 2 3 4
    // 97 98 98 97 36

    for (int i = 0; i < size; ++i) {
        suffixArray[i] = i; // put the index of the string
        r[i] = str[i]; // put value of the ascii code in the r
    }

    cout << "k = 0: ";
    for (int i = 0; i < size; ++i) cout << r[i] << " ";
    cout << '\n';

    for (int k = 1; k < 2 * size; k *= 2) {
        // Use merge sort to sort the suffix indices
        mergeSortOnSuffixIndices(suffixArray, r, k, 0, size - 1, result); // we sort according to r the smallest r will be put int the first
        // k=0 ranks: 97 98 98 97 36
        // suffixarray= 0 1 2 3 4
//36 is the lowest , it will go first
// then 97 , but we have two 97's , so we will judge based on the kth character in the r , so the 3rd index will win , then the 0
// so until now we are : 4 3 0
// we have two 98 , which has the lower in the kth character r after it ?
// the one at index 2 will win
//
// so 4 3 0 2 1


// 0 1 2 3 4
// 97 98 98 97 36

// 4 3 0 2 1 ( SUFFIX ARRAY )
// r=0
//  [()()()()()]
// trgm dh b2a
// 4th index u will put 0
// 3rd index u will put 1
// 0 index u will put 2
// 2nd index u will put 3
// 1st index u will put 4
// 2 4 3 1 0


// 4 3 0 2 1 ( SUFFIX ARRAY )
//[()()()()()]

        //
        suffixArrayTempRank[suffixArray[0]] = 0;

        for (int i = 1; i < size; ++i) {
            // i=3
            int previous = suffixArray[i - 1];
            int current = suffixArray[i]; // previous (4) , current(3)
            suffixArrayTempRank[suffixArray[i]] = suffixArrayTempRank[suffixArray[i - 1]]; // same as the last r
            // however , if u find that the last one is different
            // or it was the same r , but the kth wasn't the same , then it's a new r !! ( and a new last b2a :D )
            // The lth was also the same ?! no adding 1 :( :)
            if (r[previous] != r[current])
                suffixArrayTempRank[suffixArray[i]]++;
            else if(r[previous] == r[current]){
                if((previous + k < size ? r[previous + k] : -5) != (current + k < size ? r[current + k] : -5))
                    suffixArrayTempRank[suffixArray[i]]++;
                
            }

        }

        r = suffixArrayTempRank;

        // Output the r for the current value of k
        cout << "k = " << k << ": ";
        for (int i = 0; i < size; ++i)
            cout << r[i] << " ";
        cout << '\n';
    }

    return suffixArray;
}

// Driver function
int main() {
    string str("ACGACTACGATAAC$");

    vector<int> suffixArray = constructSuffixArray(str, str.size());

    cout << "The Final Suffix Array: ";
    for (int i = 0; i < suffixArray.size(); ++i) {
        cout << suffixArray[i] << ' ';
    }
    cout << endl;
// The following is just illustration for your help only, nothing required about it. Check lecture.
///////////////////////////////////////////////////////////////////////////////////////////////////
// i      0  1  2  3  4  5  6  7  8  9 10 11 12 13 14
// t      A  C  G  A  C  T  A  C  G  A  T  A  A  C  $
// --------------------------------------------------
// k=0    1  2  3  1  2  4  1  2  3  1  4  1  1  2  0
// k=1    2  5  7  2  6  8  2  5  7  3  8  1  2  4  0
// k=2    3  7 10  4  9 13  3  8 11  5 12  1  2  6  0
// k=4    3  8 11  5 10 14  4  9 12  6 13  1  2  7  0
// sa=   14 11 12  0  6  3  9 13  1  7  4  2  8 10  5
///////////////////////////////////////////////////////////////////////////////////////////////////
/*
ACGACTACGATAAC$ 0
CGACTACGATAAC$  1
GACTACGATAAC$   2
ACTACGATAAC$    3
CTACGATAAC$     4
TACGATAAC$      5
ACGATAAC$       6
CGATAAC$        7
GATAAC$         8
ATAAC$          9
TAAC$           10
AAC$            11
AC$             12
C$              13
$               14
*/

    return 0;
}
