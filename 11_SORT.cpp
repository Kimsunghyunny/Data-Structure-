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
	LE temp;//�� �ӽ� ������ temp ���� ����

	int min; //���� ���� ���� �ִ� �迭�� ������ �����ϱ� ���� ���� ����

	//i�� ���϶��� �ڸ��� ���� ���� ���� ���� ������ �������ش�.
	for (int i = 0; i < numKeys - 1; i++)
	{
		min = i;//�ϴ� min�� ���� i�� �д�
		for (int j = i + 1; j < numKeys; j++)//���� ������ ���鼭 ù��° �迭�� ���� ���� ���� ���� ������, ���� ���� ���� ���� �迭�� ������ min�� ����
			if (keyList[j] < keyList[minPt])
				min = j;
		temp = keyList[i]; //temp�� i��° �� �ӽ� ���� (swqp�ϱ� ���Ͽ�)
		keyList[i] = keyList[min];
		keyList[min] = temp;
		//���� swap���ش�.
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
	LE mid = keyList[(left + right) / 2];//����� �ִ� ���� ����
	LE temp;//�ӽ� ������ ���� ����

	int i = left;
	int j = right;

	while (left<j || i<right)//���ʺ��� �������� �� ũ�ų� �������� ���ʺ��� �� Ŭ���� ��Ƽ���� ������ �ִ°��̴� ����ؼ� ����
	{
		while (keyList[i]<mid)//i��°�� ���� mid�� �ִ� �� ���� ������
			i++;
		while (keyList[j]>mid)//j��°�� ���� mid�� �ִ� �� ���� Ŭ��
			j--;

		if (i <= j) {//i�� j���� �۰ų� ������ ���� �ٲ��ش� (mid�� ���ʿ��� mid������ ������, �����ʿ��� ū���� ������ �ڸ��� ����ؼ� �Ű��ش�
			temp = keyList[i]; 
			keyList[i] = keyList[j]; 
			keyList[j] = temp;
			i++;                       
			j--;                   
		}
		else {//�̹� mid���� ��� ������ ��������, ���� ���� �����ʿ� ���ؼ��� quick��Ʈ�� ���� ����Լ��� ���� ���ش�.
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
	LE temp;//�ӽ� ���� ���� temp ����

	//�������� (���� ����)
	for (int i = 0; i < numKeys - 1; i++)
		for (int j = i; j < numKeys; j++)
			if (keyList[j] < keyList[j + 1])//�������� ����
			{
				temp = keyList[j+1];
				keyList[j] = keyList[j + 1];
				keyList[j + 1] = temp;
			}
}