class Solution {
public:
    string minWindow(string s, string t) {
        int start=0,end=0,count=0;
        unordered_map<char,int>mm;
        for(int i=0;i<t.size();i++){
            mm[t[i]]++;
        }
        int len=INT_MAX;
        int index=-1;
        count=t.size();
        while(end<s.size()){
            mm[s[end]]--;
            if(mm[s[end]]>=0)
            count--;
            while(count==0&&start<=end){
                if(len>(end-start+1)){
                    len=end-start+1;
                    index=start;
                }
                mm[s[start]]++;
                if(mm[s[start]]>0)
                count++;
                start++;
            }
            end++;
        }
        if(index==-1)
        return "";
        string str="";
        for(int i=index;i<index+len;i++){
            str+=s[i];
        }
        return str;

    }
};