class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> freq(26, 0);

        int j = 0;
        int i = 0;
        int count = p.length();
        for(int i = 0; i < p.length(); i++){
        	freq[p[i] - 'a']++;
        }
        while(j < s.length()){

        	if(freq[s[j] - 'a'] > 0){

        		freq[s[j] - 'a']--;
        		count--;
	        	if(count == 0){
	        		ans.push_back(i);
	        	}
	        	j++;
        	}
        	else if(i == j){
        		j++;
        		i++;
        		count = p.length();
        	}
        	else{
        		freq[s[i] - 'a']++;
        		i++;
        		count++;
        	}

        }
        return res;
    }
};