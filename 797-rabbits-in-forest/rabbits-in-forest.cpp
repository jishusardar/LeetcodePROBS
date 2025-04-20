class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mm;
        int count=0;
        for(int i=0;i<answers.size();i++){
            if(answers[i]==0)
            count++;
            else if(mm[answers[i]]==0){
                count+=answers[i]+1;
                mm[answers[i]]=answers[i];
            }
            else
            mm[answers[i]]--;
        }
        return count;
    }
};