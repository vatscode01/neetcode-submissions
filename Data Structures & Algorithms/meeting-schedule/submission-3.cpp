/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    bool canAttendMeetings(vector<Interval>& a) {
        if (a.size() <= 1) return true;
        sort(a.begin(), a.end(), cmp);
        for (int i = 0; i < a.size() - 1; i++) {
            if (a[i].end > a[i + 1].start) return false;
        }
        return true;
    }
    static bool cmp(Interval a, Interval b) {
        if (a.start == b.start) return a.end <= b.start;
        return a.start < b.start;
    }
};
