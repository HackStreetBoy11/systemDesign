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
        name = n;
        price = p;
    }
};

// Heap:
//   [Product "Laptop"] at 0xBBB
//   [Product "Mouse"]  at 0xCCC
//   [ShoppingCart] at 0xAAA
//     products vector -> contains { 0xBBB, 0xCCC }

// STACK
// ┌─────────────────────┐
// │ cart  -> 0xAAA      │   (pointer variable)
// │ cart2 -> 0xDDD      │
// └─────────────────────┘

// HEAP
// 0xAAA: ShoppingCart object
//   - vector<Product*> products
//     -> internal buffer (on heap) holding { 0xBBB, 0xCCC }

// 0xBBB: Product("Laptop", 999.99)
//   - fields: name (string object), price (double)

// 0xCCC: Product("Mouse", 25.50)
//   - fields: name, price

// 0xDDD: ShoppingCart object (cart2)
//   - products vector -> { 0xEEE }

// 0xEEE: Product("Keyboard", 45.00)

class ShoppingCart
{
private:
    vector<Product *> products;
    // cart stores pointers to dynamically allocated Product Ojbects

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

    void printInvoice()
    {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : products)
        {
            cout << p->name << "- $" << p->price << "\n";
        }
        cout << "Total: $" << calculateTotal() << "\n";
    }

    void saveToDatabase()
    {
        cout << "Saving shopping cart to database...\n";
    }
};

int main()
{
    ShoppingCart* cart = new ShoppingCart();
    // creates a cart using dynamic memory

    cart->addProduct(new Product("Laptop", 999.99));
    cart->addProduct(new Product("Mouse", 25.50));

    cart->printInvoice();
    cart->saveToDatabase();
    ShoppingCart* cart2 =new ShoppingCart();
    cart2->addProduct(new Product("Keyboard", 45.00));
    cart2->printInvoice();
    return 0;
}