#include <iostream>
#include <string.h>
using namespace std;

#define MAX 20

int  n = 6;
char simpul[MAX] = {'A','B','C','D','E','F'};
int  adj[MAX][MAX];
int  jml_kunjungi;

int cariIndex(char c) {
    for (int k = 0; k < n; k++) {
        if (simpul[k] == c)
            return k;
    }
    return -1;
}


void bfs(int awal) {
    int visited[MAX] = {0};
    int queue[MAX];
    int depan = 0, belakang = 0;

    cout << "\nHasil BFS :" << endl;

    queue[belakang++] = awal;
    visited[awal]     = 1;
    jml_kunjungi      = 0;

    while (depan < belakang) {
        int node = queue[depan++];
        cout << simpul[node] << " ";
        jml_kunjungi++;

        for (int r = 0; r < n; r++) {
            if (adj[node][r] && !visited[r]) {
                visited[r]        = 1;
                queue[belakang++] = r;
            }
        }
    }
    cout << endl;
}

void dfs(int awal) {
    int visited[MAX] = {0};
    int stack[MAX];
    int top = -1;

    cout << "\nHasil DFS :" << endl;

    stack[++top] = awal;
    jml_kunjungi = 0;

    while (top != -1) {
        int node = stack[top--];

        if (!visited[node]) {
            visited[node] = 1;
            cout << simpul[node] << " ";
            jml_kunjungi++;

            for (int r = n - 1; r >= 0; r--) {
                if (adj[node][r] && !visited[r]) {
                    stack[++top] = r;
                }
            }
        }
    }
    cout << endl;
}

int main() {
    char awal_simpul;
    int  idx_awal;

    memset(adj, 0, sizeof(adj));

    adj[0][1] = adj[1][0] = 1; 
    adj[0][2] = adj[2][0] = 1; 
    adj[1][3] = adj[3][1] = 1; 
    adj[3][4] = adj[4][3] = 1; 
    adj[4][2] = adj[2][4] = 1; 
    adj[5][2] = adj[2][5] = 1; 

    cout << "Masukkan simpul awal : ";
    cin >> awal_simpul;

    idx_awal = cariIndex(awal_simpul);

    if (idx_awal == -1) {
        cout << "Simpul tidak ditemukan!" << endl;
        return 1;
    }

    bfs(idx_awal);
    dfs(idx_awal);

    cout << "\nJumlah simpul yang dikunjungi : " << jml_kunjungi << endl;

    return 0;
}