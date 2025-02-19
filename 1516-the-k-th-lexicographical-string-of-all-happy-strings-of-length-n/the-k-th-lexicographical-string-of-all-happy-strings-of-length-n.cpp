class Solution {
public:
    string str="abc";
    void strings(int n,string &temp,vector<string>&ans)
    {
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<str.size();i++){
            if(temp.size()==0){
                temp.push_back(str[i]);
                strings(n,temp,ans);
                temp.pop_back();
            }
            else if(temp.size()&&temp[temp.size()-1]!=str[i]){
                temp.push_back(str[i]);
                strings(n,temp,ans);
                temp.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) { 
        vector<string>ans;
        string temp;
        strings(n,temp,ans);
        if(ans.size()<k)
        return "";
        return ans[k-1];
    }
};