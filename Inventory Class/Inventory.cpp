// I am deferent, I am Scorpio!

# include <iostream>
# include <fstream>
# include <windows.h>
# include <string.h>

using namespace std;

/*	
	class
 */
 
class Inventory
{
	public:
	void readItems();
	void displayItem();
	int getItemID();
	float getPrice();
	float getQuantity();
	int return_ItemID();
	void updateQuantity(float q);
	
	
	private:
	int itemID;
	char itemName[20];
	float itemPrice;
	float quantity;
	float totalPrice;
};

/* 
	class functions 
*/

void Inventory::readItems()
{
	int price, quant;
	cout << "\nPlease Enter Item ID: "; 
	getItemID();
	cout << "Please Enter Item Name: ";
	cin >> itemName;
	cout << "Please Enter Item Price: ";
	price = getPrice();
	cout << "Please Enter Item Quanity: ";
	
	quant = getQuantity();
	totalPrice = price * quant;
}

float Inventory::getPrice()
{
	cin >> itemPrice;
	return itemPrice;
}

int Inventory::getItemID()
{
	cin >> itemID;
	return itemID;
}

float Inventory::getQuantity()
{
	cin >> quantity;
	return quantity;
}

void Inventory::updateQuantity(float q)
{
	quantity += q;
	totalPrice = quantity * itemPrice;
}

int Inventory::return_ItemID()
{	
	return itemID;
}

void Inventory::displayItem()
{
	cout << "\nItem ID: " << itemID;
	cout << "\tItem Name : " << itemName;
	cout << "\tItem Price :" << itemPrice;
	cout << "\tItem Quantity :" << quantity;
	cout << "\tTotal Price :" << totalPrice;
}

/* 
		Non Class Functions 
*/

void appendToFile()
{
	
	Inventory ABakery;
	fstream outFile;
	outFile.open("Inventory.txt",ios::app);
	ABakery.readItems();
	outFile.write(reinterpret_cast <char *> (&ABakery), sizeof(Inventory));
//	ABakery.displayItem();
	outFile.close();
	cout << "\nInventry record added successfully ";
}

void displayAll()
{
	Inventory ABakery;
	ifstream inFile;
	inFile.open("Inventory.txt");
	if(!inFile)
	{
		cout << "\nERROR IN OPENNING FILE";
	}
	// displaying all data from file
	while(inFile.read(reinterpret_cast <char *> (&ABakery), sizeof(Inventory)))
	{
		ABakery.displayItem();
		cout << endl;
	}
	inFile.close();
}

void increaseQuanity(int x)
{
	int found = 0;
	Inventory ABakery;
	float quant;
	fstream outFile;
	outFile.open("Inventory.txt");
	if(!outFile)
	{
		cout<<"\nERROR IN OPENNING FILE";
		return;
	}
	while(!outFile.eof() && found == 0)
	{
		outFile.read(reinterpret_cast <char *> (&ABakery), sizeof(Inventory));
		// checking if item id is present or not (b.f)
		if(ABakery.return_ItemID() == x)
		{
			int qu;
			// updating quantity
			cout << "\nAdd Quantity: ";
			cin >> qu;
			ABakery.updateQuantity(qu);
			// getting the position and writing on it
			int pos = (-1) * static_cast <int> (sizeof(ABakery));
			outFile.seekp(pos,ios::cur);
			outFile.write(reinterpret_cast <char *> (&ABakery), sizeof(Inventory));	
			cout << "\nItem Quantity updated successfully" <<endl;
			found = 1;
		}
	}
	outFile.close();
	if(found == 0)
	{
		cout << "\nRecord Not Found" << endl;
	}
	
}

void deleteExistingFile()
{
	ofstream myFile;
	myFile.open("Inventory.txt");
	myFile << "";
	myFile.close();
	
	system("del Inventory.txt");
	system("cls");		
}

/*
	Main Function starts
*/

main()

{
	// clearing and deleting existing file
	deleteExistingFile();
	
	// created color handler to control colors of console
	
	HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colors, 3);
	
	// loop to display welcome on main screen 
	char BakeryName[38] = "Welcome to ABC Bakery - BY Scorpio-BS";
	for (int i = 0; i < 37; i++)
	{
		cout << BakeryName[i];
		Sleep(80);
	}
	cout << endl;
	SetConsoleTextAttribute(colors, 2);
		
	// object and variables 	
	Inventory ABakery;
	char choice; 
	int id;
	char cont;	
	
	// while user press other than 1 program will start from here
	// cout << '\a'; is used for warning
	
	opt1:
	cout << "\nEnter Choice" << endl;
	cout << "\n1. ADD AN INVENTORY ITEM" << endl;
	cout << "2. DISPLAY FILE DATA" << endl;
	cout << "3. INCREASE QUANTITY" << endl;  
	cout << "\nPlease Select A Choice: ";
	cin >> 	choice;
	
	if (choice == '1')
	{
		
		goto gpt;
	}
	else if (choice != '1')
	{
		cout << "\nERROR IN OPENNING FILE" << endl;
		cout << '\a';
		goto opt1;
	}

	// when user add an item program will then start from here
	
	opt:
	cout << "\n\nEnter Choice" << endl;
	cout << "1. ADD AN INVENTORY ITEM" << endl;
	cout << "2. DISPLAY FILE DATA" << endl;
	cout << "3. INCREASE QUANTITY" << endl;  
	cout << "Please Select A Choice: ";
	cin >> 	choice;
	
	switch (choice)
	{
		case '1':
			// when user choose 1 first time program will start from here
			gpt:
			appendToFile();
			cout << "\n\nDo you want to continue? : ";
			cin >> cont;
			
			if (cont == 'y')
			
			{
				goto opt;
			}
			else
			{
				cout << '\a';
				cout << "\n\nTake Care Good Bye!" << endl;
				break;
			}
		case '2':
			displayAll();
			cout << "\n\nDo you want to continue? : ";
			cin >> cont;
			if (cont == 'y')
			{
				goto opt;
			}
			else
			{
				cout << '\a';
				cout << "\n\nTake Care Good Bye!" << endl;
				break;
			}
			break;
		case '3':
			cout << "Enter Item Id: ";
			cin >> id;
			increaseQuanity(id);
			cout << "\n\nDo you want to continue? : ";
			cin >> cont;
			if (cont == 'y')
			{
				goto opt;
			}
			else
			{
				cout << '\a';
				cout << "\n\nTake Care Good Bye!" << endl;
				break;
			}
			
			break;
		default:
			cout << "\n\nSelect Option From 1 - 3" << endl;
			cout << '\a';
			goto opt;		
	}
	// set console color back to white default	
	SetConsoleTextAttribute(colors, 15);
}

