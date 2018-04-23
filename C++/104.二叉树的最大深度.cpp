/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/


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

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : 
		val(x), left(NULL), right(NULL) 
	{
	}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)
		{
			return 0;
		}

		int lDepth = maxDepth(root->left);
		int rDepth = maxDepth(root->right);

		if (lDepth > rDepth)
		{
			return lDepth + 1;
		}
		else
		{
			return rDepth + 1;
		}
	}
};

int main(int argc, char* argv[], char* env[])
{
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node9 = new TreeNode(9);
	TreeNode* node20 = new TreeNode(20);
	TreeNode* node15 = new TreeNode(20);
	TreeNode* node7 = new TreeNode(20);

	node3->left = node9;
	node3->right = node20;

	node20->left = node15;
	node20->right = node7;

	Solution s;
	cout << s.maxDepth(node3) << endl;

	delete node3;
	delete node9;
	delete node20;
	delete node15;
	delete node7;

	return 0;
}


