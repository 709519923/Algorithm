#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
int w[MAXN][MAXN]; // 房间成本
int l; // 房间数
int maxCost; // 预算
bool vis[MAXN][MAXN]; // 标记数组
int ans = 0; // 最长路线长度

class MyClass {
public:
    MyClass() {
        res = 0;
    }
    int res;
};

void dfs(int x, int y, int cost, int len) {
    if (x < 0 || x >= l || y < 0 || y >= l) return; // 越界
    if (vis[x][y]) return; // 已经访问过
    if (cost + w[x][y] > maxCost) return; // 超出预算
    if (x == 0 || x == l-1 || y == 0 || y == l-1) { // 到达边界
        if (cost + w[x][y] == maxCost) ans = max(ans, len+1); // 刚好花完预算
        else ans = max(ans, len); // 没有花完预算
        return;
    }
    vis[x][y] = true; // 标记为已访问
    dfs(x+1, y, cost+w[x][y], len+1); // 向下走
    dfs(x-1, y, cost+w[x][y], len+1); // 向上走
    dfs(x, y+1, cost+w[x][y], len+1); // 向右走
    dfs(x, y-1, cost+w[x][y], len+1); // 向左走
    vis[x][y] = false; // 标记为未访问
}

int main() {
    MyClass myClass;
    cin >> maxCost >> l;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            cin >> w[i][j];
        }
    }
    myClass.res = 0;
    dfs(0, 0, myClass.res, 0); // 从(0,0)开始搜索
    if (ans == 0) cout << 0 << endl; // 不存在路线
    else cout << ans << endl; // 存在路线，输出最长路线长度
    return 0;
}