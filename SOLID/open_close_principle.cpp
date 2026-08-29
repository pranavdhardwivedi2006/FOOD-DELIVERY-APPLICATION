#include<bits/stdc++.h>
using namespace std;

class Product {
public:
    string name;
    double price;
    Product(string name, double price) {
        this -> name = name;
        this -> price = price;
    }
};

class shoppingCart {
    vector<Product*> cart;

public:
    void addToCart(Product* product) {
        cart.push_back(product);
    }
    
    const vector<Product*>& getCart() {
        return cart;
    }
    
    double calculateTotal() {
        double total = 0;
        
        for (auto p : cart) {
            total += p -> price;
        }
        
        return total;
    }
};

class shoppingCartPrinter {
    shoppingCart* cart;

public:
    shoppingCartPrinter(shoppingCart* cart) {
        this -> cart = cart;
    }
    
    void printInvoice() {
        for (auto p : cart -> getCart()) {
            cout << "Product : " << p -> name;
            cout << " Price : " << p -> price << endl;
        }
    }
};

class DBPersistance {
    shoppingCart* cart;
public:
    virtual void save(shoppingCart* cart) = 0;
};

class SQLPersistance : public DBPersistance {
public :
    void save(shoppingCart* cart) override {
        cout << "Saving to SQL\n";
    }
};

class MongoPersistance : public DBPersistance {
public :
    void save(shoppingCart* cart) override {
        cout << "Saving to MongoDB\n";
    }
};

class FilePersistance : public DBPersistance {
public :
    void save(shoppingCart* cart) override {
        cout << "Saving to File\n";
    }
};

int main() {
    shoppingCart* cart = new shoppingCart();
    
    Product* p = new Product("Lenovo", 50000);
    cart -> addToCart(p);
    p = new Product("Acer", 30000);
    cart -> addToCart(p);
    
    shoppingCartPrinter* printer = new shoppingCartPrinter(cart);
    printer -> printInvoice();
    
    DBPersistance* sql = new SQLPersistance();
    DBPersistance* mongo = new MongoPersistance();
    DBPersistance* file = new FilePersistance();
    sql -> save(cart);
    file -> save(cart);
    mongo -> save(cart);
}