#pragma once
#include "stdafx.h"

class iTerminal;
class Config;

class Divider {
private:
	void divide(iTerminal *, Config *, std::string);
public:
	void run(iTerminal *, Config *);
};