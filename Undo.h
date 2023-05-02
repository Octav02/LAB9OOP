#pragma once

#include "MovieRepositoryFile.h"


class ActiuneUndo {
public :
    virtual void undo() = 0;
    virtual ~ActiuneUndo() = default;
};

class UndoAdauga : public ActiuneUndo {
private:
    Movie movie;
    MovieRepositoryFile& repo;
public:
    UndoAdauga(MovieRepositoryFile& repo, const Movie& movie) :  repo{repo}, movie{movie} {};
    void undo() override;
};

class UndoSterge : public ActiuneUndo {
private:
    Movie movie;
    MovieRepositoryFile& repo;
public:
    UndoSterge(MovieRepositoryFile& repo, const Movie& movie) : repo{repo}, movie{movie} {};
    void undo() override;
};

class UndoModifica : public ActiuneUndo {
private:
    Movie movie;
    MovieRepositoryFile& repo;
public:
    UndoModifica(MovieRepositoryFile& repo, const Movie& movie) : repo{repo}, movie{movie} {};
    void undo() override;
};