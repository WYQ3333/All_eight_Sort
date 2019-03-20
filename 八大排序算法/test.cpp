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

//快速排序

int PartSort1(vector<int>& array, int left, int right){
	//左右指针法
	int& temp = array[right];		//最右边的数字作为基准值
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
	//挖坑法
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
		//表明已经排序完毕
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