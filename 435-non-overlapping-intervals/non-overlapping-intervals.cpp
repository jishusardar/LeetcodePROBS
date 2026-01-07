class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        for(int i=0;i<intervals.size();i++){
            swap(intervals[i][0],intervals[i][1]);
        }
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][1];
        int end=intervals[0][0];
        int count=1;
        for(int i=1;i<intervals.size();i++){
            if(end<=intervals[i][1]){
                count++;
                end=intervals[i][0];
                start=intervals[i][1];
            }
        }
        return n-count;

    }
};