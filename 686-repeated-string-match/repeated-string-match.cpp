class Solution {
public:
    void lps(string s,vector<int>&arr){
        int pre=0,suff=1;
        while(suff<s.size()){
            if(s[pre]==s[suff]){
                arr[suff]=pre+1;
                pre++,suff++;
            }
            else{
                if(pre==0){
                    arr[suff]=0;
                    suff++;
                }
                else
                pre=arr[pre-1];
            }
        }
    }
    bool string_matching(string a,string b,vector<int>&arr){
        int first=0,second=0;
        while(first<a.size()&&second<b.size()){
            if(a[first]==b[second])
            first++,second++;
            else{
                if(second==0)
                first++;
                else
                second=arr[second-1];
            }
        }
        if(second==b.size())
        return 1;
        return 0;
    }
    int repeatedStringMatch(string a, string b) {
        string temp=a;
        int ans=1;
        while(a.size()<b.size()){
            a+=temp;
            ans++;
        }
        vector<int>arr(b.size(),0);
        lps(b,arr);
        if(!(string_matching(a,b,arr))){
            a+=temp;
            ans++;
            return string_matching(a,b,arr)==1?ans:-1;
        }
        return ans;
    }
};