/******************************************************************************

  Problem: Given the heads of two intersecting singly-linked lists, return
           the node where the lists meet.

 ******************************************************************************/
#include <iostream>

using namespace std;

struct Node {
  int val_;
  Node* next_;
  Node (int val) {
    val_= val;
    next_ = nullptr;
  }
};

/* This is probably uglier than it needs to be */
Node* intersect(Node* head1, Node* head2) {
  if (head1 == head2) {
    return head1;
  }

  auto l1 = head1, 
       l2 = head2;

  unsigned int count1 = 1, 
               count2 = 1;


  while (l1->next_ != nullptr) {
    l1 = l1->next_;
    ++count1;
  }
  while (l2->next_ != nullptr) {
    l2 = l2->next_;
    ++count2;
  }

  l1 = head1;
  l2 = head2;

  while (count1 > count2) {
    l1 = l1->next_;
    --count1;
  }

  while (count2 > count1) {
    l2 = l2->next_;
    --count2;
  }

  /* Assuming there is always an intersection */
  while (l1 != l2) {
    l1=l1->next_;
    l2=l2->next_;
  }

  return l1;
}

int main() {
  /* This is dumb and I hate it */
  Node head1(1);
  Node l1(2);
  Node l2(3);
  Node l3(4);
  Node head2(1);
  Node l4(5);
  Node l5(6);
  Node l6(7);

  head1.next_ = &l1;
  l1.next_ = &l2;
  l2.next_ = &l3;
  l3.next_ = &l4;
  l4.next_ = &l5;
  head2.next_ = &l6;
  l6.next_ = &l4;

  Node* hi = intersect(&head1, &head2);
  cout << hi->val_ << endl;
  return 0;
}
