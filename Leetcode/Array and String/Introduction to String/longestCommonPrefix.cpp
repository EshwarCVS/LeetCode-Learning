class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){return "";}
        if(strs.size() == 1){return strs[0];}
        string result;
        int index=1;
        for(auto itr=strs[0].begin(); itr!=strs[0].end();itr++){
            for(int i=1; i<strs.size();i++){
                if(index <= strs[i].length())
                {   string currentWord = strs[i];
                    char currentLetter = currentWord.at(index - 1);
                    if(*itr != currentLetter || index > currentWord.length()){
                        return result;
                    }
                }
                else{
                    return result;
                }
            }
            index++;
            result+= *itr;
        }
        return result;
    }
};
