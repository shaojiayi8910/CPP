#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<new>
using namespace std;

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  class Solution {
  public:
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          int total = 0;//记录总值
          int next = 0;//进位
          ListNode * result = new ListNode();//listnode的结果
          ListNode * cur = result;//当前的listnode
          while (l1 != NULL && l2 != NULL)
          {
              total = l1->val + l2->val + next;
              cur->next = new ListNode(total % 10);
              next = total / 10;
              l1 = l1->next;
              l2 = l2->next;
              cur = cur->next;
           }
          while (l1 != NULL)
          {
              total = l1->val + next;
              cur->next = new ListNode(total % 10);
              next = total / 10;
              l1 = l1->next;
              cur = cur->next;
          }
          while (l2 != NULL)
          {
              total = l2->val + next;
              cur->next = new ListNode(total % 10);
              next = total / 10;
              l2 = l2->next;
              cur = cur->next;
          }
          if (next != 0)
          {
              cur->next = new ListNode(next);
          }
          return result->next;
      }
  };
  int main()
  {   
      ListNode;
      return 0;
  }