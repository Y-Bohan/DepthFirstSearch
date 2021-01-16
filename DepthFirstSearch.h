//�������������˼������һ���������ֵܽ�㣬�����ӽ�㣬���ȵݹ�����ӽ�㣬�ٵݹ�����ֵܽ�㡣
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
	DepthFirstSearch(Graph G,int s);			//���캯�����Զ�����DFS�㷨
	~DepthFirstSearch();
	void dfs(Graph G,int v);		//������������ݹ麯��
	int getCount();		//�����붥��s���������ж������
private:
	bool* marked;		//������Ƕ����Ƿ񱻷��ʹ�����i�Ѿ������ʹ�����marked[i]=true;
	int count;			//��¼�붥��s���������ж������
	vector<int> array;			//����붥��s�����Ķ��㣻
};

DepthFirstSearch::DepthFirstSearch(Graph G,int s)
{
	int N = G.getVertex();		//��ȡͼ�еĶ�����
	marked = new bool[N];
	for (int i = 0; i < N; i++)			//��ʼÿ������Ϊδ�����ʹ�
		marked[i] = false;
	count = 0;
	dfs(G, s);			//����DFS�㷨
}

void DepthFirstSearch::dfs(Graph G, int v)
{
	marked[v] = true;			//����v�Ѿ����ʹ������Ϊtrue
	count++;				//�Ͷ���s��ͨ�ĵ�����1
	cout << v << " ";			//��ӡ�����ǰ����
	array.push_back(v);
	vector<int> adj = G.getAdj(v);
	for (vector<int>::iterator it = adj.begin(); it != adj.end(); it++)			//�����붥��v�����������ڽӶ��㣬���δ�����ʹ��������εݹ������ڽӶ�����ӽ��
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


