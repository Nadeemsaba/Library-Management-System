#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    int id_no;
    string stream;
    string book1, book2;
    string book1Date, book2Date;
    int book_no = 0;
    int totalFine = 0;

    Student() {}
    Student(string name, int id_no, string stream)
        : name(name), id_no(id_no), stream(stream), book1(""), book2(""), book_no(0), book1Date(""), book2Date(""), totalFine(0) {}
};

struct Node {
    string key;
    Node* left;
    Node* right;

    Node(string k) : key(k), left(nullptr), right(nullptr) {}
};

class BookTree {
public:
    Node* root;

    BookTree() : root(nullptr) {}

    Node* insertRec(Node* root, string key) {
        if (root == nullptr) return new Node(key);
        if (key < root->key)
            root->left = insertRec(root->left, key);
        else if (key > root->key)
            root->right = insertRec(root->right, key);
        return root;
    }

    void insert(string key) {
        root = insertRec(root, key);
    }

    bool search(Node* root, string key) {
        if (!root) return false;
        if (key == root->key) return true;
        if (key < root->key) return search(root->left, key);
        return search(root->right, key);
    }

    bool contains(string key) {
        return search(root, key);
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }

    void displayInorder() {
        inorder(root);
    }
};

string getCurrentDate() {
    time_t t = time(0);
    tm* now = localtime(&t);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d", now);
    return string(buf);
}

void displayBooks(const map<string, int>& bookQuantities) {
    for (auto& entry : bookQuantities) {
        cout << "Book: " << entry.first << ", Quantity: " << entry.second << "\n";
    }
}

int calculateFine(const string& issueDate) {
    time_t now = time(0);
    tm issue = {};
    sscanf(issueDate.c_str(), "%d-%d-%d", &issue.tm_year, &issue.tm_mon, &issue.tm_mday);
    issue.tm_year -= 1900;
    issue.tm_mon -= 1;
    time_t issueTime = mktime(&issue);
    double diff = difftime(now, issueTime) / (60 * 60 * 24);
    if (diff > 15) {
        return static_cast<int>((diff - 15) * 2);
    }
    return 0;
}

void issueBook(Student& student, BookTree& tree, map<string, int>& bookQuantities) {
    if (student.book_no >= 2) {
        cout << "Maximum 2 books can be issued.\n";
        return;
    }
    string bookName;
    cin.ignore();
    cout << "Enter book name to issue: ";
    getline(cin, bookName);
    if (tree.contains(bookName) && bookQuantities[bookName] > 0) {
        bookQuantities[bookName]--;
        string today = getCurrentDate();
        if (student.book1 == "") {
            student.book1 = bookName;
            student.book1Date = today;
        } else {
            student.book2 = bookName;
            student.book2Date = today;
        }
        student.book_no++;
        cout << "Book issued successfully on " << today << ". Please return within 15 days.\n";
    } else {
        cout << "Book not available.\n";
    }
}

void returnBook(Student& student, map<string, int>& bookQuantities) {
    cout << "Books issued: ";
    if (student.book1 != "") cout << "1. " << student.book1 << " ";
    if (student.book2 != "") cout << "2. " << student.book2 << " ";
    cout << "\nEnter book name to return: ";
    string returnBook;
    getline(cin, returnBook);

    if (student.book1 == returnBook) {
        int fine = calculateFine(student.book1Date);
        student.totalFine += fine;
        if (fine > 0) cout << "Late return. Fine: Rs. " << fine << "\n";
        student.book1 = "";
        student.book1Date = "";
        student.book_no--;
        bookQuantities[returnBook]++;
        cout << "Book returned successfully.\n";
    } else if (student.book2 == returnBook) {
        int fine = calculateFine(student.book2Date);
        student.totalFine += fine;
        if (fine > 0) cout << "Late return. Fine: Rs. " << fine << "\n";
        student.book2 = "";
        student.book2Date = "";
        student.book_no--;
        bookQuantities[returnBook]++;
        cout << "Book returned successfully.\n";
    } else {
        cout << "You have not issued this book.\n";
    }
}

void librarianMenu(BookTree& tree, map<string, int>& bookQuantities) {
    int libChoice;
    while (true) {
        cout << "\n1. Add Book\n2. Show Books\n3. Display Book in Alphabetical Order\n4. Exit\nEnter choice: ";
        cin >> libChoice;
        cin.ignore();
        if (libChoice == 1) {
            string bookName;
            int quantity;
            cout << "Enter book name: ";
            getline(cin, bookName);
            cout << "Enter quantity: ";
            cin >> quantity;
            cin.ignore();
            if (!tree.contains(bookName)) {
                tree.insert(bookName);
            }
            bookQuantities[bookName] += quantity;
        } else if (libChoice == 2) {
            displayBooks(bookQuantities);
        } else if (libChoice == 3) {
            tree.displayInorder();
            cout << "\n";
        } else {
            break;
        }
    }
}

void userMenu(Student& student, BookTree& tree, map<string, int>& bookQuantities) {
    int userChoice;
    while (true) {
        cout << "\n1. Issue Book\n2. Return Book\n3. View Issued Books\n4. View Total Fine\n5. Exit\nEnter choice: ";
        cin >> userChoice;
        cin.ignore();
        if (userChoice == 1) {
            issueBook(student, tree, bookQuantities);
        } else if (userChoice == 2) {
            returnBook(student, bookQuantities);
        } else if (userChoice == 3) {
            cout << "Book 1: " << (student.book1.empty() ? "None" : student.book1 + " (" + student.book1Date + ")")
                 << ", Book 2: " << (student.book2.empty() ? "None" : student.book2 + " (" + student.book2Date + ")") << "\n";
        } else if (userChoice == 4) {
            cout << "Total fine accumulated: Rs. " << student.totalFine << "\n";
        } else {
            break;
        }
    }
}

int main() {
    vector<Student> students = {
        Student("Aby", 12318757, "B.Tech-CSE"),
        Student("Lia", 12325062, "B.Tech-CSE"),
        Student("Noor", 12322598, "B.Tech-CSE")
    };

    map<string, int> bookQuantities;
    BookTree tree;

    int choice;
    while (true) {
        cout << "\n1. Librarian Login\n2. User Login\n3. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) {
            string id, pwd;
            cout << "Enter UserId: ";
            cin >> id;
            cout << "Enter Password: ";
            cin >> pwd;
            if (id == "19876" && pwd == "abc123") {
                cout << "Login Successful!\n";
                librarianMenu(tree, bookQuantities);
            } else {
                cout << "Invalid login.\n";
            }
        } else if (choice == 2) {
            int userId;
            cout << "Enter your ID: ";
            cin >> userId;
            Student* student = nullptr;
            for (auto& s : students) {
                if (s.id_no == userId) {
                    student = &s;
                    break;
                }
            }
            if (!student) {
                cout << "Student not found.\n";
                continue;
            }
            userMenu(*student, tree, bookQuantities);
        } else {
            break;
        }
    }
    return 0;
}
