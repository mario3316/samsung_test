#include <stdio.h>
#include <queue>

using namespace std;

typedef struct guest {
	int sr, sc;
	int tr, tc;
	bool is_end;
}guest;

int N, M, F;
int MAP[21][21];
int visited[21][21];
int start_r, start_c;
vector<guest> G;

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };


bool is_in(int nr, int nc) {
	if ((nr >= 0 && nr < N) && (nc >= 0 && nc < N)) 
		return true;
	else
		return false;
}

int calc_dist(int r, int c, int target_r, int target_c){
	fill(&visited[0][0], &visited[20][21], 0);
	queue<pair<int, int>> q;

	if (r == target_r && c == target_c)
		return 0;

	q.push(make_pair(r, c));
	visited[r][c]= 1;

	while (!q.empty()) {
		pair<int, int> current = q.front();
		if (current.first == target_r && current.second == target_c) {
			return visited[target_r][target_c]-1;// 방문한 노드가 target노드 이면 Return
		}
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = current.first + dr[i];
			int nc = current.second + dc[i];

			if (is_in(nr, nc) && !visited[nr][nc] && MAP[nr][nc] == 0) {
				q.push(make_pair(nr, nc));
				visited[nr][nc] = visited[current.first][current.second] +1;
			}
		}
	}
	return -1;
}

bool is_complete() {
	for (int i = 0; i < M; i++) {
		if (!G[i].is_end) {
			return false;
		}
	}
	return true;
}

int solve() {

	while (1) {

		int min = 10000000;
		int node = 0; // 다음으로 방문할 승객

		for (int i = 0; i < M; i++) {

			if (!G[i].is_end) {
				int dist = calc_dist(start_r, start_c, G[i].sr, G[i].sc);
				if (dist == -1)
					return -1;

				if (dist < min) {
					node = i;
					min = dist;
				}
				else if (dist == min) { // 거리가 같을때 우선순위
					if (G[i].sr < G[node].sr) {
						node = i;
						min = dist;
					}
					else if (G[i].sc < G[node].sc) {
						node = i;
						min = dist;
					}
				}
			}
		}

		int used_fuel = calc_dist(start_r, start_c, G[node].sr, G[node].sc);
		if (used_fuel == -1)
			return -1;
		F -= used_fuel;
		if (F <= 0)
			return -1;
		start_r = G[node].sr;
		start_c = G[node].sc;
		// 태우러 가기

		used_fuel = calc_dist(start_r, start_c, G[node].tr, G[node].tc);
		if (used_fuel == -1)
			return -1;
		F -= used_fuel;
		if (F < 0)
			return -1;
		G[node].is_end = true;
		F += used_fuel * 2;
		start_r = G[node].tr;
		start_c = G[node].tc;
		// 내려주기

		if (is_complete()) {
			return F;
		}
	}
}

int main(void) {
	fill(&visited[0][0], &visited[20][21], 0);
	// 초기화

	scanf("%d %d %d", &N, &M, &F);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &MAP[i][j]);
		}
	} // MAP 입력

	scanf("%d %d", &start_r, &start_c);
	start_r--;
	start_c--;

	for (int i = 0; i < M; i++) {
		guest temp;
		scanf("%d %d %d %d", &temp.sr, &temp.sc, &temp.tr, &temp.tc);
		G.push_back(temp);
	}

	for (int i = 0; i < M; i++) {
		G[i].is_end = false;
		G[i].sr--;
		G[i].sc--;
		G[i].tr--;
		G[i].tc--;
	}

	printf("%d", solve());

	return 0;
}