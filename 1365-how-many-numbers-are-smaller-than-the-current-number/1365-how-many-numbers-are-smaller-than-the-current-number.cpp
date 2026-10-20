class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
       map<int ,int>mp;
       vector<int>v;
       for(int a:nums)
            mp[a]++;
        for(int x:nums){
            int cnt=0;
            for(auto it:mp)
            {
                if(it.first<x)
                    cnt+=it.second;
            }
            v.push_back(cnt);
        }
        return v;


    }
};