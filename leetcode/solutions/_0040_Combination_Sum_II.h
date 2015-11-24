//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0040_COMBINATION_SUM_II_H
#define LEETCODE__0040_COMBINATION_SUM_II_H


class _0040_Combination_Sum_II {

    class Solution {
    public:
        vector<vector<int> > ans;  // answer
        vector<int> can;  // "can" is a vector from candidates after processing
        vector<bool> used;
        int t;
        vector<vector<int> > combinationSum2(vector<int> &num, int target) {
            ans.clear();
            can = num;
            sort(can.begin(), can.end());  // to make sure that the solutions in ans is in non-descending order
            used.resize(can.size());
            t = target;
            dfs(0, 0);
            sort(ans.begin(), ans.end());
            vector<vector<int> > trueAns;
            for (int i = 0; i < ans.size(); i++) {
                if (trueAns.size() > 0 && trueAns.back() == ans[i]) continue;
                trueAns.push_back(ans[i]);
            }
            return trueAns;
        }
        void dfs(int pos, int nowSum) {

            if (nowSum == t) {
                vector<int> anAns;
                for (int i = 0; i < can.size(); i++) {
                    if (used[i]) anAns.push_back(can[i]);
                }
                ans.push_back(anAns);
                return;
            }

            if (nowSum > t || pos >= can.size()) return;

            used[pos] = false;
            dfs(pos + 1, nowSum);
            if (can[pos] + nowSum <= t) {
                used[pos] = true;
                dfs(pos + 1, can[pos] + nowSum);
                used[pos] = false;
            }
        }
    };

};


#endif //LEETCODE__0040_COMBINATION_SUM_II_H
