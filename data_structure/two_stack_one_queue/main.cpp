#include <iostream>
#include <stack>
#include <queue>

class my_queue {
 public:
   void queue_push(const int ele) {
     s1_.push(ele);
   }
   void queue_pop() {
     if (s2_.empty()) {
       while (!s1_.empty()) {
         s2_.push(s1_.top());
         s1_.pop();
       }
       std::cout<<s2_.top()<<std::endl;
       s2_.pop();
     } else {
       std::cout<<s2_.top()<<std::endl;
       s2_.pop();
     }
   }
   void queue_front() {
   
   }
 private:
   std::stack<int> s1_;
   std::stack<int> s2_;
};

int main() {
  my_queue q;
  q.queue_push(1);
  q.queue_push(2);

  q.queue_pop();
  q.queue_pop();
  q.queue_push(5);
  q.queue_pop();
}
