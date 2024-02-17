#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//struct for the Product Arrays 
struct Product {
    int ID;
    string name;
    double price;
    string category;
};

class ProductDatabase {
private:
    unordered_map<int, Product> products;

public:
    // Function to load Data from a file 
    void loadData(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Product product;
            string temp;

            getline(ss, temp, ',');
            product.ID = stoi(temp);

            getline(ss, product.name, ',');
            getline(ss, temp, ',');
            product.price = stod(temp);

            getline(ss, product.category, ',');

            products[product.ID] = product;
        }

        file.close();
    }

    // Function for Inserting a new product
    void insertProduct(const Product& product) {
        products[product.ID] = product;
    }

    // Function for Updating an existing product
    void updateProduct(const Product& product) {
        if (products.find(product.ID) != products.end()) {
            products[product.ID] = product;
        }
        else {
            cerr << "Product with ID " << product.ID << " could not be found." << endl;
        }
    }

    // Function for Deleting products
    void deleteProduct(int ID) {
        if (products.find(ID) != products.end()) {
            products.erase(ID);
        }
        else {
            cerr << "Product with ID " << ID << " could not be found." << endl;
        }
    }

    // Function to search for products by ID
    Product* searchByID(int ID) {
        if (products.find(ID) != products.end()) {
            return &products[ID];
        }
        else {
            return nullptr;
        }
    }

    // Function to search for products by name
    vector<Product*> searchByName(const string& name) {
        vector<Product*> result;
        for (auto& pair : products) {
            if (pair.second.name == name) {
                result.push_back(&pair.second);
            }
        }
        return result;
    }

    // Function to display all of the products 
    void displayAllProducts() {
        cout << "Products in database:" << endl;
        for (auto& pair : products) {
            cout << "ID: " << pair.first << ", Name: " << pair.second.name << ", Price: " << pair.second.price << ", Category: " << pair.second.category << endl;
        }
    }

    // Function to sort the database by price ascending using a bubble sort 
    void bubbleSortByPriceAscending() {
        vector<pair<int, Product>> sortedProducts;
        for (auto& pair : products) {
            sortedProducts.push_back(pair);
        }

        int n = sortedProducts.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (sortedProducts[j].second.price > sortedProducts[j + 1].second.price) {
                    swap(sortedProducts[j], sortedProducts[j + 1]);
                }
            }
        }

        cout << "Products sorted by price (ascending):" << endl;
        for (auto& pair : sortedProducts) {
            cout << "ID: " << pair.first << ", Name: " << pair.second.name << ", Price: " << pair.second.price << ", Category: " << pair.second.category << endl;
        }
    }

    // Function to sort the database by price descending using a bubble sort 
    void bubbleSortByPriceDescending() {
        vector<pair<int, Product>> sortedProducts;
        for (auto& pair : products) {
            sortedProducts.push_back(pair);
        }

        int n = sortedProducts.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (sortedProducts[j].second.price < sortedProducts[j + 1].second.price) {
                    swap(sortedProducts[j], sortedProducts[j + 1]);
                }
            }
        }

        cout << "Products sorted by price (descending):" << endl;
        for (auto& pair : sortedProducts) {
            cout << "ID: " << pair.first << ", Name: " << pair.second.name << ", Price: " << pair.second.price << ", Category: " << pair.second.category << endl;
        }
    }

};


