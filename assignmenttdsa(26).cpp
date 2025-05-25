#include <iostream>
using namespace std;

class Node {
public:
    string strdata;
    int intdata;
    Node* next;

    Node(int value) {
        intdata = value;
        next = NULL;
    }

    Node(string value) {
        strdata = value;
        next = NULL;
    }
};

class List {
public:
    Node* head;

    List() {
        head = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == NULL)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void insert(string value) {
        Node* newNode = new Node(value);
        if (head == NULL)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->strdata == "")
                cout << temp->intdata;
            else
                cout << temp->strdata;
            cout << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void update(int id) {
    Node* temp = head;
    while (temp != NULL) {
        
        if (temp->intdata == id) {
            
            Node* nameNode = temp->next;
            Node* amountNode = nameNode->next;
            Node* dateNode = amountNode->next;
            Node* dayNode = dateNode->next;
            Node* timeNode = dayNode->next;

            string newName, newDate, newDay, newTime;
            int newAmount;

            cout << "\n--- Updating Record for ID: " << id << " ---\n";
            cin.ignore(); 

            cout << "Enter new Name: ";
            getline(cin, newName);
            cout << "Enter new Amount: ";
            cin >> newAmount;
            cin.ignore();
            cout << "Enter new Date: ";
            getline(cin, newDate);
            cout << "Enter new Day: ";
            getline(cin, newDay);
            cout << "Enter new Time: ";
            getline(cin, newTime);

            
            nameNode->strdata = newName;
            amountNode->intdata = newAmount;
            dateNode->strdata = newDate;
            dayNode->strdata = newDay;
            timeNode->strdata = newTime;

            cout << "Record updated successfully.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "ID not found in the list.\n";
}
};

class MasterList {
public:
    Node* head1;
    Node* head2;
    Node* head3;

    MasterList() {
        head1 = NULL;
        head2 = NULL;
        head3 = NULL;
    }

    void addLists(Node* h1, Node* h2, Node* h3) {
        head1 = h1;
        head2 = h2;
        head3 = h3;
    }

    void displayHeads() {
        cout << "\nMaster Linked List :" << endl;

        if (head1 != NULL) {
            if (head1->strdata == "")
                cout << head1->intdata << endl;
            else
                cout << head1->strdata << endl;
        }

        if (head2 != NULL) {
            if (head2->strdata == "")
                cout << head2->intdata << endl;
            else
                cout << head2->strdata << endl;
        }

        if (head3 != NULL) {
            if (head3->strdata == "")
                cout << head3->intdata << endl;
            else
                cout << head3->strdata << endl;
        }
    }
};

int main() {
    List s, e, g;
    
    s.insert(1);
    s.insert("Sugar");
    s.insert(700);
    s.insert("12-5-2025");
    s.insert("Monday");
    s.insert("12:30AM");


    e.insert(2);
    e.insert("Electric");
    e.insert(4000);
    e.insert("20-5-2025");
    e.insert("Wednesday");
    e.insert("11:45AM");

    g.insert(3);
    g.insert("Gas");
    g.insert(2500);
    g.insert("8-5-2025");
    g.insert("Friday");
    g.insert("2:00AM");
    
    cout << "Sugar List:" << endl;
    s.display();

    cout << "Electric List:" << endl;
    e.display();

    cout << "Gas List:" << endl;
    g.display();

    MasterList master;
    master.addLists(s.head,e.head,g.head);
    master.displayHeads();


    int choice;
    do {
        cout << "\n===== Menu =====" << endl;
        cout << "1. Add" << endl;
        cout << "2. Delete" << endl;
        cout << "3. View Expense" << endl;
        cout << "4. Update"<<endl;
        cout << "5. highest total expense"<<endl; 
        cout << "6. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int listChoice, id, amount;
            string name, date, day, time;
            cout << "Select List: 1) Sugar  2) Electric  3) Gas: "<<endl;
            cin >> listChoice;
            cin.ignore();

            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Amount: ";
            cin >> amount;
            cin.ignore();
            cout << "Enter Date: ";
            getline(cin, date);
            cout << "Enter Day: ";
            getline(cin, day);
            cout << "Enter Time: ";
            getline(cin, time);

            if (listChoice == 1) {
                s.insert(id);
                s.insert(name);
                s.insert(amount);
                s.insert(date);
                s.insert(day);
                s.insert(time);
                cout << "Added to Sugar list."<<endl;
            } else if (listChoice == 2) {
                e.insert(id);
                e.insert(name);
                e.insert(amount);
                e.insert(date);
                e.insert(day);
                e.insert(time);
                cout << "Added to Electric list."<<endl;
            } else if (listChoice == 3) {
                g.insert(id);
                g.insert(name);
                g.insert(amount);
                g.insert(date);
                g.insert(day);
                g.insert(time);
                cout << "Added to Gas list."<<endl;
            }

        } else if (choice == 2) {
            int delChoice;
            cout << "Select List to Delete: 1) Sugar  2) Electric  3) Gas: ";
            cin >> delChoice;

            if (delChoice == 1) {
                s.head = NULL;
                cout << "Sugar list deleted."<<endl;
            } else if (delChoice == 2) {
                e.head = NULL;
                cout << "Electric list deleted."<<endl;
            } else if (delChoice == 3) {
                g.head = NULL;
                cout << "Gas list deleted."<<endl;
            }

        } else if (choice == 3) {
           cout << "Sugar List:" << endl;
             s.display();

           cout << "Electric List:" << endl;
             e.display();

           cout << "Gas List:" << endl;
             g.display();  
        } else if (choice == 4) {
           int updateList, updateId;
            cout << "Select List to Update: 1) Sugar  2) Electric  3) Gas: ";
            cin >> updateList;
            cout << "Enter ID to Update: ";
            cin >> updateId;

           if (updateList == 1) {
            s.update(updateId);
            } else if (updateList == 2) {
            e.update(updateId);
            } else if (updateList == 3) {
            g.update(updateId);
            } else {
          cout << "Invalid List.\n";
        }
	    }   else if (choice == 5) {
            int sugar = 0, electric = 0, gas = 0;
            Node* temp;

           temp = s.head;
           while (temp != NULL) {
           Node* current = temp;
           for (int i = 0; i < 6 && current != NULL; i++) {
            if (i == 2) sugar += current->intdata;
            current = current->next;
        }
          temp = current;
        }
        
           temp = e.head;
           while (temp != NULL) {
           Node* current = temp;
          for (int i = 0; i < 6 && current != NULL; i++) {
            if (i == 2) electric += current->intdata;
            current = current->next;
        }
          temp = current;
        }

           temp = g.head;
           while (temp != NULL) {
          Node* current = temp;
        for (int i = 0; i < 6 && current != NULL; i++) {
            if (i == 2) gas += current->intdata;
            current = current->next;
        }
          temp = current;
        }

      cout << "\nSugar total: " << sugar << endl;
      cout << "Electric total: " << electric << endl;
      cout << "Gas total: " << gas << endl;

      if (sugar > electric && sugar > gas)
        cout << "Highest expense: " << sugar << " (Sugar)"<<endl;
      else if (electric > sugar && electric > gas)
        cout << "Highest expense: " << electric << " (Electric)"<<endl;
      else if (gas > sugar && gas > electric)
        cout << "Highest expense: " << gas << " (Gas)"<<endl;
      else
        cout << "Some lists have equal highest expenses."<<endl;
}
}
	while (choice != 6);

    cout << "Program ended."<<endl;
    return 0;
}
