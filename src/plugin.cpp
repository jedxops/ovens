//Jeff Austin
//9/25/2018
//
//
//


//include our header file!
#include "manual.h"


//declare necessary prototypes!
void clear();		//functionality for clearing the screen.
bool read_from_file(BST * &);

int main()
{
	int catch_value = 0;	//function return value

	BST * tree = NULL;
	tree = new BST;

	catch_value = read_from_file(tree);
	if(catch_value)
	{
		//tree.display();
		//cout << tree.get_root() -> get_pliance() -> get_manufacturer();	
	}

	else	//text file read in (of data) failure notification.
	{
		for(int i = 0; i < 50; ++i)
			cout << "\n";
		cout << "Text file retrieval error, program exiting.";
	}

	//tree -> display();		//displaying the tree object's data.

	cout << "\nThere are: " << (*tree).count() << " items.\n";

	int catchv = (*tree).count_duplicates();
	if(catchv != 0)	cout << "\nThere were duplicates!\n";
	else cout << "\nNo duplicates!\n";

	tree -> display();

	//delete tree;
	//tree = NULL;

	BST * tree2 = new BST(*tree);

	tree -> display();
	cout << "\nTree 2 data:\n";
	tree2 -> display();

	//tree2 -> change_root();

	if(tree -> is_same_tree(*tree, *tree2) == 0)//zero is the flag for same tree, one is the flag for different.
	{
		cout << "\n\nSame tree!\n\n";
	}

	return 0;
}

bool read_from_file(BST * & tree)
{
	//statically creating variables.
	//(ada std formating for A.R.A.E allocation).

	char store[LARGE];
	char modelnumSTAT[LARGE];
	oven object;

	ifstream input_file;

	//open the file
	input_file.open("ovens.txt");
	
	//prime the pump:
	if(input_file)
	{
		input_file.get(store, LARGE, '\n');
		//cout << store;
		input_file.ignore(LARGE, '\n');
		//read in:
		while(input_file && (!(input_file.eof())))
		{
			input_file.get(modelnumSTAT, LARGE, '\n');
			//cout << modelnumSTAT;
			input_file.ignore(LARGE, '\n');

			//prime the pump!
			input_file.ignore(LARGE, '\n');
			//cout << "Store: "  << store << ".\n";
			//cout << "Model: " << modelnumSTAT << ".\n";
			object.construct(store, modelnumSTAT);
			tree -> insert(object);
			input_file.get(store, LARGE, '\n');
			input_file.ignore(LARGE, '\n');
			//cout << "obj: " << object.get_manufacturer();
		}
		input_file.clear();
		input_file.close();
		//cout << tree.get_root() -> get_pliance() -> get_manufacturer() << "this is the root";
		//tree.display();
		return 1;
	}

	//TEXT FILE READ ERROR. In this case we return 0, which is failure here.
	else
	{
		return 0;
	}
	return 0;
}

//function for clearing the screen.
void clear()
{
	for(int i = 0; i < 50; ++i)
		cout << "\n";
}
