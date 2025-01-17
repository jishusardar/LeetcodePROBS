class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int on=0;
        for(int i=0;i<derived.size();i++){
            if(derived[i]==1)
            on++;
        }
        if(on%2)
        return false;
        return true;
    }
};