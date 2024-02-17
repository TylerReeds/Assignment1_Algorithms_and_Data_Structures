#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Database.h"
#include <ctime> 
//Tyler Reeds Assignment 1 Algorithms and Data Structures 
using namespace std;

int main() {
    //Uses ProductDatabase class to make a new local variable 
    ProductDatabase data;

    //Calls load data from file function and uses product_data.txt file 
    data.loadData("product_data.txt");

    //Calls display all products function 
    data.displayAllProducts();

    //Insert Data Manipulation 
    Product newProduct = { 17171, " Test Inserted Product", 17.99, "Electronics" };
    data.insertProduct(newProduct);
    cout << "\nAfter inserting new product:" << endl;
    data.displayAllProducts();

    //Update Data Manipulation 
    Product updatedProduct = { 40374, " Updated Smartphone", 799.99, "Electronics" };
    data.updateProduct(updatedProduct);
    cout << "\nAfter updating product:" << endl;
    data.displayAllProducts();

    //Delete Data Manipulation 
    data.deleteProduct(40374);
    cout << "\nAfter deleting product:" << endl;
    data.displayAllProducts();

    //Search using ID 
    data.displayAllProducts();
    int searchID = 30251;
    Product* foundProduct = data.searchByID(searchID);
    if (foundProduct != nullptr) {
        cout << "\nProduct found by ID " << searchID << ": " << foundProduct->name << endl;
    }
    else {
        cout << "\nProduct with ID " << searchID << " not found." << endl;
    }

    //Search using Product Name 
    data.displayAllProducts();
    string searchName = " Shirt RSQGL";
    vector<Product*> foundProductsByName = data.searchByName(searchName);
    cout << "\nProducts found by name \"" << searchName << "\":" << endl;
    for (auto& product : foundProductsByName) {
        cout << "ID: " << product->ID << ", Name: " << product->name << ", Price: " << product->price << ", Category: " << product->category << endl;
    }

    //Calls the bubble sort ascending function 
    data.bubbleSortByPriceAscending();

    //Calls the bubble sort descending function 
    data.bubbleSortByPriceDescending();


    //To measure the time taken to sort data by ascending price
    clock_t start = clock();
    data.bubbleSortByPriceAscending();
    clock_t end = clock();
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken to sort by price ascending: " << timeTaken << " seconds" << endl;

    //To measure the time taken to sort data by descending price 
    start = clock();
    data.bubbleSortByPriceDescending();
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken to sort by price descending: " << timeTaken << " seconds" << endl;

    return 0;
}
