#ifndef ENTITIES_H
#define ENTITIES_H

#include <string>

struct Book {
    int id;
    std::string title;
    int author_id;
    std::string genre;
    bool is_borrowed;
};

struct Author {
    int id;
    std::string name;
};

struct Borrower {
    int id;
    std::string name;
    std::string email;
};

struct BorrowRecord {
    int id;
    int book_id;
    int borrower_id;
    std::string borrow_date;
    std::string return_date;
};

#endif // ENTITIES_H