#pragma once

#include "Movie.h"
#include "Exceptions.h"
#include <vector>

using namespace std;

class MovieRepository {
protected:
    vector<Movie> movies;
public:
    MovieRepository() = default;

    virtual ~MovieRepository();

    virtual void add(const Movie &movie);

    virtual void remove(const Movie &movie);

    virtual void update(const Movie &movie);

    virtual const vector<Movie> &getAll() const;

    virtual int size() const;

    virtual const Movie &getMovie(int index) const;

    virtual int find(const Movie &movie) const;


};
