//solved using map : by checking frequency
//
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int>pro(n+1,0);
        int missing =0,duplicate=0;

        for(int i=0;i<n;i++){
            pro[nums[i]]++;
        }

        for(int i=1;i<pro.size();i++)
        {
            if(pro[i]==2)duplicate=i;
            if(pro[i]==0)missing=i;

        }
        return {duplicate,missing};
    }
};