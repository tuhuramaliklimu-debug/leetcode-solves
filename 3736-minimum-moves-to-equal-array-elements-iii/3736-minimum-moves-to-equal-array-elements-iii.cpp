class Solution {
public:
    int minMoves(vector<int>& n) {
        int big=*max_element(n.begin(),n.end());
        int cnt =0;
        for(int i=0;i<n.size();i++){
            cnt+=(big-n[i]);
        }
        return cnt;
    }
};