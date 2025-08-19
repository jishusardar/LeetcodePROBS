class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int num;
        int maxi=INT_MIN;
        int min;
        int i,j;
        vector<pair<int,pair<int,int>>>temp;
        pair<int,pair<int,int>>Ele;
        vector<int>ans(2);
        int n=nums.size();
        for(int i=0;i<n;i++){
            temp.push_back(make_pair(nums[i][0],make_pair(i,0)));
            maxi=max(maxi,nums[i][0]);
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q(temp.begin(),temp.end());
        Ele=q.top();
        ans[0]=Ele.first;
        ans[1]=maxi;
        while(q.size()==nums.size()){
            Ele=q.top();
            q.pop();
            num=Ele.first;
            i=Ele.second.first;
            j=Ele.second.second;
            if(j+1<nums[i].size()){
                q.push(make_pair(nums[i][j+1],make_pair(i,j+1)));
                maxi=max(maxi,nums[i][j+1]);
                min=q.top().first;
                if(maxi-min<ans[1]-ans[0]){
                    ans[0]=min;
                    ans[1]=maxi;
                }
            }
        }
        return ans;
    }
};