#include<iostream>
#include<vector>
#include<queue>

using namespace std; 

void printGraph(vector<int>g[], int n) {
    for(int i = 1; i<=n;i++){
        cout<<i<<" is connected to: ";
        for (int j = 0; j<g[i].size();j++)
            cout << g[i][j] << " ";
        cout<<endl;
    }
    cout<<"*********************\n";
}
void bfs(vector<int>g[],int n,int s){
    bool disc[n+1]= {false};  //is discovered array of nodes
    disc[s] = true;         // setting root node as discovered
    queue<int> l ;       // make a queue of nodes discovered;   
    l.push(s);               // pushing root as first node discovered in queue           
    cout<<"bfs is: ";
    while(!l.empty()){
        cout<<l.front()<<" ";
        for(int j = 0;j<g[l.front()].size();j++){
            if(disc[g[l.front()][j]] == false){
                l.push(g[l.front()][j]);
                disc[g[l.front()][j]] = true;
            }
        }
        l.pop();        
    }
}

int main()
{
    int n=8, m,r;
    cout<<"Enter the number of nodes and edeges respectively: ";
    cin>>n>>m;
    cout<<"Enter the root node: ";
    cin>>r;
    vector<int> g[9];  // decalring a adjacency list and marking the edges
    for(int i = 0; i<11;i++){
        int x, y;
        cout<<"Enter the edges: ";
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // g[1].push_back(2);
    // g[2].push_back(1);
    // g[1].push_back(3);
    // g[3].push_back(1);
    // g[2].push_back(3);
    // g[3].push_back(2);
    // g[2].push_back(5);
    // g[5].push_back(2);
    // g[2].push_back(4);
    // g[4].push_back(2);
    // g[4].push_back(5);
    // g[5].push_back(4);
    // g[5].push_back(6);
    // g[6].push_back(5);
    // g[5].push_back(3);
    // g[3].push_back(5);
    // g[3].push_back(7);
    // g[7].push_back(3);
    // g[3].push_back(8);
    // g[8].push_back(3);
    // g[7].push_back(8);
    // g[8].push_back(7);
    printGraph(g,n);  
    bfs(g,n,1);
    return 0;
}

