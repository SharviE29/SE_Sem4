//Topological sorting for directed graphs with no cycles

#include<iostream>
#include<queue>
#include "stacksandqueues.h"
using namespace std;
class Node1{
    
    int dvertex;
    Node1 *next;

    public:
    Node1()
    {
        dvertex=0;
        next=nullptr;
    }
    Node1(int v)
    {
        dvertex=v;
        next=nullptr;
    }
    friend class Graph;
};
class Graph{
   
    private:
    int vernum;
    int edgenum;
    Node1 **header;

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
        header=new Node1*[v];
        for(int i=0;i<v;i++)
        {
            header[i]=nullptr;
        }
    }
    void display();
    void acceptgraph();
    void topologicalsort();
};

void Graph::acceptgraph()
{
    int sour,dest;
    for(int i=0;i<edgenum;i++)
    {
        cout<<"Enter the source vertex: ";
        cin>>sour;
        cout<<"Enter the destination vertex: ";
        cin>>dest;
        Node1 *destNode1=new Node1(dest);
        if(header[sour]==nullptr)
        {
            header[sour]=destNode1;
        }
        else{
            Node1 *temp=header[sour];
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next=destNode1;

        }
    }
}
void Graph::display()
{
    for(int i=0;i<vernum;i++)
    {
        Node1 *temp=header[i];
        cout<<i<<"-->";
        while(temp!=nullptr)
        {
            cout<<temp->dvertex<<"-->";
            temp=temp->next;
        }
        cout<<endl;
    }
}
void Graph::topologicalsort()
{
    int *indegree=new int[vernum];
    for (int i=0;i<vernum;i++)
    {
        indegree[i]==0;     
    }
    for (int i=0;i<vernum;i++)
    {
        Node1 *temp=header[i];
        while(temp!=nullptr)
        {
            indegree[temp->dvertex]++;
            temp=temp->next;
        }
    }
    cout<<" *******************"<<endl;
    //displaying the indegree of the elements
    cout<<"Indegree of elements: "<<endl;
    for (int i=0;i<vernum;i++)
    {
        cout<<i<<"-->"<<indegree[i];
        cout<<endl;
    }
    //enqueing elements having an indegree 0
    Queue q(1000); 
    for (int i=0;i<vernum;i++)
    {
        if(indegree[i]==0)
        {
            q.enqueue(i);
        }
    }
    int topologicalorder[vernum];
    for (int i=0;i<vernum;i++)
    {
        topologicalorder[i]=0;
    }
    int k=0;
    while(!q.isEmpty())
    {
        int v=q.dequeue();
        topologicalorder[k]=v;
        k++;
        Node1 *temp=header[v];
        while(temp!=nullptr)
        {
            indegree[temp->dvertex]--;
            if(indegree[temp->dvertex]==0)
            {
                q.enqueue(temp->dvertex);
            }
            temp=temp->next;
        }
    }
    cout<<" *******************"<<endl;
    cout<<"Topological sort:"<<endl;
    //displaying the topological order
    for (int i=0;i<vernum;i++)
    {
        cout<<topologicalorder[i]<<" ";
        //cout<<endl;
    }
    cout<<endl;
}
int main()
{
    int v,e;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    cout<<"Enter the number of edges: ";
    cin>>e;
    Graph g(v,e);
    int ch;
    do{
        cout<<"************MENU***********\n1.Accept graph\n2.Display graph\n3.Topological sort\n4.Exit\nEnter your choice :";
        cin>>ch;
        switch(ch)
        {
            case 1:
                g.acceptgraph();
                break;
            case 2:
                cout<<"Following is the graph: "<<endl;
                g.display();
                break;
            case 3:
                g.topologicalsort();
                break;
            case 4:
                break;
            default:
                cout<<"Invalid choice\n";
        }

    }while(ch!=4);
    return 0;
}



