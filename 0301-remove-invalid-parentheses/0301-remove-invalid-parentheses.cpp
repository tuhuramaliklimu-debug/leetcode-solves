class Solution {
private:
    vector<string>res;
public:
    vector<string> removeInvalidParentheses(string s) {
        helper(s,0,0,{'(',')'});
        return res;
    }

    void helper(string s,int l,int r,const vector<char>&para){
        int len=s.length();
        int counter=0;

        while(r<len){
            char ch=s[r];
            if(ch==para[0]){
                counter++;
            }else if(ch==para[1])counter--;
            
            if(counter<0)break;
            r++;
        }
        if(counter<0){
            
            while(l<=r){
                char ch=s[l];
                if(ch!=para[1]|| (l>0 && s[l]==s[l-1])){
                    l++;
                    continue;
                }
                s.erase(l,1);
                helper(s,l,r,para);
                s.insert(s.begin()+l,para[1]);
                l++;
            }
        }

        else if(counter>0){
            reverse(s.begin(),s.end());
            helper(s,0,0,{')','('});
        }
        else{
            res.push_back(para[0]=='(' 
            ? s 
            : string (s.rbegin(),s.rend())
            );
        }

    }
};