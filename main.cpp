
#include "Tests.h"
#include "UserInterface.h"
using namespace std;

int main() {
    Tests tests;
    tests.testAll();

    AbstractRepository *repo = new MovieRepositoryFile("/home/octav/CLionProjects/LAB9OOP/Persistence/movies.csv");
    AbstractRepository* repo1 = new MovieRepository();
    Validator validator;
    Service service(repo1, validator);

    UserInterface ui = UserInterface(service);
    ui.run();
    delete repo;
    delete repo1;
    return 0;
}
