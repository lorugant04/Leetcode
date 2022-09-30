/*
* n = 3
* src = 0
* [[0,1,1],[1,0,1],[1,1,0]]
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool validpath(int n, vector<vector<int>>& adjmat, int src, int dst)
{
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int vertex = q.front();
        q.pop();

        if(vertex == dst)
        {
            return true;
        }
        
        visited[vertex] = true;

        for(int i=0; i<adjmat[vertex].size(); i++)
        {
            if(visited[adjmat[vertex][i]] == false && adjmat[vertex][i] > 0)
            {
                q.push(i);
            }
        }

    }
    return false;
}

int main(int argc,char* argv[])
{
    int n = 3;
    int src = 0;
    int dst = 2;   
    vector<vector<int>> adjmat = {{0,1,1},{1,0,1},{1,1,0}};
    cout << validpath(n,adjmat,src,dst) << endl; 
    n = 6;
    adjmat = {{0,1,1,0,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{0,0,0,0,1,1},{0,0,0,1,0,1},{0,0,0,1,1,0}};
    src = 0;
    dst = 5;
    cout << validpath(n,adjmat,src,dst) << endl;
    return 0;
}