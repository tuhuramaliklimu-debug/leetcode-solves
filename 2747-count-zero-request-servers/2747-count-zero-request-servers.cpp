class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        auto lambda = [](vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        };
        sort(logs.begin(), logs.end(), lambda);

        vector<int> ans(queries.size());
        
        vector<pair<int, int>> time;
        for(int i=0; i<queries.size(); i++){
            time.push_back({queries[i], i});
        }
        sort(time.begin(), time.end());

        unordered_map<int, int> mp;
        int i=0, j=0;

        for(auto [t, idx]:time){
            int start=t-x, end=t;
            while(j<logs.size() && logs[j][1]<=end){
                mp[logs[j][0]]++;
                j++;
            }

            while(i<j && logs[i][1]<start){
                mp[logs[i][0]]--;
                if(mp[logs[i][0]]==0) mp.erase(logs[i][0]);
                i++;
            }
            ans[idx] = n-mp.size();
        }
        return ans;
    }
};