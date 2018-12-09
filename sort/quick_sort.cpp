#include <iostream>

void my_swap(int* arr, int idx1, int idx2) {
  int tmp = arr[idx1];
  arr[idx1] = arr[idx2];
  arr[idx2] = tmp;
}

int partitionGetPosition(int*arr, int low, int high) {
  int key = arr[low];
  while(low < high) {
    while(low < high && arr[high] >= key)
      high--;
    my_swap(arr, low, high);
    while(low < high && arr[low] <= key) 
      low++;
    my_swap(arr, low, high);
  }
  return low;
}

void quick_sort(int* arr, int low, int high) {
  int pos;
  if (low < high) {
    pos = partitionGetPosition(arr, low, high);
    quick_sort(arr, low, pos - 1);
    quick_sort(arr, pos + 1, high);
  }
}

int main() {
  int arr[10] = { 100, 100, -48, 24, 1255, 0, 10000, 932, 8737, 0};
  // int arr[2] = { 100, 100};
  quick_sort(arr, 0, 9);
  for (int i = 0; i < 9; i++) 
    std::cout<<arr[i]<<std::endl;
}
