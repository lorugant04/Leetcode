/*
 points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind
{
    private:
    vector<int> root;
    vector<int> rank;

    public:
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

    void unionset(int x , int y)
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

int manhattan(int xi, int yi, int xj, int yj)
{
    int x = abs(xi-xj);
    int y = abs(yi-yj);

    return abs(x+y);
}

 int minCostConnectPoints(vector<vector<int>>& points) {

   vector<pair<int, pair<int,int>>> edges;

    for(int i=0; i<points.size(); i++)
    {
        for(int j=0; j<points.size(); j++)
        {
            if(i != j)
            {
                int w = manhattan(points[i][0], points[i][1], points[j][0], points[j][1]);
                edges.push_back({w,{i,j}});
            }
        }
    }

    sort(edges.begin(), edges.end());

    UnionFind uf(points.size());
    int min_cost = 0;
    int edges_count = 0;


    for(int i=0; i<edges.size(), edges_count < points.size()-1; i++)
    {
        int w = edges[i].first;
        int v1 = edges[i].second.first;
        int v2 = edges[i].second.second;

        if(uf.find(v1) != uf.find(v2))
        {
            uf.unionset(v1,v2);
            edges_count++;
            min_cost += w;
        }
    }

    return min_cost;
 }

int main(int argc,char* argv[])
{
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << minCostConnectPoints(points) << endl;
    return 0;
}