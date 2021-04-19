#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <math.h>    // To use cos,sin,acos,asin,pow and sqrt function
#include <fstream>   // To write and read file,
#include <windows.h> // To use Sleep and system command
#include <conio.h>
#include <ctime> // Time

using namespace std;

int a, id;
int *b = &a;
int TN;
char nama[100], HA[2000], confirm;
string email, line, lastn, ha, name, lastname;

struct bus
{
    string bus,
        driver,
        to,
        //from,
        nobas;

    char from[100];

    int noseat[40],
        idbus;

} Sini[5], Laju[5], Pantas[5], dari, pergi;

struct time
{
    string tarikh;

    float depart;
} masa, sampai[5];

struct customer
{
    string name;
    string mycard;
    string bascomp;
    string fon;
    struct customer *next;

} * cus;

struct seatinfo
{

    int chair;
    char avail;
    int selectseat;

} seat[30];

void bt();
void tnc();
void loc();
void info();
void loab();
void save();
void admin();
void fmasa();
void avaib();
void Search();
void listbus();
void listbus2();
void adminmod();
void readfile();
void showregbas();
void readfiletnc();

void getseatinfo(seatinfo seat[]);
void displayseat(seatinfo seat[]);
void type_text(const string text);
void Enter_Direct(string, string, string, string);
void savefile(seatinfo seat[], int, string, string, string, string);
void printinvoice(seatinfo seat[], int, string, string, string, string);

void getselectseat(seatinfo[], int);
int compare(const void *, const void *);

int main()
{
    for (;;)
    {
        time_t now = time(0);   // current date/time based on current system
        char *dt = ctime(&now); // convert now to string form

        cout << "The local date and time is: " << dt << endl;
        cout << endl;
        cout << "\t *****************************************************************" << endl;
        cout << "\t *                                                               *" << endl;
        cout << "\t *                         BUS TICKETING SYSTEM!                 *" << endl;
        cout << "\t *                                                               *" << endl;
        cout << "\t *                  Please pick your selection:                  *" << endl;
        cout << "\t *               1. LIST OF AVAILABLE BUS                        *" << endl;
        cout << "\t *               2. BOOK TICKET                                  *" << endl;
        cout << "\t *               3. ADMIN ONLY                                   *" << endl;
        cout << "\t *               4. EXIT SYSTEM                                  *" << endl;
        cout << "\t *                                                               *" << endl;
        cout << "\t *****************************************************************" << endl;
        cout << "Your selection is: ";

        cin >> *b;

        switch (a)
        {
        case 1:
            loab();
            break;
        case 2:
            bt();
            break;
        case 3:
            admin();
            break;
        case 4:
            type_text("Program end");
            cout << endl;
            return 0;
        defaut:
            cout << "Invalid" << endl;
            break;
        }

        system("PAUSE");
        system("CLS");
    }

    //return 0;
}

void info()
{
    //1
    Sini[0].bus = "Bus Sini";
    Sini[0].driver = "Ahmad";
    Sini[0].nobas = "SIN 123";
    Sini[0].idbus = 249;

    Laju[0].bus = "Bus Laju";
    Laju[0].driver = "Labu";
    Laju[0].nobas = "LAJ 123";
    Laju[0].idbus = 1070;

    Pantas[0].bus = "Bas Pantas";
    Pantas[0].driver = "Sibu";
    Pantas[0].nobas = "PAN 123";
    Pantas[0].idbus = 1108;

    //2
    Sini[1].bus = "Bus Sini";
    Sini[1].driver = "Lah";
    Sini[1].nobas = "SIN 101";
    Sini[1].idbus = 349;

    Laju[1].bus = "Bus Laju";
    Laju[1].driver = "Lisa";
    Laju[1].nobas = "LAJ 101";
    Laju[1].idbus = 1089;

    Pantas[1].bus = "Bas Pantas";
    Pantas[1].driver = "Yein";
    Pantas[1].nobas = "PAN 101";
    Pantas[1].idbus = 1155;

    //3
    Sini[2].bus = "Bus Sini";
    Sini[2].driver = "Afiq";
    Sini[2].nobas = "SIN 205";
    Sini[2].idbus = 199;

    Laju[2].bus = "Bus Laju";
    Laju[2].driver = "Grey";
    Laju[2].nobas = "LAJ 222";
    Laju[2].idbus = 1075;

    Pantas[2].bus = "Bas Pantas";
    Pantas[2].driver = "Yetty";
    Pantas[2].nobas = "PAN 456";
    Pantas[2].idbus = 1123;

    //4
    Sini[3].bus = "Bus Sini";
    Sini[3].driver = "Ted";
    Sini[3].nobas = "SIN 665";
    Sini[3].idbus = 897;

    Laju[3].bus = "Bus Laju";
    Laju[3].driver = "Lan";
    Laju[3].nobas = "LAJ 664";
    Laju[3].idbus = 1045;

    Pantas[3].bus = "Bas Pantas";
    Pantas[3].driver = "Bad";
    Pantas[3].nobas = "PAN 478";
    Pantas[3].idbus = 1134;

    //5
    Sini[4].bus = "Bus Sini";
    Sini[4].driver = "Aiman";
    Sini[4].nobas = "SIN 546";
    Sini[4].idbus = 154;

    Laju[4].bus = "Bus Laju";
    Laju[4].driver = "Acap";
    Laju[4].nobas = "LAJ 453";
    Laju[4].idbus = 1078;

    Pantas[4].bus = "Bas Pantas";
    Pantas[4].driver = "Stella";
    Pantas[4].nobas = "PAN 155";
    Pantas[4].idbus = 1137;
}

void loab()
{
    info();

    switch (a)
    {
    case 1:
        listbus();
        break;
    case 2:
        listbus2();
        break;
    defaut:
        cout << "Invalid" << endl;
        break;
    }
}

void listbus()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Company: " << Sini[i].bus << endl;
        cout << "Bus No: " << Sini[i].idbus << endl;
        cout << "Bus Driver: " << Sini[i].driver << endl;
        cout << endl;
        cout << "Company: " << Laju[i].bus << endl;
        cout << "Bus No: " << Laju[i].idbus << endl;
        cout << "Bus Driver: " << Laju[i].driver << endl;
        cout << endl;
        cout << "Company: " << Pantas[i].bus << endl;
        cout << "Bus No: " << Pantas[i].idbus << endl;
        cout << "Bus Driver: " << Pantas[i].driver << endl;
        cout << endl;
    }
}

void fmasa()
{
    sampai[0].depart = 09.30;
    sampai[1].depart = 10.45;
    sampai[2].depart = 12.15;
    sampai[3].depart = 20.30;
    sampai[4].depart = 21.45;
}

void listbus2()
{
    fmasa();
    cout << setprecision(2) << fixed;

    cout << "\t======================================================================================================" << endl;
    cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
    cout << "\t======================================================================================================" << endl;
    cout << "\t||" << Sini[0].bus;
    cout << "\t||" << Sini[0].idbus << "\t";
    cout << "\t||" << Sini[0].driver << "\t";
    cout << "\t||" << dari.from << "\t";
    cout << "\t||" << pergi.to << "\t";
    cout << "\t||" << sampai[0].depart << "\t\t    ||";
    cout << endl;
    cout << "\t||" << Sini[1].bus;
    cout << "\t||" << Sini[1].idbus << "\t";
    cout << "\t||" << Sini[1].driver << "\t";
    cout << "\t||" << dari.from << "\t";
    cout << "\t||" << pergi.to << "\t";
    cout << "\t||" << sampai[1].depart << "\t\t    ||";
    cout << endl;
    cout << "\t||" << Sini[2].bus;
    cout << "\t||" << Sini[2].idbus << "\t";
    cout << "\t||" << Sini[2].driver << "\t";
    cout << "\t||" << dari.from << "\t";
    cout << "\t||" << pergi.to << "\t";
    cout << "\t||" << sampai[2].depart << "\t\t    ||";
    cout << endl;
    cout << "\t||" << Sini[3].bus;
    cout << "\t||" << Sini[3].idbus << "\t";
    cout << "\t||" << Sini[3].driver << "\t";
    cout << "\t||" << dari.from << "\t";
    cout << "\t||" << pergi.to << "\t";
    cout << "\t||" << sampai[3].depart << "\t\t    ||";
    cout << endl;
    cout << "\t||" << Sini[4].bus;
    cout << "\t||" << Sini[4].idbus << "\t";
    cout << "\t||" << Sini[4].driver << "\t";
    cout << "\t||" << dari.from << "\t";
    cout << "\t||" << pergi.to << "\t";
    cout << "\t||" << sampai[4].depart << "\t\t    ||";
    cout << endl;
    cout << "\t||" << Laju[0].bus;
    cout << "\t||" << Laju[0].idbus << "\t";
    cout << "\t||" << Laju[0].driver << "\t";
    cout << "\t||" << dari.from << "\t";
    cout << "\t||" << pergi.to << "\t";
    cout << "\t||" << sampai[0].depart << "\t\t    ||";
    cout << endl;
    cout << "\t||" << Laju[1].bus;
    cout << "\t||" << Laju[1].idbus << "\t";
    cout << "\t||" << Laju[1].driver << "\t";
    cout << "\t||" << dari.from << "\t";
    cout << "\t||" << pergi.to << "\t";
    cout << "\t||" << sampai[1].depart << "\t\t    ||";
    cout << endl;
    cout << "\t||" << Laju[2].bus;
    cout << "\t||" << Laju[2].idbus << "\t";
    cout << "\t||" << Laju[2].driver << "\t";
    cout << "\t||" << dari.from << "\t";
    cout << "\t||" << pergi.to << "\t";
    cout << "\t||" << sampai[2].depart << "\t\t    ||";
    cout << endl;
    cout << "\t||" << Laju[3].bus;
    cout << "\t||" << Laju[3].idbus << "\t";
    cout << "\t||" << Laju[3].driver << "\t";
    cout << "\t||" << dari.from << "\t";
    cout << "\t||" << pergi.to << "\t";
    cout << "\t||" << sampai[3].depart << "\t\t    ||";
    cout << endl;
    cout << "\t||" << Laju[4].bus;
    cout << "\t||" << Laju[4].idbus << "\t";
    cout << "\t||" << Laju[4].driver << "\t";
    cout << "\t||" << dari.from << "\t";
    cout << "\t||" << pergi.to << "\t";
    cout << "\t||" << sampai[4].depart << "\t\t    ||";
    cout << endl;
    cout << "\t||" << Pantas[0].bus;
    cout << "\t||" << Pantas[0].idbus << "\t";
    cout << "\t||" << Pantas[0].driver << "\t";
    cout << "\t||" << dari.from << "\t";
    cout << "\t||" << pergi.to << "\t";
    cout << "\t||" << sampai[0].depart << "\t\t    ||";
    cout << endl;
    cout << "\t||" << Pantas[1].bus;
    cout << "\t||" << Pantas[1].idbus << "\t";
    cout << "\t||" << Pantas[1].driver << "\t";
    cout << "\t||" << dari.from << "\t";
    cout << "\t||" << pergi.to << "\t";
    cout << "\t||" << sampai[1].depart << "\t\t    ||";
    cout << endl;
    cout << "\t||" << Pantas[2].bus;
    cout << "\t||" << Pantas[2].idbus << "\t";
    cout << "\t||" << Pantas[2].driver << "\t";
    cout << "\t||" << dari.from << "\t";
    cout << "\t||" << pergi.to << "\t";
    cout << "\t||" << sampai[2].depart << "\t\t    ||";
    cout << endl;
    cout << "\t||" << Pantas[3].bus;
    cout << "\t||" << Pantas[3].idbus << "\t";
    cout << "\t||" << Pantas[3].driver << "\t";
    cout << "\t||" << dari.from << "\t";
    cout << "\t||" << pergi.to << "\t";
    cout << "\t||" << sampai[3].depart << "\t\t    ||";
    cout << endl;
    cout << "\t||" << Pantas[4].bus;
    cout << "\t||" << Pantas[4].idbus << "\t";
    cout << "\t||" << Pantas[4].driver;
    cout << "\t||" << dari.from << "\t";
    cout << "\t||" << pergi.to << "\t";
    cout << "\t||" << sampai[4].depart << "\t\t    ||";
    cout << endl;
    cout << "\t======================================================================================================" << endl;
}

void bt()
{
    int org;
    string kerusi[50];

    cout << "Date to depart: ";
    cin >> masa.tarikh;
    cout << "From: ";
    cin.ignore();
    cin.getline(dari.from, 100);
    cout << "To: ";
    cin >> pergi.to;
    cout << endl;
    loab();
    cout << endl;

b:
    cout << "Input your selection bas id: ";
    cin >> id;

    if (id == 249)
    {
        cout << "\t======================================================================================================" << endl;
        cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\t||" << Sini[0].bus;
        cout << "\t||" << Sini[0].idbus << "\t";
        cout << "\t||" << Sini[0].driver << "\t";
        cout << "\t||" << dari.from << "\t";
        cout << "\t||" << pergi.to << "\t";
        cout << "\t||" << sampai[0].depart << "\t\t    ||";
        cout << endl;
        cout << "\t======================================================================================================" << endl;
        goto c;
    }

    else if (id == 349)
    {
        cout << "\t======================================================================================================" << endl;
        cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\t||" << Sini[1].bus;
        cout << "\t||" << Sini[1].idbus << "\t";
        cout << "\t||" << Sini[1].driver << "\t";
        cout << "\t||" << dari.from << "\t";
        cout << "\t||" << pergi.to << "\t";
        cout << "\t||" << sampai[1].depart << "\t\t    ||";
        cout << endl;
        cout << "\t======================================================================================================" << endl;
        goto c;
    }

    else if (id == 199)
    {
        cout << "\t======================================================================================================" << endl;
        cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\t||" << Sini[2].bus;
        cout << "\t||" << Sini[2].idbus << "\t";
        cout << "\t||" << Sini[2].driver << "\t";
        cout << "\t||" << dari.from << "\t";
        cout << "\t||" << pergi.to << "\t";
        cout << "\t||" << sampai[2].depart << "\t\t    ||";
        cout << endl;
        cout << "\t======================================================================================================" << endl;
        goto c;
    }

    else if (id == 897)
    {
        cout << "\t======================================================================================================" << endl;
        cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\t||" << Sini[3].bus;
        cout << "\t||" << Sini[3].idbus << "\t";
        cout << "\t||" << Sini[3].driver << "\t";
        cout << "\t||" << dari.from << "\t";
        cout << "\t||" << pergi.to << "\t";
        cout << "\t||" << sampai[3].depart << "\t\t    ||";
        cout << endl;
        cout << "\t======================================================================================================" << endl;
        goto c;
    }

    else if (id == 154)
    {
        cout << "\t======================================================================================================" << endl;
        cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\t||" << Sini[4].bus;
        cout << "\t||" << Sini[4].idbus << "\t";
        cout << "\t||" << Sini[4].driver << "\t";
        cout << "\t||" << dari.from << "\t";
        cout << "\t||" << pergi.to << "\t";
        cout << "\t||" << sampai[4].depart << "\t\t    ||";
        cout << endl;
        cout << "\t======================================================================================================" << endl;
        goto c;
    }

    else if (id == 1070)
    {
        cout << "\t======================================================================================================" << endl;
        cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\t||" << Laju[0].bus;
        cout << "\t||" << Laju[0].idbus << "\t";
        cout << "\t||" << Laju[0].driver << "\t";
        cout << "\t||" << dari.from << "\t";
        cout << "\t||" << pergi.to << "\t";
        cout << "\t||" << sampai[0].depart << "\t\t    ||";
        cout << endl;
        cout << "\t======================================================================================================" << endl;
        goto c;
    }

    else if (id == 1089)
    {
        cout << "\t======================================================================================================" << endl;
        cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\t||" << Laju[1].bus;
        cout << "\t||" << Laju[1].idbus << "\t";
        cout << "\t||" << Laju[1].driver << "\t";
        cout << "\t||" << dari.from << "\t";
        cout << "\t||" << pergi.to << "\t";
        cout << "\t||" << sampai[1].depart << "\t\t    ||";
        cout << endl;
        cout << "\t======================================================================================================" << endl;
        goto c;
    }

    else if (id == 1075)
    {
        cout << "\t======================================================================================================" << endl;
        cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\t||" << Laju[2].bus;
        cout << "\t||" << Laju[2].idbus << "\t";
        cout << "\t||" << Laju[2].driver << "\t";
        cout << "\t||" << dari.from << "\t";
        cout << "\t||" << pergi.to << "\t";
        cout << "\t||" << sampai[2].depart << "\t\t    ||";
        cout << endl;
        cout << "\t======================================================================================================" << endl;
        goto c;
    }

    else if (id == 1045)
    {
        cout << "\t======================================================================================================" << endl;
        cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\t||" << Laju[3].bus;
        cout << "\t||" << Laju[3].idbus << "\t";
        cout << "\t||" << Laju[3].driver << "\t";
        cout << "\t||" << dari.from << "\t";
        cout << "\t||" << pergi.to << "\t";
        cout << "\t||" << sampai[3].depart << "\t\t    ||";
        cout << endl;
        cout << "\t======================================================================================================" << endl;
        goto c;
    }

    else if (id == 1078)
    {
        cout << "\t======================================================================================================" << endl;
        cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\t||" << Laju[4].bus;
        cout << "\t||" << Laju[4].idbus << "\t";
        cout << "\t||" << Laju[4].driver << "\t";
        cout << "\t||" << dari.from << "\t";
        cout << "\t||" << pergi.to << "\t";
        cout << "\t||" << sampai[4].depart << "\t\t    ||";
        cout << endl;
        cout << "\t======================================================================================================" << endl;
        goto c;
    }

    else if (id == 1108)
    {
        cout << "\t======================================================================================================" << endl;
        cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\t||" << Pantas[0].bus;
        cout << "\t||" << Pantas[0].idbus << "\t";
        cout << "\t||" << Pantas[0].driver << "\t";
        cout << "\t||" << dari.from << "\t";
        cout << "\t||" << pergi.to << "\t";
        cout << "\t||" << sampai[0].depart << "\t\t    ||";
        cout << endl;
        cout << "\t======================================================================================================" << endl;
        goto c;
    }

    else if (id == 1155)
    {
        cout << "\t======================================================================================================" << endl;
        cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\t||" << Pantas[1].bus;
        cout << "\t||" << Pantas[1].idbus << "\t";
        cout << "\t||" << Pantas[1].driver << "\t";
        cout << "\t||" << dari.from << "\t";
        cout << "\t||" << pergi.to << "\t";
        cout << "\t||" << sampai[1].depart << "\t\t    ||";
        cout << endl;
        cout << "\t======================================================================================================" << endl;
        goto c;
    }

    else if (id == 1123)
    {
        cout << "\t======================================================================================================" << endl;
        cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\t||" << Pantas[2].bus;
        cout << "\t||" << Pantas[2].idbus << "\t";
        cout << "\t||" << Pantas[2].driver << "\t";
        cout << "\t||" << dari.from << "\t";
        cout << "\t||" << pergi.to << "\t";
        cout << "\t||" << sampai[2].depart << "\t\t    ||";
        cout << endl;
        cout << "\t======================================================================================================" << endl;
        goto c;
    }

    else if (id == 1134)
    {
        cout << "\t======================================================================================================" << endl;
        cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\t||" << Pantas[3].bus;
        cout << "\t||" << Pantas[3].idbus << "\t";
        cout << "\t||" << Pantas[3].driver << "\t";
        cout << "\t||" << dari.from << "\t";
        cout << "\t||" << pergi.to << "\t";
        cout << "\t||" << sampai[3].depart << "\t\t    ||";
        cout << endl;
        cout << "\t======================================================================================================" << endl;
        goto c;
    }

    else if (id == 1137)
    {
        cout << "\t======================================================================================================" << endl;
        cout << "\t||Company\t||Bus Id\t||Bus Driver\t||Depart from\t||Arrive at\t||Time to depart\t||" << endl;
        cout << "\t======================================================================================================" << endl;
        cout << "\t||" << Pantas[4].bus;
        cout << "\t||" << Pantas[4].idbus << "\t";
        cout << "\t||" << Pantas[4].driver << "\t";
        cout << "\t||" << dari.from << "\t";
        cout << "\t||" << pergi.to << "\t";
        cout << "\t||" << sampai[4].depart << "\t\t    ||";
        cout << endl;
        cout << "\t======================================================================================================" << endl;
        goto c;
    }
    else
    {
        cout << "Invalid" << endl;
        goto b;
    }

c:
    tnc();
}

void getselectseat(seatinfo seat[], int seatamount)
{
    cout << "\nTotal seat: " << seatamount;
    cout << "\nSeat number: ";

    for (int i = 0; i < seatamount; i++)
    {
        cout << "B" << seat[i].selectseat << " ";
    }
    cout << endl;
}

void displayseat(seatinfo seat[])
{
    int x = 1;
    for (int j = 1; j < 11; j++)
    {
        for (int i = 1; i < 4; i++)
        {
            if (x < 10)
            {
                cout << "B" << seat[x++].chair << " [" << seat[1].avail << "]\t"; // 1 digit row
            }
            else
                cout << "B" << seat[x++].chair << "[" << seat[1].avail << "]\t"; // display for 2digit row
        }
        cout << endl;
    }
}

void getseatinfo(seatinfo seat[])
{

    for (int i = 1; i < 31; i++)
    {
        seat[i].chair = i + 0; // all seat counter
    }

    seat[1].avail = '0'; //shows 0 on seat display
    seat[2].avail = 'X'; //show X on seat display
}

void avaib()
{

    //variable declare
    int seatamount, selectseat;
    string line;
    string name;
    string mycard;
    string email;
    string fon;

    cout << "Seat available:\n\n";
    getseatinfo(seat); // get info for bus
    displayseat(seat); // display bus seat;

totalbookseat:
    cout << "\nTotal seats you need to book:\n";
    cin >> seatamount;

    if (seatamount > 30)
    {
        cout << "Amount of seats booked too large, try again.\n";
        goto totalbookseat;
    }

chooseseat:
    if (seatamount > 1)
    {
        cout << "Please select your seats in term of number:\n";
    }
    else
        cout << "Please select your seat in term of number:\n";

    for (int i = 0; i < seatamount; i++)
    {
        cin >> seat[i].selectseat;
    }

    for (int k = 0; k < seatamount; k++)
    {
        if (seat[k].selectseat > 30)
        {
            cout << "Seat B" << seat[k].selectseat << " does not exist. Try again.\n\n";
            goto chooseseat;
        }
    }

    for (int j = 0; j < seatamount; j++)
    {
        if (seat[j + 1].selectseat == seat[j].selectseat || seat[j + 1].selectseat == seat[j].selectseat)
        {
            cout << "Seat B" << seat[j].selectseat << " have been choose twice! Choose again.\n"
                 << endl;
            goto chooseseat;
        }

        if (seat[j].selectseat == seat[j + 2].selectseat || seat[j].selectseat == seat[j + 2].selectseat)
        {
            cout << "Seat B" << seat[j].selectseat << " have been choose twice! Choose again.\n"
                 << endl;
            goto chooseseat;
        }
    }
    system("pause");
    system("cls");

again:
    cout << "################ Information ##################\n\n";
    cout << "Please enter your personal detail:\n";
    cout << "\nFirst Name: ";
    cin >> name;
    cout << "\nLast Name: ";
    cin >> lastname;
    cout << "\nI/C: ";
    cin >> mycard;
    cout << "\nPhone: ";
    cin >> fon;
    cout << endl;
    cout << "###############################################\n\n";

    if (cus == 0)
    {
        cus = new (struct customer);

        cus->name = name;
        cus->mycard = mycard;
        cus->fon = fon;
        cus->next = NULL;
    }

    else
    {
        struct customer *nw = new (struct customer);
        struct customer *temp = cus;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        nw->name = name;
        nw->mycard = mycard;
        nw->fon = fon;
        temp->next = nw;
        nw->next = NULL;
    }

    //function call for print out invoice receipt on txt file
    save();
    printinvoice(seat, seatamount, name, lastname, mycard, fon);
    savefile(seat, seatamount, name, lastname, mycard, fon);

microagain:
    cout << "\nAll information correct?(y/n)\n\a";
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y')
    {
        goto next;
    }

    if (confirm == 'n' || confirm == 'N')
    {
        system("cls");
        goto again;
    }

    if (confirm != 'n' || confirm != 'N' || confirm != 'y' || confirm != 'Y')
    {
        cout << "Wrong input! Enter again.\n";
        goto microagain;
    }

next:
    //function call for display selected seat
    getselectseat(seat, seatamount);

    return;
}

/***********************************************************
* ADMIN SECTION                                             *
*************************************************************/

void admin()
{
    string username;
    string password;

    for (; password != "0296";)
    {
        cout << "Username: ";
        cin >> username;
        if (username == "Admin")
        {
            cout << "Password: ";
            cin >> password;
            if (password == "0296")
            {
                type_text("Admin Mod");
                cout << endl;
                system("PAUSE");
                system("CLS");
                adminmod();
            }
            else
            {
                type_text("Wrong Username or Password");
                cout << endl;
            }
        }
        else
        {
            cout << "Password: ";
            cin >> password;
            type_text("Wrong Username or Password");
            cout << endl;
        }
    }
}

void adminmod()
{
    for (;;)
    {
        cout << endl;
        cout << "\t *****************************************************************" << endl;
        cout << "\t *                                                               *" << endl;
        cout << "\t *                           ADMIN MOD                           *" << endl;
        cout << "\t *                                                               *" << endl;
        cout << "\t *                  Please pick your selection:                  *" << endl;
        cout << "\t *               1. SHOW LIST OF CUSTOMERS                       *" << endl;
        cout << "\t *               2. Search (All database)                        *" << endl;
        cout << "\t *               3. EXIT ADMIN MOD                               *" << endl;
        cout << "\t *               4. EXIT SYSTEM                                  *" << endl;
        cout << "\t *                                                               *" << endl;
        cout << "\t *****************************************************************" << endl;
        cout << "Your selection is: ";

        cin >> *b;

        switch (a)
        {
        case 1:
            loc();
            break;
        case 2:
            Search();
        case 3:
            system("CLS");
            return; //Return to the main();
            break;
        case 4:
            type_text("Program end");
            cout << endl;
            exit(EXIT_FAILURE); //Force exit the program
        defaut:
            cout << "Invalid" << endl;
            break;
        }

        system("PAUSE");
        system("CLS");
    }
}

void tnc()
{
    string TNC;

    cout << "Have you read the Term and Condition? (Y/N)";
    cin >> TNC;

    if (TNC == "N" || TNC == "n")
    {
        cout << "Do you want to read it? (Y/N)";
        cin >> TNC;
        if (TNC == "Y" || TNC == "y")
        {
            readfiletnc();
            system("PAUSE");
            system("CLS");

            cout << "Do agree to our Term and Condition? (Y/N)";
            cin >> TNC;
            if (TNC == "Y" || TNC == "y")
            {
                avaib();
            }

            else
            {
                exit(EXIT_FAILURE);
                cout << endl;
            }
        }

        else
        {
            exit(EXIT_FAILURE);
            cout << endl;
        }
    }

    else
    {
        cout << "Do agree to our Term and Condition? (Y/N)";
        cin >> TNC;

        if (TNC == "Y" || TNC == "y")
        {
            avaib();
        }

        else
        {
            exit(EXIT_FAILURE);
            cout << endl;
        }
    }
}

void savefile(seatinfo seat[], int seatamount, string nameprint, string lastnameprint, string icprint, string phoneprint)
{
    for (int i = 0; i < 5; i++)
    {
        if (id == Sini[i].idbus)
        {
            ofstream write("SINI.txt", ios::app);
            write << "********************Terminal Bas Bersepadu********************\n\n";
            write << "************************CUSTOMER DATABASE*********************\n\n";
            write << "Name: " << nameprint << " " << lastnameprint << endl;
            write << "I/C: " << icprint << endl;
            write << "Phone: 0" << phoneprint << endl;
            write << "Total seat: " << seatamount << endl;
            write << "Seat number: ";

            for (int i = 0; i < seatamount; i++)
            {
                write << "B" << seat[i].selectseat << " ";
            }

            write << endl;
            write << endl;
            write << "      This database generated by computer. No signature needed." << endl;
            write << "**************************************************************\n\n";
        }

        else if (id == Laju[i].idbus)
        {
            ofstream write("LAJU.txt", ios::app);
            write << "********************Terminal Bas Bersepadu********************\n\n";
            write << "************************CUSTOMER DATABASE*********************\n\n";
            write << "Name: " << nameprint << " " << lastnameprint << endl;
            write << "I/C: " << icprint << endl;
            write << "Phone: 0" << phoneprint << endl;
            write << "Total seat: " << seatamount << endl;
            write << "Seat number: ";

            for (int i = 0; i < seatamount; i++)
            {
                write << "B" << seat[i].selectseat << " ";
            }

            write << endl;
            write << endl;
            write << "      This database generated by computer. No signature needed." << endl;
            write << "**************************************************************\n\n";
        }

        else if (id == Pantas[i].idbus)
        {
            ofstream write("PANTAS.txt", ios::app);
            write << "********************Terminal Bas Bersepadu********************\n\n";
            write << "************************CUSTOMER DATABASE*********************\n\n";
            write << "Name: " << nameprint << " " << lastnameprint << endl;
            write << "I/C: " << icprint << endl;
            write << "Phone: 0" << phoneprint << endl;
            write << "Total seat: " << seatamount << endl;
            write << "Seat number: ";

            for (int i = 0; i < seatamount; i++)
            {
                write << "B" << seat[i].selectseat << " ";
            }

            write << endl;
            write << endl;
            write << "      This database generated by computer. No signature needed." << endl;
            write << "**************************************************************\n\n";
        }
    }
}

void readfile()
{

    switch (a)
    {
    case 1:
    {
        ifstream myfiletnc("SINI.txt");
        if (myfiletnc.is_open())
        {
            while (getline(myfiletnc, line))
            {
                cout << line << '\n';
            }
            myfiletnc.close();
        }
        break;
    }

    case 2:
    {
        ifstream myfiletnc("LAJU.txt");
        if (myfiletnc.is_open())
        {
            while (getline(myfiletnc, line))
            {
                cout << line << '\n';
            }
            myfiletnc.close();
        }
        break;
    }

    case 3:
    {
        ifstream myfiletnc("PANTAS.txt");
        if (myfiletnc.is_open())
        {
            while (getline(myfiletnc, line))
            {
                cout << line << '\n';
            }
            myfiletnc.close();
        }
        break;
    }

    defaut:
        cout << "Invalid" << endl;
        break;
    }
}

void readfiletnc()
{
    ifstream myfiletnc("TNC.txt");
    if (myfiletnc.is_open())
    {
        while (getline(myfiletnc, line))
        {
            cout << line << '\n';
        }
        myfiletnc.close();
    }
}

void loc()
{
    system("CLS");
    for (;;)
    {
        cout << endl;
        cout << "\t *****************************************************************" << endl;
        cout << "\t *                                                               *" << endl;
        cout << "\t *                       Customer Database                       *" << endl;
        cout << "\t *                                                               *" << endl;
        cout << "\t *                  Please pick your company:                    *" << endl;
        cout << "\t *               1. Sini Bus                                     *" << endl;
        cout << "\t *               2. Laju Bus                                     *" << endl;
        cout << "\t *               3. Pantas Bus                                   *" << endl;
        cout << "\t *               4. EXIT SYSTEM                                  *" << endl;
        cout << "\t *                                                               *" << endl;
        cout << "\t *****************************************************************" << endl;
        cout << "Your selection is: ";

        cin >> *b;

        switch (a)
        {
        case 1:
            readfile();
            break;
        case 2:
            readfile();
            break;
        case 3:
            readfile();
            break;
        case 4:
            system("CLS");
            return; //Return to the main();
            break;
        case 5:
            type_text("Program end");
            cout << endl;
            exit(EXIT_FAILURE); //Force exit the program
        defaut:
            cout << "Invalid" << endl;
            break;
        }

        system("PAUSE");
        system("CLS");
    }
}

void printinvoice(seatinfo seat[], int seatamount, string nameprint, string lastnameprint, string icprint, string phoneprint)
{

    ofstream write("Ticket1.txt", ios::app);
    write << "********************Terminal Bas Bersepadu********************\n\n";
    write << "************************Ticket Invoice************************\n\n";
    write << "Name: " << nameprint << " " << lastnameprint << endl;
    write << "I/C: " << icprint << endl;
    write << "Phone: 0" << phoneprint << endl;
    write << "Total seat: " << seatamount << endl;
    write << "Seat number: ";

    for (int i = 0; i < seatamount; i++)
    {

        write << "B" << seat[i].selectseat << " ";
    }
    write << endl;
    write << endl;
    write << "      This invoice generated by computer. No signature needed." << endl;
    write << "**************************************************************\n\n";
}

void type_text(const string text) // Output one character
{
    for (size_t i = 0; i < text.size(); ++i) // Loop through each character in the text
    {
        cout << text[i] << flush; // Flush to make sure the output is not delayed
        Sleep(30);                // Sleep 30 milliseconds
    }
}

void Search()
{
    string ic;

    system("cls");

    cout << "\n\n\t\tSEARCH DATA \n\n\t\t";
    cout << "\n\n\t\tEnter IC Number that You wish to search: \n\n\t\t";
    cin >> ic;

    struct customer *temp = cus;
    while (temp)
    {
        if (temp->mycard == ic)
        {
            system("cls");
            cout << "\t\tName                : " << temp->name << endl;
            cout << "\t\tMycard Number       : " << temp->mycard << endl;
            cout << "\t\tPhone Number        : " << temp->fon << endl;

            system("pause");
            system("cls");
            adminmod();
        }

        else
        {
            cout << "\t\tUser Not Found! " << endl;
            system("pause");
            system("cls");
            adminmod();
        }
        temp = temp->next;
    }
}

void Enter_Direct(string a, string b, string d)
{
    if (cus == 0)
    {
        cus = new (struct customer);
        cus->name = a;
        cus->mycard = b;
        cus->fon = d;
        cus->next = NULL;
    }
    else
    {
        struct customer *nw = new (struct customer);
        struct customer *temp = cus;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        nw->name = a;
        nw->mycard = b;
        nw->fon = d;
        temp->next = nw;
        nw->next = NULL;
    }
}

void save() //save data
{
    ofstream data; //output file stream. used to create file and write file
    data.open("database.txt");
    struct customer *temp = cus;
    while (temp)
    {
        data << endl;
        data << temp->name << endl;
        data << temp->mycard << endl;
        data << temp->fon << endl;
        temp = temp->next;
    }
    data.close();
}

void databaseread() // load data from file to linked list
{
    string line, a;
    string b, c, d;
    ifstream data("database.txt"); //input file stream. used to read information from file

    while (getline(data, line))
    {
        if (line != "")
        {
            a = line;
            getline(data, line);
            b = line;
            getline(data, line);
            d = line;
            getline(data, line);
            Enter_Direct(a, b, d); //add direct into linked list
        }
    }
    data.close();
}

int compare(const void *a, const void *b)
{
    const int *x = (int *)a;
    const int *y = (int *)b;

    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;

    return 0;
}
/***********************************************************
* Title  :   Bus Ticketing System                           *
* Authors:   AFIQ HARITH BIN AHAMAD & HAZRIEN BIN NAZMAN    *
* GROUP  :   EE241 C5A                                      *
*                                                           *
*************************************************************/
