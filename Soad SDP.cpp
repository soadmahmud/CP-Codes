#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

class Customer //A class of customer variables
{
public:

    string name, mobile_number;

    double due;
};

vector <Customer> customers; //vector that will store all customer data

class Admin //class for id and password
{
public:

    string user_id, password;
};


void welcome(); //Show welcome message

void Add_Customer(); //Function to add new customer

void Add_Payment(); //Function to add payment

void Add_Due();  //Function to update due

void view_all_customers();  //Function to view all customer name with due

void view_customer_deails();  //Function a specific customer details

void update_customer_details();  //Function to update customer details

void delete_customer();  //Function to delete customer data

double get_total_due();  //Function that will return total due of all customer

void saveDataToFile(const vector<Customer>& customers); //Function that will save all customer data to a binary file from the vector

void save_admin_data(Admin &data); //Function to save user id and password

vector<Customer> retrieveDataFromFile();  //Function that will retrieve all customer data from the binary file and push them into the vector

Admin get_admin_data(); //Function that will retrieve user id and password from a binary file



int main()
{
    customers = retrieveDataFromFile();  //all customer data from file inserted into the vector

    Admin data = get_admin_data(); //user id and password inserted into class object named 'data'

    welcome(); //Show a welcome message

    //loop that will run until it get valid user id and password
    while(true)
    {
        string id, pass; //take id and password from user

        cout << "Enter User ID: \n";

        cin >> id;

        cout << "Enter Password: \n";

        cin >> pass;

        if(id == data.user_id && pass == data.password) //check for correct user id and password
            break;

        system("cls");

        cout << "Invalid User ID or Password!\n";

    }

    system("cls"); //clear the console screen


    while(true)
    {
        //print user interface

        cout << "Total Customers: " << customers.size() << "\tTotal Due: " << get_total_due() << " BDT\n\n";

        cout << "1. Add New Customer\n";
        cout << "2. ADD Payment\n";
        cout << "3. ADD Due\n";
        cout << "4. View All Customers\n";
        cout << "5. View Customer Details\n";
        cout << "6. Update Customer Details\n";
        cout << "7. Delete Customer Data\n";
        cout << "8. Change User ID & Password\n";
        cout << "9. Save & Exit\n";
        cout << "\nEnter your choice: ";

        int choice;

        cin >> choice; //get customer choice


        if(cin.fail()) //Handle with invalid input
        {
            cin.clear();

            cin.ignore(1000, '\n');

            cout << "Invalid Input!\nEnter again: ";

            cin >> choice;
        }

        system("cls");

        switch(choice)
        {
        case 1:
            Add_Customer();
            break;

        case 2:
            Add_Payment();
            break;

        case 3:
            Add_Due();
            break;

        case 4:
            view_all_customers();
            break;

        case 5:
            view_customer_deails();
            break;

        case 6:
            update_customer_details();
            break;

        case 7:
            delete_customer();
            break;

        case 8:
        {
            cout << "Enter New User ID:\n";

            cin >> data.user_id; //get new user id

            cout << "Enter New Password:\n";

            cin >> data.password; //get new password

            save_admin_data(data); //save user id and password into the binary file

            cout << "User ID & Password Updated Successfully!\n";
        }

        case 9:
        {
            saveDataToFile(customers); //save vector data into the binary file

            cout << "Saved & Exiting...\n";

            return 0;
        }

        default:
            cout << "Invalid Choice!\n";
        }

        cout << endl;

        system("pause"); //Pause the window until user press any key

        system("cls");  //clear the console screen
    }

    return 0;
}


void welcome()
{
    printf("\n\n\n");
    printf("\n\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t      =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=");
    printf("\n\t\t      =                   WELCOME              =");
    printf("\n\t\t      =                     TO                 =");
    printf("\n\t\t      =                  BUSINESS              =");
    printf("\n\t\t      =                 MANAGEMENT             =");
    printf("\n\t\t      =                   SYSTEM               =");
    printf("\n\t\t      =                                        =");
    printf("\n\t\t      =                Developed BY:           =");
    printf("\n\t\t      =            Soad, Maruf, Ashraful       =");
    printf("\n\t\t      =               Ayesha, Baidika          =");
    printf("\n\t\t      =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n\n\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n\n\n");

    system("pause");

    system("cls");

}

//Function to add new customer

void Add_Customer()
{
    system("cls");

    Customer new_customer;

    cout << "Customer Name: ";

    fflush(stdin);

    getline(cin, new_customer.name); //get customer name


    //Check for duplicate input
    for(int i =  0; i < customers.size(); i++)
    {
        if(customers[i].name == new_customer.name)
        {
            cout << "There is already a customer in this name!\n";
            cout << "Press 1 to exit\nPress 2 to add new customer\n";

            int choice;

            cin >> choice;

            if(choice == 1)
                return;

            else if(choice == 2)
            {
                system("cls");

                cout << "Customer Name: ";

                fflush(stdin);

                getline(cin, new_customer.name);

                i = -1;
            }

            else
            {
                cout << "Invalid keyword!\n";

                return;
            }
        }
    }

    cout << "Customer Mobile Number: ";

    fflush(stdin);

    getline(cin, new_customer.mobile_number); //get customer mobile number

    cout << "Customer Due: ";

    cin >> new_customer.due; //get due amount

    if(cin.fail()) //Handle with invalid input
    {
        cin.clear();

        cin.ignore(10000, '\n');

        cin >> new_customer.due;
    }

    customers.push_back(new_customer); //Push_back customer data into the vector

    cout << "Customer added successfully!\n";
}


//Function to add payment
void Add_Payment()
{
    system("cls");

    cout << "Customer Full Name: ";

    string name;

    fflush(stdin);

    getline(cin, name); //get customer name

    int i;

    bool check = false;


    //Check for customer
    for(i = 0; i < customers.size(); i++)
    {
        if(customers[i].name == name)
        {
            check = true;

            break;
        }
    }

    //If customer found
    if(check)
    {
        double payment;

        cout << "Payment ammount: ";

        cin >> payment; //take payment amount

        customers[i].due -= payment; //update due amount

        cout << "Payment Updated Successfully!\n";

        cout << "Outstanding due: " << customers[i].due << endl; //print updated due
    }

    //If no customer found
    else
    {
        cout << "There is no customer in this name!\n";

        cout << "Press 1 to view all customers\nPress 2 to go to main page!\n";

        int choice;

        cin >> choice; //take choice

        if(cin.fail()) //Handle with invalid input
        {
            cin.clear();

            cin.ignore(10000, '\n');

            cout << "Wrong keyword!\n";

            return;
        }

        if(choice == 1)
            view_all_customers();

        else if(choice == 2)
        {
            return;
        }

        else
        {
            cout << "Wrong keyword!\n";

            return;
        }
    }
}


//Function to update due
void Add_Due()
{
    system("cls");

    cout << "Customer Full Name: ";

    string name;

    fflush(stdin);

    getline(cin, name); //get customer name

    int i;

    bool check = false;

    for(i = 0; i < customers.size(); i++)
    {
        if(customers[i].name == name)
        {
            check = true;

            break;
        }
    }

    //if customer found
    if(check)
    {
        double due;

        cout << "Due ammount: ";

        cin >> due;

        customers[i].due += due;

        cout << "Due ammount Updated Successfully!\n";

        cout << "Updated due: " << customers[i].due << endl;
    }

    //if no customer found
    else
    {
        cout << "There is no customer in this name!\n";

        cout << "Press 1 to view all customers\nPress 2 to go to main page!\n";

        int choice;

        cin >> choice;

        if(cin.fail())
        {
            cin.clear();

            cin.ignore(10000, '\n');

            cout << "Wrong keyword!\n";

            return;
        }

        if(choice == 1)
            view_all_customers();

        else if(choice == 2)
        {

            return;
        }

        else
        {
            cout << "Wrong keyword!\n";

            return;
        }
    }
}

 //Function to view all customer name with due
void view_all_customers()
{
    system("cls");


    if(customers.size() == 0)
    {
        cout << "No Customer Found!\n";

        return;
    }


    cout <<"Total Customer: " << customers.size() << "\tTotal Due: " << get_total_due() << " BDT" << endl;

    cout << endl;

    cout << "Name\t\tDue Ammount\n";

    for(auto i : customers)
    {
        cout << i.name;

        if(i.name.size() > 5)
            cout << "\t" << i.due << " BDT\n";

        else
            cout << "\t\t" << i.due << " BDT\n";
    }
}

 //Function a specific customer details
void view_customer_deails()
{
    system("cls");

    cout << "Customer Full Name: ";

    string name;

    fflush(stdin);

    getline(cin, name);

    int i;

    bool check = false;

    for(i = 0; i < customers.size(); i++)
    {
        if(customers[i].name == name)
        {
            check = true;

            break;
        }
    }

    if(check)
    {
        cout << "Due Ammount: " << customers[i].due << endl;

        cout << "Mobile Number: " << customers[i].mobile_number << endl;
    }

    else
    {
        cout << "There is no customer in this name!\n";

        cout << "Press 1 to view all customers\nPress 2 to go to main page!\n";

        int choice;

        cin >> choice;

        if(cin.fail())
        {
            cin.clear();

            cin.ignore(10000, '\n');

            cout << "Wrong keyword!\n";

            return;
        }

        if(choice == 1)
            view_all_customers();

        else if(choice == 2)
        {

            return;
        }

        else
        {
            cout << "Wrong keyword!\n";

            return;
        }
    }
}

 //Function to update customer details
void update_customer_details()
{
    system("cls");

    cout << "Customer Full Name: ";

    string name;

    fflush(stdin);

    getline(cin, name);

    int i;

    bool check = false;

    for(i = 0; i < customers.size(); i++)
    {
        if(customers[i].name == name)
        {
            check = true;

            break;
        }
    }

    if(check)
    {
        cout << "Press 1 to Change Customer Name\n";
        cout << "press 2 to Change Mobile Number\n";
        cout << "press 3 to Change Both\n";

        int choice;

        cin >> choice;

        if(choice == 1)
        {
            cout << "New name: ";

            fflush(stdin);

            getline(cin, customers[i].name);

            for(int j =  0; j < customers.size(); j++)
            {
                if(i == j)
                    continue;

                if(customers[j].name == customers[i].name)
                {
                    system("cls");

                    cout << "There is already a customer in this name!\n";
                    cout << "Press 1 to exit\nPress 2 to enter new name\n";

                    int choice;

                    cin >> choice;

                    if(choice == 1)
                        return;

                    else if(choice == 2)
                    {
                        cout << "Customer Name: ";

                        fflush(stdin);

                        getline(cin, customers[i].name);

                        j = -1;
                    }

                    else
                    {
                        cout << "Invalid keyword!\n";

                        return;
                    }
                }
            }

            cout << "Name Updated Successfully!\n";
        }

        else if(choice == 2)
        {
            cout << "New mobile number: ";

            cin >> customers[i].mobile_number;

            cout << "Mobile Number Updated Successfully!\n";
        }

        else if(choice == 3)
        {
            cout << "New name: ";

            fflush(stdin);

            getline(cin, customers[i].name);

            for(int j =  0; j < customers.size(); j++)
            {
                if(i == j)
                    continue;

                if(customers[j].name == customers[i].name)
                {
                    cout << "There is already a customer in this name!\n";
                    cout << "Press 1 to exit\nPress 2 to enter new name\n";

                    int choice;

                    cin >> choice;

                    if(choice == 1)
                        return;

                    else if(choice == 2)
                    {
                        cout << "Customer Name: ";

                        fflush(stdin);

                        getline(cin, customers[i].name);

                        j = -1;
                    }

                    else
                    {
                        cout << "Invalid keyword!\n";

                        return;
                    }
                }
            }

            cout << "Name Updated Successfully!\n";

            system("pause");

            system("cls");

            cout << "New mobile number: ";

            cin >> customers[i].mobile_number;

            cout << "Mobile Number Updated Successfully!\n";
        }

        else
        {
            cout << "Wrong keyword! Going to main page...\n";

            return;
        }
    }

    else
    {
        cout << "There is no customer in this name!\n";

        cout << "Press 1 to view all customers\nPress 2 to go to main page!\n";

        int choice;

        cin >> choice;

        if(cin.fail())
        {
            cin.clear();

            cin.ignore(10000, '\n');

            cout << "Wrong keyword!\n";

            return;
        }

        if(choice == 1)
            view_all_customers();

        else if(choice == 2)
        {

            return;
        }

        else
        {
            cout << "Wrong keyword!\n";

            return;
        }
    }
}

//Function to delete customer data
void delete_customer()
{
    system("cls");

    cout << "Customer Full Name: ";

    string name;

    fflush(stdin);

    getline(cin, name);

    int i;

    bool check = false;

    for(i = 0; i < customers.size(); i++)
    {
        if(customers[i].name == name)
        {
            check = true;

            break;
        }
    }

    if(check)
    {
        customers.erase(customers.begin() + i);

        cout << "Customer Data Deleted Successfully!\n";

    }

    else
    {
        cout << "There is no customer in this name!\n";

        cout << "Press 1 to view all customers\nPress 2 to go to main page!\n";

        int choice;

        cin >> choice;

        if(cin.fail())
        {
            cin.clear();

            cin.ignore(10000, '\n');

            cout << "Wrong keyword!\n";

            return;
        }

        if(choice == 1)
            view_all_customers();

        else if(choice == 2)
        {

            return;
        }

        else
        {
            cout << "Wrong keyword!\n";

            return;
        }
    }
}


//Function that will return total due of all customer
double get_total_due()
{
    double due = 0;

    for(auto i : customers)
        due += i.due;

    return due;
}

void saveDataToFile(const vector<Customer>& customers)
{
    ofstream file("customer.bin", ios::binary); // Open file in binary write mode

    if (!file.is_open())
        return;

    // Write number of customers as the first element
    int numPersons = customers.size();

    file.write(reinterpret_cast<const char*>(&numPersons), sizeof(int));


    // Write each person to the file
    for(const Customer& p : customers)
    {
        int nameSize = p.name.size();

        file.write(reinterpret_cast<const char*>(&nameSize), sizeof(int));
        file.write(p.name.c_str(), nameSize);

        file.write(reinterpret_cast<const char*>(&p.due), sizeof(double));

        int numSize = p.mobile_number.size();

        file.write(reinterpret_cast<const char*>(&numSize), sizeof(int));
        file.write(p.mobile_number.c_str(), numSize);
    }

    file.close(); // Close the file
}

void save_admin_data(Admin &data)
{
        ofstream file("admin.bin", ios::binary);

        if(!file.is_open())
            return;

        int idsize = data.user_id.size();

        file.write(reinterpret_cast <const char*> (&idsize), sizeof(int));
        file.write(data.user_id.c_str(), idsize);


        int pass_size = data.password.size();

        file.write(reinterpret_cast <const char*> (&pass_size), sizeof(int));
        file.write(data.password.c_str(), pass_size);

        file.close();

}


vector<Customer> retrieveDataFromFile()
{
    vector<Customer> customers;

    ifstream file("customer.bin", ios::binary); // Open file in binary read mode

    if (!file.is_open())
        return customers;

    // Read number of customers from the file
    int numcustomers;

    file.read(reinterpret_cast<char*>(&numcustomers), sizeof(int));

    // Read each person from the file
    for (int i = 0; i < numcustomers; i++)
    {
        Customer obj;

        int nameSize, numSize;


        file.read(reinterpret_cast<char*>(&nameSize), sizeof(int));
        obj.name.resize(nameSize);
        file.read(&obj.name[0], nameSize);


        file.read(reinterpret_cast<char*>(&obj.due), sizeof(double));


        file.read(reinterpret_cast<char*>(&numSize), sizeof(int));
        obj.mobile_number.resize(numSize);
        file.read(&obj.mobile_number[0], numSize);


        customers.push_back(obj);
    }

    file.close(); // Close the file

    return customers;
}

Admin get_admin_data()
{
    Admin data;

    ifstream file("admin.bin", ios::binary);

    if(!file.is_open())
    {
        data.user_id = "admin";

        data.password = "1234";

        return data;
    }

    int idsize, pass_size;


    file.read(reinterpret_cast <char*> (&idsize), sizeof(int));
    data.user_id.resize(idsize);
    file.read(&data.user_id[0], idsize);


    file.read(reinterpret_cast <char*> (&pass_size), sizeof(int));
    data.password.resize(pass_size);
    file.read(&data.password[0], pass_size);


    file.close();

    return data;
}
