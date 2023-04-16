#include <iostream>
#include <vector>

using namespace std;

float absoluteFunction(float v)
{
    if (v < 0)
        v *= -1;
    return v;
}

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
    static int ID;

public:
    Publisher(string name = "temp", string location = "temp")
    {
        this->name = name;
        this->location = location;
        ID++;
        id = ID;
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
    static int ID;

public:
    Book(string name, Publisher publisher, BookType type)
    {
        this->name = name;
        this->publisher = publisher;
        this->type = type;
        ID++;
        id = ID;
        borrowed = false;
    }
    string showInfo()
    {
        string tempString;
        tempString += to_string(id);
        tempString += ". ";
        tempString += name;
        tempString += "\n";
        return tempString;
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
    BookType returnBookType()
    {
        return type;
    }
    string returnName()
    {
        return name;
    }
    void borrowStatus(bool x)
    {
        borrowed = x;
    }
    int showID()
    {
        return id;
    }
};

class Member
{
private:
    string id;
    string name;
    vector<Book> books;

public:
    Member(string id, string name)
    {
        this->id = id;
        this->name = name;
    }
    bool borrowNewBook(Book wantedBook)
    {
        if (books.size() < 5)
        {
            books.push_back(wantedBook);
            return true;
        }
        return false;
    }
    void returnBook(string returningBook)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (returningBook == books[i].returnName())
            {
                books.erase(books.begin()+i);
            }
        }
    }
    string showMemberID()
    {
        return id;
    }
};

class Library
{
private:
    int id;
    string name;
    vector<Book> books;
    int position;
    static int ID;

public:
    Library(string name, int position)
    {
        this->name = name;
        this->position = position;
        ID++;
        id = ID;
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
    void addNewBook(Book bookToAdd)
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
    int showLibID()
    {
        return id;
    }
    string showLibraryName()
    {
        return name;
    }
    int showLibPosition()
    {
        return position;
    }
    void libraryBorrowStatus(bool x, int bookID)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].showID() == bookID)
            {
                books[i].borrowStatus(x);
                break;
            }
        }
    }
};

class LibrariesHandler
{
private:
    vector<Library> libraries;
    vector<Member> members;

public:
    void createLibrary(string name, int position)
    {
        Library tempLibrary(name, position);
        libraries.push_back(tempLibrary);
    }
    void addBook(int libId, string name, Publisher publisher, BookType type)
    {
        Book tempBook(name, publisher, type);
        for (int i = 0; i < libraries.size(); i++)
        {
            if (libId == libraries[i].showLibID())
            {
                libraries[i].addNewBook(tempBook);
                break;
            }
        }
    }
    void addBook(int libId, Book book)
    {
        for (int i = 0; i < libraries.size(); i++)
        {
            if (libId == libraries[i].showLibID())
            {
                libraries[i].addNewBook(book);
                break;
            }
        }
    }
    void addMember(string name, string id)
    {
        Member tempMember(name, id);
        members.push_back(tempMember);
    }
    vector<Book> getAllBooks(int libId)
    {
        for (int i = 0; i < libraries.size(); i++)
        {
            if (libId == libraries[i].showLibID())
            {
                return libraries[i].returnAvailabeBook();
            }
        }
    }
    string getAllBooksInfo(int libId)
    {
        vector<Book> tempBookVector;
        string tempString = "";
        for (int i = 0; i < libraries.size(); i++)
        {
            if (libId == libraries[i].showLibID())
            {
                tempBookVector = libraries[i].returnAvailabeBook();
                break;
            }
        }
        for (int i = 0; i < tempBookVector.size(); i++)
        {
            tempString += tempBookVector[i].showInfo();
        }
        return tempString;
    }
    vector<Book> filterByType(int libId, BookType type)
    {
        for (int i = 0; i < libraries.size(); i++)
        {
            if (libId == libraries[i].showLibID())
            {
                return libraries[i].returnBasedOnType(type);
            }
        }
    }
    string filterByTypeAndShowInfo(int libId, BookType type)
    {
        vector<Book> tempBookVector;
        string tempString = "";
        for (int i = 0; i < libraries.size(); i++)
        {
            if (libId == libraries[i].showLibID())
            {
                tempBookVector = libraries[i].returnBasedOnType(type);
                break;
            }
        }
        for (int i = 0; i < tempBookVector.size(); i++)
        {
            tempString += tempBookVector[i].showInfo();
        }
        return tempString;
    }
    bool borrow(string memberId, int libId, string name)
    {
        vector<Book> tempBookVector;
        int j = -1;
        int x = -1;

        for (int i = 0; i < libraries.size(); i++)
        {
            if (libId == libraries[i].showLibID())
            {
                tempBookVector = libraries[i].returnAvailabeBook();
                x = i;
                break;
            }
        }
        if (tempBookVector.size() == 0)
        {
            return false;
        }
        for (int i = 0; i < tempBookVector.size(); i++)
        {
            if (tempBookVector[i].returnName() == name)
            {
                j = i;
                break;
            }
        }
        for (int i = 0; i < members.size(); i++)
        {
            if (memberId == members[i].showMemberID() && j != -1)
            {
                libraries[x].libraryBorrowStatus(true, tempBookVector[x].showID());
                return members[i].borrowNewBook(tempBookVector[j]);
                break;
            }
        }
        return false;
    }
    void returnBook(string memberId, int libraryId, string name)
    {
        int libraryNumber = -1;
        for (int i = 0; i < libraries.size(); i++)
        {
            if (libraries[i].showLibID() == libraryId)
            {
                libraryNumber = i;
                break;
            }
        }
        for (int i = 0; i < members.size(); i++)
        {
            if (memberId == members[i].showMemberID())
            {
                members[i].returnBook(name);
                break;
            }
        }
        vector<Book> y = libraries[libraryNumber].returnAvailabeBook();
        for (int i = 0; i < y.size(); i++)
        {
            if (y[i].returnName() == name)
            {
                libraries[libraryNumber].libraryBorrowStatus(false, i);
                break;
            }
        }
    }
    int size()
    {
        return libraries.size();
    }
    Library findNearestLibraryByPosition(string name, int position)
    {
        vector<Library> tempLibraries;
        vector<Book> tempBookVector;
        Library closestLibrary("", -1);
        for (int j = 0; j < libraries.size(); j++)
        {
            tempBookVector = libraries[j].returnAvailabeBook();
            for (int i = 0; i < tempBookVector.size(); i++)
            {
                if (tempBookVector[i].returnName() == name)
                {
                    tempLibraries.push_back(libraries[j]);        //finds the book that we gave the name for from our libraries
                    break;
                }
            }
        }
        closestLibrary = tempLibraries[0];
        for (int i = 0; i < tempLibraries.size(); i++)
        {
            if (absoluteFunction(tempLibraries[i].showLibPosition() - position) < absoluteFunction(closestLibrary.showLibPosition() - position))
            {
                closestLibrary = tempLibraries[i];          //finds the closest library
            }
        }
        return closestLibrary;
    }
    string findLibrariesHaveBook(string name, int position)
    {
        vector<Book> tempBookVector;
        vector<Library> tempLibraries;
        Library x("", -1);
        string y = "";
        for (int j = 0; j < libraries.size(); j++)
        {
            tempBookVector = libraries[j].returnAvailabeBook();
            for (int i = 0; i < tempBookVector.size(); i++)
            {
                if (tempBookVector[i].returnName() == name)
                {
                    tempLibraries.push_back(libraries[j]);        //finds the book that we gave the name for from our libraries
                    break;
                }
            }
        }
        for (int i = 0; i < tempLibraries.size() - 1; i++)
        {
            for (int j = 0; j < tempLibraries.size() - i - 1; j++)
            {
                if (absoluteFunction(tempLibraries[j].showLibPosition() - position) > absoluteFunction(tempLibraries[j + 1].showLibPosition() - position))
                {
                    x = tempLibraries[j + 1];
                    tempLibraries[j] = tempLibraries[j + 1];          //sorts our libraries based on distance using bubble sort algorithm
                    tempLibraries[j + 1] = x;
                }
            }
        }
        for (int i = 0; i < tempLibraries.size(); i++)
        {
            y += to_string(i + 1);
            y += ". ";
            y += tempLibraries[i].showLibraryName();
            y += " ";                                                                               //converts our sorted array to string
            y += to_string(absoluteFunction(tempLibraries[i].showLibPosition() - position));
            y += "\n";
        }
        return y;
    }
};