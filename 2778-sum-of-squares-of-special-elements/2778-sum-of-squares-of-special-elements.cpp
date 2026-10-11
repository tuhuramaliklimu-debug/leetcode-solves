class Solution {
public:
    int sumOfSquares(vector<int>& v) {
       int n=v.size();
       int sum=0;

       for(int i=1;i<=n;i++)
       {
        if(n%i==0)
            sum += v[i-1]*v[i-1];
       }
       return sum;
    }
};