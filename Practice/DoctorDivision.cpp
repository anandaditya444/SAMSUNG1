#include <iostream>

using namespace std;


int N,E,T,start;
float adj_mat[1000][1000];
float finale[1000];

void go(int curr_node, float probab, int num_traversals){
    if(num_traversals==0){
        finale[curr_node]+=probab;
        return;
    }
    for(int i=0; i<N; i++){
        if(adj_mat[curr_node][i]>0){
            go(i, probab*adj_mat[curr_node][i], num_traversals-1);
        }
    }
}


void solution(){
    cin>>N>>E>>T;
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            adj_mat[i][j]=0;
        }
        finale[i]=0;
    }

    for(int i=0; i<E; i++){
        int U,V;
        float probab;
        cin>>U>>V>>probab;
        adj_mat[--U][--V]=probab;
    }
    cin>>start;

    int num_traversals = T/10;
    if(num_traversals==0){
        cout<<start<<endl;
        return;
    }
    for(int i=0; i<N; i++){
        if(adj_mat[start][i]>0)
            go(i, adj_mat[start][i], num_traversals-1);
    }
    float max_probab=0;
    int idx=start;
    for(int i=0; i<N; i++){
        cout<<finale[i]<<" ";
        if(finale[i]>max_probab){
            idx=i;
            max_probab=finale[i];
        }
    }
    if(max_probab==0)
        cout<<"\nFinal Destination : Exit Lab"<<endl;
    else
        cout<<"\nFinal Destination : "<<max_probab<<" "<<idx+1<<endl;
}

int main(){
    int test_cases;
    cin>>test_cases;
    while(test_cases>0){
        test_cases--;
        solution();
    }
    return 0;
}