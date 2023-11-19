#include <iostream>
#include <conio.h>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
#include <list>
using namespace std;


class Movies
{
    string name;
    string genre;
    float rating;
    int views;
    int year;
    string director;
    string lead_actor;
    string lead_actress;

public:
    void set_name(string name)
    {
        this->name = name;
    }
    void set_genre(string genre)
    {
        this->genre = genre;
    }
    void set_rating(float rating)
    {
        this->rating = rating;
    }
    void set_views(int views)
    {
        this->views = views;
    }
    void set_year(int year)
    {
        this->year = year;
    }
    void set_director(string director)
    {
        this->director = director;
    }
    void set_lead_actor(string lead_actor)
    {
        this->lead_actor = lead_actor;
    }
    void set_lead_actress(string lead_actress)
    {
        this->lead_actress = lead_actress;
    }
    string get_name()
    {
        return name;
    }
    string get_genre()
    {
        return genre;
    }
    float get_rating()
    {
        return rating;
    }
    int get_views()
    {
        return views;
    }
    int get_year()
    {
        return year;
    }
    string get_director()
    {
        return director;
    }
    string get_lead_actor()
    {
        return lead_actor;
    }
    string get_lead_actress()
    {
        return lead_actress;
    }

    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Genre: " << genre << endl;
        cout << "Rating: " << rating << endl;
        cout << "Views: " << views << endl;
        cout << "Year: " << year << endl;
        cout << "Director: " << director << endl;
        cout << "Lead Actor: " << lead_actor << endl;
        cout << "Lead Actress: " << lead_actress << endl;
    }
    Movies()
    {
        name = "";
        genre = "";
        rating = 0;
        views = 0;
        year = 0;
        director = "";
        lead_actor = "";
        lead_actress = "";
    }
    Movies(string name, string genre, float rating, int views, int year, string director, string lead_actor, string lead_actress)
    {
        this->name = name;
        this->genre = genre;
        this->rating = rating;
        this->views = views;
        this->year = year;
        this->director = director;
        this->lead_actor = lead_actor;
        this->lead_actress = lead_actress;
    }
    
    void movie_file() // to append movie details to a file
    {
        ofstream m("movies.txt", ios::app);
        m << name << setw(20) << genre << setw(20) << rating << setw(20) << views << setw(20) << year << setw(20) << director << setw(20) << lead_actor << setw(20) << lead_actress << endl;
        m.close();
    }
};

class Users
{
    string name;
    string email;
    string password;
    Movies *myList;
    int myListSize;

public:
    void set_name(string name)
    {
        this->name = name;
    }
    void set_email(string email)
    {
        this->email = email;
    }
    void set_password(string password)
    {
        this->password = password;
    }
    void set_myList(Movies *myList, int myListSize)
    {
        this->myList = myList;
        this->myListSize = myListSize;
    }
    string get_name()
    {
        return name;
    }
    string get_email()
    {
        return email;
    }
    string get_password()
    {
        return password;
    }
    Movies *get_myList()
    {
        return myList;
    }
    int get_myListSize()
    {
        return myListSize;
    }
    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Password: " << password << endl;
        cout << "My List: " << endl;
        for (int i = 0; i < myListSize; i++)
        {
            myList[i].print();
        }
    }
    Users()
    {
        name = "";
        email = "";
        password = "";
        myList = NULL;
        myListSize = 0;
    }
    Users(string name, string email, string password)
    {
        this->name = name;
        this->email = email;
        this->password = password;
        myList = NULL;
        myListSize = 0;
    }
    Users(string name, string email, string password, Movies *myList, int myListSize)
    {
        this->name = name;
        this->email = email;
        this->password = password;
        this->myList = myList;
        this->myListSize = myListSize;
    }
    Users(string filename)
    {
        filename.append(".txt");
        cout << filename << endl;
        ifstream p(filename,ios::in);
        string check;
        // we have to wrrite code to read movies from the file and then store it in the array
        if(p.is_open()){
            while(getline(p, check)){
			
			 if (!p.eof())
            {
                istringstream iss(check);
                iss >> name >> email >> password;
                //we have to write to a func to write movies into the obj aswell
            }
}}
  else{cout<<"File not found"<<endl;
  }      
        p.close();
    }

    void user_file() // to append user login credentials to a file
    {
        ofstream m("users.txt", ios::app);
        m << name << setw(20) << email << setw(20) << password << endl;
        m.close();
    }
};
string signIn(string username, string password)
{
    string name, email, pass;
    string check;
    int i = 0;
    ifstream p("users.txt");
    
       while( getline(p, check)){
	           if (!p.eof())
        {
            istringstream iss(check);
            iss >> name >> email >> pass;
            if (username == name && pass == password)
            {
            	p.close();
                return username;
            }
        }
}
    
    cout << "Invalid username or password" << endl;
    cout << "Press any key to continue" << endl;
    getch();
    system("cls");
    // menu();
    p.close();
    return "\0";
    
}


// class Admin
// {
//     string name;
//     string email;
//     string password;
// };

// class Recommendation
// {
//     int capacity;
//     list<Movies> *table;

// public:
//     // make a
// };
void displayMenu() {
    cout << "=== Movie App Menu ===" << endl;
    cout << "1. Sign In" << endl;
    cout << "2. Sign Up" << endl;
    cout << "3. Exit" << endl;
    cout << "======================" << endl;
}
void signUp() {
    
    string name, email, password;
    cout << "Enter your user name: ";
    cin >> name;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your password: ";
    cin >> password;
    Users u(name, email, password, NULL, 0);
    u.user_file();
    // add code to sort the username in ascending order and to make sure no duplicate usernames are added
    cout << "Sign-up successful. You can now sign in with your credentials." << endl;
}2
void handleMenuChoice(int choice) {
    string username;
    string password;
    string email;
    
    if (choice == 1) {
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
        Users u1(signIn(username, password));
        //call interface function of user
    } else if (choice == 2) {
        signUp();
    } else if (choice == 3) {
       return;
    } else if (choice == 4) {
        // Do nothing; exit handled in the loop condition
    } else {
        cout << "Invalid choice. Please enter a valid option." << endl;
    }
}





void exitProgram() {
    cout << "Exiting the program. Goodbye!" << endl;
    // Add any necessary cleanup code before exiting
    exit(0);
}
    
    int main() {
        // Movies m("Avengers", "Action", 4.5, 100, 2012, "Russo Brothers", "Robert Downey Jr.", "Scarlett Johansson");
    // m.movie_file();
    // string name="Niggs";
    // Users user("John", "kike","bruh");
    // user.user_file();
    // name=login("John", "bruh");
    // Users u(name);
    // cout<<u.get_name()<<endl;
    // cout<<u.get_email()<<endl;
    // cout<<u.get_password()<<endl;
    int choice;

    do {
        system("cls");
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        handleMenuChoice(choice);

    } while (choice != 4); // Exit when the user chooses option 4

    return 0;
}




