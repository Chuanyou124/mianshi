/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) 
    {
        vector<vector<TreeNode *>> result;
        vector<vector<int>> resultVal;
        if (!root)
        {
            return resultVal;
        }
        vector<TreeNode *> aRow;
        aRow.push_back(root);
        result.push_back(aRow);
        bool goOn = true;
        bool fromRight = true;
        
        while (goOn)
        {
            vector<TreeNode *> aRow;
            for (int i = result.back().size() - 1; i >= 0; --i)
            {
                if (fromRight)
                {
                    if (result.back()[i]->right)
                    {
                        aRow.push_back(result.back()[i]->right);
                    }
                    if (result.back()[i]->left)
                    {
                        aRow.push_back(result.back()[i]->left);
                    }
                }
                else
                {
                    if (result.back()[i]->left)
                    {
                        aRow.push_back(result.back()[i]->left);
                    }
                    if (result.back()[i]->right)
                    {
                        aRow.push_back(result.back()[i]->right);
                    }
                }
            }
            if (aRow.size())
            {
                result.push_back(aRow);
                fromRight = fromRight ? false:true;
            }
            else
            {
                goOn = false;
            }
        }
        for (int i = 0; i < result.size(); ++i)
        {
            vector<int> aRowVal;
            for (int j = 0; j < result[i].size(); ++j)
            {
                aRowVal.push_back(result[i][j]->val);
            }
            resultVal.push_back(aRowVal);
        }
        return resultVal;
    }
}; 
