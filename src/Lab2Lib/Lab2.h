#ifndef LAB2_H
#define LAB2_H

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

using namespace std;

// Основа
void showMenu();
void printArguments();
void printReadme();
void CreateFile();

// Копирование файла
extern "C" void copyFile(string path, string fileName);

// Перемещение файла
extern "C" void moveFile(string path, string fileName);

// Удаление файлов
extern "C" void deleteFile(string fileName);
extern "C" void DeleteFile(string path, string fileName);

// Процессы
int IsNumeric(const char* ccharptr_CharacterList);
extern "C" int displayProc();

// Показать все файлы
extern "C" void displayAllFiles(const char *dirName);

// Размер файла и директории
extern "C" int getFileSize(const char *fileName);
extern "C" int getDirSize(const char *dirName);

#endif
