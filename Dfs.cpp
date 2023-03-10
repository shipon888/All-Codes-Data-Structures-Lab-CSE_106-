// DFS in C++
#include <bits/stdc++.h>
using namespace std;

vector<char> adj[10];
int visited[10];

// Add edge
void addEdge(vector<char> adj[], char s, char d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

void dfs(int nod)
{
    if (visited[nod])
        {   //printf("\t%d\t",visited[nod]);
            return;
        }
    //printf("%d\n",visited[nod]);
    visited[nod] = 1;
    cout << nod << "\t";

    for (int i = 0; i < adj[nod].size(); i++)
    {
        dfs(adj[nod][i]);
    }
}

int main()
{
    char V, E;
    int a, b;
    scanf("%d %d", &V, &E);

    for(int i=0; i<=E;i++)
        visited[i]=0;

    for (int i = 0; i < E; i++)
    {
        scanf("%c %c", &a, &b);
        addEdge(adj, a, b);
    }

    cout << "Printing graph using DFS:" << endl;
    dfs(1);
}

/**
7 7
1 2 3
1 5
2 3
2 5
3 4
4 5
4 6

7 7
A B C
A E
B C
B E
C D
D E
D F
*/
