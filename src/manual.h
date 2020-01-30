//Jeff Austin
//9/25/2018
//Austin_Products.corp
//This program will simply store oven data into a binary 
//search tree and then it will perform recursive
//operations on the tree and its data.
//
//
//Data Structures:
//There will be three data structures associated with this program.
//The first will be the outer most part: The binary search tree
//(not an advanced/balanced tree). Each node of the binary search tree 
//is to have a head pointer to a linear linked list of oven objects
//(so there will be a linear linked list of oven objects for any given
//node in the BST). Every matching manufacturer will be placed in the same
//outer BST node and sorted alphabetically in the linear linked list.
//
//
//
//
//
//The program will start by reading in data from an external file and storing 
//it. It then  will initiate the process of executing complex recursive
//operations such as sorted displays, retrievals and mining.
//
//
//


#include <iostream>
#include <cstring>
#include <cctype>
#include <math.h>
#include <fstream>
using namespace std;


const int MAX_SIZE = 1500;
const int LARGE = 1000;


class oven
{
	public:
		oven();			//defualt constructor.
		oven(const oven &);	//copy constructor.
		oven(char *, char *);	//constructor with arguments.
		~oven();
		void construct(char *, char *);//function that copies data into the oven class members.
		char * get_manufacturer();
		char * get_model_number();
		void set_manufacturer(char *);
		void set_model_number(char *);
	private:
		char * manufacturer;
		char * model_number;
};

class node
{
	public:
		node();		//constructor for the node class
		~node();	//destructor for the node class
		node * & get_right();	//getter function for the node's right pointer.
		node * & get_left();	//getter function for the node's left pointer. 
		oven * & get_pliance();	//getter function for the node's pliance pointer. 
		void set_right(node *);	//setter function for the node class' right pointer.
		void set_left(node *);	//setter function for the node class' left pointer.
		void set_pliance(oven *);//setter function for the node class' pliance pointer.
	private:
		node * right;		//right pointer.
		node * left;		//left pointer.
		oven * pliance;		//pliance pointer (oven object).
};


class BST
{
	public: BST();
		BST(const BST &);	//copy constructor for the BST class.
		node * & get_root();
		~BST();

		void insert(oven);
		void display();
		void remove_all();
		void change_root();
		int is_same_tree(BST, BST);
		int count();
		int count_duplicates();
	private:
		void insert(oven, node * &);
		void display(node *);
		void remove_all(node * &);
		void copy_tree(node *, node * &);
		int is_same_tree(node *, node *);
		int count(node *);
		int count_duplicates(node *);
		int find_match(node *, char *);

		node * root;
};

