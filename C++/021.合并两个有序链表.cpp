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
		
		// 遍历l2，把每个节点插入到l1上
		while (l2 != NULL)
		{		
			int n = l2->val;
			
			// 在l1上找插入位置
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
			// 找到了，则把n插入到posNode后面
			if (posNode != NULL)
			{
				node->next = posNode->next;
				posNode->next = node;
			}
			else
			// 没找到，插入到l1最前面
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
