//
// Created by xuyetao on 2020/7/21.
//

#include <iostream>
#include <vector>

using namespace std;

void mergeArray(vector<int> &a, int first, int mid, int last, vector<int> &temp) {
    int i = first, j = mid + 1, m = mid, n = last, k = 0;
    while (i <= m && j <= n) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i <= m) {
        temp[k++] = a[i++];
    }
    while (j <= n) {
        temp[k++] = a[j++];
    }
    for (i = 0; i < k; i++) {
        a[first + i] = temp[i];
    }
}

void mergeSort(vector<int> &a, int first, int last, vector<int> &temp) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(a, first, mid, temp);
        mergeSort(a, mid + 1, last, temp);
        mergeArray(a, first, mid, last, temp);
    }
}

int main() {
    vector<int> arr = {5, 3, 2, 0, 1, 6, 4};
    vector<int> temp = {5, 3, 2, 0, 1, 6, 4};
    mergeSort(arr, 0, 6, temp);
    for (int i = 0; i < 7; i++) {
        cout << arr[i];
    }
    cout << endl;
}
