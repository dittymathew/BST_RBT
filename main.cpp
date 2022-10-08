#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<sys/time.h>
#include<sstream>
#include "tree.h"
#include "rbt.cpp"
#include "bst.cpp"
using namespace std;

/**
* Function Name : PopulateDict(Dict *dictobj,char *dictfile,char *timeinsert)
*
*Input:	Arguments	Datatype	Description
*
*	dictobj		Object		Base Class Object
*
*	dictfile	char*		Filename of file which contain keys to insert
*
*	timeinsert	char*		Filename of file where we stores the execution time of insertion 
*
* Return NULL
*
* Purpose: 1) Read Dictionary file(given as command line argument)
*
*	   2) Input the Key values in the file to corresponding datastructure
*
*	   3) Evaluate time taken for insertion
*
*	   4) Store the evaluated time to a file(name given as commandline argument) for each set of inputs
*
*
 */

void Dict::PopulateDict(Dict *dictobj,char *dictfile,char *timeinsert)
{
	ifstream in (dictfile); ///Creating file pointer for dictionary file
	ofstream out (timeinsert,std::ios_base::app);///Creating file pointer for timeinsert file
   	timeval t1, t2;
	double elapsedTime;
	string line; ///String variable line stores the line reading from file
	int i,count,j,key;
	count=0;
	int val;
	gettimeofday(&t1, NULL);
	if(in.is_open()){ ///File Checking
	while(getline(in,line)!=NULL) ///Reading Line
	{
		std::istringstream buffer(line);
		buffer >> val; ///Store the values into val
		dictobj->Insert(val);///Inserting Value
		count++; ///Setting count
	}}
	in.close();
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	out <<count<<"\t"<<elapsedTime<<"\n"; ///Storing the time
}

/**
* Function Name : LocateDict(Dict *dictobj,char *locfile,char *timesearch)
*
*Input:	Arguments	Datatype	Description
*
*	dictobj		Object		Base Class Object
*
*	locfile		char*		Filename of file which contain Search keys
*
*	timesearch	char*		Filename of file where we stores the execution time of searching
*
* Return NULL
*
* Purpose: 1) Read file(given as command line argument) that contains values to search
*	 2) Search key values in the file to corresponding datastructure
*	 3) Evaluate time taken for searching
*	 4) Store the evaluated time to a file(name given as commandline argument) for each set of inputs
*
*
 */
void Dict::LocateDict(Dict *dictobj,char *locfile,char *timesearch){
	ifstream in (locfile);///Setting the file pointer of locfile
	ofstream out (timesearch,std::ios_base::app);///Creating file pointer for timeinsert file
   	timeval t1, t2;
	double elapsedTime;
	string line; ///String variable line stores the line reading from file
	int val;
	int count,i,j;
	count=0;

	gettimeofday(&t1, NULL);
	if(in.is_open()){ ///File Checking
	while(getline(in,line)!=NULL) ///Reading Line
	{
		std::istringstream buffer(line);
		buffer >> val; ///Store the values into array val
		if(dictobj->Search(val)){ ///Searching Values in the corresponding data structure
//			cout<<"Search Key "<<val<<" Found\n";
		}
		else{
//			cout<<"Search Key "<<val<<" Not Found\n";
		}
		count++; ///Setting count
	}}
	in.close();
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;      // sec to ms
    	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;   // us to ms
	out <<count<<"\t"<<elapsedTime<<"\n"; ///Storing the time


}

int main(int argc, char *argv[])
{
int choice,ext,delkey,inskey,srchkey;
char *dictfile,*locfile,*timeinsfile,*timesrchfile;
Dict *obj; ///Creating object of Dict class (Base Class)
Dict *obj1; ///Creating object of Dict class (Base Class)
BST bt;///Creating object of class Binary Search Tree(Derived class)
RBT rt; ///Creating object of class Redblack tree(Derived class)
ext=0;
//cout<<"Enter: \n1 - BST \n2 - RBT\n";
//cin>>choice;
if(strcmp(argv[1],"-bst")==0)
	choice=1;
else
	choice=2;

switch(choice)
{
  case 1:	///For Binary search tree
	obj=&bt;///Setting the base class object as BST object
	dictfile= argv[2];
	locfile =argv[3];
	if(strcmp(argv[4],"-t") ==0){
		timeinsfile =argv[5];
		timesrchfile =argv[6];
	}else{
		timeinsfile =argv[4];
		timesrchfile =argv[5];
	}
	break;
  case 2:	///For Red Black tree
	obj=&rt;///Setting the base class object as RBT object
	dictfile= argv[1];
	locfile =argv[2];
	if(strcmp(argv[3],"-t") ==0){
		timeinsfile =argv[4];
		timesrchfile =argv[5];
	}else{
		timeinsfile =argv[3];
		timesrchfile =argv[4];
	}
	break;
default: 
	cout<<"Enter a either 1 or 2\n";
 
} /// end of switch
obj1->PopulateDict(obj,dictfile,timeinsfile);
obj1->LocateDict(obj,locfile,timesrchfile);
while(ext !=6){

/*******************************MENU***************************/
cout<<"\n*****************************************************\n";
cout<<"Enter \n1 - Insert \n2 - Delete\n3 - Search\n4 - Display\n5 - Clear\n6 - Exit\n";
cin>>ext;
cout<<"\n*****************************************************\n";
/*************************************************************/
switch(ext)
{
  case 1:		///To Insert
	cout<<"Enter Key to Insert\n";
	cin>>inskey;
	obj->Insert(inskey);
	cout<<"Key "<<inskey<<" Inserted\n";
	break;
  case 2:		///To Delete
	cout<<"Enter Key to Delete\n";
	cin>>delkey;
	if(obj->Delete(delkey)) {cout<<"Key "<<delkey<<" Deleted\n";}
		else	{cout<<"Key "<<delkey<<" Not Found\n";}
	break;
  case 3:		///To Search
	cout<<"Enter Key to Search\n";
	cin>>srchkey;
	if(obj->Search(srchkey)){ ///Searching Values in the corresponding data structure
		cout<<"Search Key "<<srchkey<<" Found\n";
	}
	else{
		cout<<"Search Key "<<srchkey<<" Not Found\n";
	}
	break;
  case 4:		///To Display
	obj->Display();
	break;
  case 5:		///To Clear List
	obj->ClearADT();
	break;
  default:
	break;
}
}
return 0;
}
