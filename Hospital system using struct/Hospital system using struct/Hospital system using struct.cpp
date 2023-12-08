#include<iostream>
#define Max_queue 5
#define Max_spec 20
using namespace std;


struct queues
{
	string names[Max_queue]{ "" };
	bool status[Max_queue]{ false };
	int len = 0;

	void add_patient(string name, bool stat)
	{
		if (len == 5)
		{
			cout << "Sorry we can't add more patients to this specialization" << endl;
		}
		else if (stat == true && len!=0)
		{
			for (int i = len; i > 0; i--)
			{
				names[i] = names[i - 1];
				status[i] = status[i - 1];
			}
			names[0] = name;
			status[0] = stat;
			len++;
		}
		else
		{
			names[len] = name;
			status[len] = stat;
			len++;
		}
	}

	void print(int spec)
	{
		if (len != 0)
		{
			cout << "There are " << len << " patients in specialization " << spec << endl;
			for (int i = 0; i < len; i++)
			{
				cout << names[i] << " ";
				if (status[i] == 0)
					cout << "regular" << endl;
				else
					cout << "Urgent" << endl;
			}
		}
	}

	void get_patient()
	{
		if (len == 0)
			cout << "There are no patients at the moment , have a rest Dr." << endl;
		else
		{
			cout << names[0] << " please go with the Dr." << endl;
			for (int i = 0; i < len-1; i++)
			{
				names[i] = names[i + 1];
				status[i] = status[i + 1];
			}
			len--;
		}
	}
};

struct hospital
{
	queues queue[Max_spec];
	void run()
	{
		string name;
		bool status;
		int spec;
		while (true)
		{
			int choice = menu();
			if (choice == 1) 
			{
				cout << "Enter the specialization , name and status of the patient" << endl;
				cin >> spec >> name >> status;
				queue[spec - 1].add_patient(name, status);
			}
			else if (choice == 2)
			{
				cout << "********************" << endl;
				for (int i = 0; i < Max_spec; i++)
				{
					queue[i].print(i + 1);
				}
			}
			else if (choice == 3)
			{
				cout << "Enter the specialization" << endl;
				cin >> spec;
				queue[spec - 1].get_patient();
			}
			else if (choice==4)
			{
				cout << "Goodbye!" << endl;
				break;
			}
				
		}
	}
	int menu()
	{
		int choice = -1;
		cout << "Enter your choice" << endl;
		cout << "1) add new patient" << endl;
		cout << "2) print all patients" << endl;
		cout << "3) get next patient" << endl;
		cout << "4) Exit" << endl;
		cin >> choice;
		if (choice < 1 || choice>4)
			cout << "Invalid input" << endl;
		return choice;
	}
	
};

int main(void)
{
	hospital h1;
	h1.run();

	return 0;
}