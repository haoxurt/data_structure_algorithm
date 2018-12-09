#include <iostream> 
#include <cassert>
template<typename T>
#if 0
class my_queue {
 public:
   my_queue(int size) : rear_(-1), front_(0), size_(size), current_num_(0) {
     arr_ = new T[size_];
   }
   ~my_queue() {
     delete []arr_;
   }
   bool empty() {
     return (current_num_ == 0);
   }
   int size() {
     return current_num_;
   }
   void push(T ele) {
     if (current_num_ == size_) 
       std::cout<<"queue is full"<<std::endl;
     else {
       if (rear_ == size_ - 1)
         rear_ = -1;
       arr_[++rear_] = ele;
       current_num_++;
     }
   }
   void pop() {
     if (empty()) 
       std::cout<<"queue is empty"<<std::endl;
     else {
       current_num_--;
       front_++;
       front_ = front_ % size_;
     }
   }
   T front() {
     if (empty()) 
       std::cerr<<"error, queue is empty"<<std::endl;
     else 
       return arr_[front_];
   }
   T back() {
     if (empty()) 
       std::cerr<<"error, queue is empty"<<std::endl;
     else 
       return arr_[rear_];
   }
   void show() {
     std::cout<<"front: "<<front_<<" "<<"rear: "<<rear_<<std::endl;
   }
 private:
   T* arr_;
   int rear_;
   int front_;
   int size_;
   int current_num_;
};
#endif 

class my_queue {
 public:
   my_queue(int size) : rear_(0), front_(0), size_(size) {
     arr_ = new T[size_];
   }
   ~my_queue() {
     delete []arr_;
   }
   bool empty() {
     return rear_ == front_;
   }
   int size() {
     return (rear_ - front_ + size_) % size_;
   }
   bool isFull() {
     return (rear_ + 1) % size_ == front_;
   }
   void push(T ele) {
     if (isFull()) 
       std::cout<<"queue is full"<<std::endl;
     else {
       arr_[rear_] = ele;
       rear_ = (rear_ + 1) % size_;
     }
   }
   void pop() {
     if (empty()) 
       std::cout<<"queue is empty"<<std::endl;
     else {
       front_ = (front_ + 1) % size_;
     }
   }
   T front() {
     if (empty()) 
       std::cerr<<"error, queue is empty"<<std::endl;
     else 
       return arr_[front_];
   }
   void show() {
     std::cout<<"front: "<<front_<<" "<<"rear: "<<rear_<<std::endl;
   }
 private:
   T* arr_;
   int rear_;
   int front_;
   int size_;
};

int main() {
  my_queue<int> test_queue(5);
  for (int i = 0; i < 5; i++)
    test_queue.push(i + 10);
  test_queue.show();
  test_queue.pop();
  test_queue.pop();
  test_queue.pop();
  test_queue.pop();
  std::cout<<test_queue.size()<<std::endl;
  test_queue.show();
  test_queue.pop();
  test_queue.show();
  test_queue.push(1111);
  std::cout<<test_queue.size()<<std::endl;
  test_queue.show();
  test_queue.push(222222);
  std::cout<<test_queue.size()<<std::endl;
  test_queue.show();
  test_queue.pop();
  std::cout<<test_queue.front()<<std::endl;
}
