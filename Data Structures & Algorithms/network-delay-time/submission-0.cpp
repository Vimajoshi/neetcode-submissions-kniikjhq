class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& time : times) {
            int u = time[0];
            int v = time[1];
            int t = time[2];
            adj[u].push_back({v, t}); 
        }

        // Step 2: Initialize a min-heap priority queue
        // Stores pairs of {current_distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Step 3: Initialize distance array with infinity
        vector<int> dist(n + 1, INT_MAX);
        
        // Start from node k
        dist[k] = 0;
        pq.push({0, k});
        
        // Step 4: Process nodes using Dijkstra's Algorithm
        while (!pq.empty()) {
            auto [curr_time, u] = pq.top();
            pq.pop();
            
            // Optimization: If we've already found a strictly shorter path to 'u', 
            // skip processing this outdated entry in the priority queue.
            if (curr_time > dist[u]) continue;
            
            // Traverse all neighbors of node 'u'
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int travel_time = edge.second;
                
                // Relaxation step: If we find a shorter path to 'v', update it
                if (dist[u] + travel_time < dist[v]) {
                    dist[v] = dist[u] + travel_time;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // Step 5: Find the maximum time needed for all nodes to receive the signal
        int max_time = 0;
        for (int i = 1; i <= n; ++i) {
            // If any node's distance is still INT_MAX, it's unreachable
            if (dist[i] == INT_MAX) {
                return -1; 
            }
            max_time = max(max_time, dist[i]);
        }
        
        return max_time;
    }
};
