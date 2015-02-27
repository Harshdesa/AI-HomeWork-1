#include<iostream>
#include<conio.h>
#include <fstream>
#include <string>
#include<stdio.h>
#include "Functions.h"
using namespace std;

/* This is program is created by Harsh Desai. */

int main(int argc,char* argv)
{
	cout<<"hello";
	Header h;
	h.a=5;
	cout<<endl<<h.a;
	int **A;
	int option,option2; int vertex; 
	Graph g(6);
	cout<<"Which File do you want to select? 1. Figure 1  OR 2. Figure 2"<<endl;
	cin>>option;
	if(option==1)
	{
	
	g.readFromFileandStoreasGraph("Input1.txt");
	}
	if(option==2)
	{
		g.readFromFileandStoreasGraph("Input2.txt");
	}
	g.display();
	cout<<"Which implementation? 1. BFS OR 2. DFS"<<endl;
	cin>>option2;
	if(option2==1)
	{
		if(option==1)
			g.BFS(0,8);
		if(option==2)
			g.BFS(0,10);
	}
	if(option2==2)
	{
		if(option==1)
			g.DFS(0,8);
		if(option==2)
			g.DFS(0,10);
	}
	getchar();
	getchar();
	getchar();
	return 0;
}