class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
     int n=arr.size(),total=0,left=0, ans=n+1;
     vector<int>dp(n+1,n);
     for(int right=0;right<n;right++){
        total+=arr[right];
        while(total >target)total-=arr[left++];
        dp[right+1]=dp[right];
        if(total==target){
            ans=min(ans,right -left+1+dp[left]);
            dp[right+1]=min(dp[right+1],right-left+1);

        }
     }   
     return ans==n+1?-1:ans;
    }
};