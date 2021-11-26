#include<iostream>
#include<vector>
using namespace std;

/*
    Demo graph

    0-----3
    |\   /|
    | \ / |
    |  4  |
    | / \ |
    |/   \|
    1-----2
*/
vector<int>adj[5];
bool visited[5];

void addEdge(vector<int>adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}

//Iteration
/*
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
    cout<<src<<"->";
	for(int i=0 ;i<adj[src].size(); i++){
		if(!visited[adj[src][i]]){
			DFS(adj[src][i]);
		}
	}
}

void printList(vector<int>adj[], int V){
    for(int i=0;i<V;i++){
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
	addEdge(adj,0,1);
    addEdge(adj,1,4);
    addEdge(adj,0,4);
    addEdge(adj,0,3);
    addEdge(adj,1,2);
    addEdge(adj,4,3);
    addEdge(adj,4,2);
    addEdge(adj,3,2);
	
	//cout<<adj.size()<<endl;
	DFS(0);
    cout<<"List check"<<endl;

    printList(adj,5);


	return 0;
}