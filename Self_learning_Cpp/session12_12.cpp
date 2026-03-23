#include <iostream>
using namespace std;

class Product
{
protected:
    string title;
    double price;

public:
    virtual void accept()
    {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void display()
    {
        cout << "Title: " << title << ", Price: " << price << endl;
    }

};


class Book : public Product
{
private:
    int pages;

public:
    void accept() 
    {
        Product::accept();
        cout << "Enter pages: ";
        cin >> pages;
    }

    void display()
    {
        Product::display();
        cout << "Pages: " << pages << endl;
    }

    int getPages()
    {
        return pages;
    }
};

class Tape : public Product
{
private:
    float playtime;

public:
    void accept()
    {
        Product::accept();
        cout << "Enter playtime: ";
        cin >> playtime;
    }

    void display()
    {
        Product::display();
        cout << "Playtime: " << playtime << endl;
    }

    float getPlaytime()
    {
        return playtime;
    }
};

int main()
{
    Product* arr[5];  
    int choice;

    for (int i = 0; i < 5; i++)
    {
        cout << "\n1. Book, 2. Tape, Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            arr[i] = new Book();
            arr[i]->accept();
            break;

        case 2:
            arr[i] = new Tape();
            arr[i]->accept();
            break;

        default:
            cout << "Invalid choice, try again\n";
        }
    }

    for (int i = 0; i < 5; i++)
    {
        Book* b = dynamic_cast<Book*>(arr[i]);
        if (b != NULL)
        {
            cout << "Pages: " << b->getPages() << endl;
        }

        Tape* t = dynamic_cast<Tape*>(arr[i]);
        if (t != NULL)
        {
            cout << "Playtime: " << t->getPlaytime() << endl;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        delete arr[i];
    }

    return 0;
}
