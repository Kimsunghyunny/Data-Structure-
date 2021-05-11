#include <istream>
#include "bstree.h"

template < class TE, class KF >
BSTreeNode<TE, KF>::BSTreeNode(const TE &elem, BSTreeNode *leftPtr, BSTreeNode *rightPtr) 
:element(elem),
left(leftPtr),
right(rightPtr)
{
}
//BSTreeNode 생성자

template < class TE, class KF >
BSTree<TE, KF>::BSTree()
	:root(0)
{
}
//BSTree 생성자, root 초기화

// Destructor
template < class TE, class KF >
BSTree<TE, KF>::~BSTree() {
	clear();
}
//BSTree소멸자

// Binary search tree manipulation operations
template < class TE, class KF >
void BSTree<TE, KF>::insert(const TE &newElement) {
	insertSub(root, newElement);
}// Insert element
//root값가 넣으려는 값을 매개변수로 하는 insertSub함수를 호출한다.

template < class TE, class KF >
void BSTree<TE, KF>::insertSub(BSTreeNode<TE, KF> *&p, const TE &newElement) {
	if (p == NULL) {
		p = new BSTreeNode<TE, KF>(newElement, NULL, NULL);
	}
	else if (newElement.key() < p->element.key())
		insertSub(p->left, newElement);
	else
		insertSub(p->right, newElement);
}
//노드가 아무것도 없는 경우에는 새노드를 만들어 왼쪽과 오른쪽 포인터에 null값을 주면서 값을 넣어준다.
//노드가 이미 있는 경우에는 새로 넣으려는 값과 원래 있는 값과 비교를 하면서 재귀함수를 호출하여 반복한뒤 노드가 존재하지 않는 곳까지 가서 새 노드를 생성하여 tree를 추가한다.

template < class TE, class KF >
int BSTree<TE, KF>::retrieve(KF searchKey, TE &searchElement) const {
	return retrieveSub(root, searchKey, searchElement);
}
// Retrieve element
//return값으로 매개변수를 root와 찾으려는 값, main에서 찾은 값을 출력하기 위해서 찾으려는 값의 주소값을 저장하는 변수로 하는retrieveSub를 호출한다.

template < class TE, class KF >
int BSTree<TE, KF>::retrieveSub(BSTreeNode<TE, KF> *p, KF searchKey, TE &searchElement) const {
	if (p == NULL) {
		return 0;
	}
	else if (searchKey < p->element.key())
		retrieveSub(p->left, searchKey, searchElement);
	else if (searchKey > p->element.key())
		retrieveSub(p->right, searchKey, searchElement);
	else {
		searchElement.setKey(searchKey);
		return 1;
	}
}
//노드가 아무것도 없을때는 값을 찾을 수 없으니 아무것도 하지않고
//노드가 존재할때는 찾으려는 값과 현재 p가 가르키고 있는 값과 비교한뒤 찾으려는 값이 현재 가르키고 있는 p의 값보다 크면 p의 right를 가르키게해서 새 retrieveSub를 호출하고
//작다면 p의 left를 가르키게 해서 retrieveSub를 호출한다. 이런방식으로 찾는 값과 p가 가르키는 값이 같아질때 searchElement에 찾는 값을 setkey함수를 이용하여 저장해준다.

template < class TE, class KF >
int BSTree<TE, KF>::remove(KF deleteKey) {
	if (empty())
		return 0;
	else
		return removeSub(root, deleteKey);
}
// Remove element
//tree가 비어있을때는 아무것도 안하지만, 비어있지 않으면 root와 지우려는값을 매개변수로 갖는 removeSub함수를 호출한다.

template < class TE, class KF >
int BSTree<TE, KF>::removeSub(BSTreeNode<TE, KF> *&p, KF deleteKey) {
	if (p == NULL)
		return 0;
	else if (deleteKey < p->element.key())
		removeSub(p->left, deleteKey);
	else if (deleteKey > p->element.key())
		removeSub(p->right, deleteKey);
	else {
		BSTreeNode<TE, KF> *temp = p;
		cutRightmost(p, temp);
		return 1;
	}
}
//tree가 비어있을때는 아무것도 하지않지만 그렇지 않은 경우에는 insertSub와 retrieveSub와 같은 방식으로, 지우려는 값과 현재 p가 가르키고 있는 값과 비교한다.
//그렇게 계속 비교를 해서 지우려는 값과 p가 가르키고 있는 값이 같을때, 노드포인터 하나를 만들어 p를 가르키게 한뒤, p와 temp를 매개변수로 갖는 cutRightmost함수를 호출한다.

template < class TE, class KF >
void BSTree<TE, KF>::cutRightmost(BSTreeNode<TE, KF> *&r, BSTreeNode<TE, KF> *&delPtr) {
	BSTreeNode<TE, KF> * temp2 = r;
	KF a;
	if (r->left == NULL) {
		r = r->right;
		delete delPtr;
	}//오른쪽에만 child를 가지고 있는 경우에, 현재 지우려는 노드의 값에 오른쪽 child의 값을 저장한다. 그런뒤 지우려는 값을 가르키고 있던 temp 포인터를 삭제해준다.
	else if (r->right == NULL) {
		r = r->left;
		delete delPtr;
	}//왼쪽에만 child를 가지고 있는 경우에, 현재 지우려는 노드의 값에 왼쪽 child의 값을 저장한다. 그런뒤 지우려는 값을 가르키고 있던 temp포인터를 삭제해준다.
	else {
		temp2 = temp2->left;
		while (temp2->right != NULL)
			temp2 = temp2->right;
		a = temp2->element.key();
		delPtr->element = temp2->element;
		removeSub(r->left, a);
		//			temp->element.setKey(p->element.key());
//		cutRightmost(r->left, temp);
	}//지우려는 노드의 child가 2인 경우에, 지우려는값을 가르키는 포인터인 temp2를 temp2의 left값을 가르키게한다.
	//그러고 나서 while문을 돌려서 지우려는 값의 자리에 넣어줄 값을 가르키게 한다. 
	//(child가 2일때는 child 중 작은방향에서 가장 큰 값으로 바꿔서 넣어야 하기 때문임)
	//그런뒤 선언해둔 int형 자료 a에 지우려는 값대신 넣어주려는 값을 저장해준다. 그 뒤에 지우려는 값의 자리에 대신 넣어주려는 a를 대입한다.
	//(a의 값을 직접넣어줄 수 없기 때문에 a의 값과 같은 temp2의 element값을 저장해준다.)
	//그뒤 removeSub를 호출하여 지우려 했던 값을 지운 뒤 a를 넣어준 노드를 제외하고, a의 값을 가진 노드를 삭제하게 한다.
}

template < class TE, class KF >
void BSTree<TE, KF>::writeKeys() const {
	if (root == 0)
		cout << "Empty tree" << endl;
	else
	{
		writeKeysSub(root);
	}
}
// Output keys
//root가 0이면 비어있다는 것이니, empty tree를 출력하게 하고, 그렇지 않은경우에만 writeKeySub를 호출한다.

template < class TE, class KF >
void BSTree<TE, KF>::writeKeysSub(BSTreeNode<TE, KF> *p) const {
	if (p->left != NULL) {
		writeKeysSub(p->left);
	}
	cout << p->element.key() << " ";
	if (p->right != NULL)
		writeKeysSub(p->right);
}
//tree의 값들을 오름차순으로 출력해야 한다. 따라서 재귀함수를 이용해서 root의 가장 외쪽에서부터 출력한뒤, child의 부모를 출력한뒤, 부모의 오른쪽 아이를 출력하는 식으로 한다.
//이런식으로, 왼쪽의 작은값부터 오른쪽의 큰값까지 오름차순으로 출력하게 한다.

template < class TE, class KF >
void BSTree<TE, KF>::clear() {
	clearSub(root);
}// Clear tree
//root를 매개변수로 하는 clearSub함수를 호출한다.

template < class TE, class KF >
void BSTree<TE, KF>::clearSub(BSTreeNode<TE, KF> *p) {
	root = NULL;
}
//지금까지 root가 연결되어 있었기 때문에 tree가 연결되어 있어서 출력할 수 있었던 것이니, root를 초기화 시켜주면 clear된다.
//즉 root의 연결을 끊어주면 값이 다 지워지게 된다.

template < class TE, class KF >											 // Binary search tree status operations
int BSTree<TE, KF>::empty() const {
	if (root == 0)
		return true;
	else
		return false;
}// Tree is empty
//root가 0이면 초기화 값으로, 비어있다는 것이니 root가 0일때 true로 return 한다.

template < class TE, class KF >
int BSTree<TE, KF>::full() const {
}// Tree is full


template < class TE, class KF >										 // Output the tree structure -- used in testing/debugging
void BSTree<TE, KF>::showStructure() const {
	if (root == 0)
		cout << "Empty tree" << endl;
	else
	{
		cout << endl;
		showSub(root, 1);
		cout << endl;
	}
}

template < class TE, class KF >
void BSTree<TE, KF>::showSub(BSTreeNode<TE, KF> *p, int level) const {
	int j;   // Loop counter

	if (p != 0)
	{
		showSub(p->right, level + 1);         // Output right subtree
		for (j = 0; j < level; j++)    // Tab over to level
			cout << "\t";
		cout << " " << p->element.key();   // Output key
		if ((p->left != 0) &&           // Output "connector"
			(p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";
		cout << endl;
		showSub(p->left, level + 1);          // Output left subtree
	}
}

// In-lab operations
template < class TE, class KF >
int BSTree<TE, KF>::height() const {
	if (empty())
		return 0;
	else {
		BSTreeNode<TE, KF> *treeheight = root;
		return heightSub(treeheight);
	}
}// Height of tree
//tree가 비어잇을때는 0으로 return하고 그렇지 않은경우에는 root를 가르키는 노드포인터를 만든뒤 그 노드포인터를 매개변수로 하는 heightSub를 호출하여 return해준다.

template < class TE, class KF >
int BSTree<TE, KF>::heightSub(BSTreeNode<TE, KF> *p) const {
	int heightleft = 0;
	int heightright = 0;
	if (p == NULL)
		return 0;//tree가 비었을때는 height가 0이니 0으로 return한다.
	else {//빈 tree가 아닐때
		heightleft = heightSub(p->left);
		heightright = heightSub(p->right);
		
		if (heightleft > heightright)//왼쪽 hegiht 와 오른쪽 height를 비교해서 더 큰값을 return하게 한다.
			return heightleft + 1;
		else
			return heightright + 1;

	}
}
//left와 right의 값을 각각 재귀호출을 통하여 각 왼쪽과 오른쪽 child가 존재할때까지
//아래의 if문들 통해서 +1씩 하게해서 값들을 왼쪽의 height와 오른쪽의최대 height를 저장하게 한다.
//그렇게 계속실행하여, 존재하는 노드의까지, 가장 높은 높이를 return하게 된다.