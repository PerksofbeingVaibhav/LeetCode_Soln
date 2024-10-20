#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

// Problem statement
// Given an undirected graph of V vertices and E edges. Your task is to find all the bridges in the given undirected graph.
// A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected (or more precisely,
// increases the number of connected components in the graph).

// Brute Force: Check every edge, remove every edge one by one, then for each edge removed, do DFS of the entire graph,
// and check using DFS whether you're able to iterate over the entire graph or not. If you can, it wasn't a bridge.
// Otherwise, it was. This is obviously a very time consuming approach.

// Modified approach:
// We'll keep track of a few things: Time of discovering a node, lowest time to reach a node, parents of nodes, and visited.

// This is also known as Tarjan's Algorithm.

// TC = O(V + 2E)           [Cuz this is the TC of simple DFS traversal, and that's what we're doing in Tarjan's algo as well].
// SC = O(V + 2E) + O(2V)   [linear]   [V+2E for adj list, 2V for the 2 vectors, i.e. discovery, and low].
void dfs(int &node, int &timer, unordered_map<int, list<int>> &adj, vector<int> &disc, vector<int> &low, int &parent, vector<vector<int>> &ans){

    disc[node] = low[node] = timer++;           // The first time we find a node, we'll initialise its discovery time as well as
                                // the lowest time for that node as the current value of timer. Increment the value of timer.
    for(auto nbr : adj[node]){      // For doing dfs traversal.
        if(nbr == parent){      // If the neighbor is the parent of current node, we don't want to do anything.
            continue;
        }
        if(disc[nbr] == -1){        // This can basically work as if( !visited[node] ), it means we have encountered a non-visited
            dfs(nbr, timer, adj, disc, low, node, ans);     // node. We have to do dfs further in this case.
            low[node] = min(low[node], low[nbr]);       // While returning from the dfs, make sure to update the low[node].
                            // low is greedy, it will take the min value wherever possible.
            if(disc[node] < low[nbr]){      // This is the bridge condition: If discovery time of node is less than lowest
                ans.push_back({node, nbr});     // time for the neighbor, it means, if this edge was to be removed, there would
            }               // be no way to reach the neighbor node. Thus, pushing it back in ans as a bridge.
        }
        else{           // If nbr is not the parent, but it is already visited: Greedy low would take the min value from the
            low[node] = min(low[node], low[nbr]);           // low of nbr, and low of node.
        }
    }

}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {

    unordered_map<int, list<int>> adj;

    for(auto it : edges){
        int u = it[0], v = it[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 1;          // To keep track of time.
    vector<int> disc(v, -1);        // To keep track of the first time discovery time for each node.
    vector<int> low(v, -1);         // To keep track of the lowest time to reach each node.
    int parent = -1;            // To keep track of the parent of each node, we'll update it in dfs call itself.

    vector<vector<int>> ans;        // To return the bridges in the end.

    for(int i = 0; i<v; i++){           // This for loop is only so that this code also works for disconnected component graphs.
        if(disc[i] == -1){              // This for loop and visited check (yeah we're using discovery time as visited as well to
            dfs(i, timer, adj, disc, low, parent, ans);     // reduce space) can be removed if the entire graph is a single 
        }                       // component in the beginning, as in leetcode.
    }

    return ans;

}