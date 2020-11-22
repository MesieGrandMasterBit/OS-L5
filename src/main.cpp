#include <dlfcn.h>
#include <iostream>
#include "Lab3.hpp"
#include "Lab2Lib/Lab2.h"
//#include "Lab2Lib/Lab2.cpp"

using namespace std;

void Menu()
{
	cout << "==========================" << endl;
	cout << "Сделайте ваш выбор:" << endl;
	cout << " a - Разработчики" << endl;
	cout << " u - Доступные аргументы" << endl;
	cout << " r - Описание" << endl;
	cout << " e - Пример" << endl;
	cout << "==========================" << endl;
	cout << "Введите аргумент: ";
}

void prArguments()
{
	cout << "==============================================================" << endl;
	cout << " 2 - Команды из лабораторной работы №2" << endl;
	cout << " p - Порождение процесса по его имени и возвращение с втроку ввода команд после завершения дочернего процесса" << endl;
	cout << " f - Перевод запускаемого процесса в фоновый режим" << endl;
	cout << " g - Получение и обрабатывание сигналов от внешних программ и ОС" << endl;
	cout << "==============================================================" << endl;
}

void prArguments2()
{
	cout << "==============================================================" << endl;
	cout << " m - Перемещение файла" << endl;
	cout << " c - Копирование файла" << endl;
        cout << " d - Удаление файла из данной папки" << endl;
	cout << " D - Удаление файла из другой папки" << endl;
	cout << " s - Подсчёт общего размера указанной файла" << endl;
	cout << " S - Подсчёт общего размера указанной директории" << endl;
	cout << " f - Отображение всех файлов в указанной директории" << endl;
	cout << " p - Отображение всех процессов из файловой системы procfs" << endl;
	cout << "==============================================================" << endl;
	cout << "ЕСЛИ ФАЙЛ НА УРОВЕНЬ ВЫШЕ, ТО ИСПОЛЬЗУЙТЕ В В НАЧАЛЕ ../" << endl;
}

void prReadme()
{
	cout << "==============================================================" << endl;
	cout << "Данная программа включает в себя:"<< endl;
	cout << "-Вызов команд из Лабораторной работы №2;" << endl;
	cout << "-Порождение процесса по его имени и возвращение с втроку ввода команд после завершения дочернего процесса;" << endl;
	cout << "-Перевод запускаемого процесса в фоновый режим;" << endl;
	cout << "-Получение и обрабатывание сигналов от внешних программ и ОС" << endl;
	cout << "==============================================================" << endl;
}

void CretFile()
{
	char* name;
	name = (char*)malloc(sizeof(char) * 256);
	cout << "Введите название файла: ";
	cin >> name;
	ofstream File;
	File.open(name);
	File.close();
}

int main()
{
	char command, camm, camm2;
	string path, fileName;
	int S, kf;
	void* handle = dlopen("./libfs.so", RTLD_LAZY);
	if (!handle) {
		cerr << "Cannot open library: " << dlerror() << endl;
		return 1;
	}
	char* dir;
	char* file;
	dir = (char*)malloc(sizeof(char) * 256);
	file = (char*)malloc(sizeof(char) * 256);
	do {
		cout << "\033c";
		Menu();
		cin >> command;
		switch(command)
		{
			case 'a' : cout << " Высотин Кирилл Евгеньевич \n Пахомов Илья Максимович \n Юрьев Юрий 		Вадимович"<< endl; 
				break;

			case 'u' : prArguments();
				do {
					cout << "Введите аргумент: " ;
     cin >> camm;
     switch(camm)
     {
     case '2' : prArguments2();
      do {
       cout << "Сколько хотите создать файлов: ";
       cin >> kf;
       for (int i=0;i<kf;i++) {
        CretFile();
       }
       cout << "Введите аргумент: ";
       cin >> camm2;
       switch(camm2)
       {
      case 'm' : { cout << "Введите название папки: ";
        cin >> path;
        cout << "Введите имя файла: ";
        cin >> fileName;
        cout << endl;
        typedef void (*moveFile_t)(string path, string fileName);
        moveFile_t moveFile = (moveFile_t) dlsym(handle, "moveFile");
	    if (!moveFile) {
		    cerr << "Cannot load symbol 'moveFile': " << dlerror() << endl;
		    dlclose(handle);
		    return 1;
	    }
        moveFile(path,fileName);
        } break;

       case 'c' : { cout << "Введите название папки: ";
        cin >> path;
        cout << "Введите имя файла: ";
        cin >> fileName;
        cout << endl;
        typedef void (*copyFile_t)(string path, string fileName);
        copyFile_t copyFile = (copyFile_t) dlsym(handle, "copyFile");
	    if (!copyFile) {
		    cerr << "Cannot load symbol 'copyFile': " << dlerror() << endl;
		    dlclose(handle);
		    return 1;
	    }
        copyFile(path,fileName);
        } break;


       case 'd' : { cout << "Введите название файла: ";
        cin >> fileName;
        typedef void (*deleteFile_t)(string fileName);
        deleteFile_t deleteFile = (deleteFile_t) dlsym(handle, "deleteFile");
	    if (!deleteFile) {
		    cerr << "Cannot load symbol 'deleteFile': " << dlerror() << endl;
		    dlclose(handle);
		    return 1;
	    }
        deleteFile(fileName);
        } break;

       case 'D' : { cout << "Введите название папки: ";
        cin >> path;
        cout << "Введите имя файла: ";
        cin >> fileName;
        typedef void (*DeleteFile_t)(string path, string fileName);
        DeleteFile_t DeleteFile = (DeleteFile_t) dlsym(handle, "DeleteFile");
	    if (!DeleteFile) {
		    cerr << "Cannot load symbol 'DeleteFile': " << dlerror() << endl;
		    dlclose(handle);
		    return 1;
	    }
        DeleteFile(path, fileName);
        } break;

       case 's' : { cout << "Введите название файла: ";
        cin >> file;
        typedef int (*getFileSize_t)(const char *fileName);
        getFileSize_t getFileSize = (getFileSize_t) dlsym(handle, "getFileSize");
	    if (!getFileSize) {
		    cerr << "Cannot load symbol 'FileSize': " << dlerror() << endl;
		    dlclose(handle);
		    return 1;
	    }

        cout << getFileSize(file) << " Kb" << endl;
        } break;

       case 'S' : { cout << "Введите имя папки: ";
        cin >> dir;
        typedef int (*getDirSize_t)(const char *dirName);
        getDirSize_t getDirSize = (getDirSize_t) dlsym(handle, "getDirSize");
	    if (!getDirSize) {
		    cerr << "Cannot load symbol 'DirSize': " << dlerror() << endl;
		    dlclose(handle);
		    return 1;
	    }
        cout << getDirSize(dir) << " Kb" << endl;
        } break;

       case 'f' : { cout << "Введите имя папки: ";
        cin >> dir;
        typedef void (*displayAllFiles_t)(const char *dirName);
        displayAllFiles_t displayAllFiles = (displayAllFiles_t) dlsym(handle, "displayAllFiles");
	    if (!displayAllFiles) {
		    cerr << "Cannot load symbol 'displayAllFiles': " << dlerror() << endl;
		    dlclose(handle);
		    return 1;
	    }
        displayAllFiles(dir);
        } break;

       case 'p' : { typedef int (*displayProc_t)();
        displayProc_t displayProc = (displayProc_t) dlsym(handle, "displayProc");
	    if (!displayProc) {
		    cerr << "Cannot load symbol 'displayProc': " << dlerror() << endl;
		    dlclose(handle);
		    return 1;
	    }
        displayProc();
        } break;

       default : cout << "Не понял. Попробуйте ещё раз" << endl;
	break;
       }
      cout << "Продолжить работу с аргументом '2'? (y)";
      cin >> camm2;
     } while(camm2 == 'y' || camm2 == 'Y');
	break;

     case 'p' :
      spawnPr();
      break;

     case 'f' :
      spawnPrFone();
      break;

     case 'g' :
      catchSignal();
      break;

    default : cout << "Не понял. Попробуйте ещё раз" << endl;
 }
    cout << "Продолжить работу с аргументом 'u'? (y)";
    cin >> camm;
   } while (camm == 'y' || camm == 'Y');
	break;

   case 'r' : prReadme();
    break;

   case 'e' : cout << "Всем ку, уважаемые дамы и господа" << endl;
    break;

   default : cout << "Каво? \n";
  }
  cout << "Продолжить работу? (y) ";
  cin >> command;
 } while (command == 'y' || command == 'Y');
 dlclose(handle);
 return 0;
}
