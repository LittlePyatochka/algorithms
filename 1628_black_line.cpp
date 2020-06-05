#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct badDay
{
	int x;
	int y;
};

bool cmp1(badDay left, badDay right) { return (left.x < right.x) || (left.x == right.x && left.y < right.y);}
bool cmp2(badDay left, badDay right) { return (left.y < right.y) || (left.y == right.y && left.x < right.x);}


int main(int argc, char const *argv[])
{
	int m,n,k; // m - строка, n - столбец
	badDay day;
	int result = 0;
	set<pair<int,int>> single; //одиночные точки точек
	
	cin >> m >> n >> k;
	std::vector<badDay> calendar (k);

	for (int i = 0; i < k; ++i)
	{
		cin >> day.x >> day.y;
		calendar.push_back(day);
	}

	for (int i = 1; i <= n; ++i)
	{
		day.x = 0;
		day.y = i;
		calendar.push_back(day);
		day.x = m+1;
		calendar.push_back(day);
	}
	for (int i = 1; i <= m; ++i)
	{
		day.x = i;
		day.y = 0;
		calendar.push_back(day);
		day.y = n+1;
		calendar.push_back(day);
	}

	sort(calendar.begin(), calendar.end(), cmp2);

	badDay last = calendar[0];
	int size;

	for(badDay temp: calendar){
		if(temp.y == last.y){ 
			size = temp.x - last.x - 1;
			if(size > 1) result++;
			if(size == 1) single.insert(make_pair(temp.x-1, temp.y));
		}
		last = temp;
	}

	sort(calendar.begin(), calendar.end(), cmp1);
	last = calendar[0];

	for(badDay temp: calendar){
		if(temp.x == last.x){
			size = temp.y - last.y - 1;
			if(size > 1 || (size == 1) && (single.find(make_pair(temp.x, temp.y-1)) != single.end() ) ) {
				result++;
			}
		
		}
		last = temp;
	}

	cout << result;
	return 0;
}