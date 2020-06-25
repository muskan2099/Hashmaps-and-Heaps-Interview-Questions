class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s == t){
            return s;
        }
        if(s.length() < t.length()){
            return "";
        }
        unordered_map<char, int> pat;
        unordered_map<char, int> text;
        int tot = 0;
        for(int i = 0; i < t.length(); i++){
        	pat[t[i]]++;
            if(pat[t[i]] == 1){
                tot++;
            }
        }
        int i = 0;
        int j = 0;
        int start = -1;
        int end = -1;
        
        int matchcount = 0;
        int minlen = INT_MAX;
        while(j < s.length()){
        	while(matchcount != tot && j < s.length()){
        		
        		text[s[j]]++;
        		if(text[s[j]] == pat[s[j]]){
        			matchcount++;
        		}
                j++;
        	}
        	//releasing i;
        	j--;
        	while(i <= j && matchcount == tot){
                int len = j - i + 1;
                if(len < minlen){
                    minlen = len;
                    start = i;
                    end = j;
                }
                if(pat[s[i]] == text[s[i]]){
                    matchcount--;
                }
                text[s[i]]--;
                i++;
            }
            j++;
        }
        if(minlen == INT_MAX){
            return "";
        }
        string ans = s.substr(start, minlen);
        return ans;
    }
};