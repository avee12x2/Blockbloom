#include <bits/stdc++.h>

using namespace std;

class Movie {
    private:
        pair <int, int> dur;
        pair <int, int> strt_time;
        int capacity;
        int booked;
        int price;
        
    public:
        bool exists;
        string title;
        set <pair<string, int> > viewers;
        Movie()
        {
            title = "";
            dur = {0, 0};
            strt_time ={0, 0};
            capacity = 0;
            booked = 0;
            price = 0;
            exists = false;
        }

        bool init(vector <bool>& time)
        {
            cout<<"Enter movie Title: ";
            std::getline(cin, title);
            cout<<"Enter duration of Movie (hr min): ";
            cin>>dur.first;
            cin>>dur.second;
            cout<<"Enter Start Time (hr min): ";
            cin>>strt_time.first;
            cin>>strt_time.second;
            cout<<"Enter Capacity: ";
            cin>>capacity;
            booked = 0;
            cout<<"Enter Price of a Ticket: ";
            cin>>price;
            exists = true;
            bool avail = true;

            int start = strt_time.first*60+strt_time.second;
            int dura = dur.first*60+dur.second;
            for(int i=start; i<start+dura; i++)
            {
                if(time[i])
                {
                    avail = false;
                    break;
                }
            }
            if(!avail)
            {
                return avail;
            }
            for(int i=start; i<start+dura; i++)
            {
                time[i] = true;
            }
            return true;
        }

        void print()
        {
            cout<<"\n";
            cout<<"Title: "<<title<<"\n";
            cout<<"Duration: "<<dur.first<<"hrs "<<dur.second<<"mins"<<"\n";
            printf("Start Time: %02d:%02d\n", strt_time.first, strt_time.second);
            //cout<<"Start Time: "<<strt_time.first<<"hrs "<<strt_time.second<<"mins"<<"\n";
            cout<<"Capacity: "<<capacity<<"\n";
            cout<<"Price: "<<price<<"\n";
        }

        void del(vector <bool>& time)
        {
            int start = get_strt_time().first*60 + get_strt_time().second;
            int dura = get_dur().first*60 + get_dur().second;
            for(int i=start; i<start+dura; i++)
            {
                time[i] = false;
            }
            dur = make_pair(0, 0);
            strt_time = make_pair(0, 0);
            capacity = 0;
            booked = 0;
            price = 0;
            title = "";
            viewers.clear();
            exists = false;
        }

        void viewer_list()
        {
            cout<<"List of Customers who have booked tickets for "<<title<<":\n";
            cout<<"Customer ID\t"<<"No of Tickets\n";
            for(auto itr:viewers)
            {
                printf("%-11s\t%d\n", itr.first.c_str(), itr.second);
            }
            cout<<"\n";
        }

        int seats_left()
        {
            return capacity-booked;
        }

        int get_price()
        {
            return price;
        }

        void book_ticket(string id, int book)
        {
            booked += book;
            viewers.insert(make_pair(id, book));
        }

        void cancel_ticket(string id, int book)
        {
            booked -= book;
            viewers.erase(make_pair(id, book));
        }

        pair <int, int> get_dur()
        {
            return dur;
        }

        pair <int, int> get_strt_time()
        {
            return strt_time;
        }

};

class Manager {
    private:
        string name;
        string password;

    public:
        int acc_balance;

        Manager()
        {
            name = "";
            password = "";
            acc_balance = 0;
        }

        void init()
        {
            cout<<"Enter the name of the Manager: ";
            cin>>name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter the password of the Manager: ";
            cin>>password;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            acc_balance = 0;
        }

        void print()
        {
            cout<<"\nName: "<<name<<" "<<"Password: "<<password<<"\n";
        }

        string get_name()
        {
            return name;
        }

        bool verify_password(string pass)
        {
            return pass==password;
        }

        bool change_password(string old_pass, string new_pass)
        {
            if(old_pass==password)
            {
                password = new_pass;
                return true;
            }
            else
            {
                return false;
            }
        }

        void add_amt(int amt)
        {
            acc_balance += amt;
        }

};

class Customer {
    private:
        string id;
        string password;
        int acc_balance;
        

    public:
        set <pair<int, int>> my_movies;

        void init()
        {
            cout<<"Enter User ID of the Customer: ";
            cin>>id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter the password of the Customer: ";
            cin>>password;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Enter initial Account Balance of the Customer: ";
            cin>>acc_balance;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        void print()
        {
            cout<<"\nUser ID: "<<id<<" "<<"Password: "<<password<<" ";
            cout<<"Account Balance: "<<acc_balance<<"\n";
        }

        string get_id()
        {
            return id;
        }

        int get_balance()
        {
            return acc_balance;
        }

        void add_amt(int amt)
        {
            acc_balance += amt;
        }

        bool verify_password(string pass)
        {
            return pass==password;
        }

        bool change_password(string old_pass, string new_pass)
        {
            if(old_pass==password)
            {
                password = new_pass;
                return true;
            }
            else
            {
                return false;
            }
        }

        void add_movie(int index, int tickets)
        {
            my_movies.insert(make_pair(index, tickets));
        }

        void cancel_movie(int index, int tickets)
        {
            my_movies.erase(make_pair(index, tickets));
        }
};

int display_movies(vector <Movie>& mov, bool input)
{
    cout<<"No. Movies\t\tStart Time\tDuration\tSeat Left\tPrice\n";
    int j = 0;
    vector <int> choice_to_index;
    for(int i=0; i<mov.size(); i++)
    {
        if(mov[i].exists)
        {
            printf("%2d. %-23s %02d:%02d     \t", j+1, mov[i].title.c_str(), mov[i].get_strt_time().first, mov[i].get_strt_time().second);
            printf("%02d:%02d   \t%-9d\t%-5d\n", mov[i].get_dur().first, mov[i].get_dur().second, mov[i].seats_left(), mov[i].get_price());
            choice_to_index.push_back(i);
            j++;
        }
    }
    cout<<"\n";
    if(input)
    {
        cout<<"Enter Choice: ";
        int choice;
        cin>>choice;
        if(choice>j)
        {
            return -1;
        }
        return choice_to_index[choice-1];
    }
    return 0;
}

void manager_control(Manager& mng, vector <Movie>& mov, vector <bool>& time, vector <Customer>& cstm, map <string, int>& cstm_index )
{
    system("cls");
    cout<<"Login as Manager Succesfull\n\n";

    while(true)
    {
        cout<<"Welcome Manager "<<mng.get_name()<<"\n\n";
        cout<<"What Task would you like to perform?\n";
        cout<<"1. View List of Movies\n";
        cout<<"2. Add A New Movie\n";
        cout<<"3. Remove a Movie\n";
        cout<<"4. View List of Customers who have booked tickects for a Movie\n";
        cout<<"5. View Account Balance\n";
        cout<<"6. Change Password\n";
        cout<<"7. Logout\n";
        cout<<"Choice: ";
        int choice;
        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(choice==1)
        {
            system("cls");
            display_movies(mov, false);
        }
        else if(choice==2)
        {
            int index = 0;
            while(index < mov.size() && mov[index].exists)
            {
                index++;
            }
            if(index==mov.size())
            {
                system("cls");
                cout<<"Maximum Number of Movies reached. No new Movies can be added\n\n";
            }
            else
            {
                bool avail;
                avail = mov[index].init(time);
                if(avail==false)
                {
                    mov[index].del(time);
                    system("cls");
                    cout<<"Time Not Available. Movie Not Added\n\n";
                }
                else
                {
                    mov[index].print();
                    cout<<"Enter y to confirm, n to cancel: ";
                    string confirm;
                    cin>>confirm;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    if(confirm=="n")
                    {
                        mov[index].del(time);
                        system("cls");
                        cout<<"Movie Cancelled\n\n";
                    }
                    else
                    {
                        system("cls");
                        cout<<"Movie Added\n\n";
                    }
                }
            }
        }
        else if(choice==3)
        {
            cout<<"\nWhich movie do you want to remove?\n\n";
            int index = display_movies(mov, true);
            if(index==-1)
            {
                system("cls");
                cout<<"Invalid Choice\n\n";
            }
            else
            {
                for(auto itr: mov[index].viewers)
                {
                    int tickets = itr.second;
                    cstm[cstm_index[itr.first]].add_amt(mov[index].get_price()*tickets);
                    mng.add_amt(-mov[index].get_price()*tickets);
                    cstm[cstm_index[itr.first]].cancel_movie(index, tickets);
                }
                mov[index].del(time);
                system("cls");
                cout<<"Movie Deleted\n\n";
            }
        }
        else if(choice==4)
        {
            cout<<"\nSelect a Movie\n\n";
            int index = display_movies(mov, true);
            if(index==-1)
            {
                system("cls");
                cout<<"Invalid Choice\n\n";
            }
            else
            {
                system("cls");
                mov[index].viewer_list();
            }
        }
        else if(choice==5)
        {
            system("cls");
            cout<<"Account Balance: "<<mng.acc_balance<<"\n\n";
        }
        else if(choice==6)
        {
            string old_pass, new_pass;
            cout<<"Enter Old Password: ";
            cin>>old_pass;
            cout<<"Enter New Passsword: ";
            cin>>new_pass;
            bool succ = mng.change_password(old_pass, new_pass);
            system("cls");
            if(succ==true)
            {
                cout<<"Password Change Succesful\n\n";
            }
            else
            {
                cout<<"Password Change Failed - Wrong Old Password\n\n";
            }
        }
        else if(choice==7)
        {
            break;
        }
        else
        {
            system("cls");
            cout<<"Invalid Choice\n\n";
        }
    }
}

void customer_control(Customer& cust, vector <Movie>& mov, vector <bool>& time, Manager& mng)
{
    system("cls");
    cout<<"Login Successful\n\n";

    while(true)
    {
        cout<<"Welcome "<<cust.get_id()<<"\n";
        cout<<"What Task would you like to perform?\n";
        cout<<"1. View List of Movies\n";
        cout<<"2. View My Movies\n";
        cout<<"3. Book Tickets\n";
        cout<<"4. Cancel Tickets\n";
        cout<<"5. View Account Balance\n";
        cout<<"6. Add Money to Account\n";
        cout<<"7. Change Password\n";
        cout<<"8. Logout\n";
        cout<<"Choice: ";
        int choice;
        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(choice==1)
        {
            system("cls");
            display_movies(mov, false);
        }
        else if(choice==2)
        {
            system("cls");
            cout<<"No. Movie\t\tTickets\n";
            int j = 0;
            for(auto itr: cust.my_movies)
            {
                printf("%2d. %-23s%d\n", j+1, mov[itr.first].title.c_str(), itr.second);
                j++;
            }
            cout<<"\n";
        }
        else if(choice==3)
        {
            cout<<"\nSelect Movie to book tickets\n\n";
            int index = display_movies(mov, true);
            if(index == -1)
            {
                system("cls");
                cout<<"Invalid Choice\n\n";
            }
            else
            {
                int sts_left = mov[index].seats_left();
                int price = mov[index].get_price();
                cout<<"\nNumber of Seats Left: "<<sts_left;
                cout<<"\nPrice of 1 seat: "<<price;
                cout<<"\nEnter number of seats to be booked: ";
                int book;
                cin>>book;
                if(book>sts_left)
                {
                    system("cls");
                    cout<<"Not Enough Seats\n\n";
                }
                else if(book*price > cust.get_balance())
                {
                    system("cls");
                    cout<<"Not Enough Money\n\n";
                }
                else
                {
                    mov[index].book_ticket(cust.get_id(), book);
                    cust.add_amt(-book*price);
                    mng.add_amt(book*price);
                    cust.add_movie(index, book);
                    system("cls");
                    cout<<"Successfully booked "<<book<<" tickets\n\n";
                }
            }
        }
        else if(choice==4)
        {
            cout<<"Select Movie to Cancel\n";
            cout<<"No. Movie\t\tTickets\n";
            int j = 0;
            vector <pair<int, int> > choice_to_index_tickets;
            for(auto itr: cust.my_movies)
            {
                printf("%2d. %-23s%d\n", j+1, mov[itr.first].title.c_str(), itr.second);
                choice_to_index_tickets.push_back(make_pair(itr.first, itr.second));
                j++;
            }
            cout<<"\n";
            cout<<"\nEnter Choice: ";
            int choice;
            cin>>choice;
            if(choice>j)
            {
                system("cls");
                cout<<"Invalid Choice\n\n";
            }
            else
            {
                int index = choice_to_index_tickets[choice-1].first;
                int tickets = choice_to_index_tickets[choice-1].second;
                mov[index].cancel_ticket(cust.get_id(), tickets);
                cust.add_amt(mov[index].get_price()*tickets);
                mng.add_amt(-mov[index].get_price()*tickets);
                cust.cancel_movie(index, tickets);
                system("cls");
                cout<<"Movie Cancelled Successfully\n\n";
            }

        }
        else if(choice==5)
        {
            system("cls");
            cout<<"Account Balance: "<<cust.get_balance()<<"\n\n";
        }
        else if(choice==6)
        {
            cout<<"Enter Amount to be added: ";
            int amt;
            cin>>amt;
            cust.add_amt(amt);
            system("cls");
            cout<<"Amount Added Successfully\n\n";
        }
        else if(choice==7)
        {
            string old_pass, new_pass;
            cout<<"Enter Old Password: ";
            cin>>old_pass;
            cout<<"Enter New Passsword: ";
            cin>>new_pass;
            bool succ = cust.change_password(old_pass, new_pass);
            system("cls");
            if(succ==true)
            {
                cout<<"Password Change Succesful\n\n";
            }
            else
            {
                cout<<"Password Change Failed - Wrong Old Password\n\n";
            }
        }
        else if(choice==8)
        {
            break;
        }
        else
        {
            system("cls");
            cout<<"Invalid Choice\n\n";
        }
    }
}

int main() {
    cout<<"Initializing System:\n\n";
    cout<<"First we will initialize the Manager\n";
    Manager mng;
    string c = "n";
    while(c=="n")
    {
        mng.init();
        mng.print();
        cout<<"Are the above details correct (y/n): ";
        cin>>c;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while(c!="y" && c!="n")
        {
            cout<<"Incorrect Input\nEnter Again: ";
            cin>>c;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout<<"\n";
    }
    
    system("cls");

    map <string, int> cstm_index;

    cout<<"Now we will Initialize the Customers\n";
    int no_customers;
    cout<<"Enter Number of Customers (N): ";
    cin>>no_customers;
    vector <Customer> cstm(no_customers);
    for(int i=0; i<no_customers; i++)
    {
        system("cls");
        cout<<"Details of Customer "<<i+1<<":\n";
        string c = "n";
        while(c=="n")
        {
            cstm[i].init();
            cstm[i].print();
            cout<<"Are the above details correct (y/n): ";
            cin>>c;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            while(c!="y" && c!="n")
            {
                cout<<"Incorrect Input\nEnter Again: ";
                cin>>c;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout<<"\n";
            if(c=="y")
            {
                if(cstm_index.find(cstm[i].get_id()) != cstm_index.end())
                {
                    cout<<"User Id already taken\n";
                    cout<<"Please Enter another User ID\n\n";
                    c="n";
                }
            }
        }
        cstm_index[cstm[i].get_id()] = i;
    }

    system("cls");

    int no_movies;
    cout<<"Enter the maximum number of Movies: ";
    cin>>no_movies;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector <Movie> mov(no_movies);
    vector <bool> time;
    time.assign(1440, false);

    system("cls");

    while(true)
    {
        cout<<"1. Login as Manager\n2. Login as Customer\n3. End\n";
        cout<<"Choice: ";
        int login;
        cin>>login;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(login==1)
        {
            cout<<"Enter Password for Manager: ";
            string pass;
            cin>>pass;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(mng.verify_password(pass))
            {
                manager_control(mng, mov, time, cstm, cstm_index);
                system("cls");
            }
            else
            {
                system("cls");
                cout<<"Login Failed\n\n";
            }
            
        }
        else if(login==2)
        {
            cout<<"Enter User Id: ";
            string usr_id;
            cin>>usr_id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(cstm_index.find(usr_id)==cstm_index.end())
            {
                system("cls");
                cout<<"User ID does not exist\n\n";
            }
            else
            {
                int index = cstm_index[usr_id];
                cout<<"Enter Password: ";
                string pass;
                cin>>pass;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if(cstm[index].verify_password(pass))
                {
                    customer_control(cstm[index], mov, time, mng);
                    system("cls");
                }
                else
                {
                    system("cls");
                    cout<<"Login Failed";
                }
            }
        }
        else if(login==3)
        {
            break;
        }
        else
        {
            system("cls");
            cout<<"Invalid Choice\n\n";
        }
    }
    return 0;
}