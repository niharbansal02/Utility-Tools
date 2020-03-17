#include <iostream>
#include <unistd.h>
#include <string.h>
#include <thread>
#include <chrono>
using namespace std;

int sleep3(long t)
{
    this_thread::sleep_for(chrono::milliseconds(t));
    return 1;
}

int main ()
{
    string a = "xrandr --output eDP-1 --brightness ";
    string b,c;
    double counter=1;
    for(int i = 0; i < 100; i++)
    {
        counter+=0.1;
        b = to_string(counter);
        c = a + b;
        system(c.c_str());
        sleep3(50);
    }
    
    b = to_string(1);
    c = a + b;
    system(c.c_str());

    return 0;
}