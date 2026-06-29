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
    bool canAttendMeetings(vector<Interval>& arr) {
        if(arr.size()==0) return true;
        sort(arr.begin(),arr.end(),[](Interval a,Interval b){
            return a.start<b.start;
        });
        int st=arr[0].start;
        int en=arr[0].end;
        int i=1;
        while(i<arr.size())
        {
        while(i<arr.size() && arr[i].start<en) return false;
        st=arr[i].start;
        en=arr[i].end;
        i++;
        }
        return true;
    }
};
