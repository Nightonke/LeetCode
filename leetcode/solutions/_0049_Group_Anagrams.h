//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0049_GROUP_ANAGRAMS_H
#define LEETCODE__0049_GROUP_ANAGRAMS_H


class _0049_Group_Anagrams {

    class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string> &strs) {
            map<string, multiset<string> > strM;
            for (vector<string>::iterator iter = strs.begin(); iter != strs.end(); iter++) {
                strM[getKey(*iter)].insert(*iter);
            }
            vector<vector<string>> ans;
            for (map<string, multiset<string> >::iterator iter = strM.begin(); iter != strM.end(); iter++) {
                vector<string> partOfAns;
                for (set<string>::iterator iter2 = iter->second.begin(); iter2 != iter->second.end(); iter2++) {
                    partOfAns.push_back(*iter2);
                }
                ans.push_back(partOfAns);
            }
            return ans;
        }
        string getKey(string s) {
            string sortS = s;
            sort(sortS.begin(), sortS.end());
            return sortS;
        }
    };

};


#endif //LEETCODE__0049_GROUP_ANAGRAMS_H
