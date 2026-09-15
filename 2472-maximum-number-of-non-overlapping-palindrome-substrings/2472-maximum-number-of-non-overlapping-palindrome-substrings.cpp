class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.size(),ans=0,start=0;
        auto check=[&](int l,int r){
            while(l<r){
                if(s[l++]!=s[r--])
                    return false;
            }
            return true;
        };
        for(int r=k-1;r<n;r++){
            int l1=r-k+1;
            if(l1>=start && check(l1,r)){
                ans++;
                start  =r+1;
                continue;

            }
            int l2=r-k;
            if(l2>=start && check(l2,r)){
                ans++;
                start =r+1;
            }
        }
        return ans;
    }
};