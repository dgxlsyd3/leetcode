#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <typeinfo>

using namespace std;

/**
* Definition for singly-linked list.
*/
 struct ListNode 
 {
     int val;
     ListNode *next;

     ListNode(int x) : 
		 val(x), next(NULL) 
	 {
	 }
 };

class Solution 
{
public: 
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		if (l1 == NULL && l2 == NULL)
		{
			return NULL;
		}

		if (l1 == NULL && l2 != NULL)
		{
			return l2;
		}

		if (l1 != NULL && l2 == NULL)
		{
			return l1;
		}
		
		// ����l2����ÿ���ڵ���뵽l1��
		while (l2 != NULL)
		{		
			int n = l2->val;
			
			// ��l1���Ҳ���λ��
			ListNode *posNode = NULL;

			ListNode *p1 = l1;
			while (p1!=NULL)
			{
				if ( p1->val < n )
				{
					posNode = p1;
				}
				else
				{
					if (p1->next != NULL)
					{
						if (p1->val <= n && p1->next->val >= n)
						{
							posNode = p1;
						}
					}
				}

				p1 = p1->next;
			}

			ListNode *node = new ListNode(n);
			// �ҵ��ˣ����n���뵽posNode����
			if (posNode != NULL)
			{
				node->next = posNode->next;
				posNode->next = node;
			}
			else
			// û�ҵ������뵽l1��ǰ��
			{
				node->next = l1;
				l1 = node;
			}

			l2 = l2->next;
		}

		return l1;
	}
};

int main(int argc, char* argv[], char* env[])
{
	ListNode *n11 = new ListNode(1);
	ListNode *n12 = new ListNode(2);
	ListNode *n14 = new ListNode(4);
	n11->next = n12;
	n12->next = n14;

	ListNode *n21 = new ListNode(2);
	ListNode *n23 = new ListNode(3);
	ListNode *n24 = new ListNode(4);
	n21->next = n23;
	n23->next = n24;

	Solution s;
	ListNode* newList = s.mergeTwoLists(n11, n21);

	while (newList!=NULL)
	{
		cout << newList->val << " " << endl;
		newList = newList->next;
	}



	return 0;
}
