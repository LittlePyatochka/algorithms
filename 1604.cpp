#include <iostream>
#include <algorithm>
using namespace std;

int cmp(const void * x1, const void * x2) { return (*(long*)x1 - *(long*)x2); }

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
    qsort(x, n, sizeof(long long), cmp);
	qsort(y, n, sizeof(long long), cmp);
    for (int i = 1; i < n; ++i)
    {
    	 summ_way += (x[i] - x[i-1])*(i*(n-i)*2);
    	 summ_way += (y[i] - y[i-1])*(i*(n-i)*2);
    	// for (int j = 0; j < n; ++j)
    	// {
    	// 	if (i != j)
    	// 	{
    	// 		summ_way += abs(x[j]-x[i]);
    	// 		summ_way += abs(y[j]-y[i]);
    	// 	}
    	// }
    }
    summ_way = summ_way/(n*(n-1));
    // res = summ_way;
    cout << summ_way;
	return 0;
}