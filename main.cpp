#include <iostream>
#include <string>

#include "project.h"

using namespace std;

int main() {
    Project p = Project("4234234", "Project X", "Here");
    
    cout << p.toString();
    return 0;
}
