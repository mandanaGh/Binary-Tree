#include <iostream>
#include <time.h>

typedef struct BTNode
{
  int key_value;
  int rank;
  struct BTNode *parent;
  struct BTNode *left_child;
  struct BTNode *right_child;
};

class BTree
{
    public:

        BTree()
		{
			root = NULL;
		}
		~BTree()
		{
			destroy_tree(this->root);
		}

		//Create randomized binary tree
		void CreateBinaryTree(int numberOfNodes)
		{
			root = CreateTreeNode(numberOfNodes, NULL, 0);
		}	
		
		// Print the tree in-order
		// Traverse the left sub-tree, root, right sub-tree
		void Inorder(int numberOfNodes)
		{
			struct BTNode *node;
			node =  InorderFirst();
			int first_rank = node->rank;
			this->aTotalSteps = 0;
			
			for (int i=1; i< numberOfNodes; i++)
				node = InorderNext(node);
			
			int final_rank = node->rank;
			CalculateAmortizedComplexity(first_rank , final_rank);
			
			//print the result
			std::cout << numberOfNodes << "    " << this->aTotalSteps << "    " ;
			std::cout << amortizedComplexity << std::endl;
		}

    private:
		
		BTNode *root;
		int aTotalSteps; //Total steps in inorder traversal
		int amortizedComplexity; 

		//Retern the most left node in the binary tree
		struct BTNode * InorderFirst()
		{
			BTNode *node = this->root;
			while ( node->left_child != NULL)
				node = node->left_child;
			return node;
		}

		// Return the node visited after node "currNode" in an inorder traversal
		struct BTNode * InorderNext(BTNode *currNode)
		{
			if (currNode->right_child != NULL)
			{
				currNode = currNode->right_child;
				this->aTotalSteps++;
				while (currNode->left_child != NULL)
				{
					currNode = currNode->left_child;
					this->aTotalSteps++;
				}
				return currNode;
			}
			else
			{
				struct BTNode *p;
				p = currNode->parent;
				this->aTotalSteps++;
				while (currNode != p->left_child)
				{
					currNode = p;
					p = p->parent;
					this->aTotalSteps++;
				}
				return p;
			}
		}

		//The amortized complexity of n-1 calls to inorder is 2(n-1)
		void CalculateAmortizedComplexity(int firstRank , int finalRank)
		{
			amortizedComplexity = aTotalSteps + (finalRank - firstRank);
		}

		//This method creates a node in the binary tree.
		struct BTNode * CreateTreeNode(int numberOfNodes, BTNode *parent, int rank)
		{
			
			// create a temporary node 
			BTNode *temp;		
			// allocate space for node
			temp = (BTNode*)malloc(sizeof(BTNode)); 
			temp->key_value = numberOfNodes;					
			temp->parent = parent;
			temp->rank = rank;
			
			int leftnumchild,rightnumchild;
			//Calculate number of children for left subtree randomly.
			leftnumchild = rand() % numberOfNodes;
			//Calculate number of children for right subtree
			rightnumchild = numberOfNodes - leftnumchild -1 ;

			if (leftnumchild > 0)
				temp->left_child = CreateTreeNode(leftnumchild, temp, rank-1);
			else
					temp->left_child = NULL;

			if (rightnumchild > 0)
					temp->right_child = CreateTreeNode(rightnumchild, temp, rank+1);
			else
					temp->right_child = NULL;
			return temp;
		}

		//This method will destroy a tree 
		void destroy_tree(BTNode *node)
		{
		  if(node != NULL)
		  {
			destroy_tree(node->left_child);
			destroy_tree(node->right_child);
			delete node;
		  }
		}
};

void main() {
   
	/* initialize random seed: */
	srand((unsigned)time(0));
	int num;
	std::cout<<"Nodes  Steps   Amortized Cost"<<std::endl;
	for(int i=1; i<=50; i++)
	{
		num = rand() % 51 + 50;//tree size is between 50 and 100
		BTree *b = new BTree();
		
		b->CreateBinaryTree(num); //Generate random binary tree
		b->Inorder(num); //Traverse tree in inorder
		
		b->~BTree();
	}
	system("PAUSE");
}




