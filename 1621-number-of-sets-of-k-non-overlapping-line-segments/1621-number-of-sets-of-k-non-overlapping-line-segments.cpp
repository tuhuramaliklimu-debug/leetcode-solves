class Solution {
public:
    int numberOfSets(int n, int k) {
        long long res=1;
        long long mod=1e9+7;
        for(int i=1;i<=k*2;++i){
            res=res*(n+k-i)%mod;
            long long base=i,exp=mod-2,inv=1;
            while(exp>0){
                if(exp%2==1)inv=inv*base%mod;
                base=base*base%mod;
                exp/=2;
            }
            res=res*inv%mod;
        }
        return  res;

    }
};