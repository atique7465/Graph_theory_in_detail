class kahns_topo_sort_cycle_detection {
    // Topological Sort Using Kahn's Algorithm & cycle ditection
    // Considering a directed graph. 
    // where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
    // return true if the graph has any cycle
    // return false if graph has no cycle also print the topo order
    // Time & space complexity: O(m+n) [Here, n be the number of nodes and m be the number of edges in the graph]

public:
    bool hasCycle(int n, vector<vector<int>>& edges) {        
        vector<vector<int>> graph(n, vector<int>());
        vector<int>indegree(n, 0);

        for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) if(indegree[i] == 0) q.push(i);
        
        int nodeSeen = 0; vector<int> topoOrder;
        while(!q.empty()){
            int node = q.front(); q.pop();
            topoOrder.push_back(node);
            nodeSeen++;
    
            for(int next:graph[node]){
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }

        if(nodeSeen == n) for(int u:topoOrder) cout<<"->"<<u;

        return nodeSeen < n ? true : false;
    }
};



class dfs_cycle_detection {

    // n is the number of node
    // edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj

    vector<vector<int>> graph, vector<bool> visited, instack;
    
public:
    int hasCycle(int n, vector<vector<int>>& edges) {        
        visited.resize(n, false); instack.resize(n, false); 
        graph.resize(n, vector<int>());

        for(int i = 0; i < edges.size(); i++) graph[edges[i][0]].push_back(edges[i][1]);
        
        for (int i = 0; i < n; i++) if (!visited[i] && dfs(i)) return true;

        return false;
    }

   bool dfs(int node){
        visited[node] = true; instack[node] = true;

        for(int next:graph[node]){
            if(!visited[next]){
               if(dfs(next)) return true;
            }else if(instack[node]) return true;
        }

        instack[node] = false;
        return false;
    }
};
