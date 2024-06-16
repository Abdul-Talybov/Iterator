#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Library.h"

using namespace std;

int main() {
    LinkedList<Book> library;

    library.add(Book("1984", "George Orwell", 1));
    library.add(Book("To Kill a Mockingbird", "Harper Lee", 2));
    library.add(Book("The Great Gatsby", "F. Scott Fitzgerald", 3));
    library.add(Book("Moby Dick", "Herman Melville", 4));

    cout << "Library book list:\n";

    for (Iterator<Book> it = library.begin(); it != library.end(); ++it) {
        cout << "Title: " << (*it).title;
        cout << ", Author: " << (*it).author;
        cout << ", Publication Year: " << (*it).publication_year << endl;
    }
    library.printList();

    return 0;
}
