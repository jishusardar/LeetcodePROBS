class Solution {
public:
string str="01";
void generate(int n,string &temp,vector<string>&ans)
{
    if(temp.size()==n){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<str.size();i++){
        if(temp.size()<n){
            temp.push_back(str[i]);
            generate(n,temp,ans);
            temp.pop_back();
        }
    }
}
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int>mm;
        string temp;
        vector<string>ans;
        int n=nums.size();
        generate(n,temp,ans);
        for(int i=0;i<nums.size();i++){
            mm[nums[i]]++;
        }
        for(int i=0;i<ans.size();i++){
            if(mm[ans[i]]==0)
            return ans[i];
        }
        return "";
    }
};