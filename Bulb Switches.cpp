class Solution {
public:
    int bulbSwitch(int n) {
        int squares = 0;
        int i = 1;
        
        while(i*i <= n){
            squares++;
            i++;
        }
        return squares;
    }
};