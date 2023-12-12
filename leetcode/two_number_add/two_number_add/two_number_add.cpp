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
          int total = 0;//��¼��ֵ
          int next = 0;//��λ
          ListNode * result = new ListNode();//listnode�Ľ��
          ListNode * cur = result;//��ǰ��listnode
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
  {   //��һ�������ʵ��
      ListNode* head = new ListNode(4);
      ListNode* node2 = new ListNode(2);
      ListNode* node3 = new ListNode(3);
      ListNode* node4 = new ListNode(1);
      //���ٸ����ڵ�Ŀռ�
      head->next = node2;
      node2->next = node3;
      node3->next = node4;
      node4->next = nullptr;
      //ʵ�ָ����ڵ�����ӹ�ϵ
      ListNode * cur = head; //��һ��ָ��cur��ָ��ǰ��㣬��ʼΪͷ���
      while (cur != nullptr) { //��cur��Ϊ��ʱ��ѭ������
          cout << cur->val << " "; //��ӡ����ǰ����ֵ
          cur = cur->next; //��curָ����һ�����
      }
      cout << endl; //����
      ///////////////////////////////////////////
       //�ڶ��������ʵ��
      ListNode* head1  = new ListNode(8);
      ListNode* node21 = new ListNode(5);
      ListNode* node31 = new ListNode(3);
      ListNode* node41  = new ListNode(7);
      //���ٸ����ڵ�Ŀռ�
      head1->next = node21 ;
      node21->next = node31 ;
      node31->next = node41 ;
      node41->next = nullptr;
      //ʵ�ָ����ڵ�����ӹ�ϵ
      ListNode* cur1 = head1; //��һ��ָ��cur��ָ��ǰ��㣬��ʼΪͷ���
      while (cur1 != nullptr) { //��cur��Ϊ��ʱ��ѭ������
          cout << cur1->val << " "; //��ӡ����ǰ����ֵ
          cur1 = cur1->next; //��curָ����һ�����
      }
      cout << endl; //����
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