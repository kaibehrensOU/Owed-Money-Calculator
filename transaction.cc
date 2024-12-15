#include "transaction.h"
#include <cctype>
using namespace std;

/// CONSTRUCTORS


/// @brief: Creates an empty transaction in the case that 
Transaction::Transaction(){
    title = "Invalid Transaction";
    buyer = "N/A";
    amount = 0;
    owers.push_back("no owers");
    includeBuyer = false;
}


Transaction::Transaction(string appData){
	includeBuyer = false;
	while(appData.find('>') != -1){
		string flag = appData.substr(appData.find('<') + 1, appData.find('>') - appData.find('<')-1);
		// cout << flag << endl;
		if(appData.find('>') < appData.length() - 1){
			appData = appData.substr(appData.find('>') + 1);
		} else {
			break;
		}
		string flagInfo = appData.substr(0, appData.find('<'));
		// cout << flagInfo << endl;
		if(flag == "t"){
			if(flagInfo != ""){
				title = flagInfo;
			} else {
				title = "Unnamed";
			}
		} else if(flag == "pm"){
			if(flagInfo != ""){
				buyer = flagInfo;
			} else {
				buyer = "*";
			}
		} else if(flag == "a"){
			if(flagInfo != "" && isDouble(flagInfo)){
				amount = stod(flagInfo);
			} else {
				amount = 0;
			}
		} else if(flag == "o"){
			if(flagInfo != ""){
				owers.push_back(flagInfo);
			}
		} else if(flag == "i"){
			includeBuyer = true;
		}
	}
}

bool Transaction::isDouble(string str){
	int decimal = str.find('.');
	for(int i = 0; i < str.length(); i++){
		if(i != decimal){
			if(!isdigit(str.at(i))){
				return false;
			}
		}
	}
	return true;
}
