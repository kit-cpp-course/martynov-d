#pragma once
#include "stdafx.h"

class iTerminal;
class Config;

class Builder {
private:
	void build(iTerminal * terminal, Config * cfg);
public:
	void run(iTerminal *, Config *);
};