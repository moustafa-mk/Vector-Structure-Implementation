#include <bits/stdc++.h>

using namespace std;

class Vector{
    private:
        int* arr = nullptr;
        int arr_sz;
        bool fixed = false;

        int* createArr(int val){
            arr_sz++;
            int* newArr = new int[arr_sz];
            for(int i = 0; i < arr_sz - 1; i++)
                newArr[i] = arr[i];
            newArr[arr_sz - 1] = val;

            return newArr;
        }

        int* deleteElement(int idx){
            int* newArr = new int[arr_sz - 1];
            int cnt = 0;

            for(int i = 0; i < idx; i++){
                newArr[cnt++] = arr[i];
            }

            for(int i = idx + 1; i < arr_sz; i++){
                newArr[cnt++] = arr[i];
            }

            arr_sz--;
            return newArr;
        }

    public:
        Vector(int sz = 0){
            if(!arr){
                arr_sz = sz;
                arr = new int[arr_sz];
            }
            if(sz != 0)
                fixed = true;
        }

        int* operator[] (int sz){
            return (arr + sz);
        }

        void pushBack(int val){
            if(fixed){
                cout << "Vector is of fixed size, please use [] operator instead. No changes have been made.\n";
                return;
            }
            arr = createArr(val);
        }

        void Delete(int idx){
            if(idx >= arr_sz){
                cout << "Index " << idx << " out of range, No changes have been made.\n";
                return;
            }
            arr = deleteElement(idx);
        }

        int Vsize(){
            return arr_sz;
        }

        void print(){
            for(int i = 0; i < arr_sz; i++)
                cout << arr[i] << " ";
            cout << '\n';
        }
};

int main()
{
    Vector vec(5);

    for(int i=0; i < 5; i++){
        vec.pushBack(i+1);
    }

    for(int i = 0; i < 5; i++){
        *vec[i] = i + 1;
    }

    vec.print();

    vec.Delete(2);  //new vec size = 4 , vec = {1, 2, 4, 5}
    vec.Delete(5);  //5 is out of range

    vec.print();
}
