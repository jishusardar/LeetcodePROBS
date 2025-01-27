class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0,end=height.size()-1;
        int ans=0;
        while(start<=end){
            int water=min(height[start],height[end])*(end-start);
            ans=max(ans,water);
            if(height[start]>height[end])
            end--;
            else
            start++;
        }
        return ans;
    }
};