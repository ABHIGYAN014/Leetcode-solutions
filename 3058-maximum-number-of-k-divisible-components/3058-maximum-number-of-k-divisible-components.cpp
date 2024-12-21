#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int count = 0; // To count K-divisible components
        
        function<long long(int, int)> dfs = [&](int node, int parent) {
            long long subtreeSum = values[node]; // Use long long for subtree sums
            
            for (int neighbor : adj[node]) {
                if (neighbor != parent) { // Avoid revisiting the parent
                    subtreeSum += dfs(neighbor, node);
                }
            }
            
            // If the subtree sum is divisible by k, count it as a component
            if (subtreeSum % k == 0) {
                count++;
                return 0LL; // Returning 0 as this part is now disconnected
            }
            
            return subtreeSum;
        };
        
        dfs(0, -1); // Start DFS from the root (node 0)
        return count;
    }
};
