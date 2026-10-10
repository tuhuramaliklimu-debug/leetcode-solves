class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalDiff = 0;
        int maxDiff = 0;
        vector<int> diffs(n);
        for (int i = 0; i < n; i++) {
            diffs[i] = abs(nums1[i] - nums2[i]);
            totalDiff += diffs[i];
            maxDiff = max(maxDiff, diffs[i]);
        }
        long long k = (long long)k1 + k2;
        if (k >= totalDiff) return 0;
        vector<int> counts(maxDiff + 1, 0);
        for (int d : diffs) counts[d]++;
        for (int i = maxDiff; i > 0 && k > 0; i--) {
            if (counts[i] == 0) continue;
            long long reduce = min((long long)counts[i], k);
            counts[i] -= reduce;
            counts[i - 1] += reduce;
            k -= reduce;
        }
        long long ans = 0;
        for (long long i = 0; i <= maxDiff; i++) {
            if (counts[i] > 0) ans += counts[i] * i * i;
        }
        return ans;
    }
};