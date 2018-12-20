#pragma once
#include "stdafx.h"

class iTerminal;

class Config {
private:
	unsigned _fileQuantity;
	unsigned _bufferSize;

public:
	void loadConfig(iTerminal *);
	void saveConfig();
	void setDefaultConfig();
	unsigned fileQuantity();
	unsigned bufferSize();

};