/*
*Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
*[[0,1],[0,2],[3,5],[5,4],[4,3]]
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool validpath(int n, vector<vector<int>>& edges, int source, int destination)
{
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(source);

    map<int,vector<int>> mp;

    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();
        if(vertex == destination)
        {
            return true;
        }

        vector<int> vec = mp[vertex];
        visited[vertex] = true;

        for(int v=0; v<vec.size(); v++)
        {
            if(visited[vec[v]] == false)
            {
                q.push(vec[v]);
            }
        }
    }
    return false;
}

int main(int argc,char* argv[])
{
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    int source = 0;
    int destination = 2;
    cout << validpath(n, edges,source, destination) << endl;
    n = 6;
    edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    source = 0;
    destination = 5;
    cout << validpath(n,edges,source,destination) << endl;
    return 0;
}