#include <iostream>
#include <algorithm>
using namespace std;

//int cmp(const void * x1, const void * x2) { return (*(long*)x1 - *(long*)x2); }

swap(long long *arr, long long i, long long j){
	long long t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void qsort(long long *arr, long long n, long long a, long long b){
	long long left = a;
	long long right = b;
	long long prop = arr[(left+right)/2];
	while(left <= right){
		while(arr[left] < prop){ left++; }
		while(arr[right] > prop){ right--; }
		if (left <= right)
		{
			swap(arr,left, right);
			left++;
			right--;
		}
	}
	if (a<right)
	{
		qsort(arr,n,a,right);
	}
	if (b>left)
	{
		qsort(arr,n,left,b);
	}

}

int main(int argc, char const *argv[])
{
	unsigned long long summ_way = 0l;
	long long n, x[100005], y[100005];
	cin >> n;


	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
		cin >> y[i];
	}
	// qsort(x, n, sizeof(long long), cmp);
	// qsort(y, n, sizeof(long long), cmp);
	qsort(x,n,0,n-1);
	qsort(y,n,0,n-1);

	for (int i = 1; i < n; ++i)
	{
		summ_way += (x[i] - x[i-1])*(i*(n-i)*2);
		summ_way += (y[i] - y[i-1])*(i*(n-i)*2);

	}
	summ_way = summ_way/(n*(n-1));
    // res = summ_way;
	cout << summ_way;
	return 0;
}