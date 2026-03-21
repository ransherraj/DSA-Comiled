/***


Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

Example 1:


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Example 2:


Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 

Constraints:

n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i (i.e., there will be no self-loops).
All the elements of graph[i] are unique.
The input graph is guaranteed to be a DAG.


****/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int> &path, int source){

        path.push_back(source);

        if(source == graph.size()-1){
            paths.push_back(path);
        }
        else{
            for(auto x : graph[source]){
                dfs(graph, paths, path, x);
            }
        }

        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<vector<int>> paths;
        vector<int> path;

        dfs(graph, paths, path, 0);

        return paths;
    }
 
};

int main() {

    int n;
    cin >> n;

    vector<vector<int>> graph(n);

    cin.ignore();  

    for(int i=0;i<n;i++){

        string line;
        getline(cin,line);

        stringstream ss(line);

        int x;

        while(ss>>x)
            graph[i].push_back(x);
    }

    Solution Sol;

    vector<vector<int>> ans = Sol.allPathsSourceTarget(graph);

    for(int i=0;i<ans.size();i++){

        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";

        cout<<endl;
    }
}
