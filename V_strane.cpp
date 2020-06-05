#include <iostream>
using namespace std;
struct sign
{
    int value;
    int index;
};

swap(sign *arr, int i, int j){
    sign t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}


void makeHeap(sign *arr, int n, int i){
    int max = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if( (left < n) && (arr[left].value > arr[max].value) ){
        max = left;
    }
    if( (right < n) && (arr[right].value > arr[max].value) ){
        max = right;
    }
    if (max != i)
    {
        swap(arr, max, i); 
        makeHeap(arr, n, max);
    }
}

int main(int argc, char const *argv[])
{
    int min;
    int n;
    cin >> n;
    sign arr[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i].value;
        arr[i].index = i+1;
    }


    for (int i = n/2-1; i >= 0; --i){ makeHeap(arr,n,i); }

    while(arr[0].value != 0){

        cout << arr[0].index << " ";
        arr[0].value--;
        min = 1;
        if (n > 2)
        {
            if (arr[1].value < arr[2].value){ min = 2; }
        }

        if (arr[min].value != 0)
        {
            cout << arr[min].index << " ";
            arr[min].value--;
        }
        if (n>2){ makeHeap(arr,n,2); }
        makeHeap(arr,n,1);
        makeHeap(arr,n,0);
    }
    return 0;
}
