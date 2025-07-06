class FindSumPairs {
public:
    vector<int>nums1;
    unordered_map<int,int>mm;
    vector<int>nums2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
        for(int i=0;i<nums2.size();i++){
            mm[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        mm[nums2[index]]--;
        nums2[index]+=val;
        mm[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(int i=0;i<nums1.size();i++){
            if(mm[tot-nums1[i]])
            ans+=mm[tot-nums1[i]];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */