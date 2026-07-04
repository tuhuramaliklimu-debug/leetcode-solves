class Solution {
public:
    int majorityElement(vector<int>& num) {
        int counter=0;
        int majority=-1;
        int n=num.size();
        
        for(int i=0;i<n;i++)
        {
            if(counter==0)
                majority=num[i];
            
            if(num[i]==majority)
                counter+=1;
            else
                counter-=1;
        }
        return majority;

    }
};