class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mm;
        mm[0]=1;
        int ans=0;
        int odd=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2)
            odd++;
            if(mm.find(odd-k)!=mm.end())
            ans+=mm[odd-k];
            mm[odd]++;
        }
        return ans;
    }
};