#include<iostream>
#include<vector>
using namespace std;

//将一个记录插入到已排序好的有序表中，从而得到一个新，记录数增1的有序表。
//即：先将序列的第1个记录看成是一个有序的子序列，
//然后从第2个记录逐个进行插入，直至整个序列有序为止。

//直接插入排序
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

//冒泡排序

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
	int i = array.size() - 1;  //初始时,最后位置保持不变
	while (i> 0) {
		int pos = 0; //每趟开始时,无记录交换
		for (int j = 0; j< i; j++)
		if (array[j]> array[j + 1]) {
			pos = j; //记录交换的位置 
			int tmp = array[j]; array[j] = array[j + 1]; array[j + 1] = tmp;
		}
		i = pos; //为下一趟排序作准备
	}
	return array;
}


//

int main(){
	vector<int> array = { 0, 4, 5, 3, 6, 7, 1, 8, 2, 9 };
	/*array = InsertSort(array);
	for (int i = 0; i < array.size(); ++i){
		cout << array[i] << " " ;
	}*/
	
	array = Bubble_1(array);
	for (int i = 0; i < array.size(); ++i){
		cout << array[i] << " ";
	}

	system("pause");
	return 0;
}