include <vector>
include <iostream>
using namespace std;

class Trip{
	public:
		
	private:
		vector<string> oweLog;
		string tripTitle;
};

class Person{
	public:
		Person(string pName); /// Creates person with empty debtsTo
		Person(string pName, Transaction purchase); /// Creates person with initialized debtsTo
		void addDebt(string debt); /// <Name>$<amount>
		string getDebts();
	private:
		string name;
		vector<string> debtsTo; /// <Name>$<amount>

};

class Transaction{
	public:
		Transaction(string purchaseData); // <t>[Title]<pM>[Purchase maker]<a>[ammount]<o>[person who owes]...?<i>
		
		string getTitle();
		Person getBuyer();
		double getAmount();
		void getOwers(const vector<Person> &owers);
	private:
		double price;
		string title;
		vector<Person> whoOwes;
		bool buyerIncluded;
		
};

int main(int argc, char[] *argv) {
// Spaghetti-12.50-Annie-|Kai|
// <Kai>
// <t-Parking<pM-Annie<a-40<o-Kai<o-Sarah<o-Kate<o-Dom<i-OAnnie
// if <pMAnnie <o- should create a number for annie
}

