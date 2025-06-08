class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>ans;
        for(int i=1;i<=n;i++){
            ans.push_back(to_string(i));
        }
        sort(ans.begin(),ans.end());
        vector<int>fans;
        for(int i=0;i<ans.size();i++){
            fans.push_back(stoi(ans[i]));
        }
        return fans;
    }
};