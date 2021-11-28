#include <iostream>
#include <vector>
using namespace std;

void initialize(vector<vector<int>>&graph){
	for(int i=0;i<graph.size();i++){
		for(int j=0;j<graph[i].size();j++){
			graph[i][j] = -1;
		}
	}
}

bool isSafe(int x, int y, vector<vector<int>>&solve){
	if(x>=0 && x<8 && y>=0 && y<8 && solve[x][y]==-1 ){
		return true;
	}
	return false;
}

int backtrack(int x, int y, int move, vector<vector<int>>&solve, vector<int>&xMove, vector<int>&yMove){
	int next_x, next_y;
	if(move == 64){
		return 1;
	}

	for(int i=0;i<(int)solve.size();i++){
		next_x = x + xMove[i];
		next_y = y + yMove[i];
		if(isSafe(next_x,next_y,solve)){
			solve[next_x][next_y] = move;
			if(backtrack(next_x,next_y,move+1,solve,xMove,yMove)==1){
				return 1;
			}
			else{
				solve[next_x][next_y] = -1;
			}
		}
	}

	return 0;
}

void printGraph(vector<vector<int>>&graph){
	for(int i=0;i<graph.size();i++){
		for(int j=0;j<graph.size();j++){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	vector<vector<int>>solve(8,vector<int>(8));
	initialize(solve);

	vector<int>xMove={1,2,2,1,-1,-2,-2,-1};
	vector<int>yMove={-2,-1,1,2,2,1,-1,-2};

	if(backtrack(0,0,1,solve,xMove,yMove) == 0){
		cout<<"GG"<<endl;
	}
	solve[0][0]=0;
	printGraph(solve);
	return 0;
}