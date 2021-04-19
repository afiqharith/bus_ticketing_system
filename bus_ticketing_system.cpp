// bus-ticket-system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <windows.h>

struct Bus
{
    std::string company;
    std::string bus_number;
    std::string depart_time;
    std::string depart_location;
    std::string arrive_location;
};

struct Passenger
{
    std::string name;
    std::string ic;
    std::string phone;
    Bus bus;
};

struct Node
{
    Passenger data;
    Node *next;
};

class App
{
public:
    void add_bus(Bus *bus, const int index, std::string company, std::string bus_number, std::string depart_time, std::string depart_location, std::string arrive_location)
    {
        bus[index].company = company;
        bus[index].bus_number = bus_number;
        bus[index].depart_time = depart_time;
        bus[index].depart_location = depart_location;
        bus[index].arrive_location = arrive_location;
    }
};

void traverse_list(Node *node)
{
    while (node != NULL)
    {
        //print current value
        std::cout << node->data.bus.bus_number << "->";

        //move to next node
        node = node->next;
    }
    std::cout << "NULL" << std::endl;
}

int main()
{
    Bus mekar[3];
    App *app = new App;

    app->add_bus(mekar, 0, "Mekar", "MKN1920", "0900", "Shah Alam", "Johor Bahru");
    app->add_bus(mekar, 1, "Mekar", "MKN1910", "1200", "Shah Alam", "Johor Bahru");
    app->add_bus(mekar, 2, "Mekar", "MKN1900", "1400", "Shah Alam", "Johor Bahru");

    Passenger passenger[31];
    passenger[0].name = "Abu";
    passenger[0].ic = "1234";
    passenger[0].phone = "012345678";
    passenger[0].bus = mekar[0];

    passenger[1].name = "Ahmad";
    passenger[1].ic = "5678";
    passenger[1].phone = "012345678";
    passenger[1].bus = mekar[1];

    Passenger passenger_id3;
    passenger[2].name = "Ali";
    passenger[2].ic = "2468";
    passenger[2].phone = "012345678";
    passenger[2].bus = mekar[2];

    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;

    head->data = passenger[0];
    head->next = second;

    second->data = passenger[1];
    second->next = third;

    third->data = passenger[2];
    third->next = NULL;

    traverse_list(head);

    std::cin.get();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
