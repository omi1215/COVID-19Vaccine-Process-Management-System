#include <iostream>
#include <fstream>
using namespace std;
ifstream read;
ofstream write;
int id_count=0,capac=500;
struct dob
{
	int y, m, d;
};
class Person
{
protected:
	long int id,cnic,contact;
	string first_name, last_name, password, address, city, state, bloodgrp, gender;
	dob date;
public:
	Person() {
		id = 0,cnic=0,contact=0;
		first_name = " ", last_name = " ", password = " ", city = " ", state = " ", bloodgrp = " ", gender = " ";
	}

	void input_firstname(string a);
	void input_lastname(string a);
	void input_pass(string a);
	void input_fdodoc(string f, string l, string pass, string ci);
	string getfirst();
	string getlast();
	string getpass();
	void input_citizen(string f, string l, long int cnic, string add, string city, string state, string blood, string gender, long int con,dob d);
};
string Person::getfirst()
{
	return first_name;
}
string Person::getlast()
{
	return last_name;
}
string Person::getpass()
{
	return password;
}
void Person ::input_fdodoc(string f, string l, string pass,string ci)
{
	first_name = f;
	last_name = l;
	password = pass;
	city = ci;
}
void Person::input_citizen(string f, string l, long int cnic, string add, string city, string state, string blood, string gender, long int con,dob d)
{
	first_name = f;
	last_name = l;
	address = add;
	this->cnic = cnic;
	this->city = city;
	this->gender = gender;
	this->state = state;
	bloodgrp = blood;
	contact = con;
	date.y = d.y;
	date.m = d.m;
	date.d = d.d;


}

void Person:: input_firstname(string a)
{
	first_name = a;
}
void Person::input_lastname(string a)
{
	last_name = a;
}
void Person::input_pass(string a)
{
	password = a;
}
class citizen
{
private:
	Person p;
	

public:
	void input_citizen(string s0,string s1, long long int s10,string s2,string s3,string s4,string s5,string s6,long long int s11,dob dd)
	{
		
		p.input_citizen(s0, s1, s10, s2, s3, s4, s5, s6, s11,dd);
		
	}
};
class vaccine
{
protected:

public:
	string vac_name;
	string vac_price, noofdose;
	void inputpriceanddose(string price, string dose)
	{
		vac_price = price;
		noofdose = dose;
	}
	void inputvac_name(string name)
	{
		vac_name = name;
	}
	string returnvac_name()
	{
		return vac_name;
	}
};
class Supplier:public vaccine
{	
public:

	string nationality;
	string id;
	vaccine vac[2];

	void inputvac(string vacc[])
	{
		this->vac[0].inputvac_name(vacc[0]);
		this->vac[1].inputvac_name(vacc[1]);
	}
	void inputnation(string n)
	{
		nationality = n;
	}
	string returnid()
	{
		return id;
	}
	string returnnation()
	{
		return nationality;
	}
	void inputid(string id)
	{
		this->id = id;
	}
	void output()
	{
		cout << id << " " << nationality << endl;
		cout << vac[0].returnvac_name();
		if (vac[1].returnvac_name()=="0")
		{

		}
		else
		{
			cout << " " << vac[1].returnvac_name() << endl;
		}
	}
};
class Admin
{
protected:
	string fname, lname, pass;
	Supplier s;
	

public:
	int batchid=0,qunatity=0;
	void callSupplier(Supplier sup)
	{
		s = sup;
		batchid = id_count;
		id_count++;
		cout << "input quantity" << endl;
		cin >> qunatity;
	}		
	void dispmain()
	{
		cout << batchid << " " << qunatity << endl;
	}
	void displaysupp()
	{
		s.output();
	}
	
};
void loogincheck(string f, string l, string p,int n)
{
	
}
class FDO
{
private:
	Person person;
public:
	void input_fdo(string a, string b , string c,string d)
	{
		person.input_fdodoc(a,b,c,d);
	}
	bool check_eligibilty()
	{
		long long int cnic;
		cout << "input cnic" << endl;

	}
	
};
class Doctor
{
private:
	Person person;
public:
	void applyvac(string d)
	{
		cout << d << endl;
		string vac;
		string str;
		ifstream in;
		ofstream out;
		in.open("vaccentre.txt");
		while (!in.eof())
		{
			in >> str;
			cout << str;
			if (str==d)
			{

				cout << "select which medicine you want to choose" << endl;
				for(int i =0;str != "-1";i++)
				{
					in >> str;
					if (str == "-1")
					{
						break;
					}
					cout <<i<<" "<< str << " ";
					in >> str;
					if (str == "-1")
					{
						break;
					}
					cout << str << endl;
				}

				break;
			}
		}
		in.close();
cout << "input no. " << endl;
		int test,temp1=0,temp2=0;
		cin >> test;
			in.open("vaccentre.txt");
		while (!in.eof())
		{
			in >> str;
			if (str == d)
			{
				
				for (int i = 0; i<test; i++)
				{
					in >> str;
					cout << i << " " << str << " ";
					in >> str;
					cout << str << endl;
				}
				in >> temp1;
				in >> temp2;
				break;
			}
		}
		in.close();
		cout << endl << endl;

		temp2--;
		in.open("vaccentre.txt");
		out.open("tempp.txt");
		while (!in.eof())
		{
			in >> str;
			out << str << endl;
		}
		in.close();
		out.close();
		in.open("tempp.txt");
		out.open("vaccentre.txt");
		while (!in.eof())
		{
			in >> str;
			if (str == d)
			{
				out << str<<endl;
				for (int i = 0; i<test; i++)
				{
					
					in >> str;
					out << str << endl;
					in >> str;
					out << str << endl;
				}
				in >> str;
				out << temp1 << endl;
				in >> str;
				out << temp2 << endl;

			}
			else
			{
				out << str << endl;
			}
		}
		in.close();
		out.close();
	}
	void checkpatient(string d)
	{
		bool test=0;
		string str;
		read.open("eligiblelist.txt");
		write.open("ttemp.txt");

		while(!read.eof())
		{
			read >> str;
			if (str == d)
			{
				test = 1;
			}
			write << str<<" ";
		}
		
		read.close();
		write.close();
		if (test == 1)
		{
			int bl, gl, ol;
			cout << "input the blood pressure" << endl;
			cin >> bl;
			cout << "input glucose level" << endl;
			cin >> gl;
			cout << "input oxygen level" << endl;
			cin >> ol;
			write.open("eligiblelist.txt");
			read.open("ttemp.txt");
			while (!read.eof())
			{
				read >> str;
				if (str == d)
				{
					write << str << " ";
					write << 2 << " " << bl << " " << gl << " " << ol << endl;
					for (int i = 0; i < 4; i++)
					{

					
						read >> str;
					}
				}
				else
				{
					write << str<<" ";
					read >> str;
					write << str << " ";
					read >> str;
					write << str << " ";
					read >> str;
					write << str << " ";
					read >> str;
					write << str << " ";
					write << endl;
				}
			}
			read.close();
			write.close();
		}
		else
		{
			cout << "cnic not eligible" << endl;
		}
	}
	void input_fdo(string a, string b, string c,string d)
	{
		person.input_fdodoc(a, b, c,d);
	}
};
class filing
{
protected:
public:
	void loginwrite(string f, string l, string p, int num);
	bool loginread(string f, string l, string p, int num);
	dob fdoread(string a);
	void writesupplier(string id, string nationality,string vacc[]);
	int countsupplier();
	void readsupplier(Supplier* sup,int i);
	void readsupplier( );
	void eligiblefile(string a);
	void loginwrite(string f, string l, string p, string q, int num);
	void retrieveread(int num);
	void writecitizen(string f, string l, long long int cnic, string add, string city, string state, string blood, string gender, long long int con,dob d);
	void displayvac(string a);
};
void filing::displayvac(string a)
{
	string str;
	read.open("vaccentre.txt");
	while (!read.eof())
	{

	}
	read >> str;

}
void filing::eligiblefile(string a)
{
	write.open("eligiblelist.txt",ios::app);
	write << a << " " << 1 <<" "<< 0<<" "<<0<<" "<<0<<" "<<0 << endl;
	write.close();
}
dob filing::fdoread(string a)
{
	string aa;
	int aaa;
	dob dbirth;
	read.open("registeredcitizen.txt");
	while (!read.eof())
	{
		read >> aa;
		
		if (aa == a)
		{
			for (int i = 0; i < 8; i++)
			{
				read >> aa;
				
			}
			read >> aaa;

			dbirth.y = aaa;
			read >> aaa;
			
			dbirth.m >> aaa;
		
			read >> aaa;
			dbirth.d >> aaa;
			break;
		}
		else
		{
			dbirth.d = 0; dbirth.m = 0; dbirth.y = 0;
		}
	}
	read.close();
	return dbirth;

}
void filing:: retrieveread(int num)
{
	ifstream in;
	string str, str1 ;
	if (num == 1)
	{
		str = "adminlogin.txt"; str1 = "admin ";
	}
	else if (num == 0)
	{
		str = "superadminlog.txt";
		str1 = "superadmin" ;
	}
	else if (num == 2)
	{
		str = "doctorlogin.txt";
		str1 = "doctor";
	}
	else if (num == 3)
	{
		str = "fdologin.txt";
	}
	in.open(str);
	cout << "data for " << str1 << " is " << endl;
	while (!in.eof())
	{
		in >> str;
		cout << str << " ";
		in >> str;
		cout << str << " ";
		in >> str;
		cout << str << endl;
	}
	in.close();
}
void filing::writecitizen(string f, string l, long long int cnic, string add, string city, string state, string blood, string gender, long long int con,dob d)
{
	write.open("registeredcitizen.txt", ios::app);
	write << cnic << endl; write << f << endl << l << endl;
	write << add << endl;
	write << city << endl << state << endl;
	write << blood << endl << gender << endl;
	write << con;
	write << endl;
	write << d.y << endl << d.m << endl  << d.d << endl;
}
void filing::readsupplier(Supplier* sup,int n)
{
	string id, nat,vaccin[2];
	ifstream rr;
	rr.open("supplier.txt");
	for (int i = 0; i < n; i++)
	{
		rr >> id;
		rr >> nat;
		rr >> vaccin[0];
		rr >> vaccin[1];
	}
	rr >> id;
	rr >> nat; 
	rr >> vaccin[0];
	rr >> vaccin[1];
	sup->inputid(id);
	sup->inputnation(nat);
	sup->inputvac(vaccin);
	rr.close();
}
void filing::readsupplier()
{
	string id, nat, vaccin[2];
	ifstream rr;
	rr.open("supplier.txt");
	while (!rr.eof())
	{
		rr >> id;
		rr >> nat;
		rr >> vaccin[0];
		rr >> vaccin[1];
		cout << id << endl << nat << endl << vaccin[0] << ' ' << vaccin[1] << endl;
	}
	

	rr.close();
}
int filing::countsupplier()
{
	ifstream r;
	string id, nationality;
	int count=0;
	r.open("supplier.txt");
	while (!r.eof())
	{
		r >> id;
		
		r >> nationality;
		r >> id;
		r >> id;
		count++;
	}
	r.close();
	return count;
}
void filing::writesupplier(string id, string nationality,string vacc[])
{
	write.open("supplier.txt", ios::app);
	write << id << " " << nationality << " "<<vacc[0] << " ";
	if (vacc[1]=="0")
	{
		cout << endl;
	}
	else
	{
		write << vacc[1] << endl;
	}
	write.close();
}
bool filing::loginread(string f, string l, string p, int num)
{
	string str, ff, ll, pp;
	if (num == 1)
	{
		str = "adminlogin.txt";
	}
	else if (num == 0)
	{
		str = "superadminlog.txt";
	}
	else if (num == 2)
	{
		str = "doctorlogin.txt";
	}
	else if (num == 3)
	{
		str = "fdologin.txt";
	}
	read.open(str);
	while (!read.eof())
	{
		read >> ff;
		read >> ll;
		read >> pp;
		if (ff == f && pp == p && ll == l)
		{
			cout << "accesed" << endl;
			return true;
		}

	}
	read.close();
	cout << "cant be accessed " << endl;
	return false;

}
bool warehouse_check(string location)
{
	string loc , pop;
	ifstream in;
	in.open("population.txt");
	while (!in.eof())
	{
		in >> loc;
		in >> pop;
		if (loc==location)
		{
			return true;
		}
	}
	in.close();
	return 0;
}
class warehouse:public Admin
{
protected:
	string warehouse_name, warehouse_location;
	string warehouse_capacity;
	Admin adminOBJ;
	public:
		void createwarehouse()
		{
			cout << "input name" << endl;
			cin >> warehouse_name;
			cout << "input location" << endl;
			cin >> warehouse_location;
			cout << "input capacity" << endl;
			cin >> warehouse_capacity;

			
			ofstream in;
			in.open("warehouse.txt");
			while (!in.eof())
			{
				in << warehouse_name;
				in << warehouse_location;
				in << warehouse_capacity;
				
			}
		}
		void transfermed(Admin admin)
		{
			cout << "input warehouse name " << endl;
			cin >> warehouse_name;
			cout << "input warehouse location" << endl;
			cin >> warehouse_location;
			cout << "input capacithy" << endl;
			cin >> warehouse_capacity;
			int temp = 0;
			bool check_ware =	warehouse_check(warehouse_location);
			if (check_ware == true)
			{


				/*cout << "input capacity" << endl;
				cin >> warehouse_capacity;*/
				adminOBJ = admin;
				string tempp;
				ifstream in;
				in.open("warehouse.txt");
				while (!in.eof())
				{
					in >> tempp;
			temp++;
					
				}

				in.close();
				in.open("warehouse.txt");
				write.open("ttemp.txt");
				int ee = 0;
				while (!in.eof())
				{
					in >> tempp;
					write << tempp << endl;
					if (tempp == "-1")
					{
						ee++;
					}
				}
				in.close();
				write.close();
				string place;

				in.open("ttemp.txt");
				write.open("warehouse.txt");
				ee = 0;
				while (ee<temp-2)
				{
					in >> place;
					if (place == warehouse_location)
					{
						write << place << endl;
						in >> place;
						write << place << endl;
						write << admin.batchid << endl;
						write << admin.qunatity << endl;
					}
					
					
					else
					{
						write << place << endl;
					}
					ee++;
				}
				in.close();
				write.close();
			}
		}
};
void filing::loginwrite(string f, string l, string p,string q, int num)
{
	string str;
	if (num == 1)
	{
		str = "adminlogin.txt";
	}
	else if (num == 2)
	{
		str = "doctorlogin.txt";
	}
	else if (num == 3)
	{
		str = "fdologin.txt";
	}
	write.open(str, ios::app);
	write << f << " " << l << " " << p <<" "<<q<< endl;
	write.close();
}
void filing::loginwrite(string f, string l, string p, int num)
{
	string str;
	if (num == 1)
	{
		str = "adminlogin.txt";
	}
	else if (num == 2)
	{
		str = "doctorlogin.txt";
	}
	else if (num == 3)
	{
		str = "fdologin.txt";
	}
	write.open(str, ios::app);
	write << f << " " << l << " " << p << endl;
	write.close();
}
void login(int login_check)
{
	filing file;
	string f, l, p;
	if (login_check == 1 || login_check == 2 || login_check == 3)
	{
		cout << "input first name" << endl;
		cin >> f;
		cout << "input last name" << endl;
		cin >> l;
		cout << "input password" << endl;
		cin >> p;
		file.loginwrite(f, l, p, login_check);


	}

}

class VaccinationCenter
{
public:
	string location, vac_batch, vac_quantity;
	void loadbatch(string loc)
	{
		location = loc;
		ifstream in;
		int cc = 0;
		in.open("warehouse.txt");
		while (!in.eof())
		{
			in >> loc;
			if (loc == location)
			{
				
				in >> loc;

				while (1)
				{

					in >> loc;
					if (loc == "-1")
					{
						break;
					}
				
					in >> loc;
					if (loc == "-1")
					{
						break;
					}
					
					cc++;
				}
				break;
			}
		}
		in.close();
		string* bat = new string[cc];
		string* cap = new string[cc];
		cc = 0;
		in.open("warehouse.txt");
		while (!in.eof())
		{
			in >> loc;
			if (loc == location)
			{
				cout << "vaccine batches in warehouse are" << endl;
				cout << "id      quantity" << endl;
				in >> loc;

				while (1)
				{

					in >> loc;
					if (loc == "-1")
					{
						break;
					}
					bat[cc] = loc;
					cout << cc << " " << loc << "   ";
					in >> loc;
					if (loc == "-1")
					{
						break;
					}
					cap[cc] = loc;
					cout << loc << endl;
					cc++;
				}
				break;
			}
		}
		in.close();
		int dd = cc;
		cout << "input which batch " << endl;
		cin >> cc;
		vac_batch = bat[cc];
		vac_quantity = cap[cc];
	/*	delete[] bat;
		delete[] cap;*/

		in.open("warehouse.txt");
		write.open("ttemp.txt");
		int temp = 0;
		while (!in.eof())
		{
			in >> loc;
			write << loc << endl;
			
		}
		in.close();
		/*	in.open("warehouse.txt");
			write.open("ttemp.txt");
			for (int i = 0; i < temp; i++)
			{
				in >> loc;
				write << loc << endl;
			}*/
		
		write.close();
		in.open("ttemp.txt");
		write.open("warehouse.txt");
		while(!in.eof())
		{
			in >> loc;
			if (loc == location)
			{
				write << loc<<endl;
				in >> loc;
				write << loc << endl;
				for (int i = 0;i<dd ;i++)
				{
					in >> loc;
					if (i ==cc )
					{

						
					
					
						in >> loc;
						
					}
					else
					write << loc<<endl;
				}
			}
			else
			write << loc<<endl;
		}
		cout << vac_batch << "   " << vac_quantity << endl;
		in.close();
		write.close();
		in.open("vaccentre.txt");
		write.open("ttemp.txt");
		while (!in.eof())
		{
			in >> loc;
			write << loc<<endl;

		}
		in.close();
		write.close();
		in.open("ttemp.txt");
		write.open("vaccentre.txt");
		while (!in.eof())
		{
			in >> loc;
			if (loc == location)
			{
				write << loc<<endl;
				write << vac_batch << endl;
				write << vac_quantity << endl;
			}
			else
			{
				write << loc << endl;
			}
		}
		in.close();
		write.close();
	}
	
	};
	class gov_off
	{

	public:
		void show_percentvac()
		{

		}
};
int main()
{
	
		int cyear, cmonth, cday;
		//current time checker
		time_t t = time(0);   // get time now
		tm* now = localtime(&t);
		cyear = (now->tm_year + 1900);
		cmonth = (now->tm_mon + 1);
		cday = (now->tm_mday);
		cout << cyear<< '-' << cmonth << '-' << cday << "\n";
	
	int check;
	filing file;
	warehouse ware;
	cout << "------welcome to PAKISTAN  Vaccination centre------\npress any of the following option \n\n";

	cout << "press 1 for super admin access\npress 2 for admin access\npress 3 for citizen access\npress 4 for FDO access\npress 5 for doctor access \n";
	cin >> check;
	if (check == 1)
	{

		bool check_bool;
		string f, l, p;
		cout << "input first name " << endl;
		cin >> f;
		cout << "input last name " << endl;
		cin >> l;
		cout << "input password" << endl;
		cin >> p;
		check_bool = file.loginread(f, l, p, 0);


		if (check_bool == true)
		{
			int check_c;
			cout << "press 1 for create\npress 2 for retrieve\n";
			cin >> check_c;
			if (check_c == 1)
			{
				int check_c_c;
				cout << "press 1 to create admin\npress 2 to create FDO\npress 3 to create supplier\npress 4 to create Doctor\n";
				cin >> check_c_c;
				if (check_c_c == 1)
				{
					login(check_c_c);
				}
				else if (check_c_c == 2)
				{
					FDO fdo;
					filing file;
					string s[4];
					cout << "input first name" << endl;
					cin >> s[0];
					cout << "input last name" << endl;
					cin >> s[1];
					cout << "input password" << endl;
					cin >> s[2];
					cout << "input city" << endl;
					cin >> s[3];
					fdo.input_fdo(s[0], s[1], s[2],s[3]);
					file.loginwrite(s[0], s[1], s[2],s[3], 3);
				}
				else if (check_c_c == 3)
				{
					int vacc_quant = 0;
					string id, nationality, vacc[2];
					cout << "input id" << endl;
					cin >> id;
					cout << "input nationality" << endl; cin >> nationality;
					cout << "input how many vaccine should this suppplier have 1 or 2" << endl;
					cin >> vacc_quant;
					if (vacc_quant == 1)
					{
						cout << "input vaccine name" << endl;
						cin >> vacc[0];
						vacc[1] = "0";
					}
					else
					{
						cout << "first vaccine" << endl;
						cin >> vacc[0]; cout << "second vaccine" << endl;
						cin >> vacc[1];
					}

					if (nationality == "international" || nationality == "local")
					{

						file.writesupplier(id, nationality, vacc);
					}
				}
				else if (check_c_c == 4)
				{
					Doctor doctor;
					filing file;
					string s[4];
					cout << "input first name" << endl;
					cin >> s[0];
					cout << "input last name" << endl;
					cin >> s[1];
					cout << "input password" << endl;
					cin >> s[2];
					cout << "input city" << endl;
					cin >> s[3];
					doctor.input_fdo(s[0], s[1], s[2],s[3]);
					file.loginwrite(s[0], s[1], s[2],s[3], 2);

				}

			}
			else if (check_c == 2)
			{
				filing file;
				int check_c_c;
				cout << "press 1 to retrieve admin\npress 2 to  retrieve doctor\npress 3 to retrieve supplier\n";
				cin >> check_c_c;
				if (check_c_c == 1)
				{
					file.retrieveread(1);
				}
				else if (check_c_c == 3)
				{
					cout << "suppliers are " << endl;
					file.readsupplier();
				}

			}
		}
	}
	else if (check == 2)
	{

		bool check_bool;
		string f, l, p;
		cout << "input first name " << endl;
		cin >> f;
		cout << "input last name " << endl;
		cin >> l;
		cout << "input password" << endl;
		cin >> p;
		check_bool = file.loginread(f, l, p, 1);
		if (check_bool == true)
		{
			Admin admin;
			int check_c;
			cout << "press 1 to buy medicine\npress 2 to load in vaccine centre\npress 3 to create warehouse";
			cin >> check_c;
			if (check_c == 1)
			{
				int check_c_c;
				cout << "press 1 to buy \n";
				cin >> check_c_c;
				if (check_c_c == 1)
				{
					int count = 0;
					count = file.countsupplier();
					Supplier* sup = new Supplier[count];
					for (int i = 0; i < count; i++)
					{
						file.readsupplier(&sup[i], i);
					}
					cout << "press no. of which supplier to select" << endl;
					int check_c_c;
					for (int i = 0; i < count; i++)
					{
						cout << i << ": ";
						sup[i].output();
					}
					cout << endl;
					cin >> check_c_c;
					admin.callSupplier(sup[check_c_c]);
					admin.displaysupp();


					ware.transfermed(admin);
				}

			}
			else if (check_c == 2)
			{
				VaccinationCenter va;
				cout << "enter city" << endl;
				string str;
				cin >> str;
				va.loadbatch(str);

			}
			else if (check_c == 3)
			{
				ware.createwarehouse();
			}
		}
		else
		{
			cout << "credential incorrect " << endl;
		}
	}
	else if (check == 3)
	{
		int check_c = 0;
		cout << "press 1 for login\npress 2 for sign up\n" << endl;
		cin >> check_c;
		if (check_c == 1)
		{
			string str,str1;
			cout << "input your cnic" << endl;
			cin >> str;
			read.open("registeredcitizen.txt");
			while(!read.eof())
			{
				read >> str1;
				if (str1==str)
				{
					read >> str1;
					cout << "first name " << str1 << endl;
					read >> str1;
					cout << "last name " << str1 << endl;
					read >> str1;
					cout << "address " << str1 << endl;
					read >> str1;
					cout << "city " << str1 << endl;
					read >> str1;
					cout << "state " << str1 << endl;
					read >> str1;
					cout << "blood group " << str1 << endl;
					read >> str1;
					cout << "gender " << str1 << endl;
					read >> str1;
					cout << "phone number " << str1 << endl;
					read >> str1;
					cout << "BIRTHDAY " << str1 << endl;
					read >> str1; cout << " " << str1 << " ";
					read >> str1; cout << str1 << endl;
					break;

				}
			}
			read.close();
			read.open("eligiblelist.txt");
			while (!read.eof())
			{
				read >> str1;	
				if (str1==str)
				{
					read >> str1;
					if (str1=="1")
					{
						cout << "eligible for vaccination" << endl;
					}
					else if (str1 == "0")
					{
						cout << "not eligible" << endl;
					}

				}
			}
			read.close();

		}
		else if (check_c == 2)
		{
			dob d;
			filing file;
			citizen cit;
			string s[7] = { (" "," "," "," "," "," ") };
			long long int s1[2] = { (0,0) };
			cout << "input first name" << endl;
			cin >> s[0];
			cout << "input last name" << endl;
			cin >> s[1];
			cout << "input address" << endl;
			cin >> s[2];
			cout << "input city" << endl;
			cin >> s[3];
			cout << "input state" << endl;
			cin >> s[4];
			cout << "input blood group" << endl;
			cin >> s[5];
			cout << "input gender" << endl;
			cin >> s[6];
			cout << "input cnic" << endl;
			cin >> s1[0];
			cout << "input contact" << endl;
			cin >> s1[1];
			cout << "input day / month / year" << endl;
			cin >> d.d >> d.m >> d.y;
			cit.input_citizen(s[0], s[1], s1[0], s[2], s[3], s[4], s[5], s[6], s1[1],d);
			file.writecitizen(s[0], s[1], s1[0], s[2], s[3], s[4], s[5], s[6], s1[1],d);
		}
	}
	else if (check == 4)
	{
	int check_c;
	cout << "press 1 to check eligibility of citizen" << endl;
	cin >> check_c;
	if (check_c == 1)
	{
		string a;
		dob dd;
		filing file;
		cout << "input cnic" << endl;
		cin >> a;
		dd=file.fdoread(a);
		if (dd.y==0)
		{
			cout << "cnic doesnt exists" << endl;
		}
		else
		{
			dd.y = cyear - dd.y;
			cout << dd.y << " " << dd.m << " " << dd.d << endl;
			if (dd.y < 50 && dd.y>10)
			{
				cout << endl;
				cout << "eligible for vaccine" << endl;
				file.eligiblefile(a);
			}
			else
			{
				cout << endl;
				cout << "person not eligible" << endl;
			}
		}
	}

	}
	else if (check == 5)
	{
	Doctor doc;
	string str,str1;
	cout << "input cnic of patient " << endl;
	cin >> str;
	cout << "press 1 to check patient \npress 2 to apply vaccine" << endl;
	int check_c;
	cin >> check_c;
	if (check_c == 1)
	{


		doc.checkpatient(str);
	}
	else if (check_c == 2)
	{


		read.open("registeredcitizen.txt");
		while (!read.eof())
		{
			read >> str1;
			if (str1 == str)
			{
				read >> str1;
				read >> str1;
				read >> str1;
				read >> str1;
				break;
			}
		}
		doc.applyvac(str1);
	}
 }
}
