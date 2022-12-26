#include<algorithm>
#include<iostream>

void sift_down(int arr[], int start, int end) {
  // 计算父结点和子结点的下标
    int parent = start;
    int child = parent * 2 + 1;
    while (child <= end) {
        if (child + 1 <= end && arr[child] < arr[child + 1]) child++;
        if (arr[parent] >= arr[child])
            return;
        else {
            std::swap(arr[parent], arr[child]);
            parent = child;
            child = parent * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len) {
  // 从最后一个节点的父节点开始 sift down 以完成堆化 (heapify)
    for (int i = (len - 1 - 1) / 2; i >= 0; i--) sift_down(arr, i, len - 1);
  // 先将第一个元素和已经排好的元素前一位做交换，再重新调整（刚调整的元素之前的元素），直到排序完毕
    for (int i = len - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        sift_down(arr, 0, i - 1);
    }
}


int main(){
    int arr[5]{1, 2, 4, 5, 3};
    heap_sort(arr, 5);
    for(const auto &i:arr){
        std::cout<<i;
    }
    std::cout<<std::endl;
}