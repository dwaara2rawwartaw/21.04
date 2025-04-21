#include <iostream>
#include <cmath>
#include <signal.h>
#include <stdio.h>
#include <csignal>
#include <unistd.h>
enum Signal
{
    SIGHUP_SIGNAL,
    SIGINT_SIGNAL
};
using namespace std;
void signal_handler(int signum)
{
    cout << "Ha-ha-ha, ti loh " << Signal(signum) << " signal! ^-^" << endl; 
}
int main()
{
    if (signal(SIGHUP, signal_handler)==SIG_ERR)
    {
        cerr << "error Settin up SIGHUP handler" << endl;
        return 1;
    }
    if (signal(SIGINT, signal_handler)==SIG_ERR)
    {
        cerr << "error Settin up SIGINT handler" << endl;
        return 2;
    }
    cout << "Programm is Running!" << endl;
    while (true)
    {
        sleep(1);
    }
    return 0;
}