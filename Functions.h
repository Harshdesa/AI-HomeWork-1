#include<iostream>
#include<conio.h>
#include <fstream>
#include<cstdio>
#include <string>
#include<stdio.h>

using namespace std;
int solution=1;
class Header{
	public: int a;

};

struct node {
    char info;
    node *next;
}; 
struct node1{
	int info;
    node1 *next;
};
class Queue 
{
	 private:
        node *front;
        node *rear;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(char);
        char dequeue();
        void display(); 
};

void Queue::display(){
    node *p = new node;
    p = front;
    if(front == NULL){
        cout<<"nNothing to Displayn";
    }else{
        while(p!=NULL){
            cout<<endl<<p->info;
            p = p->next;
        }
    }
} 
 
Queue::Queue() {
    front = NULL;
    rear = NULL;
} 
 
Queue::~Queue() {
    delete front;
} 
 
void Queue::enqueue(char data) {
    node *temp = new node();
    temp->info = data;
    temp->next = NULL;
    if(front == NULL){
        front = temp;
    }else{
        rear->next = temp;
    }
    rear = temp;
} 
 
char Queue::dequeue() {
    node *temp = new node();
    char value;
    if(front == NULL){
        cout<<"nQueue is Emtptyn";
    }else{
        temp = front;
        value = temp->info;
        front = front->next;
        delete temp;
    }
    return value;
} 
 
bool Queue::isEmpty() {
    return (front == NULL);
} 


class Stack
{
private:
	node1 *top;
public:
	Stack();
	~Stack();
	bool isEmpty();
	void push(int);
	int pop();
	void display();
};
void Stack::display()
{
	node1* p=new node1();
	p=top;
	if(top==NULL)
		cout<<"Nothing to display"<<endl;
	else 
	{
		while(p!=NULL)
		{
			cout<<p->info;
			p=p->next;
		}
	}


}
Stack::Stack()
{
top=NULL;
}
Stack::~Stack()
{
	delete top;
}
void Stack::push(int data)
{
	node1 *temp=new node1();
	node1 *temp2=new node1();
	temp->info=data;
	temp->next=NULL;			//back
	if(top==NULL)
	{
		top=temp;
	}else 
	{temp2=top;

					
		top=temp;
		top->next=temp2;			//back
	}
	
}
int Stack::pop()
{
	node1 *temp=new node1();
	int value;
	if(top==NULL)
	{
		cout<<"Stack is empty"<<endl;
	}
	else
	{
		temp=top;
		value=temp->info;
		top=top->next;			//Back value
		delete temp;

	}
	return value;
}
bool Stack::isEmpty(){
	return (top == NULL);
}
struct TreeNode
{
	TreeNode *parent;			
	TreeNode *sibling1;			//front
	TreeNode *sibling2;			// rear
	int childnum;
	int val;
	TreeNode *children[];
	TreeNode(int value):val(value),childnum(0){}
};

class Tree
{ 
public:
	TreeNode *root;
	Tree(int size=2);
	void insertNode(TreeNode *newNode,int value);
	void insertNode(int value);
	int checkIfNodeCanBeInserted(TreeNode* Node,int value);
	TreeNode* checkTillSiblingHasChildren(TreeNode *node);
	void printSolution(TreeNode *node);
	void printSolutionDFS(TreeNode *node,int option);
	char convertBackToChar(TreeNode *node);
	void printExpandedFirstSolution(TreeNode *node,int option);
};

Tree::Tree(int size)
{
	root=NULL;
	return;
}

char Tree::convertBackToChar(TreeNode *node)
{
	if(node->val==0)
		return 'A';
	if(node->val==1)
		return 'B';
	if(node->val==2)
		return 'C';
	if(node->val==3)
		return 'D';
	if(node->val==4)
		return 'E';
	if(node->val==5)
		return 'F';

}

void Tree::insertNode(int value)
{
	if (root == NULL)
		root = new TreeNode(value);
	else
		insertNode(root, value);	

}

void Tree::insertNode(TreeNode *node,int value)
{
	node->children[node->childnum]= new TreeNode(value);
	node->children[node->childnum]->parent=node;
	node->childnum++;
}

int Tree::checkIfNodeCanBeInserted(TreeNode *node,int value)
{
	int array1[20][20];
	array1[value][node->val]=1;
	array1[node->val][value]=1;
	while(node->parent!=NULL)
	{
		if((array1[node->val][node->parent->val]==1)||(array1[node->parent->val][node->val]==1))
		{
			return 0;
			cout<<"Cancel"<<endl;
		}
		//cout<<value<<'\t'<<node->val<<endl;
		array1[node->parent->val][node->val]=1;
		array1[node->val][node->parent->val]=1;
		//cout<<"hello"<<endl;
		node=node->parent;
	}

	return 1;


}

TreeNode* Tree::checkTillSiblingHasChildren(TreeNode* node)
{
	//cout<<"hello";
	while(node->childnum==0)
	{
		node=node->sibling1;
		if(node==NULL)
		{
			return NULL;
		}
	}
	//cout<<"Node value"<<node->val;
	int g=node->childnum;
	g=g-1;
	//cout<<"g"<<g<<endl;
	//cout<<node->children[g]->val<<endl;
	return node->children[g];
}

void Tree::printSolution(TreeNode *node)
{
	char a[15];
	int i=1;
	//cout<<convertBackToChar(node);
	a[0]=convertBackToChar(node);
	while(node->parent!=NULL)
	{
		node=node->parent;
		a[i]=convertBackToChar(node);
		i++;
		//cout<<convertBackToChar(node);
	}
	for(int c=i-1;c>=0;c--)
	{
		cout<<a[c];

	}
	cout<<endl;

}
void Tree::printSolutionDFS(TreeNode *node,int option)				// Also include parameter for number of sides counted
{
	char a[15];
	int i=1;
	
	TreeNode* node2;
	node2=node;
	int count=0;
	while(node->parent!=NULL)
	{
		node=node->parent;
		count++;
		//cout<<node->val;
	}
	if(count==option)
	{
		
		node=node2;
		//cout<<convertBackToChar(node);
		a[0]=convertBackToChar(node);
		while(node->parent!=NULL)
		{
			node=node->parent;
			a[i]=convertBackToChar(node);
			i++;
			//cout<<convertBackToChar(node);
		}
		for(int c=i-1;c>=0;c--)
		{
			cout<<a[c];

		}
		cout<<"Solution Number: "<<solution<<endl;
		solution++;
	}
	//cout<<endl;

}

void Tree::printExpandedFirstSolution(TreeNode *node,int option)
{
	int count=0;
	cout<<"The nodes expanded :"<<endl;
//	cout<<node->val;
	while(1)
	{
		while(node->sibling2!=NULL)
		{
			cout<<convertBackToChar(node);
		node=node->sibling2;
		
		}
		cout<<convertBackToChar(node);
	while(node->sibling1!=NULL)
	{
		node=node->sibling1;
	}
	
	while(node->childnum==0)
	{
		node=node->sibling2;
	}
	node=node->children[0];

	count++;
	if(count==option)
	{
		break;
	}
	}
}

class Graph {
    private:
        int n;
        int **A;
    public:
		int nodesexpanded[100];
        Graph(int size = 2);
        ~Graph();
		void display();
		void readFromFileandStoreasGraph(string filename);
		void storeAsGraph(string line);
       bool isConnected(int, int);
	  // void connectionMade(int x,int y);
        void addEdge(int x, int y);
      void BFS(int , int);
	  void DFS(int , int);
}; 






Graph::Graph(int size) {
    int i, j;
    if (size < 2) n = 2;
    else n = size;
    A = new int*[n];
    for (i = 0; i < n; ++i)
        A[i] = new int[n];
	for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            A[i][j] = 0;
} 

Graph::~Graph() {
    for (int i = 0; i < n; ++i)
    delete [] A[i];
    delete [] A;
} 

bool Graph::isConnected(int x, int y) {
    return (A[x][y] == 1);
}


void Graph::addEdge(int x, int y) {
    A[x][y] = A[y][x] = 1;
} 
 
void Graph::display()
{
	 for (int i = 0; i < n; ++i)
	 {
        for (int j = 0; j < n; ++j)
		{
            cout<<A[i][j]<<'\t';
		}
		cout<<endl;
	 }

}



void Graph::storeAsGraph(string line)
{
	int x,y;
		if(line[0]=='A'){x=0;}
		if(line[0]=='B'){x=1;}
		if(line[0]=='C'){x=2;}
		if(line[0]=='D'){x=3;}
		if(line[0]=='E'){x=4;}
		if(line[0]=='F'){x=5;}
		if(line[2]=='A'){y=0;}
		if(line[2]=='B'){y=1;}
		if(line[2]=='C'){y=2;}
		if(line[2]=='D'){y=3;}
		if(line[2]=='E'){y=4;}
		if(line[2]=='F'){y=5;}
	addEdge(x,y);
}

void Graph::readFromFileandStoreasGraph(string filename)
{
	string line;
	ifstream myfile(filename);
	if (myfile.is_open())
	{
		while ( getline(myfile,line) )
		{
			cout << line << '\n';
			storeAsGraph(line);
		}
		myfile.close();
	}

}					// To read from file 

//void Graph::connectionMade(int x,int y)
//{
//	C[x][y]=C[y][x]=1;
//}

void Graph::BFS(int x,int required)			// Queue structure working! Tree Structure working! 
{
	
	Queue Q;		Tree T;
	TreeNode* node;		TreeNode* node1;		TreeNode* node2;		TreeNode* node3;		TreeNode* node4;
	//node2=new TreeNode(5);
	//cout<<node2->val<<endl<<node2->childnum<<endl;
	int flag=0;		int g;
	Q.enqueue(x);	T.insertNode(x);	T.root->parent=NULL;	T.root->sibling1=NULL;		T.root->sibling2=NULL;
	node=T.root;									// A is the root ; current node points to A
	//cout<<node->val<<endl;
	int e=0;
	while(!Q.isEmpty())
	{
		int k=Q.dequeue();
		if(e==0)				// If it is root 
		{
			//cout<<"checker 2"<<endl;	// Nothing 
		}
		else if(node->sibling2==NULL)
		{
			//cout<<"checker3"<<endl;
			while(node->sibling1 !=NULL)
			{

				node=node->sibling1;
			}
			while(node->childnum==0)
			{
				node=node->sibling2;
			}
			node=node->children[0];										// pointer goes to children 
				//if(e>106)
				//cout<<node->val<<endl;
				//cout<<node->sibling1<<endl;												// Counter 
			
		}
		else 
		{
			node=node->sibling2;
			//cout<<node->val<<endl;
			//cout<<"checker4"<<endl;
		}
		//nodesexpanded[e]=k;
		e++;
		//if(e==220)						// Level 7 ends at iteration 199
		//	break;
		//cout<<"expanded node :"<<'\t'<<k<<'\t';
		int counter=0;	//Counter for sibling
		if(node->sibling1!=NULL)												// CHECK FOR ITERATION E=32 !!!!!!!!!!!!
		{
			//cout<<"checker 1"<<endl;
			 flag=1;
			 //cout<<"Node's number of children"<<node->sibling1->childnum;
			 g=node->sibling1->childnum;
			 if(g==0)
			 {
			 node3=node->sibling1;
			 //cout<<node3->sibling1->val<<endl;
				 node3=T.checkTillSiblingHasChildren(node3);
				 //cout<<node3->val<<endl;
			 }
			 else
			 {
			 g=g-1;
			// if(e==34)
				// cout<<"value of g"<<g<<endl;
			 node3=node->sibling1->children[g];
			 //cout<<node->sibling1->children[g]->val;
			 }
		
		}




		for (int i = 0; i < n; ++i)
		{
            if (isConnected(k, i)) {
               
				if(T.checkIfNodeCanBeInserted(node,i)==1)															//checks if the node can be inserted or not
				{
				Q.enqueue(i);
				if(e>1)
				{
				//cout<<"parent of the node:"<<node->parent->val<<endl;												//cout<<"hello"<<endl;
				}
				T.insertNode(node,i);
				//cout<<node->children[counter]->parent->val<<":"<<'\t'<<node->children[counter]->val<<endl;				// Prints the children of the node and parent of that child 
																//cout<<"hello"<<endl;
				node->children[counter]->sibling1=NULL;
			//	cout<<"Sibling 1 of "<<'\t'<<node->children[counter]->val<<"is"<<'\t'<<node->children[counter]->sibling1<<endl;
				if((flag==1)&&(e!=0))
				{
					node->children[counter]->sibling1=node3;
				//	cout<<node->children[counter]->sibling1->val<<endl;
					node4=node->children[counter];
					int t=node->sibling1->childnum;
				//	cout<<"ATTENTION"<<t<<endl;
					t=t-1;			// oN E=35 ,IT BECOMES -1 
					if(node3!=NULL)
					{
					node=node3;
					node->sibling2=node4;
					//node->sibling1->children[t]->sibling2=node4;	
					node=node4->parent;
					}
					flag=0;


				}
				if(counter==0)
				{
					node->children[counter]->sibling2=NULL;


				}
				if(counter!=0)
				{
					node1=node->children[counter];
				node->children[counter]->sibling1=node2;							// Sibling 1
				//cout<<"Sibling 1 of "<<'\t'<<node->children[counter]->val<<"is"<<'\t'<<node->children[counter]->sibling1->val<<endl;		// Check sibling1 
				counter--;
				node->children[counter]->sibling2=node1;							// Sibling2   But check for 1st node as it access invalid memory 
				//cout<<node->children[counter]->sibling2->val<<endl;
				//cout<<"Sibling 2 of "<<'\t'<<node->children[counter]->val<<"is"<<'\t'<<node->children[counter]->sibling2->val<<endl;		// Check sibling2 
				counter++;
				node->children[counter]->sibling2=NULL;
																		//cout<<node->children[counter]->sibling2;
				if(node->children[counter]->sibling2==NULL)
				{
					//cout<<"Sibling2 of "<<'\t'<<node->children[counter]->val<<"is"<<'\t'<<node->children[counter]->sibling2;		// sibling2 of end child node is set to NULL
				//cout<<"let's check if it comes out to be null:Succesful";
				}
				}
				node2=node->children[counter];										//Temporary node 
				counter++;															// Counter for sibling
            }
			}
		}
		//cout<<node->childnum;
		
}
//cout<<endl<<node->val<<endl;
//node=node->sibling1;
//cout<<node->val<<endl;
//node=node->sibling1;
//cout<<node->val;
int hello=0;
if(required==8)
	{cout<<"Solutions from A TO A"<<endl;
cout<<"No Solutions"<<endl;
cout<<"Solutions to anywhere else from A"<<endl;}

if(required==10)
cout<<"Solutions from A to A"<<endl;

while(node->sibling1!=NULL)
{
	T.printSolution(node);
	hello++;
	//cout<<"hello"<<endl;
	node=node->sibling1;
	//cout<<node->val<<endl;
	
}
hello++;
T.printSolution(node);
cout<<hello<<"solutions"<<endl;
while(node->parent!=NULL)
{
	node=node->parent;
}
T.printExpandedFirstSolution(node,required);
if(required==10)
{
cout<<endl<<"Solutions to anywhere from A"<<endl;
cout<<"No Solution"<<endl;
}
}
void printer(int required)
{
	if(required==8)
	{cout<<"Solutions from A TO A"<<endl;
	cout<<"No Solutions"<<endl;
	cout<<"Solutions to anywhere else from A"<<endl;}

	if(required==10)
		cout<<"Solutions from A to A"<<endl;

}

void Graph::DFS(int x,int required)
{
	Stack S; Tree T1;
	TreeNode* node;		TreeNode* node1;		TreeNode* node2;		TreeNode* node3;		TreeNode* node4;
	S.push(x);	T1.insertNode(x);	T1.root->parent=NULL;	T1.root->sibling1=NULL;		T1.root->sibling2=NULL;
	node=T1.root;									// A is the root ; current node points to A
	int e=0;
	int flag;
	printer(required);
	while(!S.isEmpty())
	{
		//S.display();
		//cout<<endl;
		int k=S.pop();
		if(e==0)				// If it is root 
		{
			//cout<<"checker 2"<<endl;	// Nothing 
		}
		else if(node->childnum>0)
		{
			int adjust=node->childnum;
			adjust=adjust-1;
			node=node->children[adjust];
		}else
		{
			while(node->sibling1==NULL)
			{
				node=node->parent;
			}
			node=node->sibling1;
		}
		//cout<<k<<endl;
		e++;
		//if(e>240)
			//break;
		int counter=0;
		
		
		
		flag=1;
		for (int i = 0; i < n; ++i)
		{
            if (isConnected(k, i)) {
				if(T1.checkIfNodeCanBeInserted(node,i)==1)
				{
					if(e>1)
					{
						//cout<<"parent of the node:"<<node->parent->val<<endl;												//cout<<"hello"<<endl;
					}
					T1.insertNode(node,i);
					//cout<<node->children[counter]->parent->val<<":"<<'\t'<<node->children[counter]->val<<endl;
					if(counter==0)
					{
						node->children[counter]->sibling1=NULL;
					}
					else 
						node->children[counter]->sibling1=node3;

					node3=node->children[counter];
				S.push(i);counter++;

				}
				else if(flag==1)
				{
					T1.printSolutionDFS(node,required);
					flag=0;
				}
			
			
			}
			

		}



	}
	while(node->parent!=NULL)
	{
		node=node->parent;
	}
	cout<<"The nodes expanded:"<<endl;
	while(node->childnum!=0)
	{
		cout<<T1.convertBackToChar(node);
		node=node->children[node->childnum-1];
	}
	cout<<T1.convertBackToChar(node);
	if(required==10)
	{
	cout<<endl<<"Solutions to anywhere from A"<<endl;
	cout<<"No Solution"<<endl;
	}
}



