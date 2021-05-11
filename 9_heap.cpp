#include "heap.h"
using namespace std;

template < class HE >
Heap<HE>::Heap(int maxNumber = defMaxHeapSize)//heap Ŭ���� ������
:maxSize(maxNumber),//maxsize���� maxnumber���� ����
size(0)//size�� 0���� �ʱ�ȭ
{
	element = new HE[maxSize];//maxsizeũ���� �迭�� ����
}

// Destructor
template < class HE >
Heap<HE>::~Heap()//�Ҹ���
{
	clear();//clear�� ���� �Ҹ�
}

// Heap manipulation operations
template < class HE >
void Heap<HE>::insert(const HE &newElement) {
	if (empty())//�迭�� empty�̸�
	{
		size++;//size�� 1�����ְ�
		element[0] = newElement;//element�迭�� ù��° ���� ���ο� ���� ����
	}
	else if(!full())//�迭�� full�� �ƴҶ�
	{
		size++;//size�� ���������ص�
		element[size - 1] = newElement;//�迭�� 0���� �����ϴ� size-1��°�� ���ο� ���� ����
		int parent;
		int bottom = size - 1;//bottom������ size-1�����Ͽ� �迭�� �� ������ ���� ����Ű�� ������ ����(�迭�� 0���� �����ϱ� ����)
		while (bottom != 0) {
			parent = (bottom - 1) / 2;//parent������ (bottom-1)/2 bottom���� �θ��� ���� �迭 ������ ����
			if (element[parent].pty() < element[bottom].pty()) {//�θ�� bottom���� ���Ͽ� bottom�� ��ũ�� heap�� ����� ���� �Ʒ� �ڵ带 ����
				HE a;
				a = element[parent];//a�� parent��°�� �迭 ���� ����
				element[parent] = element[bottom];
				element[bottom] = a;
				//parent�� bottom��°�� ������ swap���ִ� ����
				bottom = parent;
				//bottom�� parent�� �ٲ���. �ֳ��ϸ� �� �ڿ� �ִ� ���� parent�� �ִ� ���� �Ǿ��� ����
			}
			else
				bottom = parent;//�θ�� bottom���� ���Ͽ� bottom���� ��ũ���ʾƵ�, bottom���� �������־� bottom�� root�� �ɶ����� �����ϰ� �Ͽ� heap�� ����� �ְ���
		}
	}

}// Insert element

template < class HE >
HE Heap<HE>::removeMax() {
	if (empty())//empty�� �����̸� 
		cout << "Empty heap" << endl;
	else {//empty�� �ƴ� �����̸�
		int root = 0;
		int bottom = size - 1;//�迭���� ���� �ڿ� �ִ� ���� ã�� ���Ͽ� bottom���� size-1�� ��
		HE item = element[root];//�ӽ÷� root��°�� �ִ� ���� �����ص�
		element[root] = element[bottom];//root���翡 bottom��°�� ���� ��
		size--;//�迭�� size�� �ٿ��� ���� �������� ��ó�� ��

		//root�� �ִ°��� �� �� bottom�� �ִ� ���� �־� �� ��, heap�� ����� ����ϱ� ������, ��ü������ ������ ��迭���� �ʿ䰡 ����
		int rightchild;
		int leftchild;
		int maxchild;
		rightchild = root*2 + 2;//root�� �����ʾ��̰��� ����ִ� �迭������
		leftchild = root*2 + 1;//root�� ���ʾ��̰��� ����ִ� �迭������
		while (leftchild <= bottom) {//leftchild�� bottom���� ũ�� �̹� heap�̴�
			if (leftchild == bottom)//child�� �ϳ��϶�,
				maxchild = leftchild;//ū ������ ���ʾ��̰��� ����
			else {//���̰� �θ��϶�
				if (element[leftchild].pty() <= element[rightchild].pty())//�����ʾ��̰��� ���ʾ��̰����� Ŭ��
					maxchild = rightchild;//�� ū ������ �����ʾ��̰��� ����
				else//���ʾ��̰� �� Ŭ��
					maxchild = leftchild;//�� ū ������ ���ʾ��̰��� ����
			}
			if (element[root].pty() < element[maxchild].pty()) {//root���� ������ ū ���̰��� ��
				HE item2 = element[root];//root�� �� ���� �ӽ÷� ����
				element[root] = element[maxchild];//root�� �� ū ���� ����
				element[maxchild] = item2;//maxchild�� �ִ� �ڸ��� root���� �����Ͽ� swap�� �Ϸ�
			}
			root = maxchild;//while���� heap�� �ϼ��ɶ����� ���ϱ�, root���� 0�̾ƴ� maxchild�� ����
			rightchild = root * 2 + 2;//root���� �ٲ������ rightchild�� leftchild�� ���� �� ����
			leftchild = root * 2 + 1;
		}
		return item;//heap���� �ٲٴ� ������ �� ������ ������ item�� return��(���� ���� ó�� root�� �ִ� ��)
	}
}// Remove max pty element
				
template < class HE >											 // Heap status operations
int Heap<HE>::empty() const {
	if (size == 0)//size�� 0�̸� �� �����̴� return 1����
		return 1;
	else
		return 0;
}// Heap is empty

template < class HE >
int Heap<HE>::full() const {
	if (size == maxSize)//size�� maxSize�� ������ �� �� �����̴� return 1����
		return 1;
	else
		return 0;
}// Heap is full

template < class HE >
void Heap<HE>::clear() {
	size = 0;//size�� 0���� �༭ �迭�� �� ��������
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
