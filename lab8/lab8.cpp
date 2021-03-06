// lab8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Patient
{
public:
	Patient(){};

	Patient(unsigned int id)
	{
		this->id = id;
	}

	void set_id(unsigned int id)
	{
		this->id = id;
	}

	unsigned int get_id() const
	{
		if (id == NULL)return NULL;
		return this->id;
	}

	void set_sex(string sex)
	{
		this->sex = sex[0];
	}

	void set_father_patient(shared_ptr<Patient> father_patient) 
	{
		this->father_patient = father_patient;
	}

	void set_mother_patient(shared_ptr<Patient> mother_patient)
	{
		this->mother_patient = mother_patient;
	}

	shared_ptr <Patient> get_mother_patient()
	{
		return this->mother_patient;
	}

	shared_ptr <Patient> get_father_patient()
	{
		return this->father_patient;
	}

	char get_sex()
	{
		return this->sex;
	}

	vector <unsigned char> get_genetic_data()
	{
		return this->genetic_data;
	}
private:

	shared_ptr <Patient> mother_patient;
	shared_ptr <Patient> father_patient;
	unsigned int id;
	vector <unsigned char> genetic_data;
	char sex;
};
bool compare(const shared_ptr <Patient> &a, const shared_ptr <Patient> &b)
{
	return a->get_id() < b->get_id();
}
double probability(shared_ptr<Patient>mother, shared_ptr<Patient>father) 
{
	int generation = 0;
	static double probability=0;
	if (mother == NULL || father == NULL)
	{
	///if(...)genetarion++ || generation--;
	///probability=...get_genetic_data()[...]*...+...;
	return probability;
	}
	///
	///probability=...+...*...probability(mother->get_mother_patient()...)
	///
	///probability=...+...*...probability(father->get_mother_patient()...)
	///

}
void write_ancestors_id(shared_ptr<Patient>parent)
{
	if (parent == NULL || parent->get_id() == NULL)return;
	cout << parent->get_id() << endl;
	write_ancestors_id(parent->get_mother_patient());
	write_ancestors_id(parent->get_father_patient());
}

int main()
{
	shared_ptr <Patient> father;
	shared_ptr <Patient> mother;
	{
		vector <shared_ptr <Patient>> patients;
		vector <shared_ptr <Patient>>::iterator iterator;
		vector <shared_ptr <Patient>>::iterator iterator_lower_bound;
		///loading  ////////////////////////////////////////////////////////////////////////////
		fstream file;
		string line;
		int i(0);
		file.open("patients.csv", ios::in);
		if (file.good() == false)
		{
			cout << "File opening error." << endl;
			exit(1);
		}

		while (!file.eof())
		{
			patients.push_back(shared_ptr <Patient>(new Patient));
			iterator = patients.end() - 1;
			line.clear();

			getline(file, line, '|');
			if (line.empty())break;
			(*iterator)->set_id(atoi(line.c_str()));

			getline(file, line, '|');
			(*iterator)->set_sex(line);

			line.clear();
			getline(file, line, '|');
			if (line.empty())
			{
				(*iterator)->set_father_patient(NULL);
				continue;
			}
			else
			{
				(*iterator)->set_father_patient(shared_ptr<Patient>(new Patient(atoi(line.c_str()))));
			}

			line.clear();
			getline(file, line);
			if (line.empty())
			{
				(*iterator)->set_mother_patient(NULL);
				continue;
			}
			else
			{
				(*iterator)->set_mother_patient(shared_ptr<Patient>(new Patient(atoi(line.c_str()))));
			}
			iterator++;

		}
		file.close();
		patients.pop_back();

		sort(patients.begin(), patients.end(), compare);

		iterator = patients.begin();
		string mother_id, father_id;
		int counter = 0;

		while (iterator != patients.end())
		{
			if ((*iterator)->get_father_patient() == NULL)
			{
				if ((*iterator)->get_mother_patient() == NULL)
				{
					iterator++;
				}
				else
				{
					iterator_lower_bound = lower_bound(patients.begin(), patients.end(), (*iterator)->get_mother_patient(), compare); 
					(*iterator)->set_mother_patient((*iterator_lower_bound));
					if ((*iterator)->get_mother_patient()->get_sex() == 'M' || (*iterator)->get_mother_patient()->get_sex() == 'm')
					{
						cout << "Error in 'patients.csv'. Incorrect data." << endl;
						return 0;
					}
					iterator++;
				}
			}
			else
			{

				iterator_lower_bound = lower_bound(patients.begin(), patients.end(), (*iterator)->get_father_patient(), compare);
				(*iterator)->set_father_patient((*iterator_lower_bound));
				if ((*iterator)->get_father_patient()->get_sex() == 'K'|| (*iterator)->get_father_patient()->get_sex() == 'k')
				{
					cout << "Error in 'patients.csv'. Incorrect data." << endl;
					return 0;
				}
				
				if ((*iterator)->get_mother_patient() == NULL)
				{
					iterator++;
				}

				else
				{
					iterator_lower_bound = lower_bound(patients.begin(), patients.end(), (*iterator)->get_mother_patient(), compare); 
					(*iterator)->set_mother_patient((*iterator_lower_bound));
					if ((*iterator)->get_mother_patient()->get_sex() == 'M'|| (*iterator)->get_mother_patient()->get_sex() == 'm')
					{
						cout << "Error in 'patients.csv'. Incorrect data." << endl;
						return 0;
					}
					iterator++;
				}
			}
			

		}
		
		cout << "Enter father's id:" << endl;
		unsigned int fid,mid;
		cin >> fid;

		cout << "Enter mother's id:" << endl;
		cin >> mid;

		iterator = lower_bound(patients.begin(), patients.end(), shared_ptr<Patient>(new Patient(fid)), compare);
		father= (*iterator);
		if (father->get_sex()=='K'|| father->get_sex() == 'k')
		{
			cout << "Error! This is not man." << endl;
			return 0;
		}

		iterator = lower_bound(patients.begin(), patients.end(), shared_ptr<Patient>(new Patient(mid)), compare);
		mother = (*iterator);
		if (mother->get_sex() == 'M'||mother->get_sex() == 'm')
		{
			cout << "Error! This is not woman." << endl;
			return 0;
		}

	}

	cout << "Family tree. Mother side:"<<endl;
	write_ancestors_id(mother);  //heap pre-order
	cout << "Family tree. Father side:"<<endl;
	write_ancestors_id(father);		//heap pre-order
	cout << endl;
	
    return 0;
}

