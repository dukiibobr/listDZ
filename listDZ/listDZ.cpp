#include <iostream>
#include <fstream>
#include <list>
using namespace std;

struct tick
{
	string destination;
	int flightNum;
	string passengerInitials;
	int departureDate;
};

class Tickets {
	list<tick>tickets;
public:
	Tickets():tickets(){}
	Tickets(tick t) :tickets{ t } {}
	
	void addTicket(tick t) {
		tickets.push_back(t);
	}

	void deleteByNum(int num) {
		for (auto it = tickets.begin();it != tickets.end();it++) {
			if (it->flightNum==num)
			{
				tickets.erase(it);
				cout << "ticket deleted" << endl;
				return;
			}
		}
		cout << "wrong number" << endl;
	}

	void printbyNum(int num) {
		for (const auto& it : tickets)
		{
			if (it.flightNum == num)
			{
				cout << "destination: " << it.destination << endl;
				cout << "flightNum: " << it.flightNum << endl;
				cout << "passengerInitials: " << it.passengerInitials << endl;
				cout << "departureDate: " << it.departureDate << endl << endl << endl;
				return;
			}
		}
		cout << "wrong number" << endl;
	}

	void printAll() {
		for (const auto& it:tickets)
		{
			cout << "destination: " << it.destination << endl;
			cout << "flightNum: " << it.flightNum << endl;
			cout << "passengerInitials: " << it.passengerInitials << endl;
			cout << "departureDate: " << it.departureDate << endl << endl<<endl;
		}
	}

	static bool compare(const tick& a, const tick& b) {
		return a.departureDate < b.departureDate;
	}
	void sortByDate() {
		tickets.sort(compare);
	}



	void addToFile() {
		ofstream out("flightTickets.txt");
		for (auto it = tickets.begin();it != tickets.end();it++)
		{
			out << it->destination << " ";
			out << it->flightNum <<  " ";
			out << it->passengerInitials <<  " ";
			out << it->departureDate<<" "<< endl;
		}
		out.close();
	}

	void readFromFile() {
		ifstream in("flightTickets.txt");
		if (!in.is_open())
		{
			cout << "file not found" << endl;
			return;
		}
		tickets.clear();

		tick t;
		while (in>>t.destination >> t.flightNum >> t.passengerInitials >> t.departureDate)
		{
			tickets.push_back(t);
		}
		in.close();
	}



};

int main()
{
	Tickets t;
	tick t2({"kolodenka",228,"KDM",30});
	tick t3({"kyiv",3,"mok",21});
	t.addTicket(t2);
	t.addTicket(t3);

	int choice;
	do
	{

		cout << "---functions---" << endl << endl;
		cout << "1			  print all" << endl;
		cout << "2			  print by flight num" << endl;
		cout << "3			  add" << endl;
		cout << "4			  delete" << endl;
		cout << "5			  sort by date" << endl;
		cout << "6			  add to file" << endl;
		cout << "7			  read from file" << endl;
		cout << "0			  return" << endl;

		cout << "choice: ";cin >> choice;


		switch (choice)
		{
		case 1:
			t.printAll();
			break;
		case 2:
		{
			int fn;
			cout << "enter flight number to add: ";cin >> fn;
			t.printbyNum(fn);
			break;
		}
		case 3:
		{
			tick temp;

			cout << "enter destination: ";cin >> temp.destination;
			cout << "enter flightNum: ";cin >> temp.flightNum;
			cout << "enter passengerInitials: ";cin >> temp.passengerInitials;
			cout << "enter departureDate: ";cin >> temp.departureDate;

			t.addTicket(temp);
		}
			break;
		case 4:
		{
			int fn2;
			cout << "enter flight number to delete: ";cin >> fn2;
			t.deleteByNum(fn2);
			break;
		}
		case 5:
			t.sortByDate();
			cout << "tickets sorted" << endl;
			break;
		case 6:
			t.addToFile();
			break;
		case 7:
			t.readFromFile();
			cout << "tickets: " << endl;
			t.printAll();
			break;
		case 0:
			cout << "end" << endl;
			break;
		default:
			break;
		}
	} while (choice!=0);
	



	return 0;
}
	   


