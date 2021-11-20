#include <iostream>
#include "Tries.h"
#define ll long long
using namespace std;

int main()
{
    Tries tries;
    tries.insert("their");
    tries.insert("there");
    tries.insert("answer");
    tries.insert("any");
    tries.insert("bye");
    cout<<tries.search("any");
	

	return 0;
}


