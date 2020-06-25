class FreqStack {
public:
   
        unordered_map<int, stack<int>> freq;
        unordered_map<int, int> num;
        int maxfreq = 0;
    
    
    void push(int x) {
        
        int times;
        if(num.count(x) == 0){
        	num[x] = 1;
        	times = 1;
        }
        else{
        	num[x]++;
        	times = num[x];
        }
        if(freq.count(times) == 0){
        	stack<int> temp;
        	temp.push(x);

        	freq[times] = temp;
        }
        else{

        	freq[times].push(x);
        }

        maxfreq = max(maxfreq, times);
    }
    
    int pop() {

    	int topop = freq[maxfreq].top();
    	freq[maxfreq].pop();
    	if(freq[maxfreq].empty()){
    		freq.erase(maxfreq);
    		maxfreq--;
    	}        

    	num[topop]--;
        
        return topop;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */