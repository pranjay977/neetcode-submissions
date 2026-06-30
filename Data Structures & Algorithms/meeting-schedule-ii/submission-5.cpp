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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto e,auto f){return e.start<f.start;});
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans=0;
        for(auto e:intervals)
        {
        while(pq.empty()==false && pq.top()<=e.start) pq.pop();
        pq.push(e.end);
        ans=max(ans,(int)pq.size());
        }
        return ans;
        }
};
