class Solution {
    vector<long long>sum,tag;
    long long bump(int x,int a,int b,int l,int r,long long above){
        if(r<a||b<l) return 0;
        long long k=min(b,r)-max(a,l)+1,old;
        if(l<=a && b<=r){
            old=sum[x]+above*k;
            tag[x]++;
        }else{
            int m=(a+b)/2;
            long long down=above+tag[x];
            old=bump(2*x,a,m,l,r,down);
            old+=bump(2*x+1,m+1,b,l,r,down);

        }
        sum[x]+=k;
        return old;
    }
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD=1e9+7;
        int n=nums.size();
        sum.assign(4*n,0);
        tag.assign(4*n,0);
        vector<int>last(100001,-1);
        long long sq=0,ans=0;
        for (int j=0;j<n;++j)
        {
            int p=last[nums[j]];
            last[nums[j]]=j;

            long long old=bump(1,0,n-1,p+1,j,0);
            sq=(sq+2*old+j-p)%MOD;
            ans=(ans+sq)%MOD;
        }
        return ans;
      
    }
};