//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0038_COUNT_AND_SAY_H
#define LEETCODE__0038_COUNT_AND_SAY_H


class _0038_Count_and_Say {

    class Solution {
    public:
        string countAndSay(int n) {
            string before = "1";
            int counter = 1;
            while(counter < n) {
                counter++;
                string next;
                for (int i = 0; i < before.size(); i++) {
                    char temp = before[i];
                    int num = 1;
                    while (i + 1 < before.size() && before[i + 1] == temp) {
                        num++;
                        i++;
                    }
                    next += numToStr(num) + temp;
                }
                before = next;
            }
            return before;
        }
        string numToStr(int num) {
            stringstream ss;
            ss << num;
            return ss.str();
        }
    };

};


#endif //LEETCODE__0038_COUNT_AND_SAY_H
