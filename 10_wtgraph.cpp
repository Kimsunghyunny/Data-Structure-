#include <iostream>
#include <string.h>
#include <assert.h>
#include "wtgraph.h"
using namespace std;

WtGraph::WtGraph(int maxNumber)//생성자
: maxSize(maxNumber),//maxNumber로 maxSize정해줌
size(0)//size는 0으로 초기화
{
	vertexList = new Vertex[maxSize];//vertex저장하는 배열 동적할당
	adjMatrix = new int[maxSize*maxSize];//가중치를 저장하는 배열 동적할당
	for (int i = 0; i < maxSize; i++)//adj에 초기값을 저장해줌
		adjMatrix[i*i] = infiniteEdgeWt;
	pathMatrix = new int[maxSize*maxSize];//최단거리를 저장하는 배열 동적할당
}

WtGraph:: ~WtGraph()//소멸자
{
	delete[] vertexList;
	delete[] adjMatrix;
	delete[] pathMatrix;
}

void WtGraph::insertVertex(Vertex newVertex)
{
	int num;
	num = index(newVertex.label);//vertexlist에 새로 정보를 넣기 위하여 index로 저장해야 할 배열순서를 불러옴
	vertexList[num] = newVertex;//vertexlist의 num번째에 새로 넣으려는 이름을 넣음
	if (!full()) {//가득 차지 않은 경우에
		if (size != 0) {//비어있지 않은 상태이면
			size++;//사이즈를 1개 증가한 뒤
			for (int i = 0; i < size; i++)
			{//for문을 통하여 각 값들을 초기값을 넣어준다.
				adjMatrix[edge(size - 1, i)] = infiniteEdgeWt;
				adjMatrix[edge(i, (size - 1))] = infiniteEdgeWt;
			}
		}
		else {//empty인 경우에
			size++;//size를 1증가시키고
			adjMatrix[edge(0, 0)] = infiniteEdgeWt;//초기화해준다.
		}
	}


}

void WtGraph::insertEdge(char *v1, char *v2, int wt)
{
	int a = index(v1);//v1의 배열순서와
	int b = index(v2);//v2의 배열순서를 정수값에 저장

	adjMatrix[edge(a, b)] = wt;//adjMatrix의 배열에 edge를 이용하여 row가 a, col이 b인 경우에 값을 wt 넣어줌
	adjMatrix[edge(b, a)] = wt;//row가b, col이 a인 경우에도 마찬가지로 (서로 가중치를 저장해서 길이 연결되었고 가중치가 있어야 하니 양쪽에 넣어줌)
}

int WtGraph::retrieveVertex(char *v, Vertex &vData) const
{
	int num;

	num = index(v);//검색하는 v의 순서를 num에 저장
	if (num < size) {//num이 size보다 작으면 num은 존재한다는 의미이기 때문에 (size보다 크거나 같으면 배열로 있을 수 없음, size는 1부터고 배열은 0부터이기 때문) 
		vData = vertexList[num];//vdata에 이름 저장
		return 1;//1로리턴
	}
	else {//num이 size보다 크거나 같으면 존재하지 않는것이니 (size=0이고 num=0이니)
		return 0;//0으로 리턴
	}

}

int WtGraph::edgeWeight(char *v1, char *v2, int &wt)
{
	int a = index(v1);//v1의 순서 a에 저장
	int b = index(v2);//v2의 순서 b에 저장
	int c = adjMatrix[edge(a, b)];//c에 (a,b)의 2차원 배열 위치를 찾아 그 위치에 있는 값을 c에 저장
	wt = c;//wt에 c를 대입
	if (wt != infiniteEdgeWt)//c가 초기값인경우도 있으니, 초기값이 아닌경우에만 가중치를 리턴
		return wt;
}

void WtGraph::removeVertex(char *v)
{
	int a = index(v);//a에 v의 순서 저장
	for (int i = a; i < (size - 1); i++) {//한칸씩 앞으로 땡겨와서 저장
		vertexList[i] = vertexList[i + 1];
	}
	for (int i = a; i < (size - 1); i++) {
		for (int j = 0; j < size; j++)
			adjMatrix[edge(i, j)] = adjMatrix[edge(i + 1, j)];
	}//adjmatrix값 한칸씩 땡겨서 저장
	for (int i = a; i < (size - 1); i++) {
		for (int j = 0; j < size; j++)
			adjMatrix[edge(i, j)] = adjMatrix[edge(i, j + 1)];
	}//adjmatrix값 한칸씩 땡겨서 저장
	size--;//하나를 지웠으니 size를 줄여줌
}

void WtGraph::removeEdge(char *v1, char *v2)

{
	int a = index(v1);//v1의 순서를 a에 저장
	int b = index(v2);//v2의 순서를 b에 저장

	adjMatrix[edge(a, b)] = infiniteEdgeWt;//각각 row가 a col이 b인경우에 초기값을 저장
	adjMatrix[edge(b, a)] = infiniteEdgeWt;//각각 row가 b col이 a인경우에 초기값을 저장
}

void WtGraph::clear()
{
	size = 0;//size를 0주면 clear됨
}

int WtGraph::empty() const
{
	if (size == 0)//size가 0이면 비어있는것이니 1을 리턴해준다
		return 1;
	else return 0;//size가 0이아니면 0을 리턴
}

int WtGraph::full() const
{
	if (size == maxSize)//size가 maxsize만큼 찼으면 꽉찼으니 1을 리턴
		return 1;
	else return 0;//size가 maxsize가 아니면 0을 리턴해준다.
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
{	//현재 이름을 저장한 vertexlist의 배열 순서를 리턴하게 하는 함수
	int sizeup;
	if (size == 0)//size가 0이면
		sizeup = 0;//sizeup은 0
	else {//size가 0이 아닐때
		sizeup = 0;
		for (int i = 0; i < size && strcmp(vertexList[sizeup].label, v) != 0; i++)//for문을 통해 v와 같은 배열의 순서를 리턴하게 함
			sizeup++;
	}
	return sizeup;
}

int& WtGraph::edge(int row, int col)
{//1차원 배열을 2차원 배열과 같이 만들고 그 값을 리턴
	int a = maxSize*row + col;
	return a;
}

void WtGraph::computerPaths() {//플로이드 알고리즘을 이용하여 최단거리를 출력하게 한다.
	int i, j, k;
	for (i = 0; i<size; i++)
		for (j = 0; j<size; j++)
			pathMatrix[edge(i,j)] = adjMatrix[edge(i,j)];
	//이중 for문을 이용하여 pathmatrix배열에 adjmatrix값을 저장함

	for (k = 0; k<size; k++) {
		for (i = 0; i < size; i++)
			for (j = 0; j < size; j++) {
				if (pathMatrix[edge(i, k)] + pathMatrix[edge(k, j)] < pathMatrix[edge(i, j)]) {
					pathMatrix[edge(i, j)] = pathMatrix[edge(i, k)] + pathMatrix[edge(k, j)];
				}
			}
	}
	//3중for문을 이용하여 최단거리를 pathMatrix에 저장하게 한다.

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if(i == j)
				pathMatrix[edge(i, j)] = infiniteEdgeWt;
		}
	}
	//pathMatrix에서 자기자신에게 가는 경우에는 초기화를 해준다.
}