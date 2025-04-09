class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int>arr(100,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]<k)
            return -1;
        }
        int count=0;
        int maxi=INT_MIN;
        bool p=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k)
            p=true;
            maxi=max(maxi,nums[i]);
            arr[nums[i]-1]++;
        }
        if(p==false)
        count++;
        for(int i=0;i<100;i++){
            if(arr[i]!=0){
                if(i+1<maxi)
                count++;
            }
        }
        return count;
    }
};