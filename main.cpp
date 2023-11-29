#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
using namespace std;

class Movies
{
    string name;
    string genre;
    float rating;
    float user_rating;
    int views;
    int year;
    string director;
    string lead_actor;
    string lead_actress;

public:
    void set_user_rating(float userrating)
    {
        this->user_rating = userrating;
    }
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
    float get_user_rating()
    {
        return user_rating;
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
        cout << endl
             << "Name: " << name << endl;
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
        user_rating=0;
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
    Movies(const Movies &m)
    {
        name = m.name;
        genre = m.genre;
        rating = m.rating;
        views = m.views;
        year = m.year;
        director = m.director;
        lead_actor = m.lead_actor;
        lead_actress = m.lead_actress;
    }
    void movie_file() // to append movie details to a file
    {
        ofstream m("movies.txt", ios::app);
        m << name << setw(20) << genre << setw(20) << rating << setw(20) << views << setw(20) << year << setw(20) << director << setw(20) << lead_actor << setw(20) << lead_actress << endl;
        m.close();
    }
};
class Node
{
    Movies data;
    Node *next;
    Node *prev;

public:
    Node()
    {
        next = NULL;
        prev = NULL;
    }
    Node(Movies data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
    void set_data(Movies data)
    {
        this->data = data;
    }
    void set_next(Node *next)
    {
        this->next = next;
    }
    void set_prev(Node *prev)
    {
        this->prev = prev;
    }
    Movies get_data()
    {
        return data;
    }
    Node *get_next()
    {
        return next;
    }
    Node *get_prev()
    {
        return prev;
    }
};

void merge_sort(Node *&head, int choice);

class Hashtable
{
    Node *array[100];

public:
    Hashtable()
    {
        for (int i = 0; i < 100; i++)
        {
            array[i] = NULL;
        }
    }
    int hashFunction(string key)
    {
        unsigned int hash = 0;
        for (int i = 0; key[i] != '\0'; i++)
        {
            hash = (hash * 31) + key[i];
        }
        return hash % 100;
    }
    int hashFunction(int key)
    {
        return key % 100;
    }
    void insert(string key, Movies m)
    {
        int index = hashFunction(key);
        Node *newNode = new Node(m);
        if (array[index] == NULL)
        {
            array[index] = newNode;
        }
        else
        {
            newNode->set_next(array[index]);
            array[index]->set_prev(newNode);
            array[index] = newNode;
        }
    }
    void insert(int key, Movies m)
    {
        int index = hashFunction(key);
        Node *newNode = new Node(m);
        if (array[index] == NULL)
        {
            array[index] = newNode;
        }
        else
        {
            newNode->set_next(array[index]);
            array[index]->set_prev(newNode);
            array[index] = newNode;
        }
    }
    void print()
    {
        for (int i = 0; i < 100; i++)
        {
            if (array[i] != NULL)
            {
                Node *temp = array[i];
                while (temp != NULL)
                {
                    temp->get_data().print();
                    temp = temp->get_next();
                }
            }
        }
    }
<<<<<<< Updated upstream
    bool search(string key){
        int index=hashFunction(key);
        if(array[index]==NULL){
            cout<<"Movie not found"<<endl;
            return false;
        }
        else{
            Node *temp=array[index];
            while(temp!=NULL){
                if(temp->get_data().get_name()==key){
                    temp->get_data().print();
                    return true;
                }
                temp=temp->get_next();
            }
            cout<<"Movie not found"<<endl;
            return false;
=======
    void print_by_string(string key)
    {
        int index = hashFunction(key);
        Node *temp = array[index];
        merge_sort(temp, 2);
        while (temp != NULL)
        {
            if (temp->get_data().get_genre() == key)
            {
                temp->get_data().print();
            }
            temp = temp->get_next();
>>>>>>> Stashed changes
        }
    }
    Movies search_by_string(string key)
    {
        int index = hashFunction(key);
        Node *temp = array[index];
        while (temp != NULL)
        {
            if (temp->get_data().get_name() == key)
            {
                return temp->get_data();
            }
            temp = temp->get_next();
        }
        Movies m;
        return m;
    }
};
<<<<<<< Updated upstream
void latest_hits();
=======

Node *merge(Node *a, Node *b, int choice)
{
    Node *result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (choice == 1)
    {
        if (a->get_data().get_year() >= b->get_data().get_year())
        {
            result = a;
            result->set_next(merge(a->get_next(), b, choice));
        }
        else
        {
            result = b;
            result->set_next(merge(a, b->get_next(), choice));
        }
    }
    else if (choice == 2)
    {
        if (a->get_data().get_rating() >= b->get_data().get_rating())
        {
            result = a;
            result->set_next(merge(a->get_next(), b, choice));
        }
        else
        {
            result = b;
            result->set_next(merge(a, b->get_next(), choice));
        }
    }
    return result;
}

Node *get_mid(Node *head)
{
    Node *slow = head;
    Node *fast = head->get_next();
    while (fast != NULL)
    {
        fast = fast->get_next();
        if (fast != NULL)
        {
            slow = slow->get_next();
            fast = fast->get_next();
        }
    }
    return slow;
}
void merge_sort(Node *&head, int choice)
{
    if (head == NULL || head->get_next() == NULL)
    {
        return;
    }
    Node *mid = get_mid(head);
    Node *a = head;
    Node *b = mid->get_next();
    mid->set_next(NULL);
    merge_sort(a, choice);
    merge_sort(b, choice);
    head = merge(a, b, choice);
}

>>>>>>> Stashed changes
class Users
{
    string name;
    string email;
    string password;
    vector<Movies> my_list;
    vector<Movies> all_movies;
    Hashtable moviesByGenre;
    Hashtable moviesByActor;
    Hashtable moviesByActress;
    Hashtable moviesByDirector;
    Hashtable moviesByYear;
    Hashtable userMoviesByGenre;
    Hashtable userMoviesByActor;
    Hashtable userMoviesByActress;
    Hashtable userMoviesByDirector;

public:
    Users()
    {
        name = "";
        email = "";
        password = "";
    }
    Users(string name, string email, string password)
    {
        this->name = name;
        this->email = email;
        this->password = password;
    }
    Users(string filename)
    {
        filename.append(".txt");
        ifstream p(filename);
        string check;
        string name, genre, director, lead_actor, lead_actress;
        float rating;
        int views, year;
        if (p.is_open())
        {
            while (getline(p, check))
            {
                istringstream iss(check);
                iss >> name >> genre >> rating >> views >> year >> director >> lead_actor >> lead_actress;
                Movies movie(name, genre, rating, views, year, director, lead_actor, lead_actress);
                my_list.push_back(movie);
            }
        }
        else
        {
            cout << "File not found" << endl;
        }
        p.close();
    }
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

    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Password: " << password << endl;
    }
    void recommended_menu()
    {
        int choice;
        do
        {
            system("cls");
            cout << "1. For you" << endl;
            cout << "2. General" << endl;
            cout << "3. Latest hits" << endl;
            cout << "4. Exit" << endl;
            cin >> choice;
            if (choice >= 1 && choice <= 3)
                initializeHashTables();
            switch (choice)
            {
            case 1:
                for_you();
                break;
            case 2:
                general_recommendation();
                break;
            case 3:
                // latest hits func
                break;
            case 4:
                return;
            default:
                cout << "Invalid choice" << endl;
                break;
            }
        } while (1);
    }
    void user_interface()
    {
        int choice;
        do
        {
            system("cls");
            cout << "1. Add to My list" << endl;
            cout << "2. Recommendation Menu" << endl;
            cout << "3. Print My List" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                add_to_list();
                break;
            case 2:
                recommended_menu();
                break;
            case 3:
                print_list();
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
            }
        } while (1);
    }

    void initializeHashTables()
    {
        ifstream p("movies.txt");
        string check;
        string name, genre, director, lead_actor, lead_actress;
        float rating;
        int views, year;
        if (p.is_open())
        {
            while (getline(p, check))
            {
                istringstream iss(check);
                iss >> name >> genre >> rating >> views >> year >> director >> lead_actor >> lead_actress;
                Movies movie(name, genre, rating, views, year, director, lead_actor, lead_actress);
                all_movies.push_back(movie);
                moviesByGenre.insert(genre, movie);
                moviesByActor.insert(lead_actor, movie);
                moviesByActress.insert(lead_actress, movie);
                moviesByDirector.insert(director, movie);
            }
        }
        else
        {
            cout << "File not found" << endl;
        }
        p.close();
<<<<<<< Updated upstream
    }
   
    void for_you(){
        string name, genre, director, lead_actor, lead_actress;
        float rating;
        int views, year;
        string check;
        ifstream p("movies.txt");
        if (p.is_open())
        {
            while (getline(p, check))
            {
                istringstream iss(check);
                iss >> name >> genre >> rating >> views >> year >> director >> lead_actor >> lead_actress;
                Movies m(name, genre, rating, views, year, director, lead_actor, lead_actress);
                watchlist.insert(genre,m);
            }
        }
        else
        {
            cout << "File not found" << endl;
        }
        p.close();
        
    }
    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Password: " << password << endl;
        cout << "My List: " << endl;
        
    }

   void recommended_menu(){
         int choice;
         do{
          system("cls");
          cout<<"1. For you"<<endl;
          cout<<"2. General"<<endl;
          cout<<"3. Latest hits"<<endl;
          cout<<"4. Exit"<<endl;
          cin>>choice;
          switch(choice){
                case 1:
                for_you();
                break;
                case 2:
                //general func
                break;
                case 3:
                latest_hits();
                break;
                case 4:
                return;
                default:
                cout<<"Invalid choice"<<endl;
                break;
          }
         }
         while(1);
   }
    void user_interface(){
        int choice;
       do{
        system("cls");
        cout<<"1. Add to my list"<<endl;
        cout<<"2. Recommended"<<endl;
        cout<<"3. Exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            //add to my list
            break;
            case 2:
            recommended_menu();
            break;
            case 3:
            return;
            break;
            default:
            cout<<"Invalid choice"<<endl;
            break;
=======
        for (int i = 0; i < my_list.size(); i++)
        {
            userMoviesByGenre.insert(my_list[i].get_genre(), my_list[i]);
            userMoviesByActor.insert(my_list[i].get_lead_actor(), my_list[i]);
            userMoviesByActress.insert(my_list[i].get_lead_actress(), my_list[i]);
            userMoviesByDirector.insert(my_list[i].get_director(), my_list[i]);
>>>>>>> Stashed changes
        }
    }
    void add_to_list()
    {
<<<<<<< Updated upstream
        name = "";
        email = "";
        password = "";
       
    }
    
    Users(string name, string email, string password)
    {
        this->name = name;
        this->email = email;
        this->password = password;
        
    }
    Users(string filename)
    {   
        set_watchlist(filename);
=======
        string searchName;
        cout << "Enter the name of the movie: ";
        cin.ignore(); // Clear buffer
        getline(cin, searchName);
        Movies movie = moviesByGenre.search_by_string(searchName);
        if (movie.get_name() == "")
        {
            cout << "Movie not found" << endl;
        }
        else
        {
            float rating;
            cout << "How would u rate the movie? (Rate out of 5)" << endl;
            cin >> rating;
            movie.set_rating(rating);
            my_list.push_back(movie);
            userMoviesByGenre.insert(movie.get_genre(), movie);
            userMoviesByActor.insert(movie.get_lead_actor(), movie);
            userMoviesByActress.insert(movie.get_lead_actress(), movie);
            userMoviesByDirector.insert(movie.get_director(), movie);
            cout << "Movie added to your list" << endl;
        }
        cout << "Press any key to continue" << endl;
        getch();
>>>>>>> Stashed changes
    }

    void for_you()
    {

    }

    void general_recommendation()
    {
        cout << "Select how you want the movies to be recommended:" << endl;
        cout << "1. By Genre" << endl;
        cout << "2. By Actor" << endl;
        cout << "3. By Actress" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string searchGenre;
            cout << "Enter the genre: ";
            cin.ignore(); // Clear buffer
            getline(cin, searchGenre);
            moviesByGenre.print_by_string(searchGenre);
            cout << endl << "Press any key to continue" << endl;
            getch();
            break;
        }
        case 2:
        {
            // Recommend movies by actor
            string searchActor;
            cout << "Enter the actor's name: ";
            cin.ignore(); // Clear buffer
            getline(cin, searchActor);
            moviesByActor.print_by_string(searchActor);
            cout << endl << "Press any key to continue" << endl;
            getch();
            break;
        }
        case 3:
        {
            // Recommend movies by genre
            string searchGenre;
            cout << "Enter the actress' name: ";
            cin.ignore(); // Clear buffer
            getline(cin, searchGenre);
            moviesByActress.print_by_string(searchGenre);
            cout << endl << "Press any key to continue" << endl;
            getch();
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    void print_list()
    {
        for (int i = 0; i < my_list.size(); i++)
        {
            my_list[i].print();
        }
        cout << "Press any key to continue" << endl;
        getch();
    }

    void user_file() // to append user login credentials to a file
    {
        ofstream m("users.txt", ios::app);
        m << name << setw(20) << email << setw(20) << password << endl;
        m.close();
        string filename = name;
        filename.append(".txt");
        ofstream new_file(filename);
        new_file.close();
    }
};
<<<<<<< Updated upstream
Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    Node* result = NULL;
    Movies l(left->get_data());
    Movies r(right->get_data());
    if (l.get_rating() >= r.get_rating()) {
        result = left;
        result->set_next( merge(left->get_next(), right));
    } else {
        result = right;
        result->set_next((left, right->get_next()));
    }

    return result;
}

// Function to perform merge sort on the linked list
Node* mergeSort(Node* head) {
    if (!head || !head->get_next()) { // Base case: 0 or 1 node
        return head;  // Base case: empty list or single node
    }

    // Split the list into two halves
    Node* slow = head;
    Node* fast = head->get_next();

    while (fast && fast->get_next()) {
        slow = slow->get_next();
        fast = fast->get_next()->get_next();
    }

    Node* secondHalf = slow->get_next();
    slow->set_next(NULL);

    // Recursively sort each half
    head = mergeSort(head);
    secondHalf = mergeSort(secondHalf);

    // Merge the sorted halves
    return merge(head, secondHalf);
}
void latest_hits(){
    Hashtable table;
    string name, genre, director, lead_actor, lead_actress;
    float rating;
    int views, year;
    string check;
    ifstream p("movies.txt");
    if (p.is_open())
    {
        while (getline(p, check))
        {
            istringstream iss(check);
            iss >> name >> genre >> rating >> views >> year >> director >> lead_actor >> lead_actress;
            Movies m(name, genre, rating, views, year, director, lead_actor, lead_actress);
            table.insert(year,m);
            
        }
    }
    else
    {
        cout << "File not found" << endl;
    }
    p.close();
    Node *temp=table.get_root_node(2023);
    //  table.print();
     
    temp=mergeSort(temp);
    // temp->get_data().print();
    // cin>>name;
    while(temp!=NULL){
        temp->get_data().print();
        temp=temp->get_next();
    }
    cout<<"Press any button to continue"<<endl;
    cin>>name;
}
string signIn(string username, string password)
=======

void displayMenu();

void signIn()
>>>>>>> Stashed changes
{
    string username;
    string password;
    system("cls");
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    ifstream p("users.txt");
    if (!p.is_open())
    {
        cout << "Error opening the file" << endl;
    }
    else
    {
        string check;
        string name, email, pass;
        while (getline(p, check))
        {

            istringstream iss(check);
            iss >> name >> email >> pass;
            if (username == name && pass == password)
            {
                Users u1(username);
                system("cls");
                u1.user_interface();
                break;
            }
        }
        if (p.eof())
        {
            cout << "Invalid username or password" << endl;
            cout << "Press any key to continue" << endl;
            getch();
            displayMenu();
        }
    }
}

// class Admin
// {
//     string name;
//     string email;
//     string password;
// };

void signUp()
{
    system("cls");
    string name, email, password;
    cout << "Enter your user name: ";
    cin >> name;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your password: ";
    cin >> password;
    Users u(name, email, password);
    u.user_file();
    // add code to sort the username in ascending order and to make sure no duplicate usernames are added
    cout << "Sign-up successful. You can now sign in with your credentials." << endl;
    cout << "Press any key to continue" << endl;
    getch();
    displayMenu();
}
void handleMenuChoice(int choice)
{
    string username;
    string password;
    string email;

    if (choice == 1)
    {
        signIn();
    }
    else if (choice == 2)
    {
        signUp();
    }
    else if (choice == 3)
    {
        return;
    }
    else
    {
        cout << "Invalid choice. Please enter a valid option." << endl;
    }
}

void displayMenu()
{
    system("cls");
    cout << "=== Movie App Menu ===" << endl;
    cout << "1. Sign In" << endl;
    cout << "2. Sign Up" << endl;
    cout << "3. Exit" << endl;
    cout << "======================" << endl;
    int choice;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        handleMenuChoice(choice);

    } while (choice != 3);
}

void exitProgram()
{
    cout << "Exiting the program. Goodbye!" << endl;
    // Add any necessary cleanup code before exiting
    exit(0);
}

int main()
{
    displayMenu();

    return 0;
}
