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
		for(int i=0;i<(v-1);i++)
		{
			header[i]=nullptr;
			
		}
	}
	void acceptgraph(int,int);
	void display();
};
void Graph::acceptgraph(int v,int e)
{   
	int s,d;
	for(int i=0;i<e;i++)
	{
		
			cout<<"Enter the source vertex: "<<endl;
			cin>>s;
			cout<<"Enter the destination vertex:"<<endl;
			cin>>d;
			Node *n=new Node[d];
			if(header[i]==nullptr)//the source vertex isn't currently pointing to any destination vertex
			{
				header[i]=n;
			}
			else
			{
				Node *temp=header[i];
				while(temp->next!=nullptr)
				{
					temp=temp->next;
				}
				temp->next=n;
			}
	}
   
	
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
