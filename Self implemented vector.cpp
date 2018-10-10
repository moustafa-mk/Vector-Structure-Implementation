#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int arr_sz);
int* addElement(int* arr, int& arr_sz, int val);
int* deleteElement(int* arr, int& arr_sz, int idx);

int main()
{
    int arr_sz = 10;
    int* arr = new int[arr_sz];
    for(int i=0; i < arr_sz; i++){
        arr[i] = i+1;
    }

    arr = addElement(arr, arr_sz, 11);

    printArray(arr, arr_sz);

    arr = deleteElement(arr, arr_sz, 3);

    printArray(arr, arr_sz);
}

void printArray(int arr[], int arr_sz){
    for(int i = 0; i < arr_sz; i++)
        cout << arr[i] << " ";
    cout << '\n';
}

int* addElement(int* arr, int& arr_sz, int val){
    int* newArr = new int[arr_sz + 1];
    for(int i = 0; i < arr_sz; i++)
        newArr[i] = arr[i];
    newArr[arr_sz] = val;

    arr_sz++;
    return newArr;
}

int* deleteElement(int* arr, int& arr_sz, int idx){
    int* newArr = new int[arr_sz - 1];
    int cnt = 0;

    for(int i = 0; i < idx; i++)
        newArr[cnt++] = arr[i];

    for(int i = idx + 1; i < arr_sz; i++)
        newArr[cnt++] = arr[i];

    arr_sz--;
    return newArr;
}
