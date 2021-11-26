#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<vector<int>> adj, int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}

void DFS(vector<vector<int>>adj, vector<bool>visited, int src){
	visited[src] = true;
	cout<<src<<"->";
	for(int i=0;i<adj[src].size();i++){
		int temp = adj[src][i];
		if(!visited[temp]){
			DFS(adj,visited,temp);
		}
	}
}

int main()
{
	int V = 5;
	vector<vector<int>>adj(0,vector<int>(V));
	vector<bool>visited(false,V);

	addEdge(adj,0,1);
	addEdge(adj,0,2);
	addEdge(adj,0,3);
	addEdge(adj,1,2);
	addEdge(adj,3,2);
	addEdge(adj,2,4);
	addEdge(adj,3,4);

	for(int i=0;i<adj.size();i++){
		for(int j=0;j<adj[i].size();j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<visited.size();i++){
		cout<<visited[i]<<" ";
	}
	//DFS(adj,visited,0);


	return 0;
}