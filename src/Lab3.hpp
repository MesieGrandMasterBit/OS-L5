#ifndef LAB3_H
#define LAB3_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string>
#include <sys/stat.h>
#include <cstdlib>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <csignal>

using namespace std;

// Help function
void showMenu();
void prArguments();
void prReadme();
void Help();

int spawnPr();
int spawnPrFone();

void catchSignal();
void signal_handler(int signal_num);

#endif
