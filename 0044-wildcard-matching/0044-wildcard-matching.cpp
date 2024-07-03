class Solution {
public:
    bool isMatch(string s, string p) {
    int sIndex = 0, pIndex = 0, match = 0, starIndex = -1;
        while (sIndex < s.size()) {
            if (pIndex < p.size() && (p[pIndex] == '?' || p[pIndex] == s[sIndex])) {
                sIndex++;
                pIndex++;
            } else if (pIndex < p.size() && p[pIndex] == '*') {
                starIndex = pIndex;
                match = sIndex;
                pIndex++;
            } else if (starIndex!= -1) {
                pIndex = starIndex + 1;
                match++;
                sIndex = match;
            } else return false;
        }
        while (pIndex < p.size() && p[pIndex] == '*') pIndex++;
        return pIndex == p.size();    
    }
};