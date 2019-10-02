#include <iostream>
using namespace std;

int graph[100][100];
int path[100];
int t,n,m;

bool issafe(int v,int pos)
{
    if(graph[path[pos-1]][v] == 0)
        return false;
    for(int i=0;i<pos;i++)
        if(path[i] == v)
            return false;

    return true;
}

bool hamil(int pos)
{
    if(pos == n)
    {
        if(graph[path[pos-1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for(int v=1;v<n;v++)
    {
        if(issafe(v,pos))
        {
            path[pos] = v;
            if(hamil(pos+1))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

int main()
{
    cin>>t;
    while(t--)
    {
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<100;j++)
            {
                graph[i][j] = 0;
            }
            path[i] = -1;
        }
        cin>>n>>m;
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            graph[x][y] = 1;
            graph[y][x] = 1;
        }
        path[0] = 0;
        if(hamil(1))
        {
            for(int i=0;i<n;i++)
                cout<<path[i]<<" ";
            cout<<path[0]<<endl;
        }
        else
            cout<<"Cycle doesn't exist"<<endl;
    }
    return 0;
}