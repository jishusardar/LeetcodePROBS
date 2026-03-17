class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int start,end,size=0,index;
        vector<int>temp(n);
        temp[0]=nums[0];
        for(int i=1;i<n;i++){
            start=0,end=size,index=size+1;
            while(start<=end){
                int mid=start+(end-start)/2;
                if(temp[mid]==nums[i]){
                    index=mid;
                    break;
                }
                else if(temp[mid]<nums[i])
                start=mid+1;
                else{
                    index=mid;
                    end=mid-1;
                }
            }
            temp[index]=nums[i];
            size=max(size,index);
        }
        return size+1;
    }
};