#include <iostream>
#include <vector>

using namespace std;

enum BookType
{
    SCIENTIFIC,
    CRIME,
    FANTASY,
    HORROR,
    CLASSICS
};

class Publisher
{
private:
    int id;
    string name;
    string location;

public:
    Publisher(string name, string location)
    {
    }
};

class Book
{
private:
    int id;
    string name;
    BookType type;
    Publisher publisher;
    bool borrowed;

public:
    Book(string name, Publisher publisher, BookType type)
    {
    }
    void showInfo()
    {
        cout << id << ". " << name << endl;
    }
};

class Member
{
private:
    string id;
    string name;
    vector<Book> books; // smaller than 5

public:
    Member(string id, string name)
    {
        // TODO
    }
};

class Library
{
private:
    int id;
    string name;
    vector<Book> books;
    int position;

public:
    Library(string name, int position)
    {
        // TODO
    }
    void findBook()
    {
    }
    void returnAvailabeBook()
    {
    }
    void addBook()
    {
    }
    void returnBasedOnType()
    {
    }
};

class LibrariesHandler
{
private:
    // STUFF
public:
    void createLibrary(string name, int position)
    {
        // TODO
    }
    void addBook(int libId, string name, Publisher publisher, BookType type)
    {
        // TODO
    }
    void addBook(int libId, Book book)
    {
        // TODO
    }
    void addMember(string name, string id)
    {
        // TODO
    }
    vector<Book> getAllBooks(int libId)
    {
        // TODO
        // return [] if no library exists
    }
    string getAllBooksInfo(int libId)
    {
        // return a empty string if empty
    }
    vector<Book> filterByType(int libId, BookType type)
    {
        // retun [] if libId does not exist
    }
    string filterByTypeAndShowInfo(int libId, BookType type)
    {
        // return empty string if libId doesen't exist
    }
    bool borrow(string memberId, int libraryId, string name)
    {
        // TODO
    }
    bool returnBook(string memberId, int libraryId, string name)
    {
        // TODO
    }
    int size()
    {
        // TODO
    }
    Library findNearestLibraryByPosition(string name, int position)
    {
        // return -1 if this book doesen't exist
        // if the distance from two libraries was the same return the library with the shorter name
    }
    string findLibrariesHaveBook(string name, int position)
    {
        // TODO
    }
};