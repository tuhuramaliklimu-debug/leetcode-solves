class Solution {
public:
    bool threeFibonacciSum(int n) {
        int i=0,j=1,k=1;
        while(i+j+k<n){
            i=j;
            j=k;
            k=i+j;
        }
        return i+j+k==n;
    }
};