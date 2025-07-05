class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans=-1,count=0,pivot=arr[0];
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(pivot==arr[i])
            count++;
            else{
                if(pivot==count)
                ans=max(ans,pivot);
                pivot=arr[i];
                count=1;
            }
        }
        if(arr[arr.size()-1]==count)
        ans=max(ans,arr[arr.size()-1]);
        return ans;
    }
};