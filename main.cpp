#include <iostream>
#include <limits>
#include "crud_operations.h"

void showMenu() {
    std::cout << "1. Add Book\n";
    std::cout << "2. List Books\n";
    std::cout << "3. Update Book\n";
    std::cout << "4. Delete Book\n";
    std::cout << "5. Add Author\n";
    std::cout << "6. List Authors\n";
    std::cout << "7. Add Borrower\n";
    std::cout << "8. List Borrowers\n";
    std::cout << "9. Add Borrow Record\n";
    std::cout << "10. List Borrow Records\n";
    std::cout << "11. Exit\n";
}

int main() {
    // Initialize the database schema
    storage.sync_schema();

    int choice;
    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
        switch (choice) {
            case 1: {
                Book book;
                std::cout << "Enter title: ";
                std::getline(std::cin, book.title);
                std::cout << "Enter author ID: ";
                std::cin >> book.author_id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
                std::cout << "Enter genre: ";
                std::getline(std::cin, book.genre);
                book.is_borrowed = false;

                // Debug print
                std::cout << "Captured Book Data: " << book.title << ", " << book.author_id << ", " << book.genre << "\n";

                addBook(book);
                break;
            }
            case 2: {
                auto books = listBooks();
                for (const auto& book : books) {
                    std::cout << "ID: " << book.id << ", Title: " << book.title << ", Author ID: " << book.author_id << ", Genre: " << book.genre << ", Borrowed: " << (book.is_borrowed ? "Yes" : "No") << "\n";
                }
                break;
            }
            case 3: {
                Book book;
                std::cout << "Enter book ID to update: ";
                std::cin >> book.id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
                std::cout << "Enter new title: ";
                std::getline(std::cin, book.title);
                std::cout << "Enter new author ID: ";
                std::cin >> book.author_id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
                std::cout << "Enter new genre: ";
                std::getline(std::cin, book.genre);
                std::cout << "Is borrowed (1 for Yes, 0 for No): ";
                std::cin >> book.is_borrowed;
                updateBook(book);
                break;
            }
            case 4: {
                int bookId;
                std::cout << "Enter book ID to delete: ";
                std::cin >> bookId;
                deleteBook(bookId);
                break;
            }
            case 5: {
                Author author;
                std::cout << "Enter author name: ";
                std::getline(std::cin, author.name);
                addAuthor(author);
                break;
            }
            case 6: {
                auto authors = listAuthors();
                for (const auto& author : authors) {
                    std::cout << "ID: " << author.id << ", Name: " << author.name << "\n";
                }
                break;
            }
            case 7: {
                Borrower borrower;
                std::cout << "Enter borrower name: ";
                std::getline(std::cin, borrower.name);
                std::cout << "Enter borrower email: ";
                std::getline(std::cin, borrower.email);
                addBorrower(borrower);
                break;
            }
            case 8: {
                auto borrowers = listBorrowers();
                for (const auto& borrower : borrowers) {
                    std::cout << "ID: " << borrower.id << ", Name: " << borrower.name << ", Email: " << borrower.email << "\n";
                }
                break;
            }
            case 9: {
                BorrowRecord record;
                std::cout << "Enter book ID: ";
                std::cin >> record.book_id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
                std::cout << "Enter borrower ID: ";
                std::cin >> record.borrower_id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
                std::cout << "Enter borrow date: ";
                std::getline(std::cin, record.borrow_date);
                std::cout << "Enter return date: ";
                std::getline(std::cin, record.return_date);
                addBorrowRecord(record);
                break;
            }
            case 10: {
                auto records = listBorrowRecords();
                for (const auto& record : records) {
                    std::cout << "ID: " << record.id << ", Book ID: " << record.book_id << ", Borrower ID: " << record.borrower_id << ", Borrow Date: " << record.borrow_date << ", Return Date: " << record.return_date << "\n";
                }
                break;
            }
            case 11:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 11);

    return 0;
}