/*  Umer Mukhtar
    i20-0696    */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "System.h"

using namespace std;

int main()
{
    srand(unsigned(time(0)));
    System sys;
    sys.centralControl();
    cout << "\n\n**** **** **** **** **** CLOSING **** **** **** **** ****" << endl;
    return 0;
}