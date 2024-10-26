#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 图的表示，使用邻接表
class Graph {
public:
    Graph(int V); // 构造函数
    void addEdge(int v, int w); // 添加边
    void BFS(int s); // 广度优先搜索

private:
    int V; // 顶点数
    vector<vector<int>> adj; // 邻接表
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // 将w添加到v的邻接列表中
}

void Graph::BFS(int s) {
    vector<bool> visited(V, false); // 初始化所有节点为未访问
    queue<int> q; // 创建一个队列

    visited[s] = true; // 标记起始节点为已访问
    q.push(s); // 将起始节点入队

    while (!q.empty()) {
        s = q.front(); // 取出队首节点
        cout << s << " "; // 输出当前访问的节点
        q.pop(); // 移除队首节点

        // 访问所有未访问的邻居节点
        for (int i : adj[s]) {
            if (!visited[i]) {
                visited[i] = true; // 标记为已访问
                q.push(i); // 将邻居节点入队
            }
        }
    }
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "广度优先搜索(BFS)的结果是: ";
    g.BFS(2);

    return 0;
}
