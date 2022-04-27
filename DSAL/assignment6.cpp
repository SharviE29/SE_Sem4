//============================================================================
// Name        : Assignment6.cpp
// Author      : Sharvi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//represent a graph using an adjacency list to perform dfs and bfs . Use the map of the area around the college as the graph. identify the prominent
//landmarks as nodes and perform dfs and bfs on that.

#include <iostream>
using namespace std;
class Node
{
	int dvertex;
	Node *next;
	
public:
	Node()
	{
		dvertex=0;
		next=nullptr;
	}
	Node(int v)
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
	Node **header;
	
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
		header=new Node *[v];
		for(int i=0;i<=v;i++)
		{
			header[i]=nullptr;
			
		}
	}
	//void acceptgraph(int,int,int,int);
	void display();
	void acceptgraph(int v,int e)
	{  
	   int sour,dest;
       for(int i=0;i<e;i++)
	   {
           cout<<"Enter the source vertex: ";
		   cin>>sour;
		   cout<<"Enter the destination vertex: ";
		   cin>>dest;
		   Node *temp=new Node(sour);
		   Node *destnode=new Node(dest);
		   destnode=temp->next;
		   if(header[i]==nullptr)
		   {
			   header[i]=temp;
		   }
		   else
		   {
			   Node *temp1=header[i];
			   while(temp1->next!=nullptr)
			   {
				   temp1=temp1->next;
			   }
			   temp1->next=destnode;
		   }
	   }
	}
};
// void Graph::acceptgraph(int v,int e,int s,int d)
// {   
// 	for(int i=0;i<e;i++)
// 	{
// 			Node *s1=new Node(s);
// 			Node *s2=new Node(d);
// 			if(header[i]==nullptr)//the source vertex isn't currently pointing to any destination vertex
// 			{
// 				header[i]=s1;
// 				header[i]->next=s2;
// 			}
// 			else
// 			{
// 				Node *temp=header[i];
// 				while(temp->next!=nullptr)
// 				{
// 					temp=temp->next;
// 				}
// 				temp->next=s2;
// 			}
// 	}	
// }
void Graph::display()
{
	for(int i=0;i<vernum;i++)
	{
		Node *temp=header[i];
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
	cout<<"Enter the number of vertices: "<<endl;
	cin>>v;
	cout<<"Enter the number of edges: "<<endl;
	cin>>e;
	Graph g(v,e);
	g.acceptgraph(v,e);
	g.display();
	return 0;
}
