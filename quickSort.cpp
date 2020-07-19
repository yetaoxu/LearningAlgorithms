//
// Created by xuyetao on 2020/7/19.
//
#include <iostream>
using namespace std;

int partition_single_side(int *arr, int startIndex, int endIndex) {
    int pivot = arr[startIndex];
    int mark = startIndex;
    for (int i = startIndex + 1; i <= endIndex; i++) {
        if (arr[i] < pivot) {
            mark++;
            int p = arr[mark];
            arr[mark] = arr[i];
            arr[i] = p;
        }
    }
    arr[startIndex] = arr[mark];
    arr[mark] = pivot;
    return mark;
}

int partition_double_side(int *arr, int startIndex, int endIndex) {
    int pivot = arr[startIndex];
    int left = startIndex;
    int right = endIndex;
    while (left != right) {
        while (left < right && arr[right] > pivot) {
            right--;
        }
        while (left < right && arr[left] <= pivot) {
            left++;
        }
        if (left < right) {
            int p = arr[left];
            arr[left] = arr[right];
            arr[right] = p;
        }
    }
    arr[startIndex] = arr[left];
    arr[left] = pivot;
    return left;
}
void quickSort(int *arr, int startIndex, int endIndex) {
    if (startIndex >= endIndex) {
        return;
    }
    int pivotIndex = partition_single_side(arr, startIndex, endIndex);
    quickSort(arr, startIndex, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, endIndex);
}


int main() {
    int arr[5] = {3, 1, 2, 5, 4};
    quickSort(arr, 0, 4);
    for (int i = 0; i < 5; i++) {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}

