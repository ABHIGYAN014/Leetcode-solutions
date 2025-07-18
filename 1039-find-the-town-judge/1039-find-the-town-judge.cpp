class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> indegree;
        unordered_map<int,int> outdegree;

        if(trust.empty() && n == 1 ) return 1;
        for(auto it : trust)
        {
            int u = it[0];
            int v = it[1];

            indegree[v]++;
            outdegree[u]++;
        }
        for(auto it : indegree){
            if(it.second == n-1 && outdegree[it.first] == 0) return it.first;
        }
        return -1;
    }
};