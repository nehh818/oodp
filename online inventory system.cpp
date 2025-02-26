#include <iostream>
using namespace std;

class Product {
private:
    string productName;
    int productID;
    double pricePerUnit;
    int availableStock;
    string supplierName;

public:
    // Default Constructor
    Product() {}

    // Parameterized Constructor
    Product(string name, int id, double price, int stock, string supplier)
        : productName(name), productID(id), pricePerUnit(price), availableStock(stock), supplierName(supplier) {}

    // Function to take product details as input and return a Product object
    static Product inputProductDetails() {
        string name, supplier;
        int id, stock;
        double price;
        
        cout << "Enter Product Name: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Enter Product ID: ";
        cin >> id;
        
        cout << "Enter Price per Unit: ";
        cin >> price;
        
        cout << "Enter Available Stock: ";
        cin >> stock;
        
        cin.ignore(); // Clear input buffer
        cout << "Enter Supplier Name: ";
        getline(cin, supplier);
        
        return Product(name, id, price, stock, supplier);
    }

    // Function to return product details as a string
    string getProductDetails() {
        return "Product Name: " + productName + "\n" +
               "Product ID: " + to_string(productID) + "\n" +
               "Price per Unit: " + to_string((int)pricePerUnit) + "\n" +
               "Available Stock: " + to_string(availableStock) + "\n" +
               "Supplier Name: " + supplierName + "\n" +
               "--------------------------------------\n";
    }

    // Function to calculate total inventory value of the product
    int calculateInventoryValue() {
        return (int)(pricePerUnit * availableStock);
    }

    // Function to check if stock is low
    bool isLowStock() {
        return availableStock < 10;
    }
};

int main() {
    int numProducts;
    cout << "Enter the number of products: ";
    cin >> numProducts;

    Product* inventory = new Product[numProducts];
    
    // Getting user input for products
    for (int i = 0; i < numProducts; i++) {
        cout << "\nEnter details for Product " << (i + 1) << ":\n";
        inventory[i] = Product::inputProductDetails();
    }

    // Calculating total inventory value
    int totalInventoryValue = 0;
    for (int i = 0; i < numProducts; i++) {
        totalInventoryValue += inventory[i].calculateInventoryValue();
    }
    cout << "\n--------------------------------\nTotal Inventory Value: " << totalInventoryValue << endl;

    // Displaying products with low stock
    cout << "\nRestock Alert:\n";
    for (int i = 0; i < numProducts; i++) {
        if (inventory[i].isLowStock()) {
            cout << inventory[i].getProductDetails();
        }
    }

    delete[] inventory; // Free dynamically allocated memory
    return 0;
}