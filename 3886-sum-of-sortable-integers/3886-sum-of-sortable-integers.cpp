static constexpr int MAX=1e5;
static int desc[MAX]={0},premax[MAX],sufmin[MAX];

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        const int n=nums.size();
        if(n==1)return 1;
        for(int i=1;i<n;i++)
            desc[i]=desc[i-1]+(nums[i-1]>nums[i]);
        premax[0]=nums[0];
        for(int i=1;i<n;++i)
            premax[i]=max(premax[i-1],nums[i]);
        sufmin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            sufmin[i]=min(sufmin[i+1],nums[i]);
        
        auto check=[&](int k){
            for(int l=0;l<n;l+=k){
                const int r=l+k-1;
                if(l && premax[l-1] > sufmin[l]) return false;
                const int d=desc[r]-desc[l]+(nums[r]>nums[l]);
                if(d>1) return false;
            }
            return true;
        };

        int res=0;
        for(int k=1;k*k<=n;k++)
        {
            if (n%k==0)
            {
                if (check(k)) res+=k;
                const int k2=n/k;
                if(k2!=k && check(k2))
                    res+=k2;
            }
        }
        return res;
    }
};