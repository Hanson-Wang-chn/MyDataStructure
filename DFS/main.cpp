#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 图的表示，使用邻接表
class Graph {
public:
    Graph(int V); // 构造函数
    void addEdge(int v, int w); // 添加边
    void DFS(int v); // 深度优先搜索

private:
    int V; // 顶点数
    vector<vector<int>> adj; // 邻接表
    void DFSUtil(int v, vector<bool> &visited); // 辅助函数
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // 将w添加到v的邻接列表中
}

void Graph::DFSUtil(int v, vector<bool> &visited) {
    visited[v] = true; // 标记当前节点为已访问
    cout << v << " "; // 输出当前访问的节点

    // 递归访问所有未访问的邻居节点
    for (int i : adj[v]) {
        if (!visited[i]) {
            DFSUtil(i, visited);
        }
    }
}

void Graph::DFS(int v) {
    vector<bool> visited(V, false); // 初始化所有节点为未访问
    DFSUtil(v, visited); // 从给定的起始节点开始DFS
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "深度优先搜索(DFS)的结果是: ";
    g.DFS(2);

    return 0;
}
