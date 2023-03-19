#include <iostream>
#include <vector>

using namespace std;

int globalID[4] = {0, 0, 0, 0};

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
    Publisher(string name = "temp", string location = "temp")
    {
        this->name = name;
        this->location = location;
        globalID[0]++;
        id = globalID[0];
    }
};

class Book
{
private:
    int id;
    bool borrowed;
    string name;
    Publisher publisher;
    BookType type;

public:
    Book(string name, Publisher publisher, BookType type)
    {
        this->name = name;
        this->publisher = publisher;
        this->type = type;
        globalID[1]++;
        id = globalID[1];
        borrowed = false;
    }
    void showInfo()
    {
        cout << id << ". " << name << endl;
    }
    bool operator==(const Book &secondbook)
    {
        if (this->id == secondbook.id)
        {
            return true;
        }
        else
            return false;
    };
    BookType returnBookType ()
    {
        return type;
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
        this->id = id;
        this->name = name;
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
        this->name = name;
        this->position = position;
        globalID[2]++;
        id = globalID[2];
    }
    Book findBook(Book wantedBook)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (wantedBook == books[i])
            {
                return books[i];
            }
        }
    }
    vector<Book> returnAvailabeBook()
    {
        return books;
    }
    void addBook(Book bookToAdd)
    {
        books.push_back(bookToAdd);
    }
    vector<Book> returnBasedOnType(BookType requestedType)
    {
        vector<Book> requestedBooks;
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].returnBookType() == requestedType)
            {
                requestedBooks.push_back(books[i]);
            }
        }
        return requestedBooks;
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

int main()
{
}