#include <bits/stdc++.h> 
using namespace std; 
  
int countKdivPairs(int A[], int n, int K) 
{ 
    int *rem = new int[n];
    for(int i = 0; i < n; i++){
        if(A[i] < 0){
            rem[i] = A[i]%K + K;
        }
        else{
            rem[i] = A[i]%K;
        }
    }
    int ans = 0;
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++){

        int r1 = rem[i];
        int r2;
        if(r1 == 0){
            r2 = 0;
        }
        else{
            r2 = K - r1;
        }

        if(hash.count(r2) != 0){
            ans += hash[r2];
        }
        if(hash.count(r1) == 0){
            hash[r1] = 1;
        }
        else{
            hash[r1]++;
        }
    }
    return ans;
} 
  
// Driver code 
int main() 
{ 
  
    int A[] = { 2, 2, 1, 7, 5, 3, 6, 2, 8, 12 }; 
    int n = sizeof(A) / sizeof(A[0]); 
    int K = 4; 
    cout << countKdivPairs(A, n, K); 
  
    return 0; 
} 