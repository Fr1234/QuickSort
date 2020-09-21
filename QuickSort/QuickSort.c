#include <stdio.h>
#include <stdlib.h>
#include<time.h>
/// <summary>
/// 製造亂數放入陣列中
/// </summary>
/// <param name="array"></param>
/// <param name="array_length"></param>
void PutRandomNumberInArray(int* array, int* array_length) {
	//srand(time(NULL));
	for (int i = 0; i < *array_length; i++) {
		array[i] = rand() % *array_length + 1;
		//for (int j = 0; j < i; j++) {
		//	if (array[i] == array[j])  //比較值是否已經存在
		//	{
		//		/*i--;
		//		break;*/
		//		j = 0;
		//		array[i] = rand() % *array_length + 1;
		//	}
		//	//	/*while (array[i] == array[j])
		//	//	{
		//	//		j = 0;
		//	//		array[i] = rand() % *array_length + 1;
		//	//	}*/
		//}
	}


}
/// <summary>
/// 印出陣列裡的數字
/// </summary>
/// <param name="array"></param>
/// <param name="array_length"></param>
void Print(int* array, int* array_length) {

	for (int i = 0; i < *array_length; i++) {
		printf("%d ", *(array + i));
	}
	printf("\n");
}
/// <summary>
/// 交換兩個位置的值
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/// <summary>
/// 調整數列
/// </summary>
/// <param name="array"></param>
/// <param name="front">最前面是第幾項</param>
/// <param name="end">最後面是第幾項</param>
int Partition(int *array, int front, int end) {
	int pivot = *(array + end);
	int i = front - 1;

	for (int j = front; j < end; j++) {
		if (*(array + j) < pivot) {
			i++;
			Swap(&array[i], &array[j]);
		}
	}
	i++;
	Swap(&array[i], &array[end]);
	return i;
}
/// <summary>
/// Quick_Sort
/// </summary>
/// <param name="array">陣列位址</param>
/// <param name="front">陣列最前面第幾項</param>
/// <param name="end">陣列最後面第幾項</param>
void Quick_Sort(int *array, int front,int end) {
	//int end=(*array_length)-1;
	//int front = 0;
	if (front < end) {
		int pivot = Partition(array,front,end);
		//printf("pivot=%d", pivot);
		Quick_Sort(array,front,pivot-1);
		Quick_Sort(array, pivot+1, end);
	}
}
/// <summary>
/// 主程式
/// </summary>
/// <returns></returns>
int main() {
	//int a = 10, b = 20;
	int A[] = { 0,10,40,5,16,1 };

	static int B[1000000];
	int  array_lengthB = sizeof(B) / sizeof(B[0]);///B陣列有幾個元素
	int  array_length = sizeof(A) / sizeof(A[0]);///A陣列有幾個元素

	clock_t start_time, end_time;
	printf("array_length=%d\n", array_length);
	Print(&A, &array_length);
	//int pivot = Partition(&A, 0,array_length-1 );
	//printf("pivot=%d", pivot);
	Quick_Sort(&A, 0,(array_length-1));
	
	Print(&A, &array_length);
	PutRandomNumberInArray(&B, &array_lengthB);
	
	Print(&B, &array_lengthB);
	//start_time = clock(); /* mircosecond */
	start_time = clock();
	Quick_Sort(&B, 0, (array_lengthB - 1));
	end_time = clock();

	Print(&B, &array_lengthB);
	
	/* CLOCKS_PER_SEC is defined at time.h */
	float total_time = (float)(end_time - start_time) / CLOCKS_PER_SEC;

	printf("1000000個陣列亂數QuickSort需要的時間 : %f sec \n", total_time);
	//Swap(&a, &b);
	//printf("a=%d,b=%d", a, b);
}