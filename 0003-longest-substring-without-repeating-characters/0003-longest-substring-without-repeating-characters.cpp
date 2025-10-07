class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;

        for(int i = 0; i < s.length(); i++){
            string m = "";
            for(int j = i; j < s.length(); j++){
                if(m.find(s[j]) == string::npos){
                    m = m + s[j];
                    if(m.length() > maxlen){
                        maxlen = m.length();
                    }
                }else{
                    break;
                }
            }
        }
        return maxlen;
    }
};