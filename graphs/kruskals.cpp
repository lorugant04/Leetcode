/* min cost to connect all points
*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

*The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

* Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
* Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
* Output: 20
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

class UnionFind
{
    public:
    vector<int> root;
    vector<int> rank;
    UnionFind(int sz) : root(sz)
    {
        rank = vector<int>(sz);

        for(int i=0; i<sz; i++)
        {
            root[i] = i;
        }
    }

    int find(int x)
    {
        while(x != root[x])
        {
            x = root[x];
        }

        return x;
    }

    void unionset(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);

        if(find(rootx) != find(rooty))
        {
            if(rank[rootx] > rank[rooty])
            {
                root[rooty] = rootx;
            }
            else if(rank[rootx] < rank[rooty])
            {
                root[rootx] = rooty;
            }
            else
            {
                root[rootx] = rooty;
                rank[rooty] += 1;
            }
        }
    }
};

int manhattan(int xi,int yi, int xj, int yj)
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
                int weight = manhattan(points[i][0], points[i][1], points[j][0], points[j][1]);
                edges.push_back({weight, {i,j}});
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
        int node1 = edges[i].second.first;
        int node2 = edges[i].second.second;
        if(uf.find(node1) != uf.find(node2))
        {
            uf.unionset(node1,node2);
            min_cost += w;
            edges_count++;
        }
    }

    return min_cost;
}

int main(int argc, char* argv[])
{
    vector<vector<int>> pt = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << minCostConnectPoints(pt) << endl;
    return 0;
}