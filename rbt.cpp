#include <iostream>
#include<cstdio>
#include "tree.h"
using namespace std;

class RBT : public Dict {
  public:
    Node* root;
    Node* leaf;
    RBT() 
    { 
    leaf =new Node();
    root =new Node();
	root->SetLeft(leaf);
	root->SetRight(leaf);
	root->SetParent(leaf);
	root->SetColor(0);
	leaf->SetData(0);
	leaf->SetLeft(leaf);
	leaf->SetRight(leaf);
//	leaf->SetColor(0);
    };
  void Insert(int val);
  bool Delete(int val);
  bool Search(int val);
  void ClearADT ();
  void Display();
  void LeftRotate(Node* x);
  void RightRotate(Node* x);
  void DeleteFixup(Node* x);
  void InsertFixup(Node* z);
  void InOrder(Node* x);
  Node* Successor(Node* x);
  Node* Minimum(Node* x);
  Node* SearchNode(Node* x,int key);
};


/**Input: Argument	Data type	Description
 *
 * 	  val		int		Value to insert
 *
 * Return: NULL
 *
 * Purpose:	1) To insert value
 *
 * 		2) Don't insert if val is already in RBT
 *
 *
 */

void RBT::Insert (int val){
	Node* newNode = new Node();///Create new Node newNode to insert
	newNode->SetData(val);///Set data to newNode
	newNode->SetLeft(leaf);
	newNode->SetRight(leaf);
	Node* x=root;
	Node* y=leaf;
	while(x != leaf){
		y=x;
		if (val==x->Data()) return;
		if(val < x->Data())
			x= x->Left();
		else
			x=x->Right();
	}
	newNode->SetParent(y);
	if(y==leaf){
		root=newNode;
		root->SetColor(0);
		root->SetParent(leaf);
//	leaf=y;
	}
	else if(newNode->Data() < y->Data())
		y->SetLeft(newNode);
	else
		y->SetRight(newNode);
	newNode->SetColor(1);
//	cout<<newNode->Data()<<"Insert Ends\n";
	if(newNode !=root )
			InsertFixup(newNode);
//Display();
}

void RBT::InsertFixup(Node* z){
	Node* y;
//		z->SetColor(0);
//	}else{

	while( z->Parent()->Color() ==1 && z!=root && z!=leaf ){
		if(z->Parent()== z->Parent()->Parent()->Left()){
			y= z->Parent()->Parent()->Right();
			if(y->Color() == 1){
				z->Parent()->SetColor(0);
				y->SetColor(0);
				z->Parent()->Parent()->SetColor(1);
				z = z->Parent()->Parent();
			cout<<root->Data()<<" "<<root<<" "<<z->Data()<<" "<<z->Parent()->Color()<<" "<<z->Parent()<<" "<<z->Parent()->Parent()->Left()<<" "<<z->Parent()->Parent()->Right()->Color()<<"hi Insert Fixup\n";
			}
			else{
			 if(z == z->Parent()->Right()){
				z= z->Parent();
				LeftRotate(z);
			 }
			z->Parent()->SetColor(0);
			z->Parent()->Parent()->SetColor(1);
			RightRotate(z->Parent()->Parent());
			}
cout<<z<<" "<<z->Parent()<<" "<<z->Parent()->Parent()<<"\n";
		}
//		else if(z->Parent()== z->Parent()->Parent()->Right()){
		else{	
			y= z->Parent()->Parent()->Left();
			cout<<y->Color()<<" "<<y->Data()<<" "<<z->Data()<<"\n";
			if(y->Color() == 0){
				z->Parent()->SetColor(1);
				y->SetColor(1);
				z->Parent()->Parent()->SetColor(0);
				z = z->Parent()->Parent();
			}
			else{
			 if(z == z->Parent()->Left()){
				z= z->Parent();
				RightRotate(z);
			}
			z->Parent()->SetColor(1);
			z->Parent()->Parent()->SetColor(0);
cout<<"Inside fixup"<<z->Parent()->Parent()->Data()<<" "<<z->Parent()->Data()<<" Right:"<<z->Parent()->Parent()->Right()->Left()->Data()<<"\n";
			LeftRotate(z->Parent()->Parent());
			}
		}

	}
	root->SetColor(0);
}

void RBT::LeftRotate(Node* x){
	Node* y =x->Right();
	x->SetRight(y->Left());
	y->Left()->SetParent(x);
	y->SetParent(x->Parent());
	if(x->Parent() == leaf)
		root = y;
	else if(x==x->Parent()->Left())
		x->Parent()->SetLeft(y);
	else
		x->Parent()->SetRight(y);
	y->SetLeft(x);
	x->SetParent(y);
}
void RBT::RightRotate(Node* x){
	Node* y =x->Left();
	x->SetLeft(y->Right());
	y->Right()->SetParent(x);
	y->SetParent(x->Parent());
	if(x->Parent() == leaf)
		root = y;
	else if(x==x->Parent()->Right())
		x->Parent()->SetRight(y);
	else
		x->Parent()->SetLeft(y);
	y->SetRight(x);
	x->SetParent(y);
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
 *
 */

  bool RBT::Delete (int val){
	Node* S =root; ///Set S as root
	Node* z =SearchNode(S,val);///Search for Key and store the pointer to that key to del
	Node* x;
	Node* y;
	if(z==leaf)
		return false;///if del is null then return false
	if(z->Left() ==leaf || z->Right()==leaf)
		y= z;
	else
		y=Successor(z);
	if(y->Left() !=leaf)
		x=y->Left();
	else
		x=y->Right();
	x->SetParent(y->Parent());
	if(y->Parent() ==leaf)
		root =x;
	else if(y==y->Parent()->Left())
		y->Parent()->SetLeft(x);
	else
		y->Parent()->SetRight(x);
	if(y!=z)
		z->SetData(y->Data());
	if(y->Color() ==0)
		DeleteFixup(x);
	return true;
}

void RBT::DeleteFixup(Node* x){
	Node* w;
	while(x !=root && x->Color() ==0){
		if(x==x->Parent()->Left()){
			w= x->Parent()->Right();
			if(w->Color() ==1){
				w->SetColor(0);
				x->Parent()->SetColor(1);
				LeftRotate(x->Parent());
				w =x->Parent()->Right();
			}
			if(w->Left()->Color() ==0 && w->Right()->Color() ==0){
				w->SetColor(1);
				x=x->Parent();
			}
			else if(w->Right()->Color() ==0){
				w->Left()->SetColor(0);
				w->SetColor(1);
				RightRotate(w);
				w=x->Parent()->Right();
			}
			w->SetColor(x->Parent()->Color());
			x->Parent()->SetColor(0);
			w->Right()->SetColor(0);
			LeftRotate(x->Parent());
			x=root;
		}
		else{
			w= x->Parent()->Left();
			if(w->Color() ==1){
				w->SetColor(0);
				x->Parent()->SetColor(1);
				RightRotate(x->Parent());
				w =x->Parent()->Left();
			}
			if(w->Right()->Color() ==0 && w->Left()->Color() ==0){
				w->SetColor(1);
				x=x->Parent();
			}
			else if(w->Left()->Color() ==0){
				w->Right()->SetColor(0);
				w->SetColor(1);
				LeftRotate(w);
				w=x->Parent()->Left();
			}
			w->SetColor(x->Parent()->Color());
			x->Parent()->SetColor(0);
			w->Left()->SetColor(0);
			RightRotate(x->Parent());
			x=root;
		}
	}
	x->SetColor(0);
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
Node* RBT::Successor(Node* x){
	Node* y;
	if(x->Right() !=leaf)///if right[x] is not null
		return Minimum(x->Right());///	return Minimum(right[x])
	y=x->Parent();///y=parent[x]
	while(y!= leaf && x ==y->Right()){///while y is not null and x==right[y]
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
Node* RBT::Minimum(Node* x){
	while(x->Left()!=leaf){ ///while left[x] is not null
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
 *
 */

  bool RBT::Search (int key){
	Node* x =root;/// set x=root
	Node* y =SearchNode(x,key);///Call SearchNode(x,key) and store its value in y
	if(y==leaf)	
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
Node* RBT::SearchNode(Node* x,int key){
	while(x!=leaf && key !=x->Data()){ ///Loop while x!=NULL and key!=key[x]
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

  void RBT::ClearADT (){
	root=NULL;
	leaf=NULL;
}


/**Input: NULL
 *
 * Return: NULL
 *
 * Purpose:	1) To display data of each nodes in the BST tree in ascending order
 */

  void RBT::Display (){
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
  void RBT::InOrder(Node* x){
	//cout<<x<<" "<<leaf<<"\n";
	if(x != leaf){ /// x is start node
		InOrder(x->Left());///Do Inorder recursively with left child node of x as start node
		cout<<x->Parent()->Data()<<" "<<x->Data() <<" "<<x->Color() << "\n";///Display data
		InOrder(x->Right());///Do Inorder recursively with right child node of x as start node

	}
}

