#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
#include <thread>
#include <chrono>

using namespace std;

int password = 123;
bool checkPass()
{
    int n;
    cout<<"Please Enter Password :";
    cin>>n;
    if(n == password)
    return true;
    else return false;
}

// Class to represent a delivery boy
class DeliveryBoy {
public:
    string name;
    double latitude;
    double longitude;
    bool available;

    DeliveryBoy() {
        name = "";
        latitude = 0.0;
        longitude = 0.0;
        available = true;
    }

    DeliveryBoy(string name, double latitude, double longitude, bool available = true) {
        this->name = name;
        this->latitude = latitude;
        this->longitude = longitude;
        this->available = available;
    }
    string getName() {
        return name;
    }
    double getLatitude() {
        return latitude;
    }
    double getLongitude() {
        return longitude;
    }
    bool isAvailable() {
        return available;
    }
    void setAvailability(bool availability) {
        available = availability;
    }
};

// Class to represent a customer entity
class Customer {
private:
    string name;
    string address;
    double latitude;
    double longitude;
    string menuItemName;
    bool isDeliveryPreferred;

public:
    Customer(string n, string addr, double lat, double lng, string menuItem, bool isDeliveryPref) {
        name = n;
        address = addr;
        latitude = lat;
        longitude = lng;
        menuItemName = menuItem;
        isDeliveryPreferred = isDeliveryPref;
    }

    string getName() {
        return name;
    }

    string getAddress() {
        return address;
    }

    double getLatitude() {
        return latitude;
    }

    double getLongitude() {
        return longitude;
    }

    string getMenuItemName() {
        return menuItemName;
    }

    bool getIsDeliveryPreferred() {
        return isDeliveryPreferred;
    }
};



// Class to represent a franchise branch
class FranchiseBranch {
public:
    string name;
    double latitude;
    double longitude;

    FranchiseBranch() {
        name = "";
        latitude = 0.0;
        longitude = 0.0;
    }
    FranchiseBranch(string name, double latitude, double longitude) {
        this->name = name;
        this->latitude = latitude;
        this->longitude = longitude;
    }
    string getName() {
        return name;
    }
    double getLatitude() {
        return latitude;
    }
    double getLongitude() {
        return longitude;
    }
};

// Class to represent a menu item
class MenuItem {
public:
    string name;
    double price;

    MenuItem() {
        name = "";
        price = 0.0;
    }

    MenuItem(string name, double price) {
        this->name = name;
        this->price = price;
    }
    string getName() {
        return name;
    }
    double getPrice() {
        return price;
    }
};


//add delivery boys
void addDeliveryBoy(vector<DeliveryBoy>& deliveryBoys) {
    string name;
    double latitude, longitude;
    int availability;

    cout << "Enter the name of the delivery boy: ";
    cin >> name;
    cout << "Enter the latitude of the delivery boy's location: ";
    cin >> latitude;
    cout << "Enter the longitude of the delivery boy's location: ";
    cin >> longitude;
    cout << "Enter the availability of the delivery boy (1 for available, 0 for unavailable): ";
    cin >> availability;
    cin.ignore(); // Ignore the newline character left in the input buffer

    DeliveryBoy deliveryBoy(name, latitude, longitude, availability);
    deliveryBoys.push_back(deliveryBoy);

    ofstream file("delivery_boys.txt", ios::app);
    if (file) {
            file << deliveryBoy.getName() << "," << deliveryBoy.getLatitude() << "," << deliveryBoy.getLongitude() << "," << deliveryBoy.isAvailable() << endl;
        file.close();
        cout << "Delivery boy records added successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }

    cout << "Delivery boy added successfully!" << endl;
}

//add franchise
// Function to add multiple franchise records to the file
void addFranchisesToFile(vector<FranchiseBranch>& franchises) {
    string name;
    double latitude, longitude;
    int availability;

    cout << "Enter the name of New Franchise: ";
    cin >> name;
    cout << "Enter the latitude of this franchise: ";
    cin >> latitude;
    cout << "Enter the longitude of this franchise: ";
    cin >> longitude;
    cin.ignore(); // Ignore the newline character left in the input buffer

    FranchiseBranch newFranchise(name, latitude, longitude);
    franchises.push_back(newFranchise);

    cout << "Franchise added successfully!" << endl;

    ofstream file("franchises.txt", ios::app);
    if (file) {
            file << newFranchise.getName() << "," << newFranchise.getLatitude() << "," << newFranchise.getLongitude()<< endl;
        file.close();
        cout << "Franchise records added successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}

void addMenuItem(vector<MenuItem>& menuItems) {
    string name;
    double price;

    cout << "Enter the name of the menu item: ";
    cin >> name;
    cout << "Enter the price of the menu item: ";
    cin >> price;
    cin.ignore(); // Ignore the newline character left in the input buffer

    MenuItem menuItem(name, price);
    menuItems.push_back(menuItem);

    cout << "Menu item added successfully!" << endl;

        ofstream file("menuItems.txt", ios::app);
    if (file) {
            file << menuItem.getName()<< "," << menuItem.getPrice() << endl;
        file.close();
        cout << "Menu items added successfully!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}

// Function to delete a delivery boy record from the file
void deleteDeliveryBoyFromFile(string name) {
    ifstream inFile("delivery_boys.txt");
    ofstream outFile("temp.txt", ios::app);
    bool deleted = false;
    if (inFile && outFile) {
        string line;
        while (getline(inFile, line)) {
            if (line.find(name) != string::npos) {
                deleted = true;
            } else {
                outFile << line << endl;
            }
        }
        inFile.close();
        outFile.close();
        remove("delivery_boys.txt");
        rename("temp.txt", "delivery_boys.txt");
        if (deleted) {
            cout << "Delivery boy deleted successfully!" << endl;
        } else {
            cout << "Delivery boy not found!" << endl;
        }
    } else {
        cout << "Error opening file!" << endl;
    }
}

// Function to delete a franchise branch record from the file
void deleteFranchiseBranchFromFile(string name) {
    ifstream inFile("franchises.txt");
    ofstream outFile("temp.txt", ios::app);
    bool deleted = false;
    if (inFile && outFile) {
        string line;
        while (getline(inFile, line)) {
            if (line.find(name) != string::npos) {
                deleted = true;
            } else {
                outFile << line << endl;
            }
        }
        inFile.close();
        outFile.close();
        remove("franchises.txt");
        rename("temp.txt", "franchises.txt");
        if (deleted) {
            cout << "Franchise branch deleted successfully!" << endl;
        } else {
            cout << "Franchise branch not found!" << endl;
        }
    } else {
        cout << "Error opening file!" << endl;
    }
}

// Function to delete a menu item record from the file
void deleteMenuItemFromFile(string name) {
    ifstream inFile("menuItems.txt");
    ofstream outFile("temp.txt", ios::app);
    bool deleted = false;
    if (inFile && outFile) {
        string line;
        while (getline(inFile, line)) {
            if (line.find(name) != string::npos) {
                deleted = true;
            } else {
                outFile << line << endl;
            }
        }
        inFile.close();
        outFile.close();
        remove("menuItems.txt");
        rename("temp.txt", "menuItems.txt");
        if (deleted) {
            cout << "Menu item deleted successfully!" << endl;
        } else {
            cout << "Menu item not found!" << endl;
        }
    } else {
        cout << "Error opening file!" << endl;
    }
}


// Function to write a delivery boy record to a file
void writeDeliveryBoyRecord(DeliveryBoy deliveryBoy) {
    ofstream file;
    file.open("delivery_boys.txt", ios::app);
    if (file) {
        file << deliveryBoy.getName() << "," << deliveryBoy.getLatitude() << "," << deliveryBoy.getLongitude() << "," << deliveryBoy.isAvailable() << endl;
        file.close();
    }
}

// Function to write a franchise branch record to a file
void writeFranchiseBranchRecord(FranchiseBranch franchiseBranch) {
    ofstream file;
    file.open("franchises.txt", ios::app);
    if (file) {
        file << franchiseBranch.getName() << "," << franchiseBranch.getLatitude() << "," << franchiseBranch.getLongitude() << endl;
        file.close();
    }
}

// Function to write a menu item record to a file
void writeMenuItemRecord(MenuItem menuItem) {
    ofstream file;
    file.open("menuItems.txt", ios::app);
    if (file) {
        file << menuItem.getName() << "," << menuItem.getPrice() << endl;
        file.close();
    }
}

// Class to represent a weighted edge in the graph
class Edge {
public:
    int destination;
    double weight;
    Edge(int destination, double weight) {
        this->destination = destination;
        this->weight = weight;
    }
};

// Class to represent a graph
class Graph {
public:
    vector<vector<Edge>> adjacencyList;
    Graph(int numVertices) {
        adjacencyList.resize(numVertices);
    }
    void addEdge(int source, int destination, double weight) {
        adjacencyList[source].push_back(Edge(destination, weight));
        adjacencyList[destination].push_back(Edge(source, weight));
    }
};

// Function to calculate the distance between two points on Earth
double distance(double latitude1, double longitude1, double latitude2, double longitude2) {
    double earthRadius = 6371.0; // km
    double latitude1Radians = latitude1 * M_PI / 180.0;
    double longitude1Radians = longitude1 * M_PI / 180.0;
    double latitude2Radians = latitude2 * M_PI / 180.0;
    double longitude2Radians = longitude2 * M_PI / 180.0;
    double deltaLatitude = latitude2Radians - latitude1Radians;
    double deltaLongitude = longitude2Radians - longitude1Radians;
    double a = sin(deltaLatitude / 2) * sin(deltaLatitude / 2) + cos(latitude1Radians) * cos(latitude2Radians) * sin(deltaLongitude / 2) * sin(deltaLongitude / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = earthRadius * c;
    return distance;
}


// Function to find the index of the closest delivery boy to a given location
int findClosestDeliveryBoy(vector<DeliveryBoy> deliveryBoys, double latitude, double longitude) {
    int closestDeliveryBoyIndex = -1;
    double closestDistance = INT_MAX;
    for (int i = 0; i < deliveryBoys.size(); i++) {
        DeliveryBoy deliveryBoy = deliveryBoys[i];
        if (deliveryBoy.isAvailable()) {
            double distanceToDeliveryBoy = distance(latitude, longitude, deliveryBoy.getLatitude(), deliveryBoy.getLongitude());
            if (distanceToDeliveryBoy < closestDistance) {
                closestDeliveryBoyIndex = i;
                closestDistance = distanceToDeliveryBoy;
            }
        }
    }
    return closestDeliveryBoyIndex;
}



// Function to assign a delivery boy to a customer based on their location
void assignDeliveryBoyToCustomer(Customer customer, vector<DeliveryBoy>& deliveryBoys) {
    int closestDeliveryBoyIndex = findClosestDeliveryBoy(deliveryBoys, customer.getLatitude(), customer.getLongitude());
    if (closestDeliveryBoyIndex != -1) {
        DeliveryBoy deliveryBoy = deliveryBoys[closestDeliveryBoyIndex];
        deliveryBoy.setAvailability(false);
        deliveryBoys[closestDeliveryBoyIndex] = deliveryBoy;
        cout << "Delivery boy " << deliveryBoy.getName() << " has been assigned to customer " << customer.getName() << "." << endl;
    } else {
        cout << "No delivery boys available." << endl;
    }
}

// Function to display the details of all delivery boys
void displayDeliveryBoys(vector<DeliveryBoy> deliveryBoys) {
    cout << "Delivery Boys:" << endl;
    for (int i = 0; i < deliveryBoys.size(); i++) {
        DeliveryBoy deliveryBoy = deliveryBoys[i];
        cout << "Name: " << deliveryBoy.getName() << endl;
        cout << "Location: (" << deliveryBoy.getLatitude() << ", " << deliveryBoy.getLongitude() << ")" << endl;
        cout << "Available: " << (deliveryBoy.isAvailable() ? "Yes" : "No") << endl;
        cout << endl;
    }
}

// Function to display the details of all franchise branches
void displayFranchiseBranches(vector<FranchiseBranch> franchiseBranches) {
    cout << "Franchise Branches:" << endl;
    for (int i = 0; i < franchiseBranches.size(); i++) {
        FranchiseBranch franchiseBranch = franchiseBranches[i];
        cout << "Name: " << franchiseBranch.getName() << endl;
        cout << "Location: (" << franchiseBranch.getLatitude() << ", " << franchiseBranch.getLongitude() << ")" << endl;
        cout << endl;
    }
}

// Function to display the details of all menu items
void displayMenuItems(vector<MenuItem> menuItems) {
    cout << "Menu Items:" << endl;
    for (int i = 0; i < menuItems.size(); i++) {
        MenuItem menuItem = menuItems[i];
        cout << "Name: " << menuItem.getName() << endl;
        cout << "Price: " << menuItem.getPrice() << endl;
        cout << endl;
    }
}


// Function to read delivery boys from a file
vector<DeliveryBoy> readDeliveryBoysFromFile() {
    vector<DeliveryBoy> deliveryBoys;
    ifstream file("delivery_boys.txt");
    if (file) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string name;
            double latitude, longitude;
            int availability;
            getline(ss, name, ',');
            ss >> latitude;
            ss.ignore();
            ss >> longitude;
            ss.ignore();
            ss >> availability;
            DeliveryBoy deliveryBoy(name, latitude, longitude, availability);
            deliveryBoys.push_back(deliveryBoy);
        }
        file.close();
    }
    return deliveryBoys;
}

// Function to read franchise branches from a file
vector<FranchiseBranch> readFranchiseBranchesFromFile() {
    vector<FranchiseBranch> franchiseBranches;
    ifstream file("franchises.txt");
    if (file) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string name;
            double latitude, longitude;
            getline(ss, name, ',');
            ss >> latitude;
            ss.ignore();
            ss >> longitude;
            FranchiseBranch franchiseBranch(name, latitude, longitude);
            franchiseBranches.push_back(franchiseBranch);
        }
        file.close();
    }
    return franchiseBranches;
}

// Function to read menu items from a file
vector<MenuItem> readMenuItemsFromFile() {
    vector<MenuItem> menuItems;
    ifstream file("menuItems.txt");
    if (file) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string name;
            double price;
            getline(ss, name, ',');
            ss >> price;
            MenuItem menuItem(name, price);
            menuItems.push_back(menuItem);
        }
        file.close();
    }
    return menuItems;
}


//To check whether an item is available or not
bool isItemPresent(string itemName) {
    ifstream menuFile("menuItems.txt"); // Open menu items file for reading

    if (!menuFile.is_open()) { // Check if file could be opened
        cout << "Error opening file.\n";
        return false;
    }

    string line;
    while (getline(menuFile, line)) { // Read file line by line
        if (line.find(itemName) != string::npos) { // Check if item name is present in the line
            menuFile.close(); // Close the file
            return true;
        }
    }

    menuFile.close(); // Close the file
    return false;
}

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        children.resize(26, nullptr);
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children[c-'a'] == nullptr) {
                current->children[c-'a'] = new TrieNode();
            }
            current = current->children[c-'a'];
        }
        current->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children[c-'a'] == nullptr) {
                return false;
            }
            current = current->children[c-'a'];
        }
        return current->isEndOfWord;
    }

    void suggest(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            if (current->children[c-'a'] == nullptr) {
                cout << "No matching item found." << endl;
                return;
            }
            current = current->children[c-'a'];
        }
        vector<string> matchingItems;
        if (current->isEndOfWord) {
            matchingItems.push_back(prefix);
        }
        findAllMatchingItems(current, prefix, matchingItems);
        if (matchingItems.size() > 0) {
            cout << "Matching Items: ";
            for (string item : matchingItems) {
                cout << item << ", ";
            }
            cout << endl;
        }
        else
            {
            cout << "No matching item found." << endl;
        }
    }

    void findAllMatchingItems(TrieNode* node, string prefix, vector<string>& matchingItems) {
        if (node == nullptr) {
            return;
        }
        if (node->isEndOfWord) {
            matchingItems.push_back(prefix);
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                char c = i + 'a';
                string newPrefix = prefix + c;
                findAllMatchingItems(node->children[i], newPrefix, matchingItems);
            }
        }
    }
};

vector<string> getMenuItemsNames(const vector<MenuItem>& menuItems) {
    vector<string> itemNames;
    for (MenuItem item : menuItems) {
        itemNames.push_back(item.getName());
    }
    return itemNames;
}


void mergeDB(vector<DeliveryBoy>& deliveryBoys, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // create temp arrays
    vector<DeliveryBoy> L(n1), R(n2);

    // copy data to temp arrays
    for (i = 0; i < n1; i++) {
        L[i] = deliveryBoys[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = deliveryBoys[mid + 1 + j];
    }

    // merge the temp arrays back into deliveryBoys[left..right]
    i = 0; // initial index of first subarray
    j = 0; // initial index of second subarray
    k = left; // initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i].getLatitude() < R[j].getLatitude()) {
            deliveryBoys[k] = L[i];
            i++;
        }
        else if(L[i].getLatitude() == R[j].getLatitude())
        {
            if (L[i].getLongitude() <= R[j].getLongitude()) {
            deliveryBoys[k] = L[i];
            i++;
            }
            else {
            deliveryBoys[k] = R[j];
            j++;
            }
        }
        else {
            deliveryBoys[k] = R[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements of L[], if there are any
    while (i < n1) {
        deliveryBoys[k] = L[i];
        i++;
        k++;
    }

    // copy the remaining elements of R[], if there are any
    while (j < n2) {
        deliveryBoys[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortDB(vector<DeliveryBoy>& deliveryBoys, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSortDB(deliveryBoys, left, mid);
    mergeSortDB(deliveryBoys, mid + 1, right);
    mergeDB(deliveryBoys, left, mid, right);
}

void mergeSortDeliveryBoysByLatitude(vector<DeliveryBoy>& deliveryBoys) {
    mergeSortDB(deliveryBoys, 0, deliveryBoys.size() - 1);
}

void mergeFB(vector<FranchiseBranch>& franchiseBranches, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // create temp arrays
    vector<FranchiseBranch> L(n1), R(n2);

    // copy data to temp arrays
    for (i = 0; i < n1; i++) {
        L[i] = franchiseBranches[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = franchiseBranches[mid + 1 + j];
    }

    // merge the temp arrays back into deliveryBoys[left..right]
    i = 0; // initial index of first subarray
    j = 0; // initial index of second subarray
    k = left; // initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i].getLatitude() < R[j].getLatitude()) {
            franchiseBranches[k] = L[i];
            i++;
        }
        else if(L[i].getLatitude() == R[j].getLatitude())
        {
            if (L[i].getLongitude() <= R[j].getLongitude()) {
            franchiseBranches[k] = L[i];
            i++;
            }
            else {
            franchiseBranches[k] = R[j];
            j++;
            }
        }
        else {
            franchiseBranches[k] = R[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements of L[], if there are any
    while (i < n1) {
        franchiseBranches[k] = L[i];
        i++;
        k++;
    }

    // copy the remaining elements of R[], if there are any
    while (j < n2) {
        franchiseBranches[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortFB(vector<FranchiseBranch>& franchiseBranches, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSortFB(franchiseBranches, left, mid);
    mergeSortFB(franchiseBranches, mid + 1, right);
    mergeFB(franchiseBranches, left, mid, right);
}

void mergeSortFranchiseBranchesByLatitude(vector<FranchiseBranch>& franchiseBranches) {
    mergeSortFB(franchiseBranches, 0, franchiseBranches.size() - 1);
}

// void setDeliveryBoyAvailableAfterDelay(DeliveryBoy& deliveryBoy) {
//     // Set the delivery boy as unavailable
//     deliveryBoy.setAvailability(false);

//     // Start a timer for 2 minutes
//     int durationInSeconds = 120; // 2 minutes in seconds
//     std::chrono::seconds duration(durationInSeconds);
//     std::this_thread::sleep_for(duration);

//     // Set the delivery boy as available again
//     deliveryBoy.setAvailability(true);
// }

int main() {

    label1:
    bool check=checkPass();

    if(check==false){

        cout<<"errrr!!! Wrong Password"<<endl;
            cout<<"Try Again"<<endl;
        goto label1;

    }


    // Read delivery boys from file
    vector<DeliveryBoy> deliveryBoys = readDeliveryBoysFromFile();
    mergeSortDeliveryBoysByLatitude(deliveryBoys);

    // Read franchise branches from file
    vector<FranchiseBranch> franchiseBranches = readFranchiseBranchesFromFile();
    mergeSortFranchiseBranchesByLatitude(franchiseBranches);

    // Read menu items from file
    vector<MenuItem> menuItems = readMenuItemsFromFile();


    vector<string> item = getMenuItemsNames(menuItems);

    Trie mItems;

    for(int i=0;i<item.size();i++)
    {
        mItems.insert(item[i]);
    }


    /* Create a graph to represent the franchise branches and their connections
    Graph franchiseBranchGraph(franchiseBranches.size());
    for (int i = 0; i < franchiseBranches.size(); i++) {
        FranchiseBranch franchiseBranch1 = franchiseBranches[i];
        for (int j = i + 1; j < franchiseBranches.size(); j++) {
            FranchiseBranch franchiseBranch2 = franchiseBranches[j];
            double distanceBetweenFranchiseBranches = distance(franchiseBranch1.getLatitude(), franchiseBranch1.getLongitude(), franchiseBranch2.getLatitude(), franchiseBranch2.getLongitude());
            if (distanceBetweenFranchiseBranches <= MAX_DISTANCE_BETWEEN_FRANCHISE_BRANCHES) {
                franchiseBranchGraph.addEdge(i, j, distanceBetweenFranchiseBranches);
            }
        }
    }
*/

    // Get input from user
    int option;
    do {

        cout << "Select an option:" << endl;
        cout << "1. Assign delivery boy to customer" << endl;
        cout << "2. Display delivery boys" << endl;
        cout << "3. Display franchise branches" << endl;
        cout << "4. Display menu items" << endl;
        cout << "5. Add Delivery Boy" << endl;
        cout << "6. Add Franchise Branch" << endl;
        cout << "7. Add Menu Items" << endl;
        cout << "8. Remove a Delivery Boy" << endl;
        cout << "9. Remove a Franchise Branch" << endl;
        cout << "10. Remove a Menu Item" << endl;
        cout << "11. Exit" << endl;
        cin >> option;

        switch (option) {
            case 1:
                // Get input from user
                {
                string customerName, customerAddress, menuItemName;
                double customerLatitude, customerLongitude;
                bool isDeliveryPreferred;
                cout << "Enter customer name: ";
                cin >> customerName;
                cout << "Enter customer address: ";
                cin >> customerAddress;
                cout << "Enter customer latitude: ";
                cin >> customerLatitude;
                cout << "Enter customer longitude: ";
                cin >> customerLongitude;

                label2:
                cout << "Enter menu item name: ";
                cin >> menuItemName;
                 if (mItems.search(menuItemName))
                {
                cout << "Matching item found." << endl;
                }
                else
                {
                int ip;
                cout << "No matching item found." << endl;
                cout << "would you like to try again? Or Get Suggestions."<<endl;
                cout << "Press 1 for try again"<<endl;
                cout << "Press 2 for Suggestions"<<endl;
                cin >> ip;

                if(ip == 1)
                goto label2;

                else if(ip == 2)
                {
                // Test suggest
                string input;
                cout << "Enter a prefix to suggest matching items: ";
                cin >> input;
                mItems.suggest(input);
                goto label2;
                }

                else
                {
                    cout <<"Invalid Input!!! Try Again"<<endl;
                    goto label2;
                }

                }

                cout << "Is delivery preferred? (0 = No, 1 = Yes): ";
                cin >> isDeliveryPreferred;

                // Create a customer object
                Customer customer(customerName, customerAddress, customerLatitude, customerLongitude, menuItemName, isDeliveryPreferred);

                // Assign a delivery boy to the customer
                assignDeliveryBoyToCustomer(customer, deliveryBoys);

                }

                break;


            case 2:
                // Display the details of all delivery boys
                displayDeliveryBoys(deliveryBoys);
                break;

            case 3:
                // Display the details of all franchise branches
                displayFranchiseBranches(franchiseBranches);
                break;
            case 4:
                // Display the details of all menu items
                displayMenuItems(menuItems);
                break;
            case 5:
            // Add a delivery boy to the delivery boys list
            {
                addDeliveryBoy(deliveryBoys);
                mergeSortDeliveryBoysByLatitude(deliveryBoys);
            }
            break;

            case 6:
            //add a new franchise
            {
                addFranchisesToFile(franchiseBranches);
                mergeSortFranchiseBranchesByLatitude(franchiseBranches);
            }
            break;

            case 7:
            // Add a new menu item to the menu items list
            {
                addMenuItem(menuItems);
            }
            break;

            case 8:
            // Remove a delivery bou
            {
                string toBeDeleted;
                cout<<"Enter name : "<<endl;
                cin>>toBeDeleted;
                deleteDeliveryBoyFromFile(toBeDeleted);
                deliveryBoys = readDeliveryBoysFromFile();
                mergeSortDeliveryBoysByLatitude(deliveryBoys);
            }
            break;
            case 9:
            // Remove a franchise branch
            {
                string toBeDeleted;
                cout<<"Enter name : "<<endl;
                cin>>toBeDeleted;
                deleteFranchiseBranchFromFile(toBeDeleted);
                franchiseBranches = readFranchiseBranchesFromFile();
                mergeSortFranchiseBranchesByLatitude(franchiseBranches);
            }
            break;
            case 10:
            // Remove a menu item
            {
                string toBeDeleted;
                cout<<"Enter name : "<<endl;
                cin>>toBeDeleted;
                deleteMenuItemFromFile(toBeDeleted);
                menuItems = readMenuItemsFromFile();
            }
            case 11:
                // Exit the program
                cout << "Exiting..." << endl;
                break;
            default:
                // Invalid option selected
                cout << "Invalid option selected. Please try again." << endl;
        }
    } while (option != 11);

    return 0;
}
