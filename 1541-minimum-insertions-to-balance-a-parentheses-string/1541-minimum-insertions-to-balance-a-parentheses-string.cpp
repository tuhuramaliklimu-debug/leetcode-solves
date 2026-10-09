class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        int ins=0,leftcnt=0,index=0;
        while(index<n){
            if(s[index]=='('){
                leftcnt++;
                index++;
            }else{
                if(leftcnt>0)leftcnt--;
                else ins++;
                if (index<n-1 && s[index+1]==')')index+=2;
                else{ins++;
                index++;}
            }
        }
        ins+=leftcnt*2;
        return ins;
    }
};