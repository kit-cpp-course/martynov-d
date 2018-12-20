#pragma once
#include "stdafx.h"
#include "iTerminal.h"


class Terminal : public iTerminal{
private:
	int menuSize;
	void printMenu(int);
	std::string infoText;

public:
	void run() override;
	
	void print(std::string) override;
	void print(char *, unsigned) override;
	void adToInfo(std::string) override;
	void printInfo() override;
	std::string readLine() override;
};