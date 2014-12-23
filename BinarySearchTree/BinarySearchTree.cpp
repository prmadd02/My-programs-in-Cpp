#include <conio.h>
#include <stdlib.h>
#include <iostream> 
#include <fstream>
#include <stdio.h>

using namespace std;

int nodeslength = 0;

int tree[100];
int node[100];

int main () {
  string line;
  ifstream myfile ("tree_nodes.txt",ifstream::in);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
    		node[nodeslength] = atoi(line.c_str());
      nodeslength = nodeslength + 1;
	  cout << line << '\n';
    }
    
	

  }
  else cout << "Unable to open file"; 

cout << nodeslength << endl;
system("PAUSE");


for(int i = 0; i < nodeslength; i++)
{	int treeindex = 1;
	int added = 0;
	
	while(added==0)
	{	
		if(tree[treeindex] == 0)
		{tree[treeindex] = node[i];
		added = 1;
		} 
		
		else if (node[i] < tree[treeindex])
		{treeindex = 2 * treeindex;
		}
		
		else if(node[i] > tree[treeindex])
		{treeindex = 2 * treeindex + 1;
		}
		
		
	}
	
}

for (int i = 0 ; i < 100; i++){
	cout<<tree[i]<<endl;
}



  return 0;
}
