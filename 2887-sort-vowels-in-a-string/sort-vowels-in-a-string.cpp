class Solution {
public:
    string sortVowels(string s) {
        vector<int>count(52,0);
        for(int i=0;i<s.size();i++){
            if(s[i]>='A'&&s[i]<='Z'){
                if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                    count[s[i]-'A']++;
                s[i]='#';
                }
            }
            if(s[i]>='a'&&s[i]<='z'){
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                     count[(s[i]-'a')+26]++;
                     s[i]='#';
                }
            }
        }
        string temp="";
        for(int i=0;i<52;i++){
            while(count[i]--){
                if(i<26){
                    char c='A'+i;
                    temp+=c;
                }
                else{
                    char c='a'+i%26;
                    temp+=c;
                }
            }
        }
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#')
            s[i]=temp[j++];
        }
        return s;
    }
};