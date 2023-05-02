#include <iostream>
#include "Tests.h"
#include "UserInterface.h"
using namespace std;

int main() {
    Tests tests;
    tests.testAll();

    MovieRepositoryFile repo("/home/octav/CLionProjects/LAB9OOP/Persistence/movies.csv");
    Validator validator;
    Service service(repo, validator);

    UserInterface ui = UserInterface(service);
    ui.run();
    return 0;
}
