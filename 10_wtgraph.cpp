#include <iostream>
#include <string.h>
#include <assert.h>
#include "wtgraph.h"
using namespace std;

WtGraph::WtGraph(int maxNumber)//������
: maxSize(maxNumber),//maxNumber�� maxSize������
size(0)//size�� 0���� �ʱ�ȭ
{
	vertexList = new Vertex[maxSize];//vertex�����ϴ� �迭 �����Ҵ�
	adjMatrix = new int[maxSize*maxSize];//����ġ�� �����ϴ� �迭 �����Ҵ�
	for (int i = 0; i < maxSize; i++)//adj�� �ʱⰪ�� ��������
		adjMatrix[i*i] = infiniteEdgeWt;
	pathMatrix = new int[maxSize*maxSize];//�ִܰŸ��� �����ϴ� �迭 �����Ҵ�
}

WtGraph:: ~WtGraph()//�Ҹ���
{
	delete[] vertexList;
	delete[] adjMatrix;
	delete[] pathMatrix;
}

void WtGraph::insertVertex(Vertex newVertex)
{
	int num;
	num = index(newVertex.label);//vertexlist�� ���� ������ �ֱ� ���Ͽ� index�� �����ؾ� �� �迭������ �ҷ���
	vertexList[num] = newVertex;//vertexlist�� num��°�� ���� �������� �̸��� ����
	if (!full()) {//���� ���� ���� ��쿡
		if (size != 0) {//������� ���� �����̸�
			size++;//����� 1�� ������ ��
			for (int i = 0; i < size; i++)
			{//for���� ���Ͽ� �� ������ �ʱⰪ�� �־��ش�.
				adjMatrix[edge(size - 1, i)] = infiniteEdgeWt;
				adjMatrix[edge(i, (size - 1))] = infiniteEdgeWt;
			}
		}
		else {//empty�� ��쿡
			size++;//size�� 1������Ű��
			adjMatrix[edge(0, 0)] = infiniteEdgeWt;//�ʱ�ȭ���ش�.
		}
	}


}

void WtGraph::insertEdge(char *v1, char *v2, int wt)
{
	int a = index(v1);//v1�� �迭������
	int b = index(v2);//v2�� �迭������ �������� ����

	adjMatrix[edge(a, b)] = wt;//adjMatrix�� �迭�� edge�� �̿��Ͽ� row�� a, col�� b�� ��쿡 ���� wt �־���
	adjMatrix[edge(b, a)] = wt;//row��b, col�� a�� ��쿡�� ���������� (���� ����ġ�� �����ؼ� ���� ����Ǿ��� ����ġ�� �־�� �ϴ� ���ʿ� �־���)
}

int WtGraph::retrieveVertex(char *v, Vertex &vData) const
{
	int num;

	num = index(v);//�˻��ϴ� v�� ������ num�� ����
	if (num < size) {//num�� size���� ������ num�� �����Ѵٴ� �ǹ��̱� ������ (size���� ũ�ų� ������ �迭�� ���� �� ����, size�� 1���Ͱ� �迭�� 0�����̱� ����) 
		vData = vertexList[num];//vdata�� �̸� ����
		return 1;//1�θ���
	}
	else {//num�� size���� ũ�ų� ������ �������� �ʴ°��̴� (size=0�̰� num=0�̴�)
		return 0;//0���� ����
	}

}

int WtGraph::edgeWeight(char *v1, char *v2, int &wt)
{
	int a = index(v1);//v1�� ���� a�� ����
	int b = index(v2);//v2�� ���� b�� ����
	int c = adjMatrix[edge(a, b)];//c�� (a,b)�� 2���� �迭 ��ġ�� ã�� �� ��ġ�� �ִ� ���� c�� ����
	wt = c;//wt�� c�� ����
	if (wt != infiniteEdgeWt)//c�� �ʱⰪ�ΰ�쵵 ������, �ʱⰪ�� �ƴѰ�쿡�� ����ġ�� ����
		return wt;
}

void WtGraph::removeVertex(char *v)
{
	int a = index(v);//a�� v�� ���� ����
	for (int i = a; i < (size - 1); i++) {//��ĭ�� ������ ���ܿͼ� ����
		vertexList[i] = vertexList[i + 1];
	}
	for (int i = a; i < (size - 1); i++) {
		for (int j = 0; j < size; j++)
			adjMatrix[edge(i, j)] = adjMatrix[edge(i + 1, j)];
	}//adjmatrix�� ��ĭ�� ���ܼ� ����
	for (int i = a; i < (size - 1); i++) {
		for (int j = 0; j < size; j++)
			adjMatrix[edge(i, j)] = adjMatrix[edge(i, j + 1)];
	}//adjmatrix�� ��ĭ�� ���ܼ� ����
	size--;//�ϳ��� �������� size�� �ٿ���
}

void WtGraph::removeEdge(char *v1, char *v2)

{
	int a = index(v1);//v1�� ������ a�� ����
	int b = index(v2);//v2�� ������ b�� ����

	adjMatrix[edge(a, b)] = infiniteEdgeWt;//���� row�� a col�� b�ΰ�쿡 �ʱⰪ�� ����
	adjMatrix[edge(b, a)] = infiniteEdgeWt;//���� row�� b col�� a�ΰ�쿡 �ʱⰪ�� ����
}

void WtGraph::clear()
{
	size = 0;//size�� 0�ָ� clear��
}

int WtGraph::empty() const
{
	if (size == 0)//size�� 0�̸� ����ִ°��̴� 1�� �������ش�
		return 1;
	else return 0;//size�� 0�̾ƴϸ� 0�� ����
}

int WtGraph::full() const
{
	if (size == maxSize)//size�� maxsize��ŭ á���� ��á���� 1�� ����
		return 1;
	else return 0;//size�� maxsize�� �ƴϸ� 0�� �������ش�.
}

void WtGraph::showStructure()
// Outputs a graph's vertex list, adjacency matrix, and path matrix.
// This operation is intended for testing/debugging purposes only.

{
	int wt,         // Edge weight
		row, col;   // Loop counters

	if (size == 0)
		cout << "Empty graph" << endl;
	else
	{
		cout << endl << "Vertex list : " << endl;
		for (row = 0; row < size; row++)
			cout << row << '\t' << vertexList[row].label << endl;

		cout << endl << "Edge matrix : " << endl << '\t';
		for (col = 0; col < size; col++)
			cout << col << '\t';
		cout << endl;
		for (row = 0; row < size; row++)
		{
			cout << row << '\t';
			for (col = 0; col < size; col++)
			{
				wt = adjMatrix[edge(row, col)];
				if (wt == infiniteEdgeWt)
					cout << "- \t";
				else
					cout << wt << '\t';
			}
			cout << endl;
		}

		cout << endl << "Path matrix : " << endl << '\t';
		for (col = 0; col < size; col++)
			cout << col << '\t';
		cout << endl;
		for (row = 0; row < size; row++)
		{
			cout << row << '\t';
			for (col = 0; col < size; col++)
			{
				wt = pathMatrix[edge(row, col)];
				if (wt == infiniteEdgeWt)
					cout << "- \t";
				else
					cout << wt << '\t';
			}
			cout << endl;
		}
	}
}

int WtGraph::index(char *v) const
{	//���� �̸��� ������ vertexlist�� �迭 ������ �����ϰ� �ϴ� �Լ�
	int sizeup;
	if (size == 0)//size�� 0�̸�
		sizeup = 0;//sizeup�� 0
	else {//size�� 0�� �ƴҶ�
		sizeup = 0;
		for (int i = 0; i < size && strcmp(vertexList[sizeup].label, v) != 0; i++)//for���� ���� v�� ���� �迭�� ������ �����ϰ� ��
			sizeup++;
	}
	return sizeup;
}

int& WtGraph::edge(int row, int col)
{//1���� �迭�� 2���� �迭�� ���� ����� �� ���� ����
	int a = maxSize*row + col;
	return a;
}

void WtGraph::computerPaths() {//�÷��̵� �˰����� �̿��Ͽ� �ִܰŸ��� ����ϰ� �Ѵ�.
	int i, j, k;
	for (i = 0; i<size; i++)
		for (j = 0; j<size; j++)
			pathMatrix[edge(i,j)] = adjMatrix[edge(i,j)];
	//���� for���� �̿��Ͽ� pathmatrix�迭�� adjmatrix���� ������

	for (k = 0; k<size; k++) {
		for (i = 0; i < size; i++)
			for (j = 0; j < size; j++) {
				if (pathMatrix[edge(i, k)] + pathMatrix[edge(k, j)] < pathMatrix[edge(i, j)]) {
					pathMatrix[edge(i, j)] = pathMatrix[edge(i, k)] + pathMatrix[edge(k, j)];
				}
			}
	}
	//3��for���� �̿��Ͽ� �ִܰŸ��� pathMatrix�� �����ϰ� �Ѵ�.

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if(i == j)
				pathMatrix[edge(i, j)] = infiniteEdgeWt;
		}
	}
	//pathMatrix���� �ڱ��ڽſ��� ���� ��쿡�� �ʱ�ȭ�� ���ش�.
}