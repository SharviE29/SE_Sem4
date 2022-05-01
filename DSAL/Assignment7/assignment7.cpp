//to implement prims and kruskals algorithm

#include<iostream>
using namespace std;
#define INT_MAX 2147483647
class Graph{
    int vernum;
    int edgenum;
    int adj [100][100];
    
    public:
    Graph()
    {
        vernum=0;
        edgenum=0;
    }
    Graph(int v,int e)
    {
        vernum=v;
        edgenum=e;
        
    }
    void display();
    void acceptgraph();
};
void acceptgraph(int v,int e)
{
    int s,d;
    int graph [v][e];
    int w;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter the source vertex: ";
        cin>>s;
        cout<<"Enter the destination vertex: ";
        cin>>d;
        cout<<"Enter the weight: ";
        cin>>w;
        graph[s][d]=w;
        graph[d][s]=w;    
    }
}
