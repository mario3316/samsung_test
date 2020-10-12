#include <stdio.h>
#include <queue>
#define MAX 11

using namespace std;

queue<pair<int,int>> q;
int MAP[MAX][MAX] = { 0, };
bool visited_bfs[MAX][MAX] = { false, };
bool visited_dfs[MAX][MAX] = { false, };

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

bool is_in(int nr, int nc) {
	if ((nr >= 0 && nr < MAX) && (nc >= 0 && nc < MAX))
		return true;
	else
		return false;
}


void BFS(int r, int c) {

	q.push(make_pair(r, c)); // ���۳�� push
	visited_bfs[r][c] = true; //queue�� push ������ ������ visited = true

	printf("BFS VISITED %d, %d\n", r, c);

	while (!q.empty()) { // ��� pop�Ͽ� queue�� ��尡 ������ ����

		pair<int,int> current = q.front();
		q.pop(); //���� ��� ������

		for (int i = 0; i < 4; i++) { // �����¿� 4���⿡ ����
			int nr = current.first + dr[i];
			int nc = current.second + dc[i];

			if (is_in(nr, nc) && !visited_bfs[nr][nc] && MAP[nr][nc] == 0) {
				q.push(make_pair(nr, nc));
				visited_bfs[nr][nc] = true;
				printf("BFS VISITED %d, %d\n", nr, nc);
			}
		}


	}

}

void DFS(int r, int c) {

	visited_dfs[r][c] = true;
	printf("DFS VISITED %d, %d\n", r, c); // ���� ���

	for (int i = 0; i < 4; i++) { // �����¿� 4���⿡ ����
		int nr = r + dr[i];
		int nc = c + dc[i];

		for (int i = 0; i < 4; i++) {
			if (is_in(nr, nc) && !visited_dfs[nr][nc] && MAP[nr][nc] == 0) { //���� �����ϸ� ��ͷ� DFS 
				DFS(nr, nc);
			}
		}
	}
}


int main(void) {

	printf("BFS START\n");
	BFS(0, 0);

	printf("DFS START\n");
	DFS(0, 0);

	return 0;
}