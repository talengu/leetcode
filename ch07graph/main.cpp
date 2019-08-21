#include<iostream>
#include"SparseGraph.h"
#include"DenseGraph.h"
#include"ReadGraph.h"
#include"Component.h"
#include"Path.h"
#include"ShortestPath.h"
using namespace std;
int main(int argc, char *argv[])
{
	string filename="testG1.txt";
	SparseGraph g1(13,false);
	ReadGraph<SparseGraph> readGraph1(g1,filename);
	//g1.show();
	cout<<endl;

	Path<SparseGraph> dfs(g1,0);
	cout<<"DFS: ";
	dfs.showPath(6);

	ShortestPath<SparseGraph> bfs(g1,0);
	cout<<"BFS: ";
	bfs.showPath(6);


	return 0;
}
