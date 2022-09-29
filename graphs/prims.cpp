#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
    public:
    vector<int> root;
    vector<int> rank;

    UnionFind(int sz):root(sz)
    {
        rank = vector<int>(sz);
        for(int i=0; i<sz; i++)
        {
            root[i] = i;
        }
    }

    int find(int x)
    {
        while( x != root[x])
        {
            x = root[x];
        }

        return x;
    }

    void unionset(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);

        if(rootx != rooty)
        {
            if(rank[rootx] < rank[rooty])
            {
                root[rootx] = rooty;
            }
            else if(rank[rootx] > rank[rooty])
            {
                root[rooty] = rootx;
            }
            else{
                root[rootx] = rooty;
                rank[rooty] += 1;
            }
        }
    }
};

int min_dist(vector<int>& visited, vector<int>& distance)
{
    int minimum = INT_MAX;
    int vertex;

    for(int i=0; i<distance.size(); i++)
    {
        if(visited[i] != 1 && distance[i] <= minimum)
        {
            minimum = distance[i];
            vertex = i;
        }
    }
    return vertex;
}

int prim(vector<vector<int>>& adjmat, int n)
{
    int min_cost = 0;
    vector<int> visited(n,0);
    vector<int> distance(n,INT_MAX);

    int src = 0;
    distance[src] = 0;

    for(int i=0; i<n-1; i++)
    {
        int u = min_dist(visited, distance);
        visited[u] = 1;

        for(int v=0; v<n; v++)
        {
            if(visited[v] != 1 && distance[u] != INT_MAX && adjmat[u][v] > 0 && distance[v] > (adjmat[u][v]))
            {
                distance[v] = adjmat[u][v];
            }
        }
    }

    for(auto d : distance)
    {
        min_cost += d;
    }
    return min_cost;
}

int manhattan(int xi, int yi, int xj, int yj)
{
    int x = abs(xi-xj);
    int y = abs(yi-yj);

    return abs(x+y);
}

int minCostConnectPoints(vector<vector<int>>& points) {

   int n = points.size();
   vector<pair<int, pair<int,int>>> edges;
   vector<vector<int>> adjmat(points.size(),vector<int> (points.size(),0));

   for(int i=0; i<points.size(); i++)
   {
      for(int j=0; j<points.size(); j++)
      {
        if(i != j)
        {
            int w = manhattan(points[i][0], points[i][1], points[j][0], points[j][1]);
            edges.push_back({w, {i,j}});
        }
      }
   }

   for(int i=0; i<edges.size(); i++)
   {
      int w = edges[i].first;
      int v1 = edges[i].second.first;
      int v2 = edges[i].second.second;

      adjmat[v1][v2] = w;
      adjmat[v2][v1]= w;
   }

   /*for(int i=0; i<adjmat.size(); i++)
   {
    for(int j=0; j<adjmat[i].size(); j++)
    {
        cout << adjmat[i][j] << " ";
    }
    cout << endl;
   }*/

   return prim(adjmat,n);
}

int main(int argc, char* argv[])
{
    vector<vector<int>> pt = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << minCostConnectPoints(pt) << endl;
    return 0;
}