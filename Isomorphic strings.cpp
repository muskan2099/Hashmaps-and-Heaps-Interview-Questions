class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> vmap1, vmap2;
        if (s.length() != t.length())   return false;
        
        for (int i = 0; i < s.length(); i++) {
            if (vmap1.find(s[i]) == vmap1.end())  {
                if (vmap2.find(t[i]) == vmap2.end()) {
                    vmap1[s[i]] = t[i];
                    vmap2[t[i]] = s[i];
                } else if (vmap2[t[i]] != s[i]) {
                    return false;
                } else {
                    vmap1[s[i]] = t[i];
                }
            }
            else {
                if (vmap1[s[i]] != t[i])    return false;
                else if (vmap2.find(t[i]) == vmap2.end())   vmap2[t[i]] = s[i];
                else if (vmap2[t[i]] != s[i])   return false;
            }
        }
        
        return true;
    }
};