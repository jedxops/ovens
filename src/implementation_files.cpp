//Jeff Austin
//9/25/2018
//
//This file contains the implementation of the functions 
//defined in the "manual.h" file.

#include "manual.h"

//BST functions
void BST::insert(oven object)
{
	insert(object, root);
}

void BST::insert(oven object, node * & root)
{
	if(root == NULL)
	{
		root = new node;
		root -> set_left(NULL);
		root -> set_right(NULL);
		root -> set_pliance(new oven(object.get_manufacturer(), object.get_model_number()));

//before this fix, the issue was that we were setting root (the alias) to point to different nodes, but this alias pointer was using the memory location of the SAME oven object each 
//time. Sure, the character arrays were different each time but the object as the same! Wehave to make sure to create a NEW object each time we creat a new node 
//(new node => new oven with new char stars, not the same 'arbitrary' oven object each time.


		return;
	}

	else
	{
		//if(strncmp(root -> get_pliance() -> get_manufacturer(), object.get_manufacturer(), 1000) > 0)
		//cout << "\nComparing: " << root -> get_pliance() -> get_manufacturer() << " and: " << object.get_manufacturer() << ".\n";
		float to_compare = (strcmp(root -> get_pliance() -> get_manufacturer(), object.get_manufacturer()));
		//cout << "\nTo_compare: " << to_compare << ".\n";
		if(to_compare > 0.0)
		{
			//cout << "\nTraversing left WE ARE IN HERE\n";
			insert(object, root -> get_left());
		}
		//if(strncmp(root -> get_pliance() -> get_manufacturer(), object.get_manufacturer(), 1000) <= 0)
		if(to_compare <= 0.0)
		{
			//cout << "\nTraversing right\n";
			insert(object, root -> get_right());
		}
	}
	return;
}

void BST::display()
{
	display(root);
}

void BST::display(node * root)
{
	if(!root)	return;

	cout << "\nManufacturer: " << root -> get_pliance() -> get_manufacturer() << ".\n";
	cout << "\nModel Number: " << root -> get_pliance() -> get_model_number() << ".\n";
	display(root -> get_right());
	display(root -> get_left());
}

void BST::remove_all()
{
	remove_all(root);
}

void BST::remove_all(node * & root)
{
	if(!root)	return;

	remove_all(root -> get_left());
	remove_all(root -> get_right());

	delete root;
	root = NULL;

	return;
}

void BST::copy_tree(node * source, node * & dest)
{
	if(!source)	return;

	dest = new node;
	dest -> set_pliance(new oven(*(source -> get_pliance())));
	dest -> set_left(NULL);
	dest -> set_right(NULL);

	copy_tree(source -> get_left(), dest -> get_left());
	copy_tree(source -> get_right(), dest -> get_right());
	return;
}


void BST::change_root()
{
	char temp[] = {"ajsdfkla"};
	if(!root)	return;
	else 
	{
		root -> get_pliance() -> set_manufacturer(new char);
		strcpy(root -> get_pliance() -> get_manufacturer(), temp);
	}
	cout << "\ndata: " << root -> get_pliance() -> get_manufacturer() << ".\n";
	return;
}


int BST::is_same_tree(BST to_compare1, BST to_compare2)
{
	return is_same_tree(to_compare1.root, to_compare2.root);
}


int BST::is_same_tree(node * to_compare1, node * to_compare2)
{
	if(!to_compare1 && !to_compare2) return 0;

	if(!to_compare1 && to_compare2)	return 1;
							//if one exists without the other then they are NOT the same tree. set flag and return.
	if(to_compare1 && !to_compare2)	return 1;

		//both pointers exist.
	int num = 0;
	if(strcmp(to_compare1 -> get_pliance() -> get_manufacturer(), to_compare2 -> get_pliance() -> get_manufacturer()) == 0)
	{
		num = is_same_tree(to_compare1 -> get_left(), to_compare2 -> get_left()) + is_same_tree(to_compare1 -> get_right(), to_compare2 -> get_right());
		return num;
	}
	return num + 1;		//if the manufacturers aren't the same then they are different trees.
}


int BST::count()
{
	return count(root);
}

int BST::count(node * root)
{
	if(!root)	return 0;
	return count(root -> get_left()) + count(root -> get_right()) + 1;
}

int BST::count_duplicates()
{
	return count_duplicates(root);
}

int BST::count_duplicates(node * root)
{
	if(!root)	return 0;
	if(find_match(this -> root, root -> get_pliance() -> get_manufacturer()) > 1)
		return count_duplicates(root -> get_left()) + count_duplicates(root -> get_right()) + 1;
	return count_duplicates(root -> get_left()) + count_duplicates(root -> get_right());
}

int BST::find_match(node * root, char * match)
{
	if(!root)	return 0;
	if(strcmp(match, root -> get_pliance() -> get_manufacturer()) == 0)
		return find_match(root -> get_left(), match) + find_match(root -> get_right(), match) + 1;
	return find_match(root -> get_left(), match) + find_match(root -> get_right(), match);
}

node * & BST::get_root()
{
	return root;
}


//node setters and getters
node * & node::get_left()
{
	return left;
}

node * & node::get_right()
{
	return right;
}

oven * & node::get_pliance()
{
	return pliance;
}

void node::set_left(node * connection)
{
	left = connection;
}

void node::set_right(node * connection)
{
	right = connection;
}

void node::set_pliance(oven * pointer)
{
	pliance = pointer;
	//cout << "Test:";
	//cout << "\n\n" << pointer -> get_manufacturer() << "\n\n";
	//cout << pliance -> get_manufacturer() << "\n\n";
	//cout << pliance -> get_model_number();
}


//oven functions
char * oven::get_manufacturer()
{
	return manufacturer;
}


char * oven::get_model_number()
{
	return model_number;
}


void oven::set_manufacturer(char * temp)
{
	manufacturer = temp;
}


void oven::set_model_number(char * temp)
{
	model_number = temp;
}


