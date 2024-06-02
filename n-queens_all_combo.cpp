#include <vector>
#include <set>
#include <string>
#include <iostream>

using namespace std;

bool col[10], row[10], diag1[20], diag2[20];;

void print(vector<string> board){
    for(auto i:board){
        cout<<i<<'\n';
    }
}
void dfs(vector<string>& cur, int n)
    {
        if (cur.size() == n)
        {
            print(cur);
            cout<<endl;
            return;
        }

        int i = cur.size();
        cur.push_back(string(n, '.'));
        for (int j = 0; j < n; j++)
        {
            if (!col[j] && !diag1[i - j + 8] && !diag2[i + j])
            {
                cur[i][j] = 'Q';
                col[j] = diag1[i - j + 8] = diag2[i + j] = true;
                dfs(cur, n);
                cur[i][j] = '.';
                col[j] = diag1[i - j + 8] = diag2[i + j] = false;
            }
        }

        cur.pop_back();
    }
void queen(int n){
    vector<string> board;
    dfs(board,n);
}
int main(){
    int n;
    cin>>n;
    queen(n);
    return 0;
}
