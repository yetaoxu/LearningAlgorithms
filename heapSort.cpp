//
// Created by xuyetao on 2020/7/19.
//

#include <iostream>
#include <vector>

using namespace std;

void downAdjust(vector<int> &arr, int parentIndex, int length) {
    int temp = arr[parentIndex];
    int childIndex = 2 * parentIndex + 1;
    while (childIndex < length) {
        if (childIndex + 1 < length && arr[childIndex + 1] > arr[childIndex]) {
            childIndex++;
        }
        if (temp >= arr[childIndex]) {
            break;
        }
        arr[parentIndex] = arr[childIndex];
        parentIndex = childIndex;
        childIndex = 2 * childIndex + 1;
    }
    arr[parentIndex] = temp;
}

void heapSort(vector<int> &arr) {
    // 从最后一个非叶子结点开始，依次做下沉调整, 将无序数组构建成最大堆
    for(int i = (arr.size() - 2) / 2; i >= 0; i--) {
        downAdjust(arr, i, arr.size());
    }

    // 循环删除堆顶元素，移到集合尾部，调整堆产生新的堆顶
    for(int i = arr.size() - 1; i > 0; i--) {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        downAdjust(arr, 0, i);
    }
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 6, 8, 9};
    heapSort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
    }
    cout << endl;
}
