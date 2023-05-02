#pragma once

#include "MovieRepositoryFile.h"
#include "Validator.h"
#include "Undo.h"
#include <memory>
class Service {
private:
    MovieRepositoryFile repo;
    MovieRepository watchlist = MovieRepository();
    Validator validator;
    vector<unique_ptr<ActiuneUndo>> undoActions;
public:
    Service() = default;
    Service( const MovieRepositoryFile& repo, const Validator &validator);
    void addMovie(const string &title, const string &genre, int year, const string &mainActor);
    void removeMovie(const string &title, const string &genre, int year, const string &mainActor);
    void updateMovie(const string &title, const string &genre, int year, const string &mainActor);
    const vector<Movie> &getAll() const;
    int size() const;
    const Movie &getMovie(int index) const;
    int find(const string & title) const;

    void doUndo();

    vector<Movie> getMoviesByTitle(const string& title);
    vector<Movie> getMoviesByYear(int year);
    vector<Movie> sortMoviesByTitle(bool ascending);
    vector<Movie> sortMoviesByGenre(bool ascending);
    vector<Movie> sortMoviesByYear(bool ascending);
    vector<Movie> sortMoviesByMainActor(bool ascending);

    void addToWatchlist(const string& title, const string& genre, int year, const string& mainActor);
    void deleteFromWatchlist(const string& title);
    vector<Movie> getWatchlist();
    void generateWatchlist(int numberOfMovies);

    void saveWatchlistToFile(const string& filename);


};
