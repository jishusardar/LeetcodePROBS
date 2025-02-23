class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums2.size(),-1);
        stack<int>st;
        for(int i=0;i<nums2.size();i++){
            while(!st.empty()&&nums2[st.top()]<nums2[i]){
                ans[st.top()]=nums2[i];
                st.pop();
            }
            st.push(i);
        }
        unordered_map<int,int>mm;
        for(int i=0;i<nums2.size();i++){
            mm[nums2[i]]=ans[i];
        }
        vector<int>arr;
        for(int i=0;i<nums1.size();i++){
            arr.push_back(mm[nums1[i]]);
        }
        return arr;
    }
};