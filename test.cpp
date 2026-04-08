#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<vector<int>> graph;
vector<vector<int>> inverse_graph;
vector<bool>        visited;
vector<int>         order;      // 첫 번째 DFS 종료 순서
vector<int>         comp_id;    // 각 정점이 속한 SCC 번호
vector<vector<int>> components; // SCC 목록

// ----------------------------------
// TODO 1. 첫 번째 DFS
// 역할:
// 1) 현재 정점 방문 처리
// 2) 원래 그래프(graph)로 DFS 진행
// 3) 탐색이 끝난 뒤 order에 현재 정점 추가
// ----------------------------------
void dfs1(int cur) {
}

// ----------------------------------
// TODO 2. 두 번째 DFS
// 역할:
// 1) 현재 정점 방문 처리
// 2) 현재 SCC 번호(id) 기록
// 3) 현재 SCC 목록에 정점 추가
// 4) 역그래프(revGraph)로 DFS 진행
// ----------------------------------
void dfs2(int cur, int id) {
}

// ----------------------------------
// SCC 구성
// ----------------------------------
void buildSCC() {
    // 1. 첫 번째 DFS
    for (int v = 1; v <= n; v++) {
        // ???
    }

    fill(visited.begin(), visited.end(), false);
    reverse(order.begin(), order.end());

    int sccCount = 0;

    // 두 번째 DFS
    for (int v: order) {
        if (!visited[v]) {
            // ???
            sccCount++;
        }
    }
}

// ----------------------------------
// 결과 출력
// ----------------------------------
void printSCC() {
    cout << "SCC 개수: " << components.size() << '\n';

    for (int i = 0; i < (int)components.size(); i++) {
        cout << "SCC #" << i << ": ";
        for (int v: components[i]) {
            cout << v << ' ';
        }
        cout << '\n';
    }

    cout << "\n각 정점의 SCC 번호\n";
    for (int v = 1; v <= n; v++) {
        cout << v << " -> " << comp_id[v] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    graph.assign(n + 1, {});
    inverse_graph.assign(n + 1, {});
    visited.assign(n + 1, false);
    comp_id.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        inverse_graph[v].push_back(u);
    }

    buildSCC();
    printSCC();

    return 0;
}