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
  {   //第一个链表的实现
      ListNode* head = new ListNode(4);
      ListNode* node2 = new ListNode(2);
      ListNode* node3 = new ListNode(3);
      ListNode* node4 = new ListNode(1);
      //开辟各个节点的空间
      head->next = node2;
      node2->next = node3;
      node3->next = node4;
      node4->next = nullptr;
      //实现各个节点的连接关系
      ListNode * cur = head; //用一个指针cur来指向当前结点，初始为头结点
      while (cur != nullptr) { //当cur不为空时，循环继续
          cout << cur->val << " "; //打印出当前结点的值
          cur = cur->next; //将cur指向下一个结点
      }
      cout << endl; //换行
      ///////////////////////////////////////////
       //第二个链表的实现
      ListNode* head1  = new ListNode(8);
      ListNode* node21 = new ListNode(5);
      ListNode* node31 = new ListNode(3);
      ListNode* node41  = new ListNode(7);
      //开辟各个节点的空间
      head1->next = node21 ;
      node21->next = node31 ;
      node31->next = node41 ;
      node41->next = nullptr;
      //实现各个节点的连接关系
      ListNode* cur1 = head1; //用一个指针cur来指向当前结点，初始为头结点
      while (cur1 != nullptr) { //当cur不为空时，循环继续
          cout << cur1->val << " "; //打印出当前结点的值
          cur1 = cur1->next; //将cur指向下一个结点
      }
      cout << endl; //换行
      cout << "after add:" << endl;
      Solution s;
      ListNode* _res = s.addTwoNumbers(head, head1);
      while ( _res!= nullptr)
      {
          cout << _res->val << " ";
          _res = _res->next;
      }
      return 0;
  }