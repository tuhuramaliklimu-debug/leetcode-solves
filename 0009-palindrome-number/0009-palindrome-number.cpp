class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
            return false;
        long reverse=0;
        int xcopy=x;
        
        while(x>0){
            int num=x%10;
            reverse=reverse*10+num;
            x=x/10;
        }
        return reverse==xcopy;
        
    }
};