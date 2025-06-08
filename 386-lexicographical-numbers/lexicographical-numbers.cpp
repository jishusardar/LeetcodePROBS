class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>ans;
        for(int i=1;i<=n;i++){
            string num=to_string(i);
            ans.push_back(num);
        }
        sort(ans.begin(),ans.end());
        vector<int>fans;
        for(int i=0;i<ans.size();i++){
            int number=stoi(ans[i]);
            fans.push_back(number);
        }
        return fans;
    }
};