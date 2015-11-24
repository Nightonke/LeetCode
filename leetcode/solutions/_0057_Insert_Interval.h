//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0057_INSERT_INTERVAL_H
#define LEETCODE__0057_INSERT_INTERVAL_H


class _0057_Insert_Interval {

    class Solution {
    public:
        void include(vector<Interval> &intervals, int target, int & l, int & r, bool & isIncluded) {
            for (int i = 0; i < intervals.size(); i++) {
                if (target < intervals[i].start) {
                    l = i - 1;
                    r = i;
                    isIncluded = false;
                    return;
                } else if (intervals[i].start <= target && target <= intervals[i].end) {
                    l = r = i;
                    isIncluded = true;
                    return;
                }
            }
            l = intervals.size() - 1;
            r = intervals.size();
            isIncluded = false;
        }
        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
            vector<Interval> ans;
            int sl, sr, el, er;
            bool si, ei;
            include(intervals, newInterval.start, sl, sr, si);
            include(intervals, newInterval.end, el, er, ei);
            if (si && ei) {
                for (int i = 0; i < intervals.size(); i++) {
                    if (i == sl) {
                        Interval newinter(intervals[sl].start, intervals[er].end);
                        ans.push_back(newinter);
                        i = er;
                    } else {
                        ans.push_back(intervals[i]);
                    }
                }
            } else if (si && !ei) {
                for (int i = 0; i < intervals.size(); i++) {
                    if (i == sl) {
                        Interval newinter(intervals[i].start, newInterval.end);
                        ans.push_back(newinter);
                        i = el;
                    } else {
                        ans.push_back(intervals[i]);
                    }
                }
            } else if (!si && ei) {
                for (int i = 0; i < intervals.size(); i++) {
                    if (i == sr) {
                        Interval newinter(newInterval.start, intervals[er].end);
                        ans.push_back(newinter);
                        i = er;
                    } else {
                        ans.push_back(intervals[i]);
                    }
                }
            } else {
                if (sr == intervals.size()) {
                    ans = intervals;
                    ans.push_back(Interval(newInterval.start, newInterval.end));
                    return ans;
                }
                if (er == 0) {
                    ans.push_back(Interval(newInterval.start, newInterval.end));
                    for (int i = 0; i < intervals.size(); i++) ans.push_back(intervals[i]);
                    return ans;
                }
                if (sl == el && sr == er) {
                    for (int i = 0; i < er; i++) ans.push_back(intervals[i]);
                    ans.push_back(Interval(newInterval.start, newInterval.end));
                    for (int i = er; i < intervals.size(); i++) ans.push_back(intervals[i]);
                    return ans;
                }
                for (int i = 0; i < intervals.size(); i++) {
                    if (i == sr) {
                        Interval newinter(newInterval.start, newInterval.end);
                        ans.push_back(newinter);
                        i = el;
                    } else {
                        ans.push_back(intervals[i]);
                    }
                }
            }
            return ans;
        }
    };

};


#endif //LEETCODE__0057_INSERT_INTERVAL_H
