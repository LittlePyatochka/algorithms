#include <iostream>
#include <math.h>

using namespace std;

void coloring( int start, int n,int **graph, int *result, int temp, bool *flag){
	if(flag){return;}
	if(temp == 0){ temp=1; }else{ temp = 0; }
	for (int i = 0; i < n; ++i)
	{	
		if(graph[start][i] > 0){
			if(result[i] >= 0 && ){ 
				if(result[i] != temp){ *flag = false; }
				continue;
			}
			result[i] = temp;
			coloring(i, n, graph, result, temp, flag);
		}
	}
}

int main(int argc, char const *argv[]){
	int n,temp;
	string res;
	cin >> n;
	if (n == 0)
	{
		cout << -1;
		return 0;
	}
	int result[n];
	int ** graph;
	bool flag = true;

	graph = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		graph[i] = new int[n];
		fill(graph[i],graph[i]+n,0);
	}

	fill(result,result+n,-1);

	for (int i = 0; i < n; ++i)
	{
		while(true){
			cin >> temp;
			if(temp == 0) break;
			graph[i][temp-1] = 1;
			graph[temp-1][i] = 1;
		}
	}

	result[0] = 0;
	coloring(0, n, graph, result, 0, &flag);

	if(flag){
		for (int i = 0; i < n; ++i)
		{
			cout << result[i];
		}
	}else{
		cout<<-1;
	}
	return 0;
}
