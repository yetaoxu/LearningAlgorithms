//
// Created by xuyetao on 2020/7/23.
//

#include <iostream>

using namespace std;

int p[10] = {0};
bool vis[10] = {false};
int n;

void dfs(int x) {
    if (x == n + 1) {
        for(int i = 1; i <= n; i++)
            cout << p[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {  //  在全排列的代码基础上,如果要求是顺序输出，则要剪枝,（只需要加一句代码) if (vis[i] == false && i > p[x])
            p[x] = i;
            vis[i] = true;
            dfs(x + 1);
            vis[i] = false;
        }
    }
}

int main() {
    while (cin >> n) {
        dfs(1);
    }
    return 0;
}

