#pragma once
#include "stdafx.h"


class iTerminal {
public:
	virtual void run() = 0;

	virtual void print(std::string) = 0;
	virtual void print(char *, unsigned) = 0;
	virtual void adToInfo(std::string) = 0;
	virtual void printInfo() = 0;
	virtual std::string readLine() = 0;
}; 
