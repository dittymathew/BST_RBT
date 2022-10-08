#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;
// Abstarct class
class Dict {
public:
 virtual void Insert(int val)=0;
 virtual bool Delete(int val)=0;
 virtual bool Search(int val)=0;
 virtual void ClearADT ()=0;
 virtual void Display()=0;
 void PopulateDict(Dict*,char*,char*);
 void LocateDict(Dict*,char*,char*);
};

/*Both BST and RBT class using the variables and member functions of Node class*/
class Node{
	int data,color; //Insert Key,color(for RBT)
	Node* left; //Left Child Node
	Node* right;//Right Child Node
	Node* parent;//Parent Node
	public:
	
	/*Member Function Declaration*/

	void SetData(int i_data);
	void SetColor(int i_color);
	void SetParent(Node* i_parent);
	void SetLeft(Node* i_left);
	void SetRight(Node* i_right);
	int Data();
	int Color();
	Node* Parent();
	Node* Left();
	Node* Right();
};

/**Function Name:	SetData(int i_data)
 * 
 * Input:	Argument	Data type	Description
 *
 * 		i_data		int		Data to set to the Node
 *
 * Return	NULL
 *
 * Purpose:	1) To set Data to the Node
 *
 *
 */

void Node::SetData(int i_data)
{
	data = i_data;
}
/**Function Name:	SetColor(int i_color)
 * 
 * Input:	Argument	Data type	Description
 *
 * 		i_color		int		Colour to set to the Node
 *
 * Return	NULL
 *
 * Purpose:	1) To set colour to the Node for RBT
 *
 *
 */

void Node::SetColor(int i_color)
{
	color = i_color;
}

/**Function Name:	SetParent(Node* i_parent)
 * 
 * Input:	Argument	Data type	Description
 *
 * 		i_parent	Node*		Node to set as parent of a given node
 *
 * Return	NULL
 *
 * Purpose:	1) To set parent of a Node
 *
 *
 *
 */

void Node::SetParent(Node* i_parent)
{
	parent = i_parent;
}

/**Function Name:	SetLeft(Node* i_left)
 * 
 * Input:	Argument	Data type	Description
 *
 * 		i_left	Node*		Node to set as left child of a given node
 *
 * Return	NULL
 *
 * Purpose:	1) To set a node as left child of a Node
 *
 *
 */

void Node::SetLeft(Node* i_left)
{
	left = i_left;
}

/**Function Name:	SetRight(Node* i_right)
 * 
 * Input:	Argument	Data type	Description
 *
 * 		i_right	Node*		Node to set as right child of a given node
 *
 * Return	NULL
 *
 * Purpose:	1) To set a node as right child of a Node
 *
 *
 */

void Node::SetRight(Node* i_right)
{
	right = i_right;
}

/**Function Name:	Data()
 * 
 * Input:	Argument	Data type	Description
 *
 * Return	corresponding data
 *
 * Purpose:	1) To return corresponding data of a Node
 *
 *
 *
 */

int Node::Data()
{
	return data;
}

/**Function Name:	Color()
 * 
 * Input:	Argument	Data type	Description
 *
 * Return	corresponding colour
 *
 * Purpose:	1) To return corresponding colour of a Node
 *
 *
 *
 */

int Node::Color()
{
	return color;
}

/**Function Name:	Parent()
 * 
 * Input:	Argument	Data type	Description
 *
 * Return	Parent node of a node
 *
 * Purpose:	1) To return parent node of a Node
 *
 */

Node* Node::Parent()
{
	return parent;
}

/**Function Name:	Left)
 * 
 * Input:	Argument	Data type	Description
 *
 * Return	Left child node of a node
 *
 * Purpose:	1) To return left child node of a Node
 *
 */

Node* Node::Left()
{
	return left;
}

/**Function Name:	Right()
 * 
 * Input:	Argument	Data type	Description
 *
 * Return	Right child node of a node
 *
 * Purpose:	1) To return right child node of a Node
 *
 */

Node* Node::Right()
{
	return right;
}

#endif /* #ifndef TREE_H */
