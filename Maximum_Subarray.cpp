#include<iostream>
#include <fstream>
using namespace std;
int size;
int kadane(int arr[]);

int main()
{
	ifstream text("text.txt");
	int sum = 0;
	int length;
	text >> size;
	int *arr = new int[size];

	for (int i = 0; i < size; i++) {
		text >> arr[i];
	}

	int KadaneMax = kadane(arr);	

	printf("���� ���� �ִ� : %d\n\n", KadaneMax);

	delete[] arr;
	return 0;
}

int kadane(int a[]){
	int max = 0;	
	int sum = 0;	
	int MaxLeft = 0;	
	int MaxRight = 0;	
	int Right,Left,CmpCount = 0;	

	for ( Right= 0; Right<size; Right++){
		sum = sum + a[Right];	

		if (sum < 0){	
			MaxLeft = Left;		
			Left = Right + 1;	
			CmpCount++;
			sum = 0;	
		}
		else if (max <= sum){	
			MaxLeft = Left;		
			MaxRight = Right;	
			CmpCount++;
			max = sum;	
		}
		else{
			
		}
		printf("�ִ밪 : %d, ���� [%d]-[%d]\n",max,MaxLeft,MaxRight);
	}
	cout << "\n��Ƚ�� : " << CmpCount << endl;
	printf("�κ��ִ밪�� ���� : [%d]-[%d]\n",MaxLeft,MaxRight);
	return max;
}