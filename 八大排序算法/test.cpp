#include<iostream>
#include<vector>
using namespace std;

//��һ����¼���뵽������õ�������У��Ӷ��õ�һ���£���¼����1�������
//�����Ƚ����еĵ�1����¼������һ������������У�
//Ȼ��ӵ�2����¼������в��룬ֱ��������������Ϊֹ��

//ֱ�Ӳ�������
vector<int>  InsertSort(vector<int>  array){
	int i = 0;
	int temp = array[0];
	for (i = 1; i < array.size(); ++i){
		temp = array[i];
		int j = i;
		while (j > 0 && temp < array[j - 1]){
			array[j] = array[j - 1];
			j--;
		}
		array[j] = temp;
	}
	return array;
}

//ð������

vector<int> BubbleSort(vector<int> array){
	int i = 0;
	for (i = 0; i < array.size(); ++i){
		for (int j = i; j < array.size(); ++j){
			if (array[j]<array[i]){
				int temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
	return array;
}

int main(){
	vector<int> array = { 0, 4, 5, 3, 6, 7, 1, 8, 2, 9 };
	/*array = InsertSort(array);
	for (int i = 0; i < array.size(); ++i){
		cout << array[i] << " " ;
	}*/
	
	array = BubbleSort(array);
	for (int i = 0; i < array.size(); ++i){
		cout << array[i] << " ";
	}

	system("pause");
	return 0;
}