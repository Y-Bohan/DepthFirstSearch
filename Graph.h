#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class Graph
{
public:
	Graph(int N);		//��ʼ������һ������N�����㵫�������ߵ�ͼ
	Graph(const Graph& G);		//˽�г�Ա�����ж��Ͽ��ٵ��ڴ棬��Ҫ�������캯��������=�������
	Graph& operator=(const Graph& G);
	int getVertex();	//��ȡͼ�ж��������
	int getEdge();		//��ȡͼ�бߵ�����
	void addEdge(int v, int w);			//��ͼ�м���һ�����Ӷ���v�Ͷ���w�ı�
	vector<int> getAdj(int v);			//��ȡ���Ӷ���v�����ж���
	bool connected(int v, int w);	//�ж϶���v�Ͷ���w֮���Ƿ��Ѿ��бߴ���
	~Graph();
private:
	int vertexCount;		//�������
	int edgeCount;		//�߸���
	vector<int>* adj;	//�洢ͼ�ṹ���ڽӱ�
};

Graph::Graph(int N)
{
	vertexCount = N;
	edgeCount = 0;
	adj = new vector<int>[N];
}

Graph::Graph(const Graph& G)
{
	vertexCount = G.vertexCount;
	edgeCount = G.edgeCount;
	adj = new vector<int>[vertexCount];
	for (int i = 0; i < vertexCount; i++)
		for (vector<int>::iterator it = G.adj[i].begin(); it != G.adj[i].end(); it++)
			adj[i].push_back(*it);
}

Graph& Graph::operator=(const Graph& G)
{
	vertexCount = G.vertexCount;
	edgeCount = G.edgeCount;
	adj = new vector<int>[vertexCount];
	for (int i = 0; i < vertexCount; i++)
		for (vector<int>::iterator it = G.adj[i].begin(); it != G.adj[i].end(); it++)
			adj[i].push_back(*it);
	return *this;
}

int Graph::getVertex()
{
	return vertexCount;
}

int Graph::getEdge()
{
	return edgeCount;
}

void Graph::addEdge(int v, int w)		//��������ͼ��˫��ģ�������ӱ�ʱ��Ҫͬʱ��ӵ�v���ڽӱ��w���ڽӱ�
{
	if (!connected(v, w))
	{
		adj[v].push_back(w);
		adj[w].push_back(v);
		edgeCount++;		//������Ҫ���Ǳߵ�������1
	}
}

vector<int> Graph::getAdj(int v)
{
	return adj[v];
}

bool Graph::connected(int v, int w)
{
	for (vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++)
	{
		if (*it == w)		//˵��v���ڽӱ�����w������֮���б�
			return true;
	}
	return false;		//������v���ڽӱ�û��w��˵������֮���ޱ�
}

Graph::~Graph()
{
	if (adj != NULL)
	{
		delete[] adj;
		adj = NULL;
	}
}
#endif 








