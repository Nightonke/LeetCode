//
// Created by Weiping Huang on 2015/11/25.
//

#ifndef LEETCODE__0257_BINARY_TREE_PATHS_H
#define LEETCODE__0257_BINARY_TREE_PATHS_H


class _0257_Binary_Tree_Paths {

    class Solution {
    public:
        vector<string> binaryTreePaths(TreeNode* root) {
            road.clear();
            answers.clear();
            preOrder(root);
            return answers;
        }
    private:
        vector<int> road;
        vector<string> answers;

        void preOrder(TreeNode * root) {
            if (!root) return;
            road.push_back(root->val);
            if (root->left) preOrder(root->left);
            if (root->right) preOrder(root->right);
            if (!root->left && !root->right) {
                string answer = "";
                for (int i = 0; i < road.size(); i++) {
                    if (i > 0) answer += "->";
                    answer += intToString(road[i]);
                }
                if (answer != "") answers.push_back(answer);
            }
            road.pop_back();
        }

        string intToString(int i) {
            string answer = "";
            bool negative = i < 0;
            if (negative) i = -i;
            do {
                answer += i % 10 + '0';
                i /= 10;
            } while (i);
            reverse(answer.begin(), answer.end());
            return negative ? "-" + answer : answer;
        }
    };

};


#endif // LEETCODE__0257_BINARY_TREE_PATHS_H
