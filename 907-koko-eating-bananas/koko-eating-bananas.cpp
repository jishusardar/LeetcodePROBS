#define ll long long
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    ll int start=0,end=0,n=piles.size();
    for (int i=0;i<n;i++) {
        start+=piles[i];
        if(piles[i]>end)
        end=piles[i];
    }
    start/=h;
    if(!start)
    start=1;
    ll int ans=-1;
    while (start<=end) {
        ll int mid=start+(end-start)/2;
        ll int time=0;
        for (int i=0;i<n;i++) {
            time+=piles[i]/mid;
            if (piles[i]%mid)
                time++;
        }
        if (time<=h) {
            ans=mid;
            end=mid-1;
        }
        else
            start=mid+1;
    }
    return ans;
    }
};