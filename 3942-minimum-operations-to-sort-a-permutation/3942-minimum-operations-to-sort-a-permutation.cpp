class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size() ,first=nums[0];
        span ring(nums);

        auto reads=[&](auto head , auto tail){
            return ranges::equal(ring.first(head.size()),head) && ranges::equal(ring.subspan(head.size()),tail);
        };

        if(reads(views::iota(first,n),views::iota(0,first))){
            int shift=(n-first)%n;
            return min(shift,n-shift+2);
        }

        if(reads(views::iota(0,first+1) |views::reverse, views::iota(first+1,n) | views::reverse)){
            int shift=first ;
            return min(shift+2,n-shift);
        }
        return -1;
    }
};