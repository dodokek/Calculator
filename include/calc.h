#ifndef CALC_H
#define CALC_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "fileUtils.h"

const int MAX_DEF_SIZE = 1000;

char* GetInputLine ();

int GetG ();

int GetN ();

int GetE ();

int GetT ();

int GetP ();

void SkipSpaces ();

#endif