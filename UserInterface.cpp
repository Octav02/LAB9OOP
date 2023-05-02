#include "UserInterface.h"

void UserInterface::printMenu() {
    cout << "1. Add movie" << endl;
    cout << "2. Remove movie" << endl;
    cout << "3. Update movie" << endl;
    cout << "4. Print all movies" << endl;
    cout << "5. Print movies by title" << endl;
    cout << "6. Print movies by year" << endl;
    cout << "7. Print sorted movies by title" << endl;
    cout << "8. Print sorted movies by genre" << endl;
    cout << "9. Print sorted movies by year" << endl;
    cout << "10. Print sorted movies by main actor" << endl;
    cout << "11. Add movie to watchlist" << endl;
    cout << "12. Delete movie from watchlist" << endl;
    cout << "13. Generate watchlist" << endl;
    cout << "14. Save watchlist to file" << endl;
    cout << "15. Print watchlist" << endl;
    cout << "16. Undo" << endl;
    cout << "0. Exit" << endl;
}

void UserInterface::addMovie() {
    string title, genre, mainActor;
    int year;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter genre: ";
cin >> genre;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter main actor: ";
    cin >> mainActor;
    try {
        this->service.addMovie(title, genre, year, mainActor);
    }
    catch (const ValidationException &exception) {
        cout << exception << endl;
    }
    catch (const RepositoryException &exception) {
        cout << exception << endl;
    }
}

void UserInterface::removeMovie() {
    string title, genre, mainActor;
    int year;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter genre: ";
    cin >> genre;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter main actor: ";
    cin >> mainActor;
    try {
        this->service.removeMovie(title, genre, year, mainActor);
    }
    catch (const RepositoryException &exception) {
        cout << exception << endl;
    }
}

void UserInterface::updateMovie() {
    string title, genre, mainActor;
    int year;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter genre: ";
    cin >> genre;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter main actor: ";
    cin >> mainActor;
    try {
        this->service.updateMovie(title, genre, year, mainActor);
    }
    catch (const ValidationException &exception) {
        cout << exception << endl;
    }
    catch (const RepositoryException &exception) {
        cout << exception << endl;
    }
}

void UserInterface::printAllMovies() {
    vector<Movie> movies = this->service.getAll();
    for (const Movie& movie : movies) {
        cout << movie << endl;
    }
}

void UserInterface::printMoviesByTitle() {
    string title;
    cout << "Enter title: ";
    cin >> title;
    vector<Movie> movies = this->service.getMoviesByTitle(title);
    for (const Movie& movie : movies) {
        cout << movie << endl;
    }
}

void UserInterface::printMoviesByYear() {
    int year;
    cout << "Enter year: ";
    cin >> year;
    vector<Movie> movies = this->service.getMoviesByYear(year);
    for (const Movie& movie : movies) {
        cout << movie << endl;
    }
}

void UserInterface::printSortedMoviesByTitle() {
    bool ascending;
    cout << "Ascending? (1/0): ";
    cin >> ascending;
    vector<Movie> movies = this->service.sortMoviesByTitle(ascending);
    for (const Movie& movie : movies) {
        cout << movie << endl;
    }
}

void UserInterface::printSortedMoviesByGenre() {
    bool ascending;
    cout << "Ascending? (1/0): ";
    cin >> ascending;
    vector<Movie> movies = this->service.sortMoviesByGenre(ascending);
    for (const Movie& movie : movies) {
        cout << movie << endl;
    }
}

void UserInterface::printSortedMoviesByYear() {
    bool ascending;
    cout << "Ascending? (1/0): ";
    cin >> ascending;
    vector<Movie> movies = this->service.sortMoviesByYear(ascending);
    for (const Movie& movie : movies) {
        cout << movie << endl;
    }
}

void UserInterface::printSortedMoviesByMainActor() {
    bool ascending;
    cout << "Ascending? (1/0): ";
    cin >> ascending;
    vector<Movie> movies = this->service.sortMoviesByMainActor(ascending);
    for (const Movie& movie : movies) {
        cout << movie << endl;
    }
}

void UserInterface::addToWatchlist() {
    string title, genre, mainActor;
    int year;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter genre: ";
    cin >> genre;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter main actor: ";
    cin >> mainActor;
    try {
        this->service.addToWatchlist(title, genre, year, mainActor);
    }
    catch (const RepositoryException &exception) {
        cout << exception << endl;
    }
}

void UserInterface::deleteFromWatchlist() {
    string title;
    cout << "Enter title: ";
    cin >> title;
    try {
        this->service.deleteFromWatchlist(title);
    }
    catch (const RepositoryException &exception) {
        cout << exception << endl;
    }
}

void UserInterface::generateWatchlist() {
    int numberOfMovies;
    cout << "Enter number of movies: ";
    cin >> numberOfMovies;
    try {
        this->service.generateWatchlist(numberOfMovies);
    }
    catch (const RepositoryException &exception) {
        cout << exception << endl;
    }
}

void UserInterface::saveWatchlistToFile() {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    try {
        this->service.saveWatchlistToFile(filename);
    }
    catch (const RepositoryException &exception) {
        cout << exception << endl;
    }
}

void UserInterface::printWatchlist() {
    vector<Movie> movies = this->service.getWatchlist();
    for (const Movie& movie : movies) {
        cout << movie << endl;
    }
}

void UserInterface::undo() {
    try {
        this->service.doUndo();
    }
    catch (const RepositoryException &exception) {
        cout << exception << endl;
    }
}

void UserInterface::run() {
    while (true) {
        this->printMenu();
        int command;
        cout << "Enter command: ";
        cin >> command;
        switch (command) {
            case 0:
                return;
            case 1:
                this->addMovie();
                break;
            case 2:
                this->removeMovie();
                break;
            case 3:
                this->updateMovie();
                break;
            case 4:
                this->printAllMovies();
                break;
            case 5:
                this->printMoviesByTitle();
                break;
            case 6:
                this->printMoviesByYear();
                break;
            case 7:
                this->printSortedMoviesByTitle();
                break;
            case 8:
                this->printSortedMoviesByGenre();
                break;
            case 9:
                this->printSortedMoviesByYear();
                break;
            case 10:
                this->printSortedMoviesByMainActor();
                break;
            case 11:
                this->addToWatchlist();
                break;
            case 12:
                this->deleteFromWatchlist();
                break;
            case 13:
                this->generateWatchlist();
                break;
            case 14:
                this->saveWatchlistToFile();
                break;
            case 15:
                this->printWatchlist();
                break;
            case 16:
                this->undo();
                break;
            default:
                cout << "Invalid command!" << endl;
                break;
        }
    }
}