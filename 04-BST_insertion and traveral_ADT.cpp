#include<iostream>
using namespace std;

template <typename T>
class TreeNode
{
public:
	T data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(T data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}
};

template<typename T>
class BinarySearchTree
{
private:
	TreeNode<T>* root;

public:
	BinarySearchTree();
	//To get the pointer to root node
	TreeNode<T>* getRoot();
	
	void insert(TreeNode<T>* current, T data);
	void traverse(TreeNode<T>* current);
};


template<typename T>
BinarySearchTree<T>::BinarySearchTree()
	{
		this->root=NULL;
	}


template<typename T>
TreeNode<T>* BinarySearchTree<T>:: getRoot()
	{
		return this->root;
	}


//insertion in the BST
template<typename T>
void BinarySearchTree<T> :: insert(TreeNode<T>* current, T data)
{
	

	if(this->root==NULL)
		{
			TreeNode<T>* newNode= new TreeNode<T>(data);
			this->root=newNode;
		}
	
	else if(data <= current->data)
	{
		if(current->left==NULL)
			{
				TreeNode<T>* newNode= new TreeNode<T>(data);
				current->left=newNode;
			}

		else 
			insert(current->left, data);
	}
	else
	{
		if(current->right == NULL )
			{
			TreeNode<T>* newNode= new TreeNode<T>(data);
			current->right=newNode;
			}
		else
			insert(current->right, data);
	}
}


//BST traversal
template<typename T>
void BinarySearchTree<T>:: traverse(TreeNode<T>* current) //in-order
{
	if(current!=NULL)
	{
		traverse(current->left);
		cout<<current->data<<" ";
		traverse(current->right);

	}
}


int main()
{
	const int size=7;
	int array[size]={20, 15, 25, 10, 18, 23, 28};
	//you can take these values as input from the user

	BinarySearchTree<int> myBST;
	TreeNode<int>* current;
	for(int i=0; i<size; i++)
	{	
		current= myBST.getRoot();
		myBST.insert(current,array[i]);
		cout<<"node has been inserted \n";
	}

	current= myBST.getRoot();
	cout<<"Inorder traversal: "<<endl;
	myBST.traverse(current);

	cout<<"\n";
	return 0;
}