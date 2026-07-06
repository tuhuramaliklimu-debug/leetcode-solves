class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int>mp;

        for(char c:s)
        {
           mp[c]++;
        }
        int v=0,cn=0;
        for(auto it:mp){
            char c=it.first;
            int cnt=it.second;

            if  (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
                v=max(v,cnt);
            else
                cn=max(cn,cnt);
        }
        return  v+cn;
    }
};