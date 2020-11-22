#include "Lab3.hpp"
#include "Lab2.hpp"

//const char *path = "Lab2Lib/pr"

int spawnPr() {
    int status = 0;
    char *path;
    path = (char*)malloc(sizeof(char) * 256);
    cout << "Введите имя процесса: ";
    cin >> path;

    pid_t pid;
    pid = fork();

    if (pid == 0) {
        execl(path, path, NULL);
	cout << "PID: " << getpid() << endl;
    } else if (pid < 0)
        status = -1;
    else if (waitpid(pid, &status, 0) != pid)
        status = -1;

    return status;
}

int spawnPrFone() {
    int status = 0;
    char *path;
    path = (char*)malloc(sizeof(char) * 256);
    cout << "Введите имя процесса: ";
    cin >> path;

    pid_t pid;
    pid = fork();

    if (pid == 0) {
        execl(path, path, NULL);
	cout << "PID: " << getpid() << endl;
        _exit (EXIT_FAILURE);
    } else if (pid < 0)
        status = -1;
    else if (waitpid(pid, &status, WNOHANG) != 0)
        status = -1;

    return status;
}

void signal_handler(int signal_num)
{
    cout << "The interrupt signal is (" << signal_num << "). \n";
}

void catchSignal()
{
    int a, i = 0, k=0;
    signal(SIGABRT, signal_handler);
    cout << "Сколько сигнал хотите обработать?\n";
    cin >> a;
    while(i!=a)
    {
	k++;
        cout << k << ". Сигнал обработан" << endl;
        i++;
    }
}
