#include <set>
#include <iostream>
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
	bool hasCycle(ListNode *head) 
	{
		set<ListNode*> setList;

		ListNode* p = head;
		while (p != NULL)
		{
			if (setList.find(p) != setList.end())
			{
				return true;
			}

			setList.insert(p);
			p = p->next;
		}

		return false;
	}
};


int main()
{
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = NULL;

	ListNode *head = p1;
	
	Solution s;
	cout << s.hasCycle(head) << endl;

	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	
	return 0;
}

