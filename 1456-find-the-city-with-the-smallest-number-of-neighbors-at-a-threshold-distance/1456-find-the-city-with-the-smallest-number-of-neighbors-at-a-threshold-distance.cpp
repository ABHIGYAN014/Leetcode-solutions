class Solution {
public:
    const int INF = 1e9; 

    vector<vector<int>> matrix(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dist(n, vector<int>(n, INF));
        
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (auto edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        return dist;
    }

    void floydd(int n, vector<vector<int>>& dist) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist = matrix(n, edges);
        floydd(n, dist);

        int minCity = -1;
        int minReachable = n + 1;

        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold)
                    count++;
            }
            if (count <= minReachable) {
                minReachable = count;
                minCity = i;
            }
        }

        return minCity;
    }
};
