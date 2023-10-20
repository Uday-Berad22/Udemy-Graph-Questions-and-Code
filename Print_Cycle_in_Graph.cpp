// Find Cycle in Both Directed and Undirected Graph using BackEdges and ancestor proerties
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<int> graph[N];
int vis[N];
bool cycle = false;
// vis[node]=0;  node is not visited

// vis[node]=1;  node is visited and is in stack

// vis[node]=2;  node is visited and is not in stack

// Storing Parent of each node
int parent[N];

void dfs(int node, int par)
{
    vis[node] = 1;
    parent[node] = par;
    for (auto &nbr : graph[node])
    {
        if (vis[nbr] == 0)
        {
            dfs(nbr, node);
        }
        else if (vis[nbr] == 1 && par != nbr)
        {
            cycle = true;
            int curr = node;
            int destination = nbr;
            while (curr != destination)
            {
                cout << curr << " -> ";
                curr = parent[curr];
            }
            cout << destination << endl;
            exit(0);
        }
    }
    vis[node] = 2;
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    { // For Undirected Graph
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // for(int i=0;i<m;i++){// For directed Graph
    //     int u,v;
    //     cin>>u>>v;
    //     graph[u].push_back(v);
    // }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i, -1);
    }
    if (cycle)
    {
        cout << "Cycle is present" << endl;
    }
    return 0;
}
