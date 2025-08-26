class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long start=0,end=0,sum=0;
        long long ans=0,pos;
        while(end<nums.size()){
            sum+=nums[end];
            pos=end-start+1;
            if(pos!=0&&pos!=1)
            sum*=pos;
            while(sum>=k&&start<=end){
                pos=end-start+1;
                if(pos!=0&&pos!=1)
                sum/=pos;
                sum-=nums[start];
                start++;
                pos=(end-start+1);
                if(pos!=0&&pos!=1)
                sum*=pos;
            }
            pos=end-start+1;
            if(pos!=0&&pos!=1)
            sum/=pos;
            if(pos!=0)
            ans+=pos;
            end++;
        }
        return ans;
    }
};