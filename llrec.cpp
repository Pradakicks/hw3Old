#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    splitHelper(head, smaller, larger, pivot);
    head = nullptr;
}


void splitHelper(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    if (head == nullptr){
      if(smaller){smaller -> next = nullptr;}
      if(larger){larger -> next = nullptr;}
      return;
    }

    if (head->val > pivot){
      if(larger){
       larger->next = head;
        splitHelper(head->next, smaller, larger->next, pivot);
      } else {
        larger = head;
        splitHelper(head->next, smaller, larger, pivot);
      }
    } else {
      if(smaller){
        smaller->next = head;
        splitHelper(head->next, smaller ->next, larger, pivot);
      } else {
        smaller = head;
        splitHelper(head->next, smaller, larger, pivot);
      }
    }


}