#include "heap.h"
using namespace std;

template < class HE >
Heap<HE>::Heap(int maxNumber = defMaxHeapSize)//heap 클래스 생성자
:maxSize(maxNumber),//maxsize값에 maxnumber값을 저장
size(0)//size를 0으로 초기화
{
	element = new HE[maxSize];//maxsize크기의 배열을 생성
}

// Destructor
template < class HE >
Heap<HE>::~Heap()//소멸자
{
	clear();//clear을 통해 소멸
}

// Heap manipulation operations
template < class HE >
void Heap<HE>::insert(const HE &newElement) {
	if (empty())//배열이 empty이면
	{
		size++;//size를 1더해주고
		element[0] = newElement;//element배열의 첫번째 값에 새로운 값을 저장
	}
	else if(!full())//배열이 full이 아닐때
	{
		size++;//size를 증가시켜준뒤
		element[size - 1] = newElement;//배열은 0부터 시작하니 size-1번째에 새로운 값을 저장
		int parent;
		int bottom = size - 1;//bottom값으로 size-1저장하여 배열의 맨 마지막 값을 가르키는 값으로 저장(배열은 0부터 시작하기 때문)
		while (bottom != 0) {
			parent = (bottom - 1) / 2;//parent값으로 (bottom-1)/2 bottom값의 부모인 값의 배열 순서를 저장
			if (element[parent].pty() < element[bottom].pty()) {//부모와 bottom값을 비교하여 bottom이 더크면 heap을 만들기 위해 아래 코드를 실행
				HE a;
				a = element[parent];//a에 parent번째의 배열 값을 저장
				element[parent] = element[bottom];
				element[bottom] = a;
				//parent와 bottom번째의 값들을 swap해주는 과정
				bottom = parent;
				//bottom을 parent로 바꿔줌. 왜냐하면 맨 뒤에 있는 값이 parent에 있던 것이 되었기 때문
			}
			else
				bottom = parent;//부모와 bottom값을 비교하여 bottom값이 더크지않아도, bottom값을 변경해주어 bottom이 root가 될때까지 실행하게 하여 heap을 만들어 주게함
		}
	}

}// Insert element

template < class HE >
HE Heap<HE>::removeMax() {
	if (empty())//empty인 상태이면 
		cout << "Empty heap" << endl;
	else {//empty가 아닌 상태이면
		int root = 0;
		int bottom = size - 1;//배열에서 제일 뒤에 있는 값을 찾기 위하여 bottom값을 size-1로 줌
		HE item = element[root];//임시로 root번째에 있는 값을 저장해둠
		element[root] = element[bottom];//root번재에 bottom번째의 값을 줌
		size--;//배열의 size를 줄여서 값이 없어지는 것처럼 함

		//root에 있는값을 뺀 뒤 bottom에 있는 값을 넣어 준 뒤, heap을 만들어 줘야하기 때문에, 전체적으로 값들을 재배열해줄 필요가 있음
		int rightchild;
		int leftchild;
		int maxchild;
		rightchild = root*2 + 2;//root의 오른쪽아이값이 들어있는 배열순서값
		leftchild = root*2 + 1;//root의 왼쪽아이값이 들어있는 배열순서값
		while (leftchild <= bottom) {//leftchild가 bottom보다 크면 이미 heap이니
			if (leftchild == bottom)//child가 하나일때,
				maxchild = leftchild;//큰 값으로 왼쪽아이값을 저장
			else {//아이가 두명일때
				if (element[leftchild].pty() <= element[rightchild].pty())//오른쪽아이값이 왼쪽아이값보다 클떄
					maxchild = rightchild;//더 큰 값으로 오른쪽아이값을 저장
				else//왼쪽아이가 더 클때
					maxchild = leftchild;//더 큰 값으로 왼쪽아이값을 저장
			}
			if (element[root].pty() < element[maxchild].pty()) {//root값과 아이중 큰 아이값을 비교
				HE item2 = element[root];//root에 들어간 값을 임시로 저장
				element[root] = element[maxchild];//root에 더 큰 값을 저장
				element[maxchild] = item2;//maxchild가 있던 자리에 root값을 저장하여 swap을 완료
			}
			root = maxchild;//while문이 heap이 완성될때까지 도니까, root값을 0이아닌 maxchild로 저장
			rightchild = root * 2 + 2;//root값이 바뀌었으니 rightchild와 leftchild도 새로 값 저장
			leftchild = root * 2 + 1;
		}
		return item;//heap으로 바꾸는 과정이 다 끝나고 나서야 item을 return함(원래 제일 처음 root에 있던 값)
	}
}// Remove max pty element
				
template < class HE >											 // Heap status operations
int Heap<HE>::empty() const {
	if (size == 0)//size가 0이면 빈 상태이니 return 1해줌
		return 1;
	else
		return 0;
}// Heap is empty

template < class HE >
int Heap<HE>::full() const {
	if (size == maxSize)//size가 maxSize와 같으면 꽉 찬 상태이니 return 1해줌
		return 1;
	else
		return 0;
}// Heap is full

template < class HE >
void Heap<HE>::clear() {
	size = 0;//size를 0으로 줘서 배열을 다 지워버림
}


template < class HE >
void Heap<HE>:: showStructure () const

// Outputs the priorities of the elements in a heap in both array
// and tree form. If the heap is empty, outputs "Empty heap". This
// operation is intended for testing/debugging purposes only.

{
    int j;   // Loop counter

    cout << endl;
    if ( size == 0 )
       cout << "Empty heap" << endl;
    else
    {
       cout << "size = " << size << endl;       // Output array form
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       for ( j = 0 ; j < size ; j++ )
           cout << element[j].pty() << "\t";
       cout << endl << endl;
       showSubtree(0,0);                        // Output tree form
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class HE >
void Heap<HE>:: showSubtree ( int index, int level ) const

// Recursive partner of the showStructure() function. Outputs the
// subtree (subheap) whose root is stored in element[index]. Argument
// level is the level of this element within the tree.

{
     int j;   // Loop counter

     if ( index < size )
     {
        showSubtree(2*index+2,level+1);        // Output right subtree
        for ( j = 0 ; j < level ; j++ )        // Tab over to level
            cout << "\t";
        cout << " " << element[index].pty();   // Output element's pty
        if ( 2*index+2 < size )                // Output "connector"
           cout << "<";
        else if ( 2*index+1 < size )
           cout << "\\";
        cout << endl;
        showSubtree(2*index+1,level+1);        // Output left subtree
    }
}
