#include <sstream>
#include "MovieRepositoryFile.h"

void MovieRepositoryFile::loadFromFile() {
    ifstream fin(this->filename);
    if (!fin.is_open()) {
        throw RepositoryException("File could not be opened!");
    }

    this->movies = vector<Movie>();
    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        if (tokens.size() != 4) {
            continue;
        }
        string title = tokens[0];
        string genre = tokens[1];
        int year = stoi(tokens[2]);
        string mainActor = tokens[3];
        Movie movie(title, genre, year, mainActor);
        this->movies.push_back(movie);
    }
}

MovieRepositoryFile::MovieRepositoryFile(const string &filename) {
    this->filename = filename;
    this->loadFromFile();
}

void MovieRepositoryFile::writeToFile() {
    ofstream fout(this->filename);
    if (!fout.is_open()) {
        throw RepositoryException("File could not be opened!");
    }
    for (const auto &movie : this->movies) {
        fout << movie << "\n";
    }
}

void MovieRepositoryFile::add(const Movie &movie) {
    this->loadFromFile();
    MovieRepository::add(movie);
    this->writeToFile();
}

void MovieRepositoryFile::remove(const Movie &movie) {
    this->loadFromFile();
    MovieRepository::remove(movie);
    this->writeToFile();
}

void MovieRepositoryFile::update(const Movie &movie) {
    this->loadFromFile();
    MovieRepository::update(movie);
    this->writeToFile();
}

MovieRepositoryFile::~MovieRepositoryFile() {
//    this->writeToFile();
//    this->movies.clear();
}

const vector<Movie> &MovieRepositoryFile::getAll() const {
    return MovieRepository::getAll();
}

int MovieRepositoryFile::size() const {
    return MovieRepository::size();
}

const Movie &MovieRepositoryFile::getMovie(int index) const {
    return MovieRepository::getMovie(index);
}

int MovieRepositoryFile::find(const Movie &movie) const {
    return MovieRepository::find(movie);
}

MovieRepositoryFile::MovieRepositoryFile() {
    this->filename = "";
}
