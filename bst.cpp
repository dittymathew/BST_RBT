#include <iostream>
#include<cstdio>
#include "tree.h"
using namespace std;


class BST : public Dict{
   Node* root;
   public:
    BST(){
		root =NULL;
	};
	
  void Insert(int val);
  bool Delete(int val);
  bool Search(int val);
  void ClearADT ();
  void Display();
  void InOrder(Node* x);
  Node* SearchNode(Node* x,int key);
  Node* Successor(Node* x);
  Node* Minimum(Node* x);

};
/**Input: Argument	Data type	Description
 *
 * 	  val		int		Value to insert
 *
 * Return: NULL
 *
 * Purpose:	1) To insert value
 *
 * 		2) Don't insert if val is already in BST
 *
 *
 */
void BST::Insert (int val){
	Node* newNode = new Node();///Create new Node newNode to insert
	newNode->SetData(val);///Set data to newNode
	Node* y = NULL; ///y=null
	Node*x = root;///x =root
	while (x!=NULL){///while x is not null
		if(val ==x->Data())	return; ///if val is already in the tree return
		y=x;	///y=x
		if(val < x->Data()){ ///if val <data[x]
			x=x->Left();///x=left[x]
		}
		else{
			x=x->Right();///else x=right[x]
		}
	}
	newNode->SetParent(y);///set parent[newNode] as y
	if(y == NULL){///if y==null
		root=newNode;///	set root as newNode
	}
	else if(newNode->Data() < y->Data()){ ///else data[newNode]<data[y]
		y->SetLeft(newNode);///		left[y]=newNode
	}
	else{
		y->SetRight(newNode);///else	right[y]=newNode
	}
}
/**Input: Argument	Data type	Description
 *
 * 	  key		int		Key to Delete
 *
 * Return: true if value is deleted
 *
 * 	   false if value not found in the tree
 *
 * Purpose:	1) To delete value from the tree
 *
 *
 */
bool BST::Delete (int key){
	Node* S =root; ///Set S as root
	Node* del =SearchNode(S,key);///Search for Key and store the pointer to that key to del
	Node* x;
	Node* y;
	if(del==NULL)
		return false;///if del is null then return false
	if(del->Left() == NULL || del->Right() == NULL) ///if left child or right child of del is null
		y=del;///	then y=del
	else
		y =Successor(del);///else y=Successor(del)
	if(y->Left()!=NULL)///if left[y] is not null
		x=y->Left();///x=left[y]
	else
		x=y->Right();///else x=right[y]
	if(x!=NULL)
		x->SetParent(y->Parent());///if x!=null then parent[x]=parent[y]
	if(y->Parent()==NULL)///if parent[y] is null then root=x
		root =x;
	else if(y==y->Parent()->Left())/// if y==left[parent[y]]
		y->Parent()->SetLeft(x);///	then left[parent[y]]=x
	else
		y->Parent()->SetRight(x);///else	right[parent[y]]=x
	if(y!=del)
		del->SetData(y->Data());///if y!=del then data[del]=data[y]
	return true;///return true
}
/**Input: Argument	Data type	Description
 *
 * 	  x		Node		Node from which the minimum value to be found
 *
 * Return: Successor of x
 *
 * Purpose:	1) To return successor of x
 *
 *
 */
Node* BST::Successor(Node* x){
	Node* y;
	if(x->Right() !=NULL)///if right[x] is not null
		return Minimum(x->Right());///	return Minimum(right[x])
	y=x->Parent();///y=parent[x]
	while(y!= NULL && x ==y->Right()){///while y is not null and x==right[y]
		x=y;///x=y
		y=y->Parent();///y=parent[y]
	}
	return y;///retutn y
}
/**Input: Argument	Data type	Description
 *
 * 	  x		Node		Node from which the minimum value to be found
 *
 * Return: Node that have minimum value
 *
 * Purpose:	1) To return pointer to the minimum element
 *
 *
 */
Node* BST::Minimum(Node* x){
	while(x->Left()!=NULL){ ///while left[x] is not null
		x=x->Left(); ///	Do x=left[x]
	}
	return x;	///return x
}
/**Input: Argument	Data type	Description
 *
 * 	  key		int		Search key
 *
 * Return: True if key is found else false
 *
 * Purpose:	1) To search a key in the tree
 *
 *
 *
 */
bool BST::Search(int key){
	Node* x =root;/// set x=root
	Node* y =SearchNode(x,key);///Call SearchNode(x,key) and store its value in y
	if(y==NULL)	
		return false;///Return false if y==NULL
	if(key==y->Data()) 
		return true;///Return true if key=key[y]
}

/**Input: Argument	Data type	Description
 *
 * 	  x		Node		Starting Node of searching
 *
 * 	  key		int		Search key
 *
 * Return: Node of search key if it is found else null
 *
 * Purpose:	1) To search a key in the tree
 *
 *
 */
Node* BST::SearchNode(Node* x,int key){
	while(x!=NULL && key !=x->Data()){ ///Loop while x!=NULL and key!=key[x]
		if(key < x->Data()){///do if key<key[x]
			x =x->Left();///	then x =left[x]
		}
		else{		     ///	else x=right[x]
			x=x->Right();
		}
	}
	return x;///return x
}
/**Input: NULL
 *
 * Return: NULL
 *
 * Purpose:	1) To clear data
 *
 *
 */
  void BST::ClearADT (){
	root=NULL;///Set root as Null
}
/**Input: NULL
 *
 * Return: NULL
 *
 * Purpose:	1) To display data of each nodes in the BST tree in ascending order
 *
 *
 *
 */
  void BST::Display (){
	Node* x =root;///Set x as root node
	InOrder(x);//Do inorder traversal of x
}
/**Input:	Argument	Data type	Description
 *
 * 		x		Node		Start Node of Inorder Traversal
 *
 * Return: NULL
 *
 * Purpose:	1) To do inorder traversal
 *
 *
 */
  void BST::InOrder(Node* x){
	if(x != NULL){ /// x is start node
		InOrder(x->Left());///Do Inorder recursively with left child node of x as start node
		cout<<x->Data()<< "\n";///Display data
		InOrder(x->Right());///Do Inorder recursively with right child node of x as start node

	}
}

