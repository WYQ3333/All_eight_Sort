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


vector<int> Bubble_1(vector<int> array) {
	int i = array.size() - 1;  //��ʼʱ,���λ�ñ��ֲ���
	while (i> 0) {
		int pos = 0; //ÿ�˿�ʼʱ,�޼�¼����
		for (int j = 0; j< i; j++)
			if (array[j]> array[j + 1]) {
				pos = j; //��¼������λ�� 
				int tmp = array[j]; array[j] = array[j + 1]; array[j + 1] = tmp;
			}
		i = pos; //Ϊ��һ��������׼��
	}
	return array;
}

//��������

int PartSort1(vector<int>& array, int left, int right){
	//����ָ�뷨
	int& temp = array[right];		//���ұߵ�������Ϊ��׼ֵ
	while (left < right){
		while (left < right && array[left] <= temp){
			left++;
		}
		while (left < right && array[right] >= temp){
			right--;
		}
		swap(array[left], array[right]);
	}
	swap(array[left], temp);
	return left;
}

int PartSort2(vector<int>& array, int left, int right){
	//�ڿӷ�
	int temp = array[right];
	while (left < right){
		while (left < right && array[left] < temp){
			left++;
		}
		array[right] = array[left];
		while (left < right && array[right] > temp){
			right--;
		}
		array[left] = array[right];
	}
	array[right] = temp;
	return right;
}

void QuickSort(vector<int>& array, int left, int right){
	if (array.empty()){
		return;
	}
	if (left > right){
		//�����Ѿ��������
		return;
	}
	int index = PartSort2(array, left, right);
	QuickSort(array, left, index - 1);
	QuickSort(array, index + 1, right);
}

int main(){
	vector<int> array = { 0, 4, 5, 3, 6, 7, 1, 8, 2, 9 };
	/*array = InsertSort(array);
	for (int i = 0; i < array.size(); ++i){
		cout << array[i] << " " ;
	}*/
	
	/*array = Bubble_1(array);
	for (int i = 0; i < array.size(); ++i){
		cout << array[i] << " ";
	}*/

	QuickSort(array, 0, array.size() - 1);
	for (int i = 0; i < array.size(); ++i){
		cout << array[i] << " ";
	}

	system("pause");
	return 0;
}