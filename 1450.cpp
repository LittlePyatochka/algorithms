#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

 int solve(int** graph, int n, int a, int final, int *length){

 	if (length[a] >= 0) return length[a];
 	int after = 0;

 	for (int i = 0; i < n; ++i)
 	{
 		if(length[i] == 0 || graph[a][i] == 0) continue;
 		if(i == final) after = max(after, graph[a][i]);
 		 else {
 		 	int after_b = solve(graph, n, i, final, length);
 		 	after_b = after_b > 0 ? after_b + graph[a][i] : 0;
 		 	after = max(after, after_b); 
 		 }
 	}
 	length[a] = after;
 	return after;
}

int main(int argc, char const *argv[]){
	int n,m,start, final;
	int temp_a, temp_b, temp_cost;
	int **graph;

	scanf("%d%d", &n, &m);
	graph = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		graph[i] = new int[n];
		fill(graph[i],graph[i]+n,0);
	}

	int length[n];
	fill(length,length+n,-1);

	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &temp_a, &temp_b, &temp_cost);
		temp_a --; temp_b --;
		graph[temp_a][temp_b] = temp_cost;
	}

	scanf("%d%d", &start, &final);
	start--; final--;

	m = solve(graph, n, start, final, length);
	m <= 0 ? printf("%s", "No solution") : printf("%d", m);

	return 0;
}