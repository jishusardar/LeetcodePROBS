class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maximum=INT_MIN;
        int minimum;
        pair<int,pair<int,int>>p;
        vector<pair<int,pair<int,int>>>temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back(make_pair(nums[i][0],make_pair(i,0)));
            maximum=max(maximum,nums[i][0]);
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q(temp.begin(),temp.end());
        vector<int>ans(2);
        ans[0]=q.top().first;
        ans[1]=maximum;
        pair<int,pair<int,int>>Ele;
        int num,i,j;
        while(q.size()==nums.size()){
            Ele=q.top();
            q.pop();
            num=Ele.first;
            i=Ele.second.first;
            j=Ele.second.second;
            if(j+1<nums[i].size()){
                q.push(make_pair(nums[i][j+1],make_pair(i,j+1)));
                maximum=max(maximum,nums[i][j+1]);
                minimum=q.top().first;
                if(maximum-minimum<ans[1]-ans[0]){
                    ans[0]=minimum;
                    ans[1]=maximum;
                }
            }
        }
        return ans;
    }
};