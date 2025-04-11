class Solution {
public:
    vector<vector<int>>directions={{-1,0},{0,1},{1,0},{0,-1}};
    void solve(vector<vector<char>>& grid,int i,int j, int n,int m)
    {
        
        grid[i][j]='0';

        for(auto dir:directions)
        {
            int i_= i+dir[0];
            int j_=j+dir[1];

            if(i_>=0 && i_<n && j_>=0 && j_<m && grid[i_][j_]=='1')
            {
                solve(grid,i_,j_,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    solve(grid,i,j,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};