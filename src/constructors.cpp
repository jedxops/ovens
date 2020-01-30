//Jeff Austin
//9/25/2018
//Austin_Products.corp
//structors file.
//
//
//This file will contain the implementation of the functions defined in
//"manual.h" -particularly the ones pertaining to constructors and destructors.
//(thus the name of the file).

//necessary pound includes.
#include "manual.h"

//default constructor.
oven::oven()
{
	manufacturer = NULL;	//initialization.
	model_number = NULL;
}

//copy constructor for the oven class.
oven::oven(const oven & obj)
{
	manufacturer = new char[strlen(obj.manufacturer) + 1];
	strcpy(manufacturer, obj.manufacturer);			//setting the current object to the data of the "obj" passed in.
	model_number = new char[strlen(obj.model_number) + 1];
	strcpy(model_number, obj.model_number);			//deep copying: allocate space, string copy.
}

//constructor with arguments.
oven::oven(char * storage, char * modelnum)
{
	manufacturer = new char[strlen(storage) + 1];
	strcpy(manufacturer, storage);
	model_number = new char[strlen(modelnum) + 1];
	strcpy(model_number, modelnum);
}

//constructor with arguments (function).
void oven::construct(char * manu, char * model)
{
	manufacturer = new char[strlen(manu) + 1];
	strcpy(manufacturer, manu);
	model_number = new char[strlen(model) + 1];
	strcpy(model_number, model);
	//cout << "\n" << manufacturer << "\n";
	//cout << "\n" << model_number << "\n";
}	//implicitly returning.

//destructor:
oven::~oven()
{
	if(manufacturer)
	{
		delete [] manufacturer;
		manufacturer = NULL;
	}
	if(model_number)
	{
		delete [] model_number;
		model_number = NULL;
	}
}


//node class constructors and destructors.
node::node()
{
	left = NULL;
	right = NULL;
	pliance = NULL;
}

node::~node()
{
	if(left)
		delete left;
	left = NULL;
	if(right)
		delete right;
	right = NULL;
	if(pliance)
		delete pliance;
	pliance = NULL;
}


//BST class constructors/destructors.
//default constructor.
BST::BST()
{
	root = NULL;
}

//copy constructor.
BST::BST(const BST & object)
{
	//paste copy function here.
	copy_tree(object.root, root);	//working copy constructor function.
}

//destructor
BST::~BST()
{
	//algorithmic removal function.
	remove_all();
}

