#include <iostream>
#include "stacksandqueues.h"
using namespace std;
class Node1
{
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
		header=nullptr;
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
	void acceptgraph()
	{
	   int sour,dest;
       for(int i=0;i<edgenum;i++)
	   {
           cout<<"Enter the source vertex: ";
		   cin>>sour;
		   cout<<"Enter the destination vertex: ";
		   cin>>dest;
		   //Node1 *temp=new Node1(sour);
		   Node1 *destNode1=new Node1(dest);
		   //temp->next=destNode1;
		   if(header[sour]==nullptr)
		   {
			   header[sour]=destNode1;
		   }
		   else
		   {
			   Node1 *temp1=header[sour];
			   while(temp1->next!=nullptr)
			   {
				   temp1=temp1->next;
			   }
			   temp1->next=destNode1;
		   }
	   }
	}
	void BFS(int);
	void DFS(int);
};

void Graph::BFS(int startver)
{
  Queue q(1000);
  int *visited=new int[vernum];
  for(int i=0;i<vernum;i++)
	  {
	     visited[i]=0;
	  }
  visited[startver]=1;
  q.enqueue(startver);
  while(!q.isEmpty())
  {
	  int v=q.dequeue();
	  cout<<v<<" ";
	  Node1* temp=header[v];
	  while(temp!=nullptr)
	  {
		  if(visited[temp->dvertex]==0)
		  {
			  q.enqueue(temp->dvertex);
			  visited[temp->dvertex]=1;
		  }
		  temp=temp->next;
	  }
  }
  cout<<endl;
}
void Graph::DFS(int startver)
{
  Stack s(1000);
  int *visitednew=new int[vernum];
  for(int i=0;i<vernum;i++)
	  {
	     visitednew[i]=0;
	  }
  visitednew[startver]=1;
  s.push(startver);
  while(!s.isEmpty())
  {
	  int v=s.pop();
	  cout<<v<<" ";
	  Node1* temp=header[v];
	  while(temp!=nullptr)
	  {
		  if(visitednew[temp->dvertex]==0)
		  {
			  s.push(temp->dvertex);
			  visitednew[temp->dvertex]=1;
		  }
		  temp=temp->next;
	  }
  }
  cout<<endl;
}
void Graph::display()
{
	for(int i=0;i<vernum;i++)
	{
		Node1 *temp=header[i];
		cout<<i<<": ";
		while(temp!=nullptr)
		{
			cout<<temp->dvertex<<"->";
			temp=temp->next;
		}
		cout<<endl;
	}
}
int main() {
	int v,e;
	int start;
	cout<<"Enter the number of vertices: ";
	cin>>v;
	cout<<"Enter the number of edges: ";
	cin>>e;
	int ch;
	Graph g(v,e);
	do
	{
		cout<<"******MENU******\n1.Accept graph\n2.Display graph\n3.BFS\n4.DFS\n5.Exit\nEnter you choice\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			g.acceptgraph();
			break;
		case 2:
			g.display();
			break;
		case 3:
			cout<<"Enter the starting vertex: ";
			cin>>start;
			g.BFS(start);
			break;
		case 4:
			cout<<"Enter the starting vertex: ";
			cin>>start;
			g.DFS(start);
			break;
		case 5:
		    cout<<"Exiting.....";
			break;
		}
	} while (ch!=5);
	return 0;
}
