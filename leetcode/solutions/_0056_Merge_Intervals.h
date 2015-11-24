//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0056_MERGE_INTERVALS_H
#define LEETCODE__0056_MERGE_INTERVALS_H


class _0056_Merge_Intervals {

    bool cmp(Interval a, Interval b) {
        if (a.start != b.start) return a.start < b.start;
        else return a.end < b.end;
    }

    class Solution {
    public:
        vector<Interval> merge(vector<Interval> &intervals) {
            if (intervals.size() < 2) return intervals;

            sort(intervals.begin(), intervals.end(), cmp);
            intervals.push_back(Interval(99999999, 99999999 + 1));
            vector<Interval> ans;
            for (int i = 0; i < intervals.size() - 1; i++) {
                if (intervals[i + 1].start <= intervals[i].end) {
                    intervals[i + 1].start = intervals[i].start;
                    if (intervals[i + 1].end < intervals[i].end) intervals[i + 1].end = intervals[i].end;
                } else {
                    ans.push_back(intervals[i]);
                }
            }
            intervals = ans;
            return intervals;
        }
    };

};


#endif //LEETCODE__0056_MERGE_INTERVALS_H
