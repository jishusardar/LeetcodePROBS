class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long start=0,end=0;
        long long sum=0,ans=0,pos;
        while(end<nums.size()){
            sum+=nums[end];
            pos=(end-start+1);
            sum*=pos;
            while(sum>=k&&start<=end){
                sum/=pos;
                sum-=nums[start];
                start++;
                pos--;
                sum*=pos;
            }
            if(sum>0)
            sum/=pos;
            ans+=(end-start+1);
            end++;
        }
        return ans;
    }
};