#include <iostream>
#include "DepthFirstSearch.h"
#include "Graph.h"
#include <fstream>
using namespace std;
int main()
{
	Graph G(9);
	fstream ifs;
	ifs.open("Graph.txt");		//Graph.txt�ļ���ŵ��ǲ���ͼ�ı�
	int v, w;
	while (!ifs.eof())		//������ͼ�ı߼��뵽g�У����ڽӱ����洢
	{
		ifs >> v >> w;
		G.addEdge(v, w);
	}

	DepthFirstSearch DFS(G, 3);
	ifs.close();
	return 0;
}