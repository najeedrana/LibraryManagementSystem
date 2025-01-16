#ifndef CRUD_OPERATIONS_H
#define CRUD_OPERATIONS_H

#include "database.h"

auto storage = initStorage();

void addBook(const Book& book) {
    storage.insert(book);
}

std::vector<Book> listBooks() {
    return storage.get_all<Book>(sqlite_orm::where(sqlite_orm::c(&Book::title) != ""));
}

void updateBook(const Book& book) {
    storage.update(book);
}

void deleteBook(int bookId) {
    storage.remove<Book>(bookId);
}

void addAuthor(const Author& author) {
    storage.insert(author);
}

std::vector<Author> listAuthors() {
    return storage.get_all<Author>();
}

void addBorrower(const Borrower& borrower) {
    storage.insert(borrower);
}

std::vector<Borrower> listBorrowers() {
    return storage.get_all<Borrower>();
}

void addBorrowRecord(const BorrowRecord& record) {
    storage.insert(record);
}

std::vector<BorrowRecord> listBorrowRecords() {
    return storage.get_all<BorrowRecord>();
}

#endif // CRUD_OPERATIONS_H