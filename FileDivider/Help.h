/* Help.h */

#pragma once
#include "stdafx.h"

/* Contains help information */
std::string help = "\
This program splits input file into blocks to protect input file infrormation.\n\n\
>>CONFIGURATIONS<<\n\
  Program configurations can be changed manually in cfg.txt file.\n\
  Please do NOT change anything in cfg.txt file except number values after \"=\" symbol.\n\
  If cfg.txt file is created on the program startup by default,\n\
  so if cfg.txt was damaged delete it. Otherwise program may not work correctly.\n\n\
>>MENU POINTS<<\n\
DIVIDE\n\
  Splits input file into multiple ones.\n\
  Make shure to save configuration file for file restortion.\n\n\
BUILD\n\
  Restores file from blocks.\n\
  Requires all blocks and cfg.txt that was used to divide this file.\n\n";