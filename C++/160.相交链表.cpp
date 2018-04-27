#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : 
		val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		set<ListNode *> setA;
		while (headA != NULL)
		{
			setA.insert(headA);
			headA = headA->next;
		}
		
		while (headB != NULL)
		{
			if (setA.find(headB) != setA.end()) {
				return headB;
			}
			headB = headB->next;
		}

		return NULL;

		/*
		while (headA != NULL)
		{
			ListNode *pB = headB;
			while (pB != NULL)
			{
				if (headA == pB)
				{
					return headA;
				}
				pB = pB->next;
			}

			headA = headA->next;
		}

		return NULL;
		*/
	}
};

int main(int argc, char* argv[], char* env[])
{
	ListNode* pa1 = new ListNode(1);
	ListNode* pa2 = new ListNode(2);

	ListNode* pb1 = new ListNode(3);
	ListNode* pb2 = new ListNode(4);
	ListNode* pb3 = new ListNode(5);
	ListNode* pb4 = new ListNode(6);

	ListNode* p7 = new ListNode(7);
	ListNode* p8 = new ListNode(8);
	ListNode* p9 = new ListNode(9);
	ListNode* p10 = new ListNode(10);

	pa1->next = pa2;
	pa2->next = p7;

	pb1->next = pb2;
	pb2->next = pb3;
	pb3->next = pb4;
	pb4->next = p7;

	p7->next = p8;
	p8->next = p9;
	p9->next = p10;

	ListNode* headA = pa1;
	ListNode* headB = pb1;

	Solution s;
	ListNode* pNode = s.getIntersectionNode(headA, headB);
	if (pNode != NULL)
	{
		cout << pNode->val << endl;
	}
	else
	{
		cout << "NULL" << endl;
	}

	delete  pa1;
	delete  pa2;

	delete  pb1;
	delete  pb2;
	delete  pb3;
	delete  pb4;

	delete  p7;
	delete  p8;
	delete  p9;
	delete  p10;

	return 0;
}
