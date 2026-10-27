class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>a;
        for(int i=0;i<m-1;i++)
            a.push_back("."+string(n-1,'#'));
        a.push_back(string(n,'.'));
        return a;

    }
};