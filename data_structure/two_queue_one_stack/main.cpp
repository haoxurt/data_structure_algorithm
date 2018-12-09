#include <queue>
#include <iostream>
class my_stack {
 public:
   void my_push(const int ele) {
     if (!q1_.empty())
       q1_.push(ele);
     else 
       q2_.push(ele);
   }

   void my_pop() {
     if (!q1_.empty()) {
       int num = q1_.size();
       while (num > 1) {
         q2_.push(q1_.front());
         q1_.pop();
         num--;
       }
       std::cout<<q1_.front()<<std::endl;
       q1_.pop();
     } else {
       int num = q2_.size();
       while (num > 1) {
         q1_.push(q2_.front());
         q2_.pop();
         num--;
       }
       std::cout<<q2_.front()<<std::endl;
       q2_.pop();
     }
   }
 // private:
   std::queue<int> q1_;
   std::queue<int> q2_;
};


int main() {
  my_stack s;
  s.my_push(100);
  s.my_push(200);
  std::cout<<s.q1_.size()<<std::endl;
  std::cout<<s.q2_.size()<<std::endl;
  s.my_pop();
  std::cout<<s.q1_.size()<<std::endl;
  std::cout<<s.q2_.size()<<std::endl;
  s.my_push(43000);
  std::cout<<s.q1_.size()<<std::endl;
  std::cout<<s.q2_.size()<<std::endl;
  s.my_pop();

}
