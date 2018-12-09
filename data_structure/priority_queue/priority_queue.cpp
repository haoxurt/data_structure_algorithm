#include <iostream> 

template<typename T>
class priority_queue{
 public:
   priority_queue(int size) : size_(size), current_nums_(0) {
     arr_ = new T[size_];
   }
   ~priority_queue() {
     delete [] arr_;
   }
   bool empty() {
     return current_nums_ == 0;
   }
   int size() {
     return current_nums_;
   }
   void push(const T& ele) {
     if (current_nums_ == size_) {
       std::cout<<"priority_queue is full"<<std::endl;
       return;
     } else {
       if (current_nums_ == 0) {
         arr_[current_nums_++] = ele;
       }
       else {
         int i;
         for (i = current_nums_ - 1; i >= 0; i--) {
           if (ele < arr_[i]) 
             arr_[i + 1] = arr_[i];
           else 
             break;
         }
         arr_[i + 1] = ele;
         current_nums_++;
       }
     }
   }
   void pop() {
     if (current_nums_ == 0)
       std::cout<<"priority_queue is empty"<<std::endl;
     else {
       current_nums_--;
     }
   }

   T top() const {
     if (current_nums_ != 0)
       return arr_[current_nums_ - 1];
     else 
       std::cout<<"priority_queue is empty"<<std::endl;
   }
   
 private:
   int size_;
   int current_nums_;
   T* arr_;
};

int main() {
  priority_queue<int> test(5);
  test.push(12);
  test.push(100);
  test.push(200);
  test.push(150);
  test.push(15);
  std::cout<<test.size()<<std::endl;
  test.pop();
  test.push(10000);
  while (!test.empty()) {
    std::cout<<test.top()<<std::endl;
    test.pop();
  }
}
