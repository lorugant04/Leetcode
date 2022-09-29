/*
*Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
*[[0,1],[0,2],[3,5],[5,4],[4,3]]
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool dfs(int n, map<int,vector<int>>& mp, int src, int dst, vector<bool>& visited, int vertex)
{
    if(visited[vertex] == 1)
    {
        return false;
    }

    cout << vertex << endl;

    if(vertex == dst)
    {
        return true;
    }

    visited[vertex] = 1;
    vector<int> vec = mp[vertex];
    for(int i=0; i<vec.size(); i++)
    {
        if(visited[vec[i]] == 0)
        {
            if(dfs(n,mp,src,dst,visited,vec[i]))
            {
                return true;
            }
        }
    }

    return false;
}

bool validpath(int n, vector<vector<int>>& edges, int src, int dst)
{
    vector<bool> visited(n,false);
    map<int,vector<int>> mp;
    int vertex = src;

    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    return dfs(n,mp,src,dst,visited,vertex);
}

int main(int argc,char* argv[])
{
    int n = 3;
    int src = 0;
    int dst = 2;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    cout << "=====" << endl;
    cout << validpath(n,edges,src,dst) << endl;
    n= 6;
    src = 0;
    dst = 5;
    edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    cout << "=====" << endl;
    cout << validpath(n,edges,src,dst) << endl;
    return 0;
}