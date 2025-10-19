class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;
    int heightmax=INT_MIN,index=-1;
    for (int i=0;i<height.size();i++) {
        if (height[i]>heightmax) {
            heightmax=height[i];
            index=i;
        }
    }
    int maxheight=INT_MIN;
    for (int i=0;i<index;i++) {
        maxheight=max(maxheight,height[i]);
        if (maxheight-height[i]>0)
        water+=maxheight-height[i];
    }
    maxheight=INT_MIN;
    for (int i=height.size()-1;i>index;i--) {
        maxheight=max(maxheight,height[i]);
        if (maxheight-height[i]>0)
        water+=maxheight-height[i];
    }
    return water;
    }
};