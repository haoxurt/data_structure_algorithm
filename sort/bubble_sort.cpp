#include <iostream>

void bubble_sort(int* arr, int n) {
  for (int i = 0; i < n -1; i++) {
    bool exchange = false;
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        exchange = true;
      }
    }
    if (!exchange)
      break;
  }
  
}
int main() {
  int arr[5] = {-100, -1, 48, 240, 1255};
  // int arr[2] = { 100, 100};
  bubble_sort(arr, 5);
  for (int i = 0; i < 5; i++) 
    std::cout<<arr[i]<<std::endl;
}
