class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> used;
        return backtrack(s, 0, used);
    }
    
    int backtrack(const string& s, int start, unordered_set<string>& used) {
        if (start == s.length()) {
            return 0;
        }
        
        int maxSplits = 0;
        
        for (int i = start; i < s.length(); ++i) {
            string sub = s.substr(start, i - start + 1);
            
            if (used.find(sub) == used.end()) {
                used.insert(sub);
                maxSplits = max(maxSplits, 1 + backtrack(s, i + 1, used));
                used.erase(sub);
            }
        }
        
        return maxSplits;
    }
};