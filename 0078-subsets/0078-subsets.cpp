class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>cur;
        vector<vector<int>>all;

        generate(0,nums,cur,all);
        return all;
    }
    void generate(int idx,vector<int>& nums,vector<int>& cur,vector<vector<int>>& all)
    {
        if(idx==nums.size()){
            all.push_back(cur);
            return ;
        }
        cur.push_back(nums[idx]);
        generate(idx+1,nums,cur,all);
        cur.pop_back();
        generate(idx+1,nums,cur,all);

    }
};