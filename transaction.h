#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <vector>
using namespace std;

class Transaction{
	public:

/** Default Constructor
 * @brief: Creates an empty transaction
 **/
        Transaction();

/** Overloaded Constructor
 * @brief - initializes transactiond data from a given string
 * 
 * @param appData - String containing all necessary information
 */
		Transaction(string appData);

		vector<string> getOwers();
		string getTitle();
		double getAmount();
		string getBuyer();
		void addOwer(string ower);
        bool isDouble(string str);
	private:
		string title;
		string buyer;
		double amount;
		vector<string> owers;
		bool includeBuyer;
};
#endif