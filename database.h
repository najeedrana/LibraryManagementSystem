#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite_orm/sqlite_orm.h>
#include "entities.h"

inline auto initStorage() {
    using namespace sqlite_orm;
    return make_storage("library.db",
        make_table("books",
            make_column("id", &Book::id, primary_key().autoincrement()),
            make_column("title", &Book::title),
            make_column("author_id", &Book::author_id),
            make_column("genre", &Book::genre),
            make_column("is_borrowed", &Book::is_borrowed)),
        make_table("authors",
            make_column("id", &Author::id, primary_key().autoincrement()),
            make_column("name", &Author::name)),
        make_table("borrowers",
            make_column("id", &Borrower::id, primary_key().autoincrement()),
            make_column("name", &Borrower::name),
            make_column("email", &Borrower::email)),
        make_table("borrow_records",
            make_column("id", &BorrowRecord::id, primary_key().autoincrement()),
            make_column("book_id", &BorrowRecord::book_id),
            make_column("borrower_id", &BorrowRecord::borrower_id),
            make_column("borrow_date", &BorrowRecord::borrow_date),
            make_column("return_date", &BorrowRecord::return_date))
    );
}

#endif // DATABASE_H