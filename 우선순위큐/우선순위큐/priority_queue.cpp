#include <stdio.h>
#include <functional>
#include <queue>

using namespace std;

int main() {
	
	// MAX HEAP
	priority_queue<int, vector<int>, less<int>> pq_max;

	for (int i = 0; i < 10; i++) {
		pq_max.push(i);
	}
	
	printf("MAX HEAP\n");
	while (!pq_max.empty()) {
		printf("%d\n", pq_max.top());
		pq_max.pop();
	}


	//MIN HEAP
	priority_queue<int, vector<int>, greater<int>> pq_min;
	
	for (int i = 0; i < 10; i++) {
		pq_min.push(i);
	}

	printf("MIN HEAP\n");
	while (!pq_min.empty()) {
		printf("%d\n", pq_min.top());
		pq_min.pop();
	}
	return 0;
}