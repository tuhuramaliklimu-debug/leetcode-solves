class Solution {
public:

    int getDigitSum(int num){
        int sum=0;
        while(num>0){
            sum+=(num%10);
            num=num/10;
        }
        return sum;
    }


    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int>afterSorted(nums);

        auto lambda=[&](int num1,int num2){
            int num1ds=getDigitSum(num1);
            int num2ds=getDigitSum(num2);
            if(num1ds!=num2ds){
                return num1ds<num2ds;
            }
            return num1<num2;
        };

        sort(begin(afterSorted),end(afterSorted),lambda);

        unordered_map<int ,int>valToIdx;
        for(int i=0;i<n;i++){
            valToIdx[nums[i]]=i;
        }

        int swapcnt=0;
        for(int i=0;i<n;i++){
            int expected=afterSorted[i];
            int currVal=nums[i];

            if(expected==currVal)continue;

            int idx= valToIdx[expected];
            nums[i]=expected;
            nums[idx]=currVal;

            valToIdx[expected]=i;
            valToIdx[currVal]=idx;
            
            swapcnt++;

        }
        return swapcnt;
    }
};