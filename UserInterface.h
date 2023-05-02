#pragma once

#include "Service.h"

class UserInterface {
private:
    Service& service;
public:
    UserInterface() = default;
    explicit UserInterface(Service& service) : service{service} {};
    void run();
    void printMenu();
    void addMovie();
    void removeMovie();
    void updateMovie();
    void printAllMovies();
    void printMoviesByTitle();
    void printMoviesByYear();
    void printSortedMoviesByTitle();
    void printSortedMoviesByGenre();
    void printSortedMoviesByYear();
    void printSortedMoviesByMainActor();
    void addToWatchlist();
    void deleteFromWatchlist();
    void generateWatchlist();
    void saveWatchlistToFile();
    void printWatchlist();
    void undo();

};