//深度优先搜索的思想遇到一个结点既有兄弟结点，又有子结点，则先递归遍历子结点，再递归遍历兄弟结点。
#ifndef DepthFirstSearch_H
#define DepthFirstSearch_H
#include <iostream>
#include "Graph.h"
#include <iterator>
#include <vector>
using namespace std;
class DepthFirstSearch
{
public:
	DepthFirstSearch(Graph G,int s);			//构造函数内自动调用DFS算法
	~DepthFirstSearch();
	void dfs(Graph G,int v);		//深度优先搜索递归函数
	int getCount();		//返回与顶点s相连的所有顶点个数
private:
	bool* marked;		//用来标记顶点是否被访问过，若i已经被访问过，则marked[i]=true;
	int count;			//记录与顶点s相连的所有顶点个数
	vector<int> array;			//存放与顶点s相连的顶点；
};

DepthFirstSearch::DepthFirstSearch(Graph G,int s)
{
	int N = G.getVertex();		//获取图中的顶点数
	marked = new bool[N];
	for (int i = 0; i < N; i++)			//初始每个点标记为未被访问过
		marked[i] = false;
	count = 0;
	dfs(G, s);			//调用DFS算法
}

void DepthFirstSearch::dfs(Graph G, int v)
{
	marked[v] = true;			//顶点v已经访问过，标记为true
	count++;				//和顶点s连通的点数加1
	cout << v << " ";			//打印输出当前顶点
	array.push_back(v);
	vector<int> adj = G.getAdj(v);
	for (vector<int>::iterator it = adj.begin(); it != adj.end(); it++)			//遍历与顶点v相连的所有邻接顶点，如果未被访问过，则依次递归搜索邻接顶点的子结点
	{
		if (!marked[*it])
			dfs(G, *it);
	}
}

int DepthFirstSearch::getCount()
{
	return count;
}

DepthFirstSearch::~DepthFirstSearch()
{
	if (marked != NULL)
	{
		delete[] marked;
		marked = NULL;
	}
}


#endif 


