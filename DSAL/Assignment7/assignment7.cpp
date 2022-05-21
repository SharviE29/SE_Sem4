/*
You have a business with several offices; you want to lease phone lines to connect
them up with each other; and the phone company charges different amounts of
money to connect different pairs of cities. You want a set of lines that connects all
your offices with a minimum total cost. Solve the problem by suggesting appropriate
data structures.
*/

#include<iostream>
using namespace std;
class Graph
{
   int a[10][10];
   int vertices;
   int edges;
   int weight;

   void addEdge(int u, int v, int w)
   {
      a[u][v] = w;
      a[v][u] = w;
   }

   public:
   Graph(int v,int e)
   {
        vertices = v;
        edges = e;
        weight = 0;
        for(int i=0;i<vertices;i++)
        {
             for(int j=0;j<vertices;j++)
             {
                a[i][j] = 0;
             }
        }
   }
   void displaygraph();
   void creategraph();
   void prims();
};

void Graph::creategraph()
{
    int source,destination,weight;
    for(int i=0;i<edges;i++)
    {
        cout<<"Enter the source: ";
        cin>>source;
        cout<<"Enter the destination: ";
        cin>>destination;
        cout<<"Enter the weight: ";
        cin>>weight;
        addEdge(source,destination,weight);
    }
}
void Graph::displaygraph()
{
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {   
              cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Graph::prims()
{
    int enumber=0;
    int visited[vertices];
    for(int i=0;i<vertices;i++)
    {
        visited[i]=false;
    }
    visited[0]=true;
    int minimum=9999999;
    int r=0;
    int c=0;
    while(enumber<vertices-1)//condition for a minimum spanning tree
    {
        minimum=9999999;
        r=0;
        c=0;

        for(int i=0;i<vertices;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<vertices;j++)
                {
                    if(!visited[j] && a[i][j])
                    {
                        if(minimum>a[i][j])
                        {
                            minimum=a[i][j];
                            r=i;
                            c=j;
                        }
                    }
                }
            }
        }
        cout<<r<<"--"<<c<<":"<<a[r][c];
        cout<<endl;
        visited[c]=true;
        enumber++;
    }
}

int main()
{
    int vertices,edges;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;
    cout<<"Enter the number of edges: ";
    cin>>edges;
    int ch;
    Graph g(vertices,edges);
    do
    {
        cout<<"1.Create graph"<<endl;
        cout<<"2.Display graph"<<endl;
        cout<<"3.Prims algorithm"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                g.creategraph();
                break;
            case 2:
                g.displaygraph();
                break;
            case 3:
                g.prims();
                break;
            case 4:
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
}while(ch!=4);
}