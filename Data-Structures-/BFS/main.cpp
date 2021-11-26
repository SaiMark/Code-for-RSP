#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addEdges(vector<vector<int>>&nums, int s, int d){
	nums[s].push_back(d);
	nums[d].push_back(s);
}

void BFS(vector<vector<int>>&nums, vector<bool>&visited ,int start){
	queue<int>next;
	next.push(start);

	visited[start]=true;
	while(!next.empty()){
		int temp = next.front();
		next.pop();
		for(int i=0 ; i<nums[temp].size() ; i++){
			if(!visited[nums[temp][i]]){
				next.push(nums[temp][i]);
				visited[nums[temp][i]]=true;
			}
		}
		cout << temp << " ";
	}

}

int main()
{
	int V = 6;
	vector<vector<int>>nums(V);
	vector<bool>visited(V,false);

	addEdges(nums,0,1);
	addEdges(nums,0,2);
	addEdges(nums,0,3);
	addEdges(nums,2,4);
	addEdges(nums,2,5);
	addEdges(nums,3,5);

	BFS(nums,visited,0);

	return 0;
}