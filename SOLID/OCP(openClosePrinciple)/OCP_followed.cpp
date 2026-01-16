#include <iostream>
#include <vector>

using namespace std;

class Product
{
public:
    string name;
    double price;
    Product(string n, double p)
    {
        this->name = n;
        this->price = p;
    }
};

class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addProduct(Product *p)
    {
        products.push_back(p);
    }

    const vector<Product *> &getProducts()
    {
        return products;
    }

    double calculateTotal()
    {
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        return total;
    }
};

class ShoppingCartPrinter
{
private:
    ShoppingCart *cart;

public:
    ShoppingCartPrinter(ShoppingCart *cart)
    {
        this->cart = cart;
    }
    void printInvoice()
    {
        cout << "Shopping Cart Invoice" << endl;
        for (auto p : cart->getProducts())
        {
            cout << p->name << " - " << p->price << endl;
        }
        cout << "Total: " << cart->calculateTotal() << endl;
    }
};

class Persistence
{
private:
    ShoppingCart *cart;

public:
    virtual void save(ShoppingCart *cart) = 0; // pure virtual function
};

class SQLPersistence : public Persistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving shopping cart to SQL database..." << endl;
    }
};

class NOSQLPersistence : public Persistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving shopping cart to NoSQL database..." << endl;
    }
};

class FilePersistence : public Persistence
{
public:
    void save(ShoppingCart *cart) override
    {
        cout << "Saving shopping cart to file..." << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 1000));
    cart->addProduct(new Product("Mouse", 50));

    ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    ShoppingCartStorage *db = new ShoppingCartStorage(cart);
    db->saveToSqlDatabase();
    return 0;
}