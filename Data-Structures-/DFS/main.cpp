#include<iostream>
#include<vector>
using namespace std;

vector<int>adj[5];
bool visited[5];

void addEdge(vector<int>adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}

// void dfs_r(int s){
//     visited[s] = true; //Mark first node as visited
//     cout << s << " ";
//     for(int i = 0; i < vec[s].size(); i++){ //Vector of adjency nodes
//         if(visited[vec[s][i]] == false) dfs_r(vec[s][i]); //If not visited, recurse it
//     }
// }
/*
//Iteration
void dfs(const vector<vector<int>> &vec, int s){
    stack<int> stk;
    stk.push(s); //Push start node
    visited[s] = true; //Mark start node
    while(!stk.empty()){ //When stack not empty
        int node = stk.top(); //Get top
        stk.pop(); //Pop top
        cout << node << " ";
        for(int i = 0; i < vec[node].size(); ++i){ //Vector of adjency nodes
            if(!visited[vec[node][i]]){ //If adjency node is not visited
                stk.push(vec[node][i]); //Push this node into stack
                visited[vec[node][i]] = true; //Mark as visited
            }
        }
    }
}*/
 void initialize() {
    for(int i = 0;i < 10;++i){
        visited[i] = false;
    }
}

void DFS(int src){
	visited[src] = true;
	for(int i=0 ;i<adj[src].size(); i++){
		if(!visited[adj[src][i]]){
            cout<<adj[src][i]<<"->";
			DFS(adj[src][i]);
		}
	}
}

int main()
{
	addEdge(adj,0,1);
	addEdge(adj,0,3);
	addEdge(adj,0,2);
	addEdge(adj,1,2);
	addEdge(adj,3,2);
	addEdge(adj,2,4);
	addEdge(adj,3,4);
	//cout<<adj.size()<<endl;
	for(int i=0;i<5;i++){
		if(!visited[i]){
			DFS(i);
		}
	}


	return 0;
}