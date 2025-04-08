class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr;
        for(int i=0;i<nums1.size();i++){
            arr.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            arr.push_back(nums2[i]);
        }
        sort(arr.begin(),arr.end());
        int start=0,end=arr.size()-1;
        if(arr.size()%2){
            return arr[start+(end-start)/2];
        }
        else{
            int start=0,end=arr.size()-1;
            int mid=start+(end-start)/2;
            double num=arr[mid]+arr[mid+1];
            return num/2;
        }
    }
};