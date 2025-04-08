class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>count;
        if(nums.size()<3){
            if(nums.size()==1)
            return 0;
            if(nums.size()==2){
                if(nums[0]==nums[1])
                return 1;
                return 0;
            }
        }
        for(int i=0;i<nums.size();i++){
            count[nums[i]-1]++;
        }
        int start=0,end=nums.size()-1;
        int pos;
        int ans=0;
        while(end>=0){
            if(count[nums[end]-1]>1){
                ans++;
                pos=3;
                if(end-start<3)
                pos=end-start+1;
                while(pos--){
                    count[nums[start]-1]--;
                    start++;
                }
            }
            else
            end--;
        }
        return ans;

    }
};