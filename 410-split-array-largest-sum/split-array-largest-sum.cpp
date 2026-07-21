#define ll long long
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        ll int start=0,end=0,n=nums.size(),ans=-1;
    for (int i=0;i<n;i++) {
        if (nums[i]>start)
            start=nums[i];
        end+=nums[i];
    }
    while (start<=end) {
        ll int mid=start+(end-start)/2;
        ll int sum=nums[0],sumu=1;
        for (int i=1;i<n;i++) {
            sum+=nums[i];
            if (sum>mid) {
                sum=nums[i];
                sumu++;
                if (sumu>k)
                    break;
            }
        }
        if (sumu<=k) {
            ans=mid;
            end=mid-1;
        }
        else
            start=mid+1;
    }
    return ans;
    }
};