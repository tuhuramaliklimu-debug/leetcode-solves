class Solution {
public:
    int countPrimes(int n) {
         if(n<=2)return 0;

         vector<bool>sieve(n,true);
         sieve[0]=sieve[1]=false;
         int cnt=1;
         for(int i=3;i*i<n;i+=2)
         {
            if(sieve[i]){
                for(int j=i*i;j<n;j+=2*i){
                    sieve[j]=false;
                }
            }
         }
         for(int i=3;i<n;i+=2){
            if(sieve[i])cnt++;
         }
        return cnt;

    }
};