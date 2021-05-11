//--------------------------------------------------------------------
//
//  Laboratory 15, In-lab Exercise 2                        sort.cpp
//
//  Implementation of a set of sorting routines
//
//--------------------------------------------------------------------

template < class LE >
void selectionSort ( LE keyList [], int numKeys )

// Selection sort routine. Sorts the first numKeys keys in keyList
// into ascending order.

{
	LE temp;//값 임시 저장할 temp 변수 선언

	int min; //작은 값을 갖고 있는 배열의 순서를 저장하기 위한 변수 선언

	//i의 값일때의 자리의 값을 가장 작은 수가 오도록 정렬해준다.
	for (int i = 0; i < numKeys - 1; i++)
	{
		min = i;//일단 min의 값을 i로 둔다
		for (int j = i + 1; j < numKeys; j++)//이중 포문을 돌면서 첫번째 배열의 값에 가장 작은 값이 오도록, 가장 작은 값을 가진 배열의 순서를 min에 저장
			if (keyList[j] < keyList[minPt])
				min = j;
		temp = keyList[i]; //temp에 i번째 값 임시 저장 (swqp하기 위하여)
		keyList[i] = keyList[min];
		keyList[min] = temp;
		//값을 swap해준다.
	}
}

//--------------------------------------------------------------------

template < class LE >
void quickSort ( LE keyList [], int numKeys )
{
    quickPartition(keyList,numKeys,0,numKeys-1);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class LE >
void quickPartition ( LE keyList [], int numKeys,
                      int left, int right         )
{
	LE mid = keyList[(left + right) / 2];//가운데에 있는 값을 저장
	LE temp;//임시 저장할 변수 선언

	int i = left;
	int j = right;

	while (left<j || i<right)//왼쪽보다 오른쪽이 더 크거나 오른쪽이 왼쪽보다 더 클때는 파티션이 나눠져 있는것이니 계속해서 실행
	{
		while (keyList[i]<mid)//i번째의 값이 mid에 있는 값 보다 작을때
			i++;
		while (keyList[j]>mid)//j번째의 값이 mid에 있는 값 보다 클때
			j--;

		if (i <= j) {//i가 j보다 작거나 같을때 값을 바꿔준다 (mid의 왼쪽에는 mid값보다 작은값, 오른쪽에는 큰값이 들어가도록 자리를 계속해서 옮겨준다
			temp = keyList[i]; 
			keyList[i] = keyList[j]; 
			keyList[j] = temp;
			i++;                       
			j--;                   
		}
		else {//이번 mid에서 모든 정렬이 끝났을때, 새로 왼쪽 오른쪽에 대해서는 quick솔트를 각각 재귀함수로 실행 해준다.
			if (left<j)
				quickPartition(keyList, numKeys, left, j);
			if (i<right)
				quickPartition(keyList, numKeys, i, right);
			return;
		}
	}
}

//--------------------------------------------------------------------

template < class LE >
void unknownSort ( LE keyList [], int numKeys )
{
	LE temp;//임시 저장 변수 temp 선언

	//버블정렬 (이중 포문)
	for (int i = 0; i < numKeys - 1; i++)
		for (int j = i; j < numKeys; j++)
			if (keyList[j] < keyList[j + 1])//오름차순 정렬
			{
				temp = keyList[j+1];
				keyList[j] = keyList[j + 1];
				keyList[j + 1] = temp;
			}
}