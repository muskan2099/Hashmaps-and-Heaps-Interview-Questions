class Solution {
public:
    int bulbSwitch(int n) {
        int squares = 0;
        for(int i = 1; i <= n; i++){
            int count = 0;
            for(int j = 1; j <= sqrt(i); j++){
                
                if(i%j == 0){
                    if(i/j == j){
                        count++;
                    }
                    else{
                        count= count + 2;
                    }
                }
            }
            if(count%2 == 0){
                cout << i << endl;         
                squares++;
            }
        }
        return squares;
    }
};