class Solution {
public:
    int maxSum(vector<int>& v, int k) {
        int MOD=1e9+7;
        vector<int>cnt(30,0);
        for( int x: v){
            for(int i=0;i<30;i++){
                if(x&(1<<i))cnt[i]++;
            }
        }
        long long res=0;
        for(int i=0;i<k;i++){
            long long cur=0;
            for(int j=29;j>=0;j--){
                if(cnt[j]>0){
                    cnt[j]--;
                    cur |=(1<<j);
                }
            }
            res=(res + cur*cur)%MOD;
        }
        return res;
        
    }
};