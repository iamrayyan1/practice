// traversal means visiting all nodes

// BFS traversal
// DFS traversal

/*
BFS:
    Covid virus
- jo jo contact mei aa rahe unko lage ga

- first step is to select starting point(starting node) - kahi se bhi start ker sakte unless question mei mention hou
- jo node visit kiya hai, uske saare adjacent nodes ko visit ker le ge
- jis jis adjacent node ko visit kerte jai ge unko queue mei add kere ge
- jab koi aur adjacent node nahi bacha toh jo queue mei elements hai unko ek ek kerke bahir nikale ge aur unke adj nodes jo unvisted hai unko visit kere ge
- phir next node pae jai ge aur jo adjacent nodes unvisited hai usko visit kere ge

- repeat process jab tak queue empty nahi hojati

- Required:
    QUEUE
    VISITED bool array

- Steps:
    1. Pop a node from queue and put it in ans
    2. Node will look into its unvisited neighbour and push them into queue and marks them as visited

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> BFSGraph(int v, vector<int> adj[])
{ // adj list given
    queue<int> q;
    vector<bool> visited(v, 0);

    q.push(0);
    visited[0] = 1;

    vector<int> ans;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!visited[adj[node][j]])
            {
                visited[adj[node][j]] = 1;
                q.push(adj[node][j]);
            }
        }
    }
}

// SC: O(v)  no of vertex
// TC: O(V+E)

// real life example: searching
// LEVELS

/*
DFS: - depth tak jao - travelling
    kahi se bhi start kerlo
    ek path lou aur usko explore kerte jao jab tak woh khatam nahi hou
    agar khatam hojai yah saari unvisited options khatam hojai phir wapis jaate raho

    Solve using recursion

    1. It will visit its all unvisited neighbour one by one
    2. agar usne saare neighbour explore kerliye then it will backtrack to where it was called
*/

void DFS(int node, vector<int> adj[], vector<bool> &visited, vector<int> &ans)
{
    visited[node] = 1;
    ans.push_back(node);

    for (int j = 0; j < adj[node].size(); j++)
    {
        if (!visited[adj[node][j]])
        {
            DFS(adj[node][j], adj, visited, ans);
        }
    }
}

vector<int> dfsHelper(int v, vector<int> adj[])
{
    vector<bool> visited(v, 0);
    vector<int> ans;
    DFS(0, adj, visited, ans);

    return ans;
}

// TC: O(V+E)
// SC: O(V)
