class Solution {
public:
    void generate(int n,int left,int right,string &temp,vector<string>&ans)
    {
        if(left+right==2*n){
            ans.push_back(temp);
            return;
        }
        if(left<n){
            temp.push_back('(');
            generate(n,left+1,right,temp,ans);
            temp.pop_back();
        }
        if(right<left){
            temp.push_back(')');
            generate(n,left,right+1,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        generate(n,0,0,temp,ans);
        return ans;
    }
};