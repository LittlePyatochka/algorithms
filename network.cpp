#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int parents[1000];

struct Cable
{
	int a;
	int b;
	int length;
};

bool cmp(Cable &left, Cable &right){ return left.length < right.length; }

int get_set(int hub){
	return hub == parents[hub] ? hub : parents[hub] = get_set(parents[hub]);
}

void unite_sets (int a, int b) {
	a = get_set (a);
	b = get_set (b);
	if (a != b)
		parents[a] = b;
}

int main(int argc, char const *argv[]){
	int n,m;
	Cable temp;
	vector<Cable> graph;
	vector<Cable> result;

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; ++i)
	{	
		scanf("%d%d%d", &temp.a, &temp.b, &temp.length);
		temp.a --; temp.b --;
		graph.push_back(temp);
	}

	sort(graph.begin(), graph.end(), cmp);
	for (int i = 0; i < n; ++i){ parents[i] = i; }

	for (Cable c: graph)
	{
		if(get_set(c.a) != get_set(c.b)){
			result.push_back(c);
			unite_sets(c.a,c.b);
		}	
	}

	printf("%d\n%d\n", result[result.size() - 1].length, result.size());
	for(Cable c : result){ printf("%d %d\n", c.a+1, c.b+1); }

	return 0;
}