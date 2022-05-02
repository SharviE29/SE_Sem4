//============================================================================
// Name        : Assignment7.cpp
// Author      : Sharvi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;
#define INT_MAX 2147483647
class Graph{
    int vernum;
    int edgenum;
    int **adj ;
    
    public:
    Graph()
    {
        vernum=0;
        edgenum=0;
        adj=nullptr;
    }
    Graph(int v,int e)
    {
        vernum=v;
        edgenum=e;
        adj=new int *[v];
        for(int i=0;i<v;i++)
        {
        	adj[i]=new int[v];
        	for(int j=0;j<v;j++)
        	{
        		adj[i][j]=0;//to avoid storing garbage values in the matrix
        	}
        }
        
    }
    void display();
    void acceptgraph();
    void prims();
};
void Graph::acceptgraph()
{
    int s,d;
    int w;
    for(int i=0;i<edgenum;i++)
    {
        cout<<"Enter the source vertex: ";
        cin>>s;
        cout<<"Enter the destination vertex: ";
        cin>>d;
        cout<<"Enter the weight: ";
        cin>>w;
        adj[s][d]=w;
        adj[d][s]=w;     
    }
}

