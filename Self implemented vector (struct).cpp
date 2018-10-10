#include <bits/stdc++.h>

using namespace std;

struct Vector{
    int arr_sz = 0;
    int* arr = new int[arr_sz];
    bool fixed = false;
};

Vector createVector(int sz){
    Vector vec;
    vec.arr_sz = sz;
    vec.arr = new int[vec.arr_sz];
    vec.fixed = true;

    return vec;
}

void pushBack(Vector& vec, int val){
    if(vec.fixed){
        cout << "vector is of fixed size, use [] operator instead.\nNo changes have been made...\n";
        return;
    }

    int* newArr = new int[vec.arr_sz + 1];
    for(int i = 0; i < vec.arr_sz; i++){
        newArr[i] = vec.arr[i];
    }
    newArr[vec.arr_sz] = val;

    vec.arr_sz++;
    vec.arr = newArr;
}

void Delete(Vector& vec, int idx){
    if(idx >= vec.arr_sz){
        cout << "Index " << idx << " out of range, no changes have been made.\n";
        return;
    }

    int* newArr = new int[vec.arr_sz - 1];
    int cnt = 0;

    for(int i = 0; i < idx; i++)
        newArr[cnt++] = vec.arr[i];

    for(int i = idx + 1; i < vec.arr_sz; i++)
        newArr[cnt++] = vec.arr[i];

    vec.arr_sz--;
    vec.arr = newArr;
}

void print(Vector vec){
    for(int i = 0; i < vec.arr_sz; i++)
        cout << vec.arr[i] << " ";
    cout << endl;
}

int main(){
    Vector vec;

    pushBack(vec, 5);
    pushBack(vec, 6);
    pushBack(vec, 7);
    pushBack(vec, 8);

    print(vec);

    Delete(vec, 2);
    Delete(vec, 5);

    print(vec);
}
