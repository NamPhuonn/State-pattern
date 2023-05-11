#pragma once
#ifndef HEADER_H
#define HEADER_H

#include<iostream>
using namespace std;


class DummyState {
private:
	string ORDER = "ORDER";
	string RECIEVE = "RECIEVE";
	string TRANSACTION = "TRANSACTION";
	string state = "";
public:
	DummyState();
	void paySuccess();
	void payFailed();
	void receiveProduct();
	string getState();
};

#endif
