//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0039_COMBINATION_SUM_H
#define LEETCODE__0039_COMBINATION_SUM_H


class _0039_Combination_Sum {

    class Solution {
    public:
        vector<vector<int> > ans;
        vector<int> can;
        vector<int> used;
        int t;
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            ans.clear();
            can.clear();
            for (int i = 0; i < candidates.size(); i++) {
                if (can.size() != 0 && can.back() == candidates[i]) continue;
                can.push_back(candidates[i]);
            }
            sort(can.begin(), can.end());
            used.resize(candidates.size());
            t = target;
            dfs(0, 0);
            return ans;
        }
        void dfs(int pos, int nowSum) {

            if (nowSum == t) {
                vector<int> anAns;
                for (int i = 0; i < can.size(); i++) {
                    for (int j = 0; j < used[i]; j++) {
                        anAns.push_back(can[i]);
                    }
                }
                ans.push_back(anAns);
                return;
            }

            if (pos >= can.size()) return;

            for (int i = 0; can[pos] * i + nowSum <= t; i++) {
                used[pos] = i;
                dfs(pos + 1, can[pos] * i + nowSum);
                //if (pos + 1 != can.size()) used[pos + 1] = 0;

            }
        }
    };

};


#endif //LEETCODE__0039_COMBINATION_SUM_H
