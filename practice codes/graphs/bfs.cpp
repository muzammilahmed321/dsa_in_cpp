#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class graph{
int v;
list <int> *l;
public:
graph(int v)
{
this->v=v;
l=new list<int> [v];
}
void addEdge(int u,int v){
l[u].push_back(v);
l[v].push_back(u);
}
//bfs traversal
void bfs(){
queue<int>q;
vector<bool> vis(v,false);
q.push(0);
vis[0]=true;
while(q.size()>0){

    int u=q.front();
    q.pop();
    cout<<u<<" ";
    for(int v:l[u]){
        if(!vis[v]){
            vis[v]=true;
            q.push(v);
        }
    }
}
cout<<endl;
}
void dfshelp(int u, vector<bool> &vis){
    cout<<u<<",";
    vis[u]=true;
    for(int v:l[u]){
       if(!vis[v]){
        dfshelp(v,vis);
       }

    }


}
void dfs(){
    int src=0;
vector<bool> vis(v,false);
dfshelp(src,vis);

}

};
int main(){

graph g(5);
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(1,3);
g.addEdge(2,3);
g.addEdge(2,4);
//g.bfs();
cout<<endl;
g.dfs();


}
