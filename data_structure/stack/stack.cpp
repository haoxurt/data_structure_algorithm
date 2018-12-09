#include <iostream>
#include <stdlib.h>
const int MAXSIZE = 0xFFFF;
template<typename T>
class my_stack{
 public:
   my_stack() : top_(-1), maxsize_(MAXSIZE) {
     arr = new T[maxsize_];
   }
   my_stack(int size) : top_(-1), maxsize_(size) {
     arr = new T[maxsize_];
   }
   bool empty() {
     if (top_ == -1)
       return true;
     else 
       return false;
   }
   int size() {
     return top_ + 1;
   }
   void push(T item) {
     if (top_ == maxsize_ - 1) {
       std::cout<<"stack is full"<<std::endl;
       exit(1);     
     }
     else 
       arr[++top_] = item;
   }
   void pop() {
     if (top_ == -1) {
       std::cout<<"no element pop"<<std::endl;
       exit(1);
     }
     else 
       top_--;
   }
   T top() {
     if (top_ == -1) {
       std::cout<<"stack is empty"<<std::endl;
       exit(2);
     } else {
       return arr[top_];
     }
   }

   ~my_stack() {
     delete []arr;
   }
 private:
   T* arr;
   int top_;
   int maxsize_;
};

int main() 
{
  my_stack<int> test_stack(5);
  for (int i = 0; i < 5; i++)
    test_stack.push(i + 10);
  std::cout<<test_stack.size()<<std::endl;
  test_stack.push(1000);
  std::cout<<test_stack.top()<<std::endl;
  test_stack.pop();
  test_stack.pop();
  std::cout<<test_stack.top()<<std::endl;
}
