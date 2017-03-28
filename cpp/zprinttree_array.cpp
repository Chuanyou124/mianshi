#include <iostream>
#include <vector>
using namespace std;

int ct = 0;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x):data(x),left(NULL),right(NULL){}
    Node():data(ct++),left(NULL),right(NULL)
    {
    }
};

void setBST(Node *top, int& begin)
{
    if (!top)
    {
        return;
    }
    setBST(top->left, begin);
    top->data = ++begin;
    setBST(top->right, begin);
}

void printTree(Node *top) //in order print
{
    if (top == NULL)
    {
        return;
    }
    printTree(top->left);
    cout<<top->data<<" ";
    printTree(top->right);
}

void zprint(Node *top)
{
	Node *npa[100];
	npa[0] = top;
	int bound = -1;
	int end = 0;
	int newEnd = 0;
	bool fromLeft = true;
	vector<int> horizontalLine;
	horizontalLine.reserve(100);

	while (newEnd > bound)
	{
		for (int i = end; i > bound; --i)
		{
			if (fromLeft)
			{
				if (npa[i]->left)
					npa[++newEnd] = npa[i]->left;
				if (npa[i]->right)
					npa[++newEnd] = npa[i]->right;
			}
			else
			{
				if (npa[i]->right)
					npa[++newEnd] = npa[i]->right;
				if (npa[i]->left)
					npa[++newEnd] = npa[i]->left;
			}
		}
		bound = end;
		end = newEnd;
		fromLeft = fromLeft ? false:true;
		horizontalLine.push_back(bound);
	}
	int j = 0;
	for (int i = 0; i <= newEnd; ++i)
	{
		cout << npa[i]->data << " ";
		if (horizontalLine[j] == i)
		{
			j++;
			cout << endl;
		}
	}
}

int main()
{
	Node nA[30];
	Node *pA[30];
	for (int i = 0; i < 30; ++i)
	{
		pA[i] = &nA[i];
		if (2*i + 1 <= 29)
		{   
			pA[i]->left = &nA[2*i + 1];
		}
		if (2*i + 2 <= 29)
		{
			pA[i]->right = &nA[2*i + 2];
		}
	}
	int beginV = 0;
	setBST(pA[0], beginV);
	// above is to set up a bst with 30 nodes
	
	printTree(pA[0]);
	cout<<endl;
	cout.flush();

	zprint(pA[0]);
	return 0;
}
