//
// Created by Weiping Huang on 2015/11/25.
//

#ifndef LEETCODE__0247_STROBOGRAMMATIC_NUMBER_II_H
#define LEETCODE__0247_STROBOGRAMMATIC_NUMBER_II_H


class _0247_Strobogrammatic_Number_II {

    class Solution {
    public:
        void DFS(int l, string s) {
            if (l == N) ans.push_back(s);
            else {
                if (l + 2 != N) DFS(l + 2, "0" + s + "0");
                DFS(l + 2, "1" + s + "1");
                DFS(l + 2, "6" + s + "9");
                DFS(l + 2, "8" + s + "8");
                DFS(l + 2, "9" + s + "6");
            }
        }
        vector<string> findStrobogrammatic(int n) {
            ans.clear();
            N = n;
            if (n % 2 == 0) {
                DFS(0, "");
            }
            else {
                DFS(1, "0");
                DFS(1, "1");
                DFS(1, "8");
            }
            sort(ans.begin(), ans.end());
            return ans;
        }
    private:
        vector<string> ans;
        int N;
    };

};


#endif // LEETCODE__0247_STROBOGRAMMATIC_NUMBER_II_H
