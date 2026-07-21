class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
            int start=0,end=0,n=weights.size();
    for (int i=0;i<n;i++) {
        if (weights[i]>start)
            start=weights[i];
        end+=weights[i];
    }
    int ans=-1;
    while (start<=end) {
        int mid=start+(end-start)/2;
        int packages=weights[0],timed=1;
        for (int i=1;i<n;i++) {
            packages+=weights[i];
            if (packages>mid) {
                packages=weights[i];
                timed++;
                if (timed>days)
                    break;
            }
        }
        if (timed>days) {
            start=mid+1;
        }
        else {
            ans=mid;
            end=mid-1;
        }

    }
    return ans;
    }
};