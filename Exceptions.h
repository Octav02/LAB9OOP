#pragma once
#include <string>
#include <utility>

class ValidationException {
private:
    std::string message;
public:
    ValidationException(std::string message) : message{std::move(message)} {}
    friend std::ostream &operator<<(std::ostream &os, const ValidationException &exception);
};

class RepositoryException {
private:
    std::string message;
public:
    RepositoryException(std::string message) : message{std::move(message)} {}

    friend std::ostream &operator<<(std::ostream &os, const RepositoryException &exception);

};