// I am deferent, I am Scorpio!

# include <iostream>

using namespace std;

class Person
{
	private:
		string FirstName;
		string LastName;
		int PersonalID;
		double Salary;
		static int person_Id;
		
	public:
		
		void setFirstName(string);
		void setLastName(string);
		void setSalary(double);
		void setPersonal_ID(int);
		void setDefault_id();
		
		string getFirstName();
		string getLastName();
		double getSalary();
		int getPersonal_id();
		
};

// Static Variable
int Person::person_Id = 8248001;

// Setter And Getter Functions class Person

void Person::setFirstName(string fn)
{	
	FirstName  = fn;
}

void Person::setLastName(string ln)
{	
	LastName = ln;
}

void Person::setSalary(double sl)
{
	Salary = sl;
}

string Person::getFirstName()
{
	return FirstName;
}

string Person::getLastName()
{
	return LastName;
}

double Person::getSalary()
{
	return Salary;
}
void Person::setDefault_id()
{
	PersonalID = person_Id;
	person_Id++;
}

void Person::setPersonal_ID(int id)
{
	PersonalID = id;
}

int Person::getPersonal_id()
{
	return PersonalID;
}

// class HRM

class HRM
{
	private:
		Person employe[10];
		int nmbr_employe[10];
	public:
		void AddPerson();
		void DeletePerson(int);
		void UpdatePerson(int);
		void display_employ();
		bool is_employe_id = false;
		int nmbr = 0;
};

void HRM::display_employ()
{
	cout << "\n"; 
	for(int i = 0; i <= nmbr-1; i++)
	{
		cout << "Sr.No: " << i + 1 << "\tEMPLOYEE ID : " << nmbr_employe[i] <<  " " << endl;
		 
	}
	cout << "\nTotal Number of Employee: " << nmbr  << endl;
}

void HRM::AddPerson()
{
	string y_n, f_name, l_name;
	double salary_1;	
	
	opt:
	if (nmbr <= 9)
	{
		cout << "\nEnter the information if new employee" << endl;
		
		employe[nmbr].setDefault_id();
		
		cout << "First Name: ";
		cin >> f_name;
		employe[nmbr].setFirstName(f_name);
		
		cout << "Last Name: ";
		cin >> l_name;
		employe[nmbr].setLastName(l_name);
		
		cout << "How much his/her salary? = ";
	
		int run = 1;
		// if user puts other then numeric value it will get an error & prompt to put numeric value	
		while (run)
		{
			if (cin >> salary_1 && salary_1 >= 0)
			{
			  employe[nmbr].setSalary(salary_1);
			  break;
			}
			
			else
			{
			  cout << "\n***Invalid Input Please Enter Valid Value***";
			  cin.clear();
			  cout << "\nHow much his/her salary? = ";
			  while (cin.get() != '\n');
			}
		}	

		nmbr_employe[nmbr] = employe[nmbr].getPersonal_id();
		
		cout << "\nThe employee with the following information has been added to the system:" << endl;
		cout << "\n";
		
		cout << "\nFirst Name \tLast Name \t Personal ID \t Salary per year (Rupees)" << endl;
		cout << "-----------    ------------     -------------    ------------------------" << endl;
			
		for(int i = 0; i <= nmbr; i++)
		{
			cout << employe[i].getFirstName() << " \t\t" << employe[i].getLastName() << "\t\t   " << employe[i].getPersonal_id()<< "\t\t" << employe[i].getSalary() << endl;
		}
		nmbr++;
		
		cout << "\nDo you want to add another employee: ";
		
		cin >> y_n;
		
		if(y_n == "y" || y_n == "Y")
		{
			goto opt;
		}
	}
	else
	{
		cout << "\n***Maximum Number Of Employee Added, Delete Someone to Add New***" << endl;
	}
}

void HRM::DeletePerson(int n)
{
	string y_n;
	cout << "Do you really want to delete employee (y/n): ";
	cin >> y_n;
	
	if(y_n == "y" || y_n == "Y")
	{
		for(int i = 0; i <= nmbr; i++)
		{
			if(employe[i].getPersonal_id()==n)			
			{
				is_employe_id = true;
				for(int z = i; z < nmbr; z++)
				{
					employe[z].setFirstName(employe[z+1].getFirstName());
					employe[z].setLastName(employe[z+1].getLastName());
					employe[z].setSalary(employe[z+1].getSalary());
					employe[z].setPersonal_ID(employe[z + 1].getPersonal_id());
					nmbr_employe[z] = nmbr_employe[z+1];
				}
				nmbr--;
				
				cout << "\nThe employee with the following information are modified in the system:" << endl;
				cout << "\n";
				
				cout << "\nFirst Name \tLast Name \t Personal ID \t Salary per year (Rupees)" << endl;
				cout << "-----------    ------------     -------------    ------------------------" << endl;
				cout << "\n";
				for(int k = 0; k <= nmbr - 1; k++)
				{
					cout << employe[k].getFirstName() << " \t\t" << employe[k].getLastName() << "\t\t   " << employe[k].getPersonal_id()<< "\t\t" << employe[k].getSalary() << endl;
				}
				
				break;
			}
		}
		
		if(is_employe_id == false)
		{
			cout << "\n***Employee Record Not Found!***" << endl;
			cout << "\nOnlye The employee with the following information are Available in the system:" << endl;
			display_employ();
			
			/*
			cout << "\nFirst Name \tLast Name \t Personal ID \t Salary per year (Rupees)" << endl;
			cout << "-----------    ------------     -------------    ------------------------" << endl;
			cout << "\n";
			for(int t = 1; t <= nmbr - 1; t++)
			{
				cout << employe[t].getFirstName() << " \t\t" << employe[t].getLastName() << "\t\t   " << employe[t].getPersonal_id()<< "\t\t" << employe[t].getSalary() << endl;
			}
			*/				
		}
	}
		
}

void HRM::UpdatePerson(int j)
{
	string y_n, choice, n_value;
	
	double n_nmbr;
	
	// start point
	gpt:
	for(int i = 0; i < nmbr; i++)
	{
		if(employe[i].getPersonal_id() == j)
		{	
			is_employe_id == true;
			
			cout << "\nplease enter the related number of field which you would like to upadate" << endl;
			cout << "1. First Name" << endl;	
			cout << "2. Family Name" << endl;
			cout << "3. Monthly Salary" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			
			if(choice == "1")
			{
				cout << "First Name: ";
				cin >> n_value;
				employe[i].setFirstName(n_value);
			}
			else if(choice == "2")
			{
				cout << "Family Name: ";
				cin >> n_value;
				employe[i].setLastName(n_value);
			}
			else if(choice == "3")
			{
				cout << "Monthly Salary: ";
				int run = 1;
				// if user puts other then numeric value it will get an error & prompt to put numeric value
				while (run)
				{
					if (cin >> n_nmbr && n_nmbr >= 0)
					{
					  employe[i].setSalary(n_nmbr);
					  break;
					}
		 			
					else
		 			{
					  cout << "\n***Invalid Input Please Enter Valid Value***";
					  cin.clear();
					  cout << "\nMonthly Salary: ";
					  while (cin.get() != '\n');
					}
				}	
			}
			
			cout << "\nThe employee with the following information has been modified in the system:" << endl;
			cout << "\n";
			
			cout << "\nFirst Name \tLast Name \t Personal ID \t Salary per year (Rupees)" << endl;
			cout << "-----------    ------------     -------------    ------------------------" << endl;
				
			for(int g = 0; g <= nmbr - 1; g++)
			{
				cout << employe[g].getFirstName() << " \t\t" << employe[g].getLastName() << "\t\t   " << employe[g].getPersonal_id()<< "\t\t" << employe[g].getSalary() << endl;
			}	
			
			cout << "\nDo you want to update another field (y/n) = ";
			cin >> y_n;		
		
			if(y_n == "y" || y_n == "Y")
			{
				
				goto gpt;
			}
			
			else
			{
				is_employe_id = true;
				break;
			}	
		}
				
	}
	
	if(is_employe_id == false)
	{
		cout << "\n***Employee Record Not Found!***" << endl;
		cout << "\nOnlye The employee with the following information are Available in the system:" << endl;
		
		display_employ();
		
		/*
		cout << "\nFirst Name \tLast Name \t Personal ID \t Salary per year (Rupees)" << endl;
		cout << "-----------    ------------     -------------    ------------------------" << endl;
		cout << "\n";
		
		for(int t = 1; t <= nmbr - 1; t++)
		{
			cout << employe[t].getFirstName() << " \t\t" << employe[t].getLastName() << "\t\t   " << employe[t].getPersonal_id()<< "\t\t" << employe[t].getSalary() << endl;
		}
		*/	
	}
}

int main()
{
	HRM emp;
	int run = 1;
	
	cout << "Welcome Aboard..." << endl;
	
	for(int i = 0; i <= 50; i++)
	{
		cout << "*";
	}
	
	cout << "\nWelcome to Human Resource Management (HRM) Software of Company XYZ. To do specific task please choose one of the following commands." << endl;
	
	while(run)
	{
		string choice, w_continue;
		
		//start point
		opt:
		cout << "\n\t1. Add new employee" << endl;
		cout << "\t2. Delete employee information" << endl;
		cout << "\t3. Update employee information" << endl;
		cout << "\t4. Quit" << endl;
		
		cout << "\n\tEnter Choice: ";
		cin >> choice;
		
		if(choice == "1")
		{	
			emp.AddPerson();
			goto opt;			
		}
		
		else if(choice == "2")
		{
			int i_remove;
			string y_n;
			
			cout << "\nID of employee to remove: ";

			int run = 1;
			
			// if user puts other then numeric value it will get an error & prompt to put numeric value
			while (run)
			{
				if (cin >> i_remove && i_remove >= 0)
				{
				  emp.DeletePerson(i_remove);
				  break;
				}
	 			
				else
	 			{
				  cout << "\n***Invalid Input Please Enter Valid Value***";
				  cin.clear();
				  cout << "\nID of employee to remove: ";
				  while (cin.get() != '\n');
				}
			}
			
			cout << "\nDo you want to continue[y/n]: ";
			cin >> w_continue;
			emp.is_employe_id = false;
			if(w_continue == "y" || w_continue == "Y")
			{
				goto opt;
			}
			
			else
			{
				cout << "\n GOOD BYE" << endl;
				cout << "\n Press any key to Quit...";
				system("pause > 0");
				break;
			}
		}	
		
		else if(choice == "3")
		{	
			int idd;
			cout << "Enter an ID of employee to modify data: ";
			cin >> idd;
			emp.UpdatePerson(idd);
			emp.is_employe_id = false;
			goto opt;
		}
		
		else if(choice == "4")
		{
			emp.display_employ();
			//cout << "employ: " << emp.nmbr;
			exit(0);
		}
		else
		{
			//system("cls");
			cout << "\n***Invalid Selection! Please Select b/w 1-4***" << endl;
			goto opt;	
		}	
	}
	
	return 0;
}
