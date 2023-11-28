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
    Movies(const Movies &m){
        name=m.name;
        genre=m.genre;
        rating=m.rating;
        views=m.views;
        year=m.year;
        director=m.director;
        lead_actor=m.lead_actor;
        lead_actress=m.lead_actress;
    }
    void movie_file() // to append movie details to a file
    {
        ofstream m("movies.txt", ios::app);
        m << name << setw(20) << genre << setw(20) << rating << setw(20) << views << setw(20) << year << setw(20) << director << setw(20) << lead_actor << setw(20) << lead_actress << endl;
        m.close();
    }
};
class Node{
    Movies data;
    Node *next;
    Node *prev;
    public:
    Node(){
        next=NULL;
        prev=NULL;
    }
    Node(Movies data){
        this->data=data;
        next=NULL;
        prev=NULL;
    }
    void set_data(Movies data){
        this->data=data;
    }
    void set_next(Node *next){
        this->next=next;
    }
    void set_prev(Node *prev){
        this->prev=prev;
    }
    Movies get_data(){
        return data;
    }
    Node *get_next(){
        return next;
    }
    Node *get_prev(){
        return prev;
    }
};
class Hashtable{
    Node *array[100];
    public:
    Hashtable(){
        for(int i=0;i<100;i++){
            array[i]=NULL;
        }
    }
    int hashFunction(string key){
        int hash=0;
        for(int i=0;key[i]!=NULL;i++){
            hash=(hash*31)+key[i];
        }
        return hash%100;
    }
    int hashFunction(int key){
        return key%100;
    }
    void insert(string key,Movies m){
        int index=hashFunction(key);
        Node *newNode=new Node(m);
        if(array[index]==NULL){
            array[index]=newNode;
        }
        else{
            Node *temp=array[index];
            while(temp->get_next()!=NULL){
                temp=temp->get_next();
            }
            temp->set_next(newNode);
            newNode->set_prev(temp);
        }
    }
    void insert(int key,Movies m){
        int index=hashFunction(key);
        Node *newNode=new Node(m);
        if(array[index]==NULL){
            array[index]=newNode;
        }
        else{
            Node *temp=array[index];
            while(temp->get_next()!=NULL){
                temp=temp->get_next();
            }
            temp->set_next(newNode);
            newNode->set_prev(temp);
        }
    }
    void print(){
        for(int i=0;i<100;i++){
            if(array[i]!=NULL){
                Node *temp=array[i];
                while(temp!=NULL){
                    temp->get_data().print();
                    temp=temp->get_next();
                }
            }
        }
    }
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
        }
    }
    Node* get_root_node(string key){
        int index=hashFunction(key);
        if(array[index]==NULL){
            return NULL;
        }
        else{
            return array[index];
        }
    }
    Node* get_root_node(int key){
        int index=hashFunction(key);
        if(array[index]==NULL){
            return NULL;
        }
        else{
            return array[index];
        }
    }        
};
void latest_hits();
class Users
{
    string name;
    string email;
    string password;
    Hashtable watchlist;

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
    void print_watchlist(){
        watchlist.print();
    }
    void set_watchlist(string filename){
        string name, genre, director, lead_actor, lead_actress;
        float rating;
        int views, year;
        string check;
        
        ifstream p(filename);
        if (p.is_open())
        {
            while (getline(p, check))
            {
                istringstream iss(check);
                iss >> name >> genre >> rating >> views >> year >> director >> lead_actor >> lead_actress;
                Movies m(name, genre, rating, views, year, director, lead_actor, lead_actress);
                watchlist.insert(name,m);
            }
        }
        else
        {
            cout << "File not found" << endl;
        }
        p.close();
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
        }
       }
       while(1);
    }
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
        set_watchlist(filename);
    }

    void create_user_file() // to append user login credentials to a file
    {
        ofstream m("users.txt",ios::app);
        m << name << setw(20) << email << setw(20) << password << endl;
        m.close();
        string filename=name;
        filename.append(".txt");
        ofstream new_file(filename);
        new_file.close();
    }
};
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
{
    string name, email, pass;
    string check;
    int i = 0;
    ifstream p("users.txt");
	if(p.is_open()){
		cout<<"fileopen";
	}
    while (getline(p, check))
    {
        
            istringstream iss(check);
            iss >> name >> email >> pass;
            if (username == name && pass == password)
            {
                p.close();
                return username;
            
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
void displayMenu() {
    cout << "=== Movie App Menu ===" << endl;
    cout << "1. Sign In" << endl;
    cout << "2. Sign Up" << endl;
    cout << "3. Exit" << endl;
    cout << "======================" << endl;
}
void signUp() {
    system("cls");
    string name, email, password;
    cout << "Enter your user name: ";
    cin >> name;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your password: ";
    cin >> password;
    Users u(name, email, password);
    u.create_user_file();
    // add code to sort the username in ascending order and to make sure no duplicate usernames are added
    cout << "Sign-up successful. You can now sign in with your credentials." << endl;
    cout << "Press any key to continue" << endl;
    getch();
}
void handleMenuChoice(int choice) {
    string username;
    string password;
    string email;
    
    if (choice == 1) {
        system("cls");
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
        username=signIn(username, password);
        if(username!="\0"){
        Users u1(username);
        system("cls");
        u1.user_interface();}
        
    } else if (choice == 2) {
        signUp();
    } else if (choice == 3) {
       return;
    } else {
        cout << "Invalid choice. Please enter a valid option." << endl;
    }
}

void exitProgram()
{
    cout << "Exiting the program. Goodbye!" << endl;
    // Add any necessary cleanup code before exiting
    exit(0);
}

int main()
{
    int choice;

    do
    {
        system("cls");
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        handleMenuChoice(choice);

    } while (choice != 3); // Exit when the user chooses option 4

    return 0;
}
