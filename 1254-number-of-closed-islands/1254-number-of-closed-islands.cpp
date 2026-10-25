class Solution {
    int m,n;
    bool closed(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=m || j<0 || j>=n)return false;
        if(grid[i][j]==1)return true;
        grid[i][j]=1;
        //bitwise & ensure all 4 calls execute
        return closed(grid,i+1,j) & closed(grid,i-1,j) &  closed(grid,i,j+1) & closed(grid,i,j-1);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
       m=grid.size();
       n=grid[0].size();
       int cnt=0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0 && closed(grid,i,j)){
                cnt++;
            }
        }
       } 
       return  cnt;
    }
};