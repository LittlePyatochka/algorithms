#include <iostream>
#include <algorithm>
using namespace std;

const double BIG_NUMBER = 1e+40;

struct coor
	{
		int x;
		int y;
		int index;
		double tang;
	};

// void bubble_sort(coor*a, int n){
//     bool swap=true;
//     while(swap){
//         swap=false;
//         --n;
//         for(int i=1; i < n; ++i){
//             if(a[i+1].tang < a[i].tang){
//                 coor t = a[i];
//                 a[i] = a[i+1];
//                 a[i+1] = t;
//                 swap=true;
//             }
//         }
//     }
// }



void sort(coor * arr, int n){
	int min;
	double min_val;
for (int i = 1; i < n; ++i)
	{
		min = i;
		min_val = arr[min].tang;
		for (int j = i; j < n; ++j)
		{
			if (arr[j].tang < min_val){
				min_val = arr[j].tang;
				min = j;
			}
		}
				coor t = arr[i];
                arr[i] = arr[min];
                arr[min] = t;
	// swap(arr, min, i);
	}
}

// bool coor_cmp(const coor coor1, const coor coor2) {
// // int coor_cmp(const void  * c1, const void * c2) {
// 	// coor coor1 = *(coor*)c1;
// 	// coor coor2 = *(coor*)c2;
// 	// if (coor1.tang > coor2.tang) return 1;
// 	return (coor1.tang < coor2.tang);
// 	// return 0;
// }


int main(int argc, char const *argv[])
{
	int n;
	// coor min;
	int min_i;
	cin >> n;
	coor dot[n];

	for (int i = 0; i < n; ++i)
    {
    	

        cin >> dot[i].x;
        cin >> dot[i].y;
        dot[i].index = i;

        if(i==0){
    		// min = dot[0];
    		min_i = 0;	
    	}

        if (dot[i].x < dot[min_i].x)
    		// min = dot[i];
    		min_i = i;
    }

    // cout << endl << " min y " << min.y;
    // coor t;
    coor t = dot[0];
    dot[0] = dot[min_i];
    dot[min_i] = t;
    // min = dot[0];
    // dot[min.index] = dot[0];
    // dot[0] = min;

    for (int i = 1; i < n; ++i)
    {
    	if (dot[0].x !=dot[i].x)
    	{
    		// dot[i].tang = (double)((min.y-dot[i].y)/(min.x-dot[i].x));
    		dot[i].tang = (double)((dot[i].y-dot[0].y)/(dot[i].x-dot[0].x));
    	} else {
    		dot[i].tang = dot[i].y >dot[0].y ? BIG_NUMBER : (-1)*BIG_NUMBER;
    	}
    }
    // 	for (int i = 1; i < n; ++i){
    //  		cout << dot[i].tang<<" ";
    // 	}
    // for (int i = 1; i < n; ++i){
    //  	cout << dot[i].index<<" ";
    //  }
    // 	cout << endl;
    //  bubble_sort(dot,n);


	sort(dot,n);

    // sort(dot, dot + n, coor_cmp);
    // qsort(dot, n, sizeof(coor), coor_cmp);

     // for (int i = 1; i < n; ++i){
     // 	cout << dot[i].tang<<" ";
     // }
     // for (int i = 1; i < n; ++i){
     // 	cout << dot[i].index<<" ";
     // }	     
     //  cout << endl;
    // for (int i = 1; i < n - 1; i++) {
    //     for (int j = 1; j < n - i - 1; j++) {
    //         if (dot[j].tang > dot[j + 1].tang) {
    //             temp = dot[j];
    //             dot[j] = dot[j + 1];
    //             dot[j + 1] = temp;
    //         }
    //     }
    // }

    cout << dot[0].index+1 <<" "<< dot[n/2].index+1;
	return 0;
}