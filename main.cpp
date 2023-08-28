// it wont work without the txt.files
#include <iostream>//declares objects that control reading from and writing to the standard streams
#include <conio.h>// it takes input from keyboard and displays it on screen
#include <fstream>//allowing you to read from and write to files
#include <windows.h>//used to access the Win32 API functions and it makes it easier for the user to use the in-built functionality.
#include <string.h>//contains some useful string functions that can be directly used in a program
#include <stdio.h>//contains the information needed to include input/output routines in our program. For instance, printf, scanf
#include <time.h>// contains time and date function declarations to provide standardized access to time/date manipulation and formatting
#include <cstdlib>//defines a collection of functions and macros to facilitate efficient, high-performing, standardized C++ code
#include <vector> //sequence containers representing arrays that can change their size during runtime.
#include <algorithm>//test whether first set is subset of another or not


using namespace std;

void mostrentedcar();
void allreservations();
void customerData();
int carCount();
int custCount();
int rate(int, int);
void newCustData();
void therenterreservations();
void averagerentaltime();
void carData ();
void admin();
void user();
void menu();
void art();
void exitArt();
void rentedcarsperday();
void newCarData();
void delCar();
void displayCar();
void existingCust();
void load();
void load_CHECK();
void gotoxy(int , int );
void time();
void Boarder();
int countUser();
void tNc();
void readUserPass();
void availCar();
int countAvail();
const string currentDateTime(); // we use const to tell the compiler to prevent the programmer from modifying it
const string Date();
void date();
void dispAvailCar();
void GotoXY(int , int );
void load_EXIT();
void load_UPDATE();
void newUserPass();
void password();
void resetAvail();
void showCarData();
void welcome();



struct car
{
	char plate_num[10];
	char brand[20];
	char model[20];
	float capacity;
	char colour[20];
	float rate_per_hour;
	float rate_per_half;
	float rate_per_day;
	char transmission[6];
};

struct customer
{
	int id;
	char name[100];
	char phone[15];
	char ic[15];
	char address[1500];
};
struct Reservation {
    string renterName;
    string reservationDetails;

};

struct pass
{
	int ID;
	char passWord[20];

};

	pass userPass[1000];
	car rent[1000];
	customer cust[1000];
	car avail[1000];


const string currentDateTime() // ensure that a string remains constant and prevent accidental modifications
{
    time_t     now = time(0);//declares a `time_t` variable `now` and assigns it the current time using the `time()` function.
    struct tm  tstruct;// declares a `struct tm` variable `tstruct` to store the time structure.
    char       buf[80];//declares a character array `buf` with a size of 80 to store the formatted date and time string.
    tstruct = *localtime(&now);// assigns the value of `tstruct` by dereferencing the pointer returned by the `localtime()` function, passing in the address of `now`.
    strftime(buf, sizeof(buf), "%d/%m/%Y TIME: %X", &tstruct);//formats the date and time string using the `strftime()` function

    return buf; // acts as a temporary placeholder for the formatted date and time string.
}

const string Date()// ensure that a string remains constant and prevent accidental modifications
{
    time_t     now = time(0);//declares a `time_t` variable `now` and assigns it the current time using the `time()` function.
    struct tm  tstruct;// declares a `struct tm` variable `tstruct` to store the time structure.
    char       buf[80];//declares a character array `buf` with a size of 80 to store the formatted date and time string.
    tstruct = *localtime(&now);// assigns the value of `tstruct` by dereferencing the pointer returned by the `localtime()` function, passing in the address of `now`.
    strftime(buf, sizeof(buf), "%d/%m/%Y TIME: %X", &tstruct);//formats the date and time string using the `strftime()` function

    return buf; //`buf` is the value being returned and allows you to pass the value of a variable back to the calling function
}

void time()
{
	int i=0;//declares an integer variable `i` and initializes it to 0.

    while( i<5)//enters a `while` loop that continues as long as the value of `i` is less than 5.
	{
	Boarder();//function that displays a visual border or header on the console.
	gotoxy(20,20); //use to print the statement at appropriate position on the screen
	cout <<"\n\n\n\n\n\t  |\t\t\t\tDATE: "<<currentDateTime() << endl;
	Sleep(900);
	system("cls");
	i++;
	}
	menu();
}

void date()
{
	cout <<"\n\t  |\t\t\t\t\t\tDATE: "<<Date()<<endl;

}

void readUserPass()
{
	ifstream ifs; //a program that reads data from files and displays it
	ifs.open("UserPass.txt");

	int i;
	while(!ifs.eof())//loop that continues until the end of the file is reached
	{
		ifs>>userPass[i].ID;//reads the `ID` member of the `userPass` structure at index `i` using the `>>` operator.
		ifs.ignore();//It ignores any remaining characters on the current line
		ifs.getline(userPass[i].passWord,20); //allows you to handle input with spaces or multiple words as a single string and used to read a line of text from the input stream and store it in a string variable.
		i++;
	}
	ifs.close(); //used to close an input file stream
}



void gotoxy(int x, int y) //use to print the statement at appropriate position on the screen
{

 COORD coord; //structure to hold screen COORDinates X and Y

 coord.X = x;

 coord.Y = y;

 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //provides a mechanism for retrieving the standard input ( STDIN ), standard output ( STDOUT ), and standard error ( STDERR ) handles associated with a process

}
void GotoXY(int x, int y) //to move the cursor to a specific position on the console screen.
{
    HANDLE a;//Declare a variable `a` of type `HANDLE` and a variable `b` of type `COORD`. The `HANDLE` type is used to interact with the console, and `COORD` is a structure that holds the coordinates of a character cell in the console.
    COORD b;
    fflush(stdout);// Flush the output stream using `fflush(stdout)`. This ensures that any pending output is written to the console before moving the cursor.
    b.X = x;//Set the x and y coordinates of the `b` structure to the values passed as parameters (`b.X = x` and `b.Y = y`).
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);//Get the handle of the standard output console using `GetStdHandle(STD_OUTPUT_HANDLE)` and assign it to the variable `a`. This handle is used to interact with the console.
    SetConsoleCursorPosition(a,b);//Use the `SetConsoleCursorPosition` function to set the cursor position on the console screen. Pass the handle `a` and the `b` structure (containing the desired x and y coordinates) as arguments.
 }

void Boarder()//function that displays a visual border or header on the console.
{
int i;//Declare a variable `i` of type `int` to be used as a loop counter.
   system("cls");//Clear the console screen using the `system("cls")` function. This ensures that the border is drawn on a clean console screen.
   for(i=10;i<140;i++)//Use a for loop to iterate from `i=10` to `i<140`. This loop is responsible for drawing the horizontal lines of the border.
   {
       GotoXY(i,10);// Inside the loop, call the `GotoXY` function to move the cursor to the current `i` position on the top border (y=10). Then, use `cout` to print the "=" character at that position.
           cout<<"=";
       GotoXY(i,58);//Call the `GotoXY` function again to move the cursor to the current `i` position on the bottom border (y=58). Then, use `cout` to print the "=" character at that position.
           cout<<"=";
   }
   for(i=10;i<58;i++)//Use another for loop to iterate from `i=10` to `i<58`. This loop is responsible for drawing the vertical lines of the border.
   {
       GotoXY(10,i);//Inside the loop, call the `GotoXY` function to move the cursor to the left border (x=10) at the current `i` position. Then, use `cout` to print the "|" character at that position.
           cout<<"|";
       GotoXY(140,i);//Call the `GotoXY` function again to move the cursor to the right border (x=140) at the current `i` position. Then, use `cout` to print the "|" character at that position.
       		cout<<"|";
   }
}

void load() //used to make the loading screen slower
{
	Boarder();//function that displays a visual border or header on the console.

	int timer =5+ rand()%20;//ensures that `timer` is assigned a random number between 5 and 24.
    int row,col,r,c,q;
    gotoxy(65,34);
    cout<<"BOOTING UP...";
    gotoxy(60,36);
    for(r=1;r<=timer;r++)// loop will execute a block of code for a number of times specified by the value of `timer`.
	{
    for(q=0;q<=100000000;q++);//to display the character slowly
    printf("%c",177);
	}
    Sleep(100);
    system("cls"); //terminal/command prompt commands used to clear the screen
}

void load_CHECK() //checks that a routine (function or class member) is called during the execution of the surrounding test case
{
	Boarder(); //function that displays a visual border or header on the console.
	int timer = rand()%5+1;//generates a random number between 1 and 5
    int row,col,r,c,q;//These variables are used as counters and coordinates for positioning the loading screen
    gotoxy(65,34);// set the cursor position to row 34 and column 65 on the console
    printf("LOG IN...");
    gotoxy(60,36);// set the cursor position to row 36 and column 60 on the console
    for(r=1;r<=timer;r++)//This loop will execute a block of code for a number of times specified by the value of `timer
	{
    for(q=0;q<=100000000;q++);//introduce a delay between each character displayed on the console
    printf("%c",177);//used here to create a loading effect by displaying a series of blocks on the console.
	}
    Sleep(100);
    system("cls");//clear the console screen. It removes all previous output from the console, creating a clean slate for the next part of the program.
}

void load_UPDATE()
{
	Boarder();//function that displays a visual border or header on the console.

    int row,col,r,c,q;//These variables are used as counters and coordinates for positioning the loading screen
    int timer = rand()%25+1;//get a random number between 1 and 25
    gotoxy(65,34);// set the cursor position to row 34 and column 65 on the console
    printf("UPDATING DATABASE...");
    gotoxy(60,36);// set the cursor position to row 36 and column 60 on the console
    for(r=1;r<=timer;r++)//This loop will execute a block of code for a number of times specified by the value of `timer
	{
    for(q=0;q<=100000000;q++);//introduce a delay between each character displayed on the console
    printf("%c",177);//used here to create a loading effect by displaying a series of blocks on the console.
	}
    Sleep(100);
    system("cls");//clear the console screen. It removes all previous output from the console, creating a clean slate for the next part of the program.
}

void load_EXIT()
{
	Boarder();//function that displays a visual border or header on the console.

    int row,col,r,c,q;//These variables are used as counters and coordinates for positioning the loading screen
    int timer = rand()%5+1;//get a random number between 1 and 5
    GotoXY(65,34);// set the cursor position to row 34 and column 65 on the console
    printf("LOGGING OFF...");
    gotoxy(60,36);// set the cursor position to row 36 and column 60 on the console
    for(r=1;r<=timer;r++)//This loop will execute a block of code for a number of times specified by the value of `timer
	{
    for(q=0;q<=100000000;q++);//introduce a delay between each character displayed on the console
    printf("%c",177);//used here to create a loading effect by displaying a series of blocks on the console.
	}
    Sleep(100);
    system("cls");//clear the console screen. It removes all previous output from the console, creating a clean slate for the next part of the program.
}




void art() // the art displayed in the begining and the ending of the output
{

	Boarder();//function that displays a visual border or header on the console.
	gotoxy(0, 20);

	ifstream ifs ("art.txt");
	string Lines = "";//This line initializes an empty string variable named `Lines` which will store the lines of the welcome message.

    if (ifs)// checks if the file was successfully opened
    {
		while (ifs.good ()) //true if the stream is good, else false
		{
	    	string TempLine;
	    	getline (ifs , TempLine); // stores it in a temporary string variable named `TempLine`.
	    	TempLine += "\n";//ensures that each line of the welcome message is displayed on a new line.

	    	Lines += TempLine;//appends the current line to the `Lines` string, effectively building the complete welcome message.
		}

	cout << Lines;// This line displays the welcome message stored in the `Lines` string on the console.
	date();
	}

    ifs.close ();
}

void welcome()
{

	Boarder();//function that displays a visual border or header on the console.
	gotoxy(0, 30);
	ifstream ifs ("welcome.txt");
	string Lines = "";//This line initializes an empty string variable named `Lines` which will store the lines of the welcome message.

    if (ifs)// checks if the file was successfully opened
    {
		while (ifs.good ())//This loop runs as long as there are no errors and the file is in a good state. It reads each line of the file
		{
	    	string TempLine;

	    	getline (ifs , TempLine);// stores it in a temporary string variable named `TempLine`.
	    	TempLine += "\n";//ensures that each line of the welcome message is displayed on a new line.
	    	Lines += TempLine;//appends the current line to the `Lines` string, effectively building the complete welcome message.
		}

	cout << Lines;// This line displays the welcome message stored in the `Lines` string on the console.


	}
	cout<<"\n\t  |\t\t\t\t\t\t\t";
	ifs.close ();
	Sleep(1000);

}


void exitArt() // the art that will be displayed in the exit of the output
{
	Boarder();//function that displays a visual border or header on the console.
	gotoxy(0, 30);
	ifstream ifs ("exit art.txt");
	string Lines = " ";//This line initializes an empty string variable named `Lines` which will store the lines of the welcome message.

    if (ifs)//checks if the file was successfully opened
    {
		while (ifs.good ())//This loop runs as long as there are no errors and the file is in a good state. It reads each line of the file
		{
	    	string TempLine;
	    	getline (ifs , TempLine);// stores it in a temporary string variable named `TempLine`.
	    	TempLine += "\n";//ensures that each line of the welcome message is displayed on a new line.

	    	Lines += TempLine;//appends the current line to the `Lines` string, effectively building the complete welcome message.
		}

	cout << Lines;// This line displays the welcome message stored in the `Lines` string on the console.

	}
    cout<<"\n\t  |\t\t\t\t\t\t\t";
    ifs.close ();
    Sleep(3000);
    exit(0);
}

int rate(int hour, int j) // equation of the total money required and the rental time
{
	int hour_24, hour_12, hour_1;
	int total, total_24, total_12, total_1;//Declare the variables `hour_24`, `hour_12`, `hour_1`, `total`, `total_24`, `total_12`, `total_1` to store intermediate and final results.

	hour_24=hour/24;// Calculate the number of whole days (`hour_24`) by dividing the total rental hours (`hour`) by 24.
	hour_12=(hour - hour_24*24)/12;//Calculate the remaining hours after subtracting the whole days (`hour_24*24`) from the total hours. This gives the number of half days (`hour_12`) by dividing the remaining hours by 12.
	hour_1=(hour - hour_24*24 - hour_12*12)/1;//Calculate the remaining hours after subtracting the whole days and half days (`hour_24*24 + hour_12*12`) from the total hours. This gives the number of single hours (`hour_1`).

	total_24 = hour_24 * rent[j].rate_per_day;// Calculate the total cost for the whole days (`total_24`) by multiplying the number of whole days (`hour_24`) by the rate per day (`rent[j].rate_per_day`).
	total_12 = hour_12 * rent[j].rate_per_half;//Calculate the total cost for the half days (`total_12`) by multiplying the number of half days (`hour_12`) by the rate per half day (`rent[j].rate_per_half`).
	total_1 = hour_1 * rent[j].rate_per_hour;//Calculate the total cost for the single hours (`total_1`) by multiplying the number of single hours (`hour_1`) by the rate per hour (`rent[j].rate_per_hour`).

	total = total_24 + total_12 + total_1;//Calculate the final total cost by adding the costs for the whole days, half days, and single hours (`total = total_24 + total_12 + total_1`).
	return total;//Return the final total cost.
}


void customerData()//the function reads customer data from a file and stores it in an array of structures for further processing or manipulation.
{
	ifstream ifs;
	ifs.open("Customer.txt");
	int custNum = 0;//initializes a variable `custNum` to 0, which will be used to keep track of the number of customers read from the file.


	while (!ifs.eof())
	{
		ifs >> cust[custNum].id;//operator is used to read the customer ID from the file and store it in `cust[custNum].id`. The `ignore()` function is then used to ignore the newline character left in the input stream after reading the ID.
		ifs.ignore();//// The `ignore()` function is then used to ignore the newline character left in the input stream after reading the ID.
		ifs.getline(cust[custNum].name,100,';');////allows accepting and reading single and multiple line strings from the input stream
		ifs.getline(cust[custNum].phone,15,';');
		ifs.getline(cust[custNum].ic,15,';');
		ifs.getline(cust[custNum].address,1500);
		custNum++;
	}

	ifs.close();
}



int custCount()
{
	int numOfCust = 0;// used to keep track of the number of non-empty lines in the file.
	ifstream ifs("Customer.txt");

	string word;//Declare a string variable `word` to store each line of the file.
	while (getline(ifs, word))////allows accepting and reading single and multiple line strings from the input stream
	{
    	if (!word.empty())
        	numOfCust++;//If the line is not empty, increment `numOfCust` by 1.
	}

	ifs.close();

	return numOfCust;// represents the count of non-empty lines in the file.
}

int countUser()
{
	int numOfCust = 0;//// used to keep track of the number of non-empty lines in the file.
	ifstream ifs("UserPass.txt");

	string word;//Declare a string variable `word` to store each line of the file.
	while (getline(ifs, word))////allows accepting and reading single and multiple line strings from the input stream
	{
    	if (!word.empty())
        	numOfCust++;//If the line is not empty, increment `numOfCust` by 1.
	}

	ifs.close();

	return numOfCust;//// represents the count of non-empty lines in the file.
}



void newCarData()
{
	cout<<"\n\n";
	art();
	cout << endl;

	ofstream ofs; //used to create files and to write information to files
	ofs.open("car rental.txt" , fstream::app); //allows both reading from and writing to files by default
	ofs<<endl;

	int newCar = carCount() + 1;
	cout << "\n\n";
	cout << "\n\t  |\t\t\t\t\t  Please enter the car data below : " << endl;

	cout << "\n\t  |\t\t\t\t\t  Plate Number : ";
	cin >> ws;//tells the compiler to ignore buffer and also to discard all the whitespaces before the actual content of string or character array
	cin.getline(rent[newCar].plate_num,10);//allows accepting and reading single and multiple line strings from the input stream
	ofs << rent[newCar].plate_num;
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Brand : ";
	cin.getline(rent[newCar].brand,20);//used to read a line of input from the user and store it in the brand member of a specific structure in an array.
	ofs << rent[newCar].brand;// used to write the value of the `brand` member of a specific structure in an array to an output file stream
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Model : ";
	cin.getline(rent[newCar].model,20);////allows accepting and reading single and multiple line strings from the input stream
	ofs << rent[newCar].model;
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Capacity : ";
	cin >> rent[newCar].capacity;
	ofs << rent[newCar].capacity;
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Colour : ";
	cin >> ws;//tells the compiler to ignore buffer and also to discard all the whitespaces before the actual content of string or character array
	cin.getline(rent[newCar].colour,20);////allows accepting and reading single and multiple line strings from the input stream
	ofs << rent[newCar].colour;
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Rate Per Hour : ";
	cin >> rent[newCar].rate_per_hour;
	ofs << rent[newCar].rate_per_hour;
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Rate Per 12 Hour : ";
	cin >> rent[newCar].rate_per_half;
	ofs << rent[newCar].rate_per_half;
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Rate Per 24 Hour : ";
	cin >> rent[newCar].rate_per_day;
	ofs << rent[newCar].rate_per_day;
	ofs << " ";

	cout << "\t  |\t\t\t\t\t  Tranmission (A/M) : ";
	cin >> ws;//tells the compiler to ignore buffer and also to discard all the whitespaces before the actual content of string or character array
	cin.getline(rent[newCar].transmission,6);////allows accepting and reading single and multiple line strings from the input stream
	ofs << rent[newCar].transmission;

	ofs.close();
	system("cls"); //terminal/command prompt commands used to clear the screen

	carData();
	admin();
}

void carData ()
{
	ifstream ifs; //reads data from files and displays it
	ifs.open("car rental.txt");
	int carNum = 0;

	while(!ifs.eof())
	{
		ifs.getline(rent[carNum].plate_num,10,' ');//used to read a line of text from a file and store it into a character array or string variable
		ifs.getline(rent[carNum].brand,20,' ');//used to read a line of text from a file and store it into a character array or string variable
		ifs.getline(rent[carNum].model,20,' ');//used to read a line of text from a file and store it into a character array or string variable
		ifs >> rent[carNum].capacity;// used for extracting data from an input stream
		ifs.ignore();// function is used to skip over a specified number of characters or a specific delimiter in the input stream
		ifs.getline(rent[carNum].colour,20,' ');//used to read a line of text from a file and store it into a character array or string variable
		ifs >> rent[carNum].rate_per_hour;// used for extracting data from an input stream
		ifs.ignore();// function is used to skip over a specified number of characters or a specific delimiter in the input stream
		ifs >> rent[carNum].rate_per_half;// used for extracting data from an input stream
		ifs.ignore();// function is used to skip over a specified number of characters or a specific delimiter in the input stream
		ifs >> rent[carNum].rate_per_day;// used for extracting data from an input stream
		ifs.ignore();// function is used to skip over a specified number of characters or a specific delimiter in the input stream
		ifs.getline(rent[carNum].transmission,6);//used to read a line of text from a file and store it into a character array or string variable
		carNum++;
		ifs>>ws;//tells the compiler to ignore buffer and also to discard all the white spaces before the actual content of string or character array
	}

	ifs.close();
}
int carCount()//the function reads each line from a file and counts the number of lines that are not empty, assuming each non-empty line represents a car listed in the file.
{
	int numOfCar = 0;
	ifstream ifs("car rental.txt");

	string word;
	while (getline(ifs, word))////allows accepting and reading single and multiple line strings from the input stream
	{
    	if (!word.empty())// checks if the `word` string is not empty using the `empty()` function. If the string is not empty, it means that a car is listed on that line
        	numOfCar++;
	}

	ifs.close();

	return numOfCar;//returns the count of cars, which is stored in the `numOfCar` variable.
}

void showCarData()
{


	int x;
	cout<<"\n\n";
	art();

	cout << endl;

	cout << "\t  |  Plate Number\tBrand\t Model\tCapacity    Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission" << endl;
	cout << "\t  |  =======================================================================================================================" << endl;
	for (int i = 0; i < carCount(); i++)
	{
		cout << "\t  |  " << rent[i].plate_num << "\t\t" << rent[i].brand << "\t " << rent[i].model << "\t   " << rent[i].capacity << "\t     "
			 << rent[i].colour << "\t  " <<rent[i].rate_per_hour << "\t\t    " << rent[i].rate_per_half << "\t\t    " << rent[i].rate_per_day
			 << "\t\t       " << rent[i].transmission << endl;
	}
	cout << "\n\n";
	cout<<"\n\t  |\t\t\t\t\t  1. BACK";
	cout<<"\n\t  |\t\t\t\t\t  2. MAIN MENU"<<endl<<"\n\n";
	cout<<"\t  |\t\t\t\t\tINPUT :";
	cin >> x;

	system("cls"); //terminal/command prompt commands used to clear the screen

	if (x==1)
	{
		admin();
	}

	if (x==2)
	{
		menu();
	}

}



void availCar ()
{
	ifstream ifs; //reads data from files and displays it
	ifs.open("available.txt");
	int carNum = 0;

	while(!ifs.eof())
	{
		ifs.getline(avail[carNum].plate_num,10,' ');//used to read a line of text from a file and store it into a character array or string variable
		ifs.getline(avail[carNum].brand,20,' ');
		ifs.getline(avail[carNum].model,20,' ');
		ifs >> avail[carNum].capacity;// used for extracting data from an input stream
		ifs.ignore();
		ifs.getline(avail[carNum].colour,20,' ');
		ifs >> avail[carNum].rate_per_hour;
		ifs.ignore();// function is used to skip over a specified number of characters or a specific delimiter in the input stream
		ifs >> avail[carNum].rate_per_half;
		ifs.ignore();
		ifs >> avail[carNum].rate_per_day;
		ifs.ignore();
		ifs.getline(avail[carNum].transmission,6);
		carNum++;
		ifs>>ws;//tells the compiler to ignore buffer and also to discard all the whitespaces before the actual content of string or character array
	}

	ifs.close();
}
int countAvail()
{
	int numOfCust = 0;// used to keep track of the number of non-empty lines in the file.
	ifstream ifs("available.txt");

	string word;//Declare a string variable `word` to store each line of the file.
	while (getline(ifs, word))////allows accepting and reading single and multiple line strings from the input stream
	{
    	if (!word.empty())
        	numOfCust++;//If the line is not empty, increment `numOfCust` by 1.
	}

	ifs.close();

	return numOfCust;// represents the count of non-empty lines in the file.
}
void displayCar()
{
	cout << "\t  |  Plate Number\tBrand\t Model\tCapacity    Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission" << endl;
	cout << "\t  |  =======================================================================================================================" << endl;
	for (int i = 0; i < carCount(); i++)
	{
		cout << "\t  |   " << rent[i].plate_num << "\t\t" << rent[i].brand << "\t " << rent[i].model << "\t   " << rent[i].capacity << "\t     "
			 << rent[i].colour << "\t  " <<rent[i].rate_per_hour << "\t\t    " << rent[i].rate_per_half << "\t\t    " << rent[i].rate_per_day
			 << "\t\t       " << rent[i].transmission << endl;
	}
}

void dispAvailCar()
{
	cout << "\t  |  Plate Number\tBrand\t Model\tCapacity    Colour   Rate Per Hour   Rate Per 12 Hour   Rate Per 24 Hour   Transmission" << endl;
	cout << "\t  |  =======================================================================================================================" << endl;
	for (int i = 0; i < countAvail(); i++)
	{
		cout << "\t  |   " << avail[i].plate_num << "\t\t" << avail[i].brand << "\t " << avail[i].model << "\t   " << avail[i].capacity << "\t     "
			 << avail[i].colour << "\t  " <<avail[i].rate_per_hour << "\t\t    " << avail[i].rate_per_half << "\t\t    " << avail[i].rate_per_day
			 << "\t\t       " << avail[i].transmission << endl;
	}
}


void resetAvail()//writes the car data to a temporary file, presumably to reset the availability status of the cars.
{
	Boarder();//function that displays a visual border or header on the console.
	ofstream ofs; //used to create files and to write information to files
	ofs.open("temp2.txt");

	for(int i = 0; i < carCount(); i++)
	{
	    // each car's data is written to the output file stream `ofs` using the `<<` operator.
			ofs << rent[i].plate_num;
			ofs << " ";
			ofs << rent[i].brand;
			ofs << " ";
			ofs << rent[i].model;
			ofs << " ";
			ofs << rent[i].capacity;
			ofs << " ";
			ofs << rent[i].colour;
			ofs << " ";
			ofs << rent[i].rate_per_hour;
			ofs << " ";
			ofs << rent[i].rate_per_half;
			ofs << " ";
			ofs << rent[i].rate_per_day;
			ofs << " ";
			ofs << rent[i].transmission;
			if(i != carCount())//used to check if the current car is not the last car.
			{
				ofs<<endl;
			}


		}




	ofs.close();
	remove("available.txt"); //deletes a specified file
	rename("temp2.txt","available.txt");//renames the file represented by the string pointed to by oldname to the string pointed to by newname

	admin();

}


void delCar()
{
	char plate[10];//character array called `plate` is declared with a size of 10. This array is used to store the license plate number of a car that is to be deleted.

	ofstream ofs;
	ofs.open("temp.txt");//output file stream object called `ofs` is declared. This object is used to open a file called "temp.txt" in write mode

	cout<<"\n\n\n\n";
	art();

	cout << endl;
	displayCar();// a new line is printed and a function call to `displayCar()` is made and displays the list of cars along with their details.

	cout << "\n\n";
	cout << "\t  | \t\tEnter the car plate number that are going to be deleted (CAPITAL LETTER W/OUT SPACE): "<<endl;
	cout<< "\t  |  \t\t\t\t\t\t\t";
	cin >> ws;//tells the compiler to ignore buffer and also to discard all the white spaces before the actual content of string or character array
	cin.getline(plate,10); //  function used to read a line of text from the standard input (cin) and store it in a character array
	int x=carCount();
	for(int i = 0; i < carCount(); i++)
	{
		if (strcmp(plate,rent[i].plate_num) != 0)//used to compare two strings lexicographically, character by character. It returns an integer value that indicates the result of the comparison:
		{
		     // each car's data is written to the output file stream `ofs` using the `<<` operator.
			ofs << rent[i].plate_num;// used to write values of variables or literals to the output stream.
			ofs << " ";
			ofs << rent[i].brand;
			ofs << " ";
			ofs << rent[i].model;
			ofs << " ";
			ofs << rent[i].capacity;
			ofs << " ";
			ofs << rent[i].colour;
			ofs << " ";
			ofs << rent[i].rate_per_hour;
			ofs << " ";
			ofs << rent[i].rate_per_half;
			ofs << " ";
			ofs << rent[i].rate_per_day;
			ofs << " ";
			ofs << rent[i].transmission;
			if(i != carCount())//checks if the variable `i` is not equal to the result of the function `carCount()`.
			{
				ofs<<endl;
			}


		}
	}

	ofs.close();

	remove("car rental.txt");
	rename("temp.txt","car rental.txt");


	system("cls"); //terminal/command prompt commands used to clear the screen

	carData();
	admin();
}
void existingCust()
{


	int tempCust, hour, userID;// `tempCust`, `hour`, and `userID` are declared as variables.
	char carSelect[10];
	tempCust = custCount() - 1;//returns the total count of customers in the system and The value is then subtracted by 1 and assigned to `tempCust`.
	ofstream log;//log` is created and opened which means any data written to it will be added to the end of the file "Log.txt"
	log.open("Log.txt", fstream::app);
	ofstream ofs; //It is used to create files and to write data to files
	ofs.open("temp.txt");
	cout<<"\n\n\n\n";
	cout << endl;

	cout<<"\n\n";
     art();
	cout << endl;

	cout << "\n\t  |\t\t\t\tPlease enter user ID : ";//The user is prompted to enter a user ID.
	cin >> userID;

	for (int i = 0 ; i < custCount() ; i++)//loop is used to iterate through all customers in the system based on total number of customers.
	{
		if (userID == cust[i].id)//checks if the user ID entered by the user matches the ID of a customer in the `cust` array.
            //if true customer information are displayed on the console
		{
			cout<<"\n\t  |\t\t\t\t\tWELCOME ";
			cout << cust[i].name;
			log <<"\nNAME: "<< cust[i].name;
			cout<<"\t  |\tID ";
			cout << cust[i].id;
			cout << "\n\n";
			log<<"\nPHONE: "<<cust[i].phone;
			log<<"\nIC: "<<cust[i].ic;
		}
	}


	dispAvailCar();

	cout<<"\n\n\t  |\t\t\t\t\tPlease select car";
	cout<<"\n\t  |\t\t\t\t\tPlate Number : ";
	cin >> ws;//tells the compiler to ignore buffer and also to discard all the whitespaces before the actual content of string or character array
	cin.getline(carSelect,10);////allows accepting and reading single and multiple line strings from the input stream
	int x=countAvail();
	for(int i = 0; i < countAvail(); i++)//used to declare a variable and assign it the value returned by a function, and then iterate over a range of values using a `for` loop
	{
	    //used to check if the `carSelect` string is not equal to the `plate_num` of the car at index `i` in the `avail` array. If the strings are not equal, the condition evaluates to true, and the code inside the `if` statement will be executed.
		if (strcmp(carSelect,avail[i].plate_num) != 0)
		{
		     // each car's data is written to the output file stream `ofs` using the `<<` operator.
			ofs << avail[i].plate_num;
			ofs << " ";
			ofs << avail[i].brand;
			ofs << " ";
			ofs << avail[i].model;
			ofs << " ";
			ofs << avail[i].capacity;
			ofs << " ";
			ofs << avail[i].colour;
			ofs << " ";
			ofs << avail[i].rate_per_hour;
			ofs << " ";
			ofs << avail[i].rate_per_half;
			ofs << " ";
			ofs << avail[i].rate_per_day;
			ofs << " ";
			ofs << avail[i].transmission;
			if(i != countAvail())
			{
				ofs<<endl;
			}


		}
	}

	ofs.close();

	remove("available.txt"); //deletes a specified file
	rename("temp.txt","available.txt"); //renames the file represented by the string pointed to by oldname to the string pointed to by newname
	cout << "\t  |\t\t\t\t\tHours of rent : ";
	cin >> hour;
	int j;
	for(int i = 0; i < carCount(); i++)
	{
		if (strcmp(carSelect,rent[i].plate_num) == 0) //used to compare two null-terminated strings and since it the return value=0 it indicates that both strings are equal
		{
			j = i;

			log<<"\nCAR: "<<rent[i].plate_num;
			log<<"\nBRAND: "<<rent[i].brand;
			log<<"\nMODEL: "<<rent[i].model;
			log <<"\nHOUR: "<< hour;
			log <<"\nPAYMENT: "<< rate(hour,j);
		}
	}

	cout << "\t  |\t\t\t\tPrice for " << hour << " hours of rent : RM ";
	cout << rate(hour,j);

	log <<"\nDATE: "<<currentDateTime();
	log<<"\n==========================================================";
	log.close();

	Sleep(5000);
	system("cls"); //terminal/command prompt commands used to clear the screen
	menu();
}

void  allreservations()
{
    ifstream myfile;// `ifstream` object named `myfile` is created to read from a file
    myfile.open("Log.txt");//The `open()` function is called on `myfile` to open the file "Log.txt".
    string myline;// A string variable named `myline` is declared to store each line read from the file.
    if(myfile.is_open())// checks if the file was successfully opened.
    {
        while(myfile)//The loop condition `myfile` checks if the `myfile` object is in a valid state.
        {
            getline(myfile,myline);//getline()` function is called to read a line from the file and store it in `myline`.
            cout<<myline<<"\n";//The contents of `myline` are then displayed on the console
        }
    }
    else
    {
      cout<<"couldnt open it ";//. The loop continues until there are no more lines to read from the file.
    }
    Sleep(6000);
    system("cls");
}


void mostrentedcar()
{
    string line, word;// string variable named `line` is declared to store each line read from the file, and another string variable named `word` is declared to store the most frequently occurring word.
    int count = 0, maxCount = 0;//This statement declares a variable named `count` of type `int` and initializes it with the value & setting its initial value to be used in further calculations or comparisons in your program.
    vector<string> words; //declares a vector object named `words` that can hold elements of type `string

    //Opens file in read mode
    ifstream file("availtemp.txt");// The function opens the file "availtemp.txt" in read mode using an `ifstream` object named `file`.

    //Reads each line
    while (getline(file, line)) //loop that reads each line from the file using the `getline()` function
        {
        transform(line.begin(), line.end(), line.begin(), ::tolower);//the line is transformed to lowercase using the `transform()` function.
        string string;
        for (auto c : line) {
            if (c == ' ' || c == ',' || c == '.') {
                words.push_back(string);
                string.clear();
            } else {
                string += c;
            }
        }
    }

    //Determine the most repeated word in a file
    for (int i = 0; i < words.size(); i++)//After parsing all the lines in the file, the function enters another loop to count the occurrences of each word in the `words` vector.
        {
        count = 1;//`count` is set to 1 for each word, and a nested loop compares each word with the remaining words in the vector
        //Count each word in the file and store it in variable count
        for (int j = i + 1; j < words.size(); j++) {
            if (words[i] == words[j]) {
                count++;
            }
        }
        //If maxCount is less than count then store value of count in maxCount
        //and corresponding word to variable word
        if (count > maxCount) // If the `count` variable is greater than the `maxCount` variable, the `maxCount` is updated with the new count, and the `word` variable is set to the corresponding word.
        {
            maxCount = count;
            word = words[i];
        }
    }

    cout << "Most rented car: " << word << endl;//. Once all the words have been counted, the function prints the most frequently occurring word on the console.
    file.close();


    Sleep(5000);
    system("cls");
}

void therenterreservations()
{
     string fileName;

    // Prompt the user to enter the file name
    cout << "Enter the file name: ";
    cin >> fileName;

    // Open the file
    ifstream inputFile(fileName);

    // Check if the file was successfully opened
    if (!inputFile) {
        cout << "Error opening file!" << endl;

    }

    // Read and print the contents of the file
    string line;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }

    // Close the file
    inputFile.close();


      Sleep(5000);
    system("cls");
}

 void rentedcarsperday()//counts the number of lines in the file by incrementing the `count` variable for each line read from the file.
{
    int count = 0;
    string line;

    /* Creating input filestream */
    ifstream file("availtemp.txt");
    while (getline(file, line))//used to read a line from the file `file` and store it in the string variable `line`.
        count++;//the `count` variable is incremented by 1 for each line read

    cout << "Numbers rented cars per day : " << count << endl;
		Sleep(6000);
    system("cls");
}

void newCustData ()
{
	cout<<"\n\n";
    art();
	cout << endl;

	availCar();
	ofstream ofs,log; //It is used to create files and to write data to files
	ofs.open("Customer.txt", fstream::app); // used to read the data from the files
	log.open("Log.txt", fstream::app);
	ofs << endl;
	ofstream availTemp;
	availTemp.open("availtemp.txt");
	cout<<"\n\n\n\n";
	cout << endl;

// assigns a unique ID to a customer
	cust[custCount()].id = custCount() + 1001;//is used as an index to access a customer object in the `cust` array. The `custCount()` value is added to 1001 to generate a unique ID for the customer.
	ofs << cust[custCount()].id;//The assigned ID value is then written to the `ofs` file using the `<<` operator.
	ofs << ";";


	cout << "\n\n";
	cout << "\n\t  |\t\t\t\t\t  Please enter the data below : " << endl;

	cout << "\n\t  |\t\t\t\t\t  Name : ";
	cin >> ws;//tells the compiler to ignore buffer and also to discard all the whitespaces before the actual content of string or character array
	cin.getline(cust[custCount()].name,100);//allows accepting and reading single and multiple line strings from the input stream
	ofs << cust[custCount()].name<<";";
	log <<"\nNAME: "<< cust[custCount()].name;

	cout << "\t  |\t\t\t\t\t  Phone Number : ";
	cin.getline(cust[custCount()].phone,15);
	ofs << cust[custCount()].phone;
	ofs << ";";
	log <<"\nPHONE: "<< cust[custCount()].phone;


	cout << "\t  |\t\t\t\t\t  IC : ";
	cin.getline(cust[custCount()].ic,15);
	ofs << cust[custCount()].ic;
	ofs << ";";
	log <<"\nIC: "<< cust[custCount()].ic;

	cout << "\t  |\t\t\t\t\t  Address : ";
	cin.getline(cust[custCount()].address,1500);////allows accepting and reading single and multiple line strings from the input stream
	ofs << cust[custCount()].address;

	ofs.close();


	system("cls"); //terminal/command prompt commands used to clear the screen

	int tempCust, hour;
	char carSelect[10];
	tempCust = custCount() - 1;

	cout<<"\n\n\n\n";
     art();
	cout << endl;

	cout<<"\n\t  |\t\t\tWELCOME ";
	cout << cust[tempCust].name;
	cout<<"\t  |\tID ";
	cout << cust[tempCust].id;
	cout << "\n\n";

	dispAvailCar();

	cout<<"\n\n\t  |\tPlease select car";
	cout<<"\n\t  |\tPlate Number : ";
	cin >> ws;//tells the compiler to ignore buffer and also to discard all the whitespaces before the actual content of string or character array
	cin.getline(carSelect,10);////allows accepting and reading single and multiple line strings from the input stream

	int x=countAvail();

	for(int i = 0; i < countAvail(); i++)
	{
		if (strcmp(carSelect,avail[i].plate_num) != 0) //compares both the strings character by character
		{
			availTemp << avail[i].plate_num;//used to insert the value of `avail[i].plate_num` into the `availTemp` stream.
			availTemp << " ";
			availTemp << avail[i].brand;
			availTemp << " ";
			availTemp << avail[i].model;
			availTemp << " ";
			availTemp << avail[i].capacity;
			availTemp << " ";
			availTemp << avail[i].colour;
			availTemp << " ";
			availTemp << avail[i].rate_per_hour;
			availTemp << " ";
			availTemp << avail[i].rate_per_half;
			availTemp << " ";
			availTemp << avail[i].rate_per_day;
			availTemp << " ";
			availTemp << avail[i].transmission;
			if(i != countAvail())
			{
				availTemp<<endl;
			}


		}
	}

	ofs.close();

	remove("available.txt"); //deletes a specified file
	rename("availtemp.txt","available.txt"); //renames the file represented by the string pointed to by oldname to the string pointed to by newname

	cout << "\t  |\tHours of rent : ";
	cin >> hour;
	int j;
	for(int i = 0; i < carCount(); i++)
	{
		if (strcmp(carSelect,rent[i].plate_num) == 0)
		{
			j = i;
			rate(hour,j);
			log<<"\nCAR: "<<rent[i].plate_num;
			log<<"\nBRAND: "<<rent[i].brand;
			log<<"\nMODEL: "<<rent[i].model;
			log <<"\nHOUR: "<< hour;
			log <<"\nPAYMENT: "<< rate(hour,j);

		}
	}



	cout << "\n\t  |\tPrice for " << hour << " hours of rent : RM ";
	cout << rate(hour,j);

	log <<"\nDATE: "<<currentDateTime();
	log<<"\n==========================================================";
	log.close();
	availTemp.close();
	availCar();

	Sleep(5000); //used to sleep the particular thread of the C++ that is running in the particular program
	system("cls"); //terminal/command prompt commands used to clear the screen
	menu();
}
void password()
{
	Boarder();//function that displays a visual border or header on the console.

   countUser(); //used to keep track of count - how many times a piece of code is executed
   string password;
   char c;
   gotoxy(40,20); //can be useful for controlling the output or creating interactive text-based user interfaces
   cout << "\n\n\n\n\t  |\t\t\tPASSWORD: ";

	while(c != '\r') //Loop until 'Enter' is pressed
         {
         c = getch(); //hold the output screen for some time until the user passes a key from the keyboard to exit the console screen
         if(c == 0)
            {
            switch(getch())
               {
               default:
                  break;
               };
            }
         else if(c == '\b')   //If the 'Backspace' key is pressed
            {
            if(password.size() != 0)  //If the password string contains data, erase last character
               {
               cout << "\b \b";
               password.erase(password.size() - 1, 1);
               }
            continue;
            }
         else if(c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')  //If user enters 1-9, a-z, or A-Z, add it to the password and display an asterisk
            {
            password += c;
            cout << "*";
            }
         else
            continue;
         }

         for(int i=0; i<countUser();i++)
         {
         	if(password.compare(userPass[i].passWord)==0)// checking if the `password` entered by the user matches the password stored for a specific user in the `userPass` array at index `i`. If they match, the code inside the `if` statement will be executed.
         	{
         		system("cls"); //terminal/command prompt commands used to clear the screen
		 		load_CHECK();
          		admin();
			 }
		 }


          if(password == "a")//the password
          	{
          system("cls");
		  load_CHECK(); //checks that a routine (function or class member) is called during the execution of the surrounding test case
          admin();
      		}

		  else
          cout<<"\n\t  |\t\t\tWrong Password.. Call Administrator";
          cout<<"\n\t  |\t\t\tReturning to Main Menu.."<<endl;
          cout<<"\n\t  |\t\t\t";
		  Sleep(1000);
          cout<<"\n\t  |\t\t\tPress Enter to Continue.";
          cout<<"\n\t  |\t\t\t";
          getch();
          menu();



}

void newUserPass()//allows the user to create a new username and password combination
{
	Boarder();//function that displays a visual border or header on the console.
	ofstream ofs;//used to create files and to write information to files
	ofs.open("UserPass.txt", fstream::app);

	userPass[countUser()].ID = countUser()+1;//function that returns the total count of users in the system. This count is used to assign an ID to the new user.


	string password;
	char c;
	gotoxy(40,20);
	cout << "\n\n\n\n\t  |\t\t\tID(DEFAULT): "<<userPass[countUser()].ID;
	cout << "\n\t  |\t\t\tADD PASSWORD: ";// The function prompts the user to enter a password. The password is stored in a string variable named `password`.

	while(c != '\r') //loop that reads each character entered by the user
         {
         c = getch(); //we can hide the input character provided by the users
         if(c == 0)
            {
            switch(getch())
               {
               default:
                  break;
               };
            }
         else if(c == '\b')   //If the 'Backspace' key is pressed
            {
            if(password.size() != 0)  //If the password string contains data, erase last character
               {
               cout << "\b \b";
               password.erase(password.size() - 1, 1);
               }
            continue;
            }
         else if(c <= '9' && c >= '0' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')  //If user enters 1-9, a-z, or A-Z, add it to the password and display an asterisk
            {
            password += c;
            cout << "*";
            }
         else
            continue;//loop continues until the user enters a character that is not a digit or a letter
         }


	strcpy(userPass[countUser()].passWord,password.c_str()); //used to copy one string to another

	ofs<<userPass[countUser()].ID;//writes the `ID` value to the "UserPass.txt" file using the `<<` operator.
	ofs<<";";
	ofs<<userPass[countUser()].passWord;
	ofs<<endl;

	system("cls");
	admin();

}


void admin()
{
	int x;
	cout<<"\n\n\n\n";
	art();

	cout << endl;

	cout<<"\n\t  |\t\t\t\t\t\t\t  1. ADD ADMIN ";
	cout<<"\n\t  |\t\t\t\t\t\t\t  2. LIST ALL THE CARS ";
	cout<<"\n\t  |\t\t\t\t\t\t\t  3. LIST ALL THE RESERVATIONS ";
	cout<<"\n\t  |\t\t\t\t\t\t\t  4. LIST ALL THE RESERVATIONS done by the renter ";
	cout<<"\n\t  |\t\t\t\t\t\t\t  5. ADD CAR ";
	cout<<"\n\t  |\t\t\t\t\t\t\t  6. DELETE CAR ";
	cout<<"\n\t  |\t\t\t\t\t\t\t  7. MOST RENTED CAR ";
	cout<<"\n\t  |\t\t\t\t\t\t\t  8. total number of rented cars per day ";
	cout<<"\n\t  |\t\t\t\t\t\t\t  9. RESET AVAILABLE CAR ";
	cout<<"\n\t  |\t\t\t\t\t\t\t  10. LOG OFF"<<endl<<"\n";
	cout<<"\t  |\t\t\t\t\t\t\tINPUT :";
	cin>>x;


	system("cls"); //terminal/command prompt commands used to clear the screen

	if (x==10)
	{
		load_EXIT();
		menu();
	}

	else if (x==2)
	{
		showCarData();
	}
	else if (x==3)
	{
		allreservations();
	}
	else if (x==4)
	{
		therenterreservations();
	}

	else if (x==5)
	{
		newCarData();
	}
	else if (x==7)
	{
		mostrentedcar();
	}

	else if (x==6)
	{
		delCar();
	}
	else if (x==8)
	{
		rentedcarsperday();
	}
	else if (x==1)
	{
		newUserPass();
	}
	else if(x==9)
	system("cls");
		resetAvail();
}

void user()
{

	int x;

	art();
	cout << endl;


	cout<<"\n\t  |\t\t\t\t\t\t\t  1. NEW";
	cout<<"\n\t  |\t\t\t\t\t\t\t  2. EXISTING";
	cout<<"\n\t  |\t\t\t\t\t\t\t  3. MAIN MENU"<<endl;
	cout<<"\n\n\t  |\t\t\t\t\t\t\tINPUT :";
	cin>>x;

	system("cls"); //terminal/command prompt commands used to clear the screen
	if (x==1)
	{
		newCustData();
	}

	else if (x==2)
	{
		system("cls"); //terminal/command prompt commands used to clear the screen
		load_UPDATE();
		existingCust();
	}

	else if (x==3)
	{
		menu();
	}




}

void menu()
{

	int x;
	art();

	cout << endl;
	cout<<"\n\t  |\t\t\t\t\t\t\t  1. ADMIN";
	cout<<"\n\t  |\t\t\t\t\t\t\t  2. USER";
	cout<<"\n\t  |\t\t\t\t\t\t\t  3. T%C";
	cout<<"\n\t  |\t\t\t\t\t\t\t  4. EXIT"<<endl<<"\n";
	cout<<"\n\t  |\t\t\t\t\t\t\tINPUT :";
	cin>>x;


	system("cls"); //terminal/command prompt commands used to clear the screen

	if (x==2)
	{
		user();
	}

	else if (x==1)
	{
		password();
	}

	if(x==3)
	{

	tNc();
	getch(); //hold the output screen for some time until the user passes a key from the keyboard to exit the console screen
	}

	if(x==5)
	time();

	else if (x==4)
	{
		cout << "\n\n\n\n";
		exitArt();

		Sleep(1000); //used to sleep the particular thread of the C++ that is running in the particular program
		exit(0);
	}

	else if (x==6)
	{

		menu();
	}





}


void tNc() // this are the rules
{

	cout<<endl;
	cout<<"\n\t  |\t\t\t1. MINIMUM RENT TIME IS 2 HOURS";
	cout<<"\n\t  |\t\t\t2. RISK BY YOUR OWN";
	cout<<"\n\t  |\t\t\t3. INCASE ACCIDENT, ALL COSTING IS PAID BY THE DRIVER";
	cout<<"\n\t  |\t\t\t4. PREPARE ITEM AS BELOW";
	cout<<"\n\t  |\t\t\t     \3COPY OF IC, LICENSE";
	cout<<"\n\t  |\t\t\t     \3DEPOSIT (BASED ON CAR TYPE)";
	cout<<"\n\t  |\t\t\t5. ADDITIONAL CHARGE IF LATE";
	cout<<"\n\t  |\t\t\t6. SAFE DRIVE!";
	cout<<"\n\n\n\n\t  |\t\t\t                             PRESS ANY KEY TO CONTINUE :)";
	cout<<"\n\t  |\t\t\t                                                            ";

	getch();
	menu();
}

main()// It calls several other functions in a specific order to perform various tasks
{
    // all the inputs we need

	welcome();//This function is called to display a welcome message on the console
	load();//This function is called to load any necessary data or configurations required for the program
	Boarder();//function that displays a visual border or header on the console.
	readUserPass();//This function is called to read and validate user credentials, such as a username and password.
	availCar();//This function is called to display the available cars for rental
	customerData();//This function is called to handle customer-related data, such as registering new customers, displaying customer information
	carData();//This function is called to handle car-related data, such as adding new cars, updating car information, or managing the car inventory
	menu();//This function is called to display a menu or options for the user to interact with


}

