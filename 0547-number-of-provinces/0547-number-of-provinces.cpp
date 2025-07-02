class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<bool>&vis,int node)
    {
        vis[node]=true;
        for(int j=0;j<isConnected.size();j++)
        {
            if(!vis[j]&& isConnected[node][j]==1){
                dfs(isConnected,vis,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n,false);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(isConnected,vis,i);
                count++;
            }
        }
        return count;
    }
};