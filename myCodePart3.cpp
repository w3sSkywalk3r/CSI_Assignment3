//
//   COPYRIGHT (C) wec16@uakron.edu>, 2021  All rights reserved.
//   Student Wesley Cunningham
//   Purpose: This is myCode and is based upon what we study for Comp Sci
//
#include <cassert>
#include <iosfwd>
#include <iostream>
#include <iomanip>
#include <limits>  // numeric_limits<std::streamsize> for validations
#include<time.h> //included to seed the rand function
#include<fstream>// allowed for file input and output in task 1C
#include<vector> // used in task 6
#include<algorithm> //was having an odd error code in task 6 and after some research I found that it could be resolved by
                    //including the algorithm library


// these are declarations - prefer this or std:: prefix
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::right;
using std::hex;
using std::vector;

static int uChoose = 0;

// stuff for our task 4 obfuscation problem and task 1
const int obfuscatSize{26};

// these codes are stored an ascii equivalent to A - Z, ascii 65 - 91
const unsigned char obfuscators[obfuscatSize] = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A,
                                            0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54,
                                            0x55, 0x56, 0x57, 0x58, 0x59, 0x5A };

const unsigned char myWord[4] = { 0x48, 0x45, 0x4C, 0x50 };

// stuff for our task 2 search problem
const unsigned char searchMe = 0x5A ;

// stuff for our string problem task 5
const int NLPsize{20};

const std::string NLPwords[NLPsize]
{
  "clique", "gang", "deceitful", "nosy", "conceited", "picky",
  "sick", "manic", "scam", "clouds", "sunshine", "amazing", "ice cream sundae",
  "interested",  "winner", "steadfast", "elated", "courageous","wowzers", "truthful"
};

// for our machine learning problem task 7
// Number of arrays with hiding spots
const int NUMSPOTS = 12;
// Number of computers in each lab
const	int SPOTSIZES[NUMSPOTS] = {23, 15, 24, 33, 11, 35, 27, 10, 22, 16, 4, 9};


int
mainMenu();

void
arrays();

void
searching();

void
sorting();

void
cStrings();

void
theStrings();

void
vectors();

void
pointers();

void
misc();

struct Test_myCode
{
  void
  default_beg()
  {
    uChoose = mainMenu();
    assert(!(std::cin.fail()));
    std::cout << " Main menu passed " << std::endl;
  }
  void
  whatAction()
  {
    switch (uChoose)
    {
      case (1):
        arrays();
        break;
      case (2):
        searching();
        break;
      case (3):
        sorting();
        break;
      case (4):
        cStrings();
        break;
      case (5):
        theStrings();
        break;
      case (6):
        vectors();
        break;
      case (7):
        pointers();
        break;
      case (8):
        misc();
        break;
      default:
        cout << "no case";
    }
  }

  // The test runner for this test class.
  void
  run()
  {
    default_beg();
    whatAction();
  }

};


int
main()
{
  Test_myCode test;
  while (true)
  {
    test.run();
  }

}



int
mainMenu()
{
  // heading, input section
  cout << endl;
  cout << setw(68) << "__________________________________________________________________ " << endl;
  cout << setw(68) << "|------------------------------------------------------------------|" << endl;
  cout << setw(68) << "|            Wesley Cunningham - The Programming Wizard            |" << endl;
  cout << setw(68) << "|                   Coded Potions and Spells                       |" << endl;
  cout << setw(68) << "|__________________________________________________________________|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "   MAIN MENU"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "1) Arrays"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "2) Searching"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "3) Sorting      "
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "4) C-strings"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "5) Strings "
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "6) Vectors"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "7) Pointers"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "8) Miscellaneous"
       << right << setw(2) << "|" << endl;
  cout << left << setw(2) << "|" << setw(21) << " " << setw(43) << "Ctrl-c to Quit"
       << right << setw(2) << "|" << endl;
  cout << setw(68) << "|__________________________________________________________________|" << endl;
  cout << endl;
  int userChoice = 0;
  // take and validate the user entry

  cout << "Enter the code that you wish to generate, or quit to exit: "; // output stream a message
  cin >> userChoice;
  return userChoice;
}

/* TASK CODE:
   Place the functions after each task where they are run and up above
   the Tasks, place the prototypes, and of course the calls go inside the
   Task itself...
   const int obfuscatSize{26};
*/
// TASK 1 CODE
void partA(const unsigned char[], const int);
void partB();
void partC();
void
arrays()
{
  // A
  partA(obfuscators, obfuscatSize);
  // B
  partB();
  // C
  partC();


 cout << "end of arrays" << endl;
 cin.get();
}

void partA(const unsigned char obfuscators[], const int obfuscatSize)
{
      cout << "Static cast is: ";
  for (auto i = 0; i < 26; ++i)
    {
        cout << static_cast<char>(obfuscators[i]) << " ";
    }
    cout << endl;
    cout << "Dec is: ";
  for (auto i = 0; i < 26; ++i)
    {
        cout << std::dec << obfuscators[i] << " ";
    }
    cout << endl;
    cout << "Hex is: ";
  for (auto i = 0; i < 26; ++i)
    {
        cout << std::hex << obfuscators[i] << " ";
    }


    cout << std::dec << endl;
   return;
}


void partB()
{
     srand(time(NULL));
  int num = rand() % 100;
  int my2DimRay[3][5] = {{num,num,num,num,num},{num,num,num,num, num},{num,num,num,num,num}};

  for(auto row = 0; row < 3; ++row)
  {
      for(auto column = 0; column < 5; ++column)
      {
           my2DimRay[row][column] = rand() % 100;
          cout << std::setfill('0') << std::setw(2) << std::fixed << std::setprecision(2) << my2DimRay[row][column] << " ";
      }
      cout << std::setfill(' ') << endl;
  }
cout << endl;
  return;
}

void partC()
{
   std::ifstream myIstream;
  std::string myString;
  int biology[25] = {0};
  int compSci[25] = {0};
  int physics[25] = {0};
  int geography[25] = {0};
  int sociology[25] = {0};
  int propSolids[25] = {0};
  int calculus[25] = {0};

  myIstream.open("myScores.txt");

 //  int propSolids[25] = {25,28,170,250,66,100,77,78,44,45,75,95};
 //  int calculus[25] = {22,25,25,25,10,90,13,70,4,50};
  while(getline(myIstream, myString, '$'))
  {
      //used sub string for all these so it is faster for the compiler to identify each line
      if(myString.substr(0,3) == "Bio")
      {
        for(auto i = 0; i < 25; ++i)
        {
            if(biology[i] == 0)
            {
                myIstream >> biology[i] >> biology[i+1];
                myIstream.ignore();
                break;
            }
        }
      }
      else if(myString.substr(0,2) == "Co")
      {
          for(auto i = 0; i < 25; ++i)
        {
            if(compSci[i] == 0)
            {
                myIstream >> compSci[i] >> compSci[i+1];
                myIstream.ignore(999, '\n');
                break;
            }
        }
      }
     else if(myString.substr(0,2) == "Ph")
      {
          for(auto i = 0; i < 25; ++i)
        {
            if(physics[i] == 0)
            {
                myIstream >> physics[i] >> physics[i+1];
                myIstream.ignore(999, '\n');
                break;
            }
        }

      }
      else if(myString.substr(0,2) == "Ge")
      {
          for(auto i = 0; i < 25; ++i)
        {
            if(geography[i] == 0)
            {
                myIstream >> geography[i] >> geography[i+1];
                myIstream.ignore(999, '\n');
                break;
            }
        }
      }
      else if(myString.substr(0,2) == "So")
      {
          for(auto i = 0; i < 25; ++i)
        {
            if(sociology[i] == 0)
            {
                myIstream >> sociology[i] >> sociology[i+1];
                myIstream.ignore(999, '\n');
                break;
            }
        }
      }
      else if(myString.substr(0,2) == "Pr")
      {
          for(auto i = 0; i < 25; ++i)
        {
            if(propSolids[i] == 0)
            {
                myIstream >> propSolids[i] >> propSolids[i+1];
                myIstream.ignore(999, '\n');
                break;
            }
        }
      }
      else if(myString.substr(0,2) == "Ca")
      {
          for (auto i = 0; i < 25; ++i)
          {
              if(calculus[i] == 0)
              {
                  myIstream >> calculus[i] >> calculus[i+1];
                  myIstream.ignore(999, '\n');
                  break;
              }
          }
      }
  }
  cout << "Biology: ";
  for(auto i = 0; i < 25; ++i)
  {
      cout << biology[i] << " ";
  }
  cout << endl;
  cout << "Computer Science: ";
  for (auto i = 0; i < 25; ++i)
  {
      cout << compSci[i] << " ";
  }
  cout << endl;
  cout << "Physics: ";
  for(auto i = 0; i < 25; ++i)
  {
      cout << physics[i] << " ";
  }
  cout << endl;
  cout << "Geography: ";
  for(auto i = 0; i < 25; ++i)
  {
      cout << geography[i] << " ";
  }
  cout << endl;
  cout << "Sociology: ";
  for(auto i = 0; i < 25; ++i)
  {
      cout << sociology[i] << " ";
  }
  cout << endl;
  cout << "Properties of Solids: ";
  for(auto i = 0; i < 25; ++i)
  {
      cout << propSolids[i] << " ";
  }
  cout << endl;
  cout << "Calculus: ";
  for(auto i = 0; i < 25; ++i)
  {
      cout << calculus[i] << " ";
  }
  cout << endl;

 myIstream.close();


}
// TASK 2 CODE
int search(const unsigned char[], const int, const unsigned char);

void
searching()
{
  cout << "Found the value at: " << search(obfuscators, obfuscatSize, searchMe) << endl;
  cout << "end of searching" << endl;
  cin.get();
}

int search(const unsigned char obfuscators[], const int obfuscatSize, const unsigned char searchMe )
{
//Used code found on slide 83 of arrays lecture as reference for task 2
 int first = 0;
 int last = obfuscatSize - 1;
 int middle;
 int position = -1;
bool found = false;

while (!found && first <= last)
{
    middle = (first + last)/ 2;
if (obfuscators[middle] == searchMe)
{
  found = true;
  position = middle;
}
else if (obfuscators[middle] > searchMe)
  last = middle -1;
else
 first = middle +1;
}
  return position;
}


// TASK 3 CODE
void task3A();
void selectionSort(int[], int);
void selectionCalculations(int[], int);
void
sorting()
{

 task3A();
  cout << "end of sorting" << endl;
  cin.get();
}

void task3A()
{
    //Hardcoded in the array values from 1C since I could not get them to pass correctly from 1C.
    int biology[25] = {11,12,47,55,7,10,99,100};
   int compSci[25] = {75,85,12,15,75,85,100,100,99,100};
   int physics[25] = {55,55,75,75,95,100,98,100,33,35};
   int geography[25] = {95,100,95,100,95,100,95,100,95,100,95,100};
   int sociology[25] = {66,180,73,80,66,80,69,80,66,80};
   int propSolids[25] = {25,28,170,250,66,100,77,78,44,45,75,95};
   int calculus[25] = {22,25,25,25,10,90,13,70,4,50};
   //For each array I had to hardcode the size using sizeOf, because without it the mode and mean were messed up
   //because it read the zeroes and counted the mode as zero, and mean was being divided by zero so outcome was zero
   selectionSort(biology, 8);
   cout << "Biology: ";
   selectionCalculations(biology, 8);

   selectionSort(compSci, 10);
   cout << "Computer Science: ";
   selectionCalculations(compSci, 10);

   selectionSort(physics, 10);
   cout << "Physics: ";
   selectionCalculations(physics, 10);

   selectionSort(geography, 12);
   cout << "Geography: ";
   selectionCalculations(geography, 12);

   selectionSort(sociology, 10);
   cout << "Sociology: ";
   selectionCalculations(sociology, 10);

   selectionSort(propSolids, 12);
   cout << "Properties of Solid Polymers: ";
   selectionCalculations(propSolids, 12);

   selectionSort(calculus, 10);
   cout << "Calculus: ";
   selectionCalculations(calculus, 10);
}

 void selectionSort(int array[], int sizeOf)
{

    int tempMax = 0;
    int tempMin = 0;
    for(auto i = 1; i < sizeOf; i += 2)
    {

       for(auto j = i + 2; j < sizeOf; j += 2)
    {

       if(array[i] != 0 && array[j] != 0 && array[j] < array[i])
       {
           //Used code from slide 97 of Array powerpoint as reference

           tempMax = array[i];
           array[i] = array[j];
           array[j] = tempMax;

           tempMin = array[i-1];
           array[i-1] = array[j-1];
           array[j-1] = tempMin;
           //break;
       }


    }

    }
    for(auto i = 0; i < sizeOf; ++i)
    {
        cout << array[i] << " ";
    }
  cout << endl;
}

void selectionCalculations(int array[], int sizeOf)
{
    float mean;
    int median = (sizeOf/2);
    int ktr = 1;
    int prev = 0;
    int mode = array[0];
    for(auto i = 0; i < sizeOf; ++i)
    {
        mean += array[i];
    }
    mean = static_cast<float>(mean)/sizeOf;
 //was having trouble calculating mode, used this link for reference https://www.cplusplus.com/forum/beginner/116489/
    for(auto i = 1; i < sizeOf; ++i)
    {
        if (array[i] == mode)
        {
            ktr++;
        }
        else
        {
            prev++;
        }
        if (ktr < prev)
        {
            mode = array[i];
            ktr = prev;
            prev = 0;
        }
    }
    cout << "mean is " << mean << ", the median is " << array[median] << ", the mode is " << mode << endl;


}


// TASK 4 CODE
void passEncrypt();
void
cStrings()
{
    //Task 4 was extremely difficult and I had trouble properly displaying the hex values
    //so here is the best version of meeting the parameters I was able to come up with


  passEncrypt();






  cout << "end of C-strings" << endl;
  cin.get();
}

void passEncrypt()
{
     const int PASSMAX = 9;
    static char userPassword[PASSMAX];
    bool flag = false;
    char userLetter = ' ';
   // string msg = " ";
    cout << "Enter an 8 character password: ";
    cin.clear();
    cin.ignore(999, '\n');
    cin.getline(userPassword, 9);
    for(auto i = 0; i < obfuscatSize; ++i)
    {
        if(userPassword[0] == obfuscators[i])
        {
            userPassword[0] = obfuscators[i];
        }
        if(userPassword[1] == obfuscators[i])
        {
            userPassword[1] = obfuscators[i];
        }
        if(userPassword[2] == obfuscators[i])
        {
            userPassword[2] = obfuscators[i];
        }
        if(userPassword[3] == obfuscators[i])
        {
            userPassword[3] = obfuscators[i];
        }
        if(userPassword[4] == obfuscators[i])
        {
            userPassword[4] = obfuscators[i];
        }
        if(userPassword[5] == obfuscators[i])
        {
            userPassword[5] = obfuscators[i];
        }
        if(userPassword[6] == obfuscators[i])
        {
            userPassword[6] = obfuscators[i];
        }
        if(userPassword[7] == obfuscators[i])
        {
            userPassword[7] = obfuscators[i];
        }
     // const unsigned char found = obfuscators.find(userPassword[i]);
     // cout << found << " ";

    }
    cout << endl;
    	cout << "Password is: " <<hex << userPassword[0] << " " << userPassword[1] << " " << userPassword[2] << " ";
  	cout << userPassword[3] << " " << userPassword[4] << " " << userPassword[5] << " " << userPassword[6] << " ";
  	cout << userPassword[7] << endl;
  std::cout << '\n';

}
// TASK 5 CODE
void task5A();
void task5B();
void
theStrings()
{
    task5A();
    task5B();
  cout << "end of strings" << endl;
  cin.get();
}

void task5A()
{
    std::string userWord;
    bool foundOrNot = false;
    std::string foundWord;
    int ktr = 0;
    int falseKtr = 0;
    int quitOrNot = 0;
    do
    {

       foundOrNot = false;

    cout << "Press -1 to quit or anything else to continue: ";
    cin >> quitOrNot;
    if(quitOrNot != -1) //allows user to repeat word search until they wish to quit or exit.
    {


    cout << endl;
    cout << "Please enter a word you would like to search for: ";
    cin.clear();
    cin.ignore(999, '\n');
    getline(cin, userWord);
    for(auto i = 0; i < NLPsize; ++i)
    {
        //searched using a 0-3 substring because 0-2 would confuse words like
        //clouds and clique for example.
        if(userWord.substr(0,3) == NLPwords[i].substr(0,3))
        {
            foundWord = NLPwords[i];
            foundOrNot = true;

        }
        else
        {

        }

    }
    if(foundOrNot == true)
    {
        std::cout << "Matched, looks like the word is: " << foundWord << endl;
        ktr += 1;
    }
    else
    {
        std::cout << "Sorry, no match was found for the word you were looking for.";
        falseKtr += 1;
    }
    }
    }while(quitOrNot != -1);

    cout << "The number of matches today was: " << ktr << endl;
    cout << "The number of matches not found was: " << falseKtr << endl;
}

void task5B()
{
    std::string userWord;
    bool foundOrNot = false;
    std::string resetUser;
    std::string foundWord;
    int index;
    int indexSum;
    int ktr = 0;
    int quitOrNot = 0;
    do
    {
       // userWord = resetUser;
       foundOrNot = false;
    cout << "Press -1 to quit or anything else to continue: ";
    cin >> quitOrNot;
    if(quitOrNot != -1)
    {


    cout << endl;
    cout << "Please enter a word you would like to search for: ";
    //the cin.clear and cin.ignore void all previous null terminators so the user can enter a new value
    cin.clear();
    cin.ignore(999, '\n');
    getline(cin, userWord);
    for(auto i = 0; i < NLPsize; ++i)
    {
        if(userWord.substr(0,3) == NLPwords[i].substr(0,3))
        {
            foundWord = NLPwords[i];
            foundOrNot = true;
            index = i;

        }
        else
        {

        }

    }
    if(foundOrNot == true)
    {
        indexSum += index;
        ktr += 1;
    }
    else
    {
        std::cout << "Sorry, no match was found for the word you were looking for.";
        ktr += 1;
    }
    }
    }while(quitOrNot != -1);
//had to static cast because if not the integer division was not showing proper value.
    if((static_cast<float>(indexSum) / ktr) >= 10)
    {
       cout << "The NLP Score rating for today is: " << static_cast<float>(indexSum)/ktr << " which means the score is positive!" << endl;
    }
    else
    {
        cout << "The NLP Score rating for today is: " << static_cast<float>(indexSum)/ktr << " which means the score is negative." << endl;
    }




}
// TASK 6 CODE
void task6A();
void vectDisplay(vector<std::string>);
void
vectors()
{
  task6A();
  cout << "end of vectors" << endl;
  cin.get();
}


void task6A()
{
    vector<std::string> task6Vect(20);

    task6Vect.assign(NLPwords, NLPwords + 20);
    vectDisplay(task6Vect);

    task6Vect.push_back("organic fritos");
    vectDisplay(task6Vect);

    task6Vect.push_back("superb coding");
    vectDisplay(task6Vect);

    task6Vect.push_back("look up there");
    vectDisplay(task6Vect);

    task6Vect.pop_back();
    vectDisplay(task6Vect);


    auto locator = find(task6Vect.begin(), task6Vect.end(),"organic fritos");
    int locateSize = locator - task6Vect.begin();
    cout << "The index location of organic fritos is: " << locateSize << endl;
    vectDisplay(task6Vect);

    locator = find(task6Vect.begin(), task6Vect.end(), "superb coding");
    locateSize = locator - task6Vect.begin();
    task6Vect[locateSize] = "crappy coding";
    vectDisplay(task6Vect);

    task6Vect.push_back("1234567890abcdefghijklmnopqrstuvwxyz1234567890");
    vectDisplay(task6Vect);

    task6Vect.resize(task6Vect.size() + 10);
    vectDisplay(task6Vect);
}

void vectDisplay(vector<std::string> task6Vect)
{
    cout << "Size of vector is: "<<task6Vect.size() << endl;
    cout << "Max size of vector is: " << task6Vect.max_size() << endl;
    cout << "Capacity of vector is: " << task6Vect.capacity() << endl;
    cout << endl;
}

// TASK 7 CODE
typedef char* charMander;
//charMander is a user defined type named after one of the best pokemon
void displayArray(charMander* machLearn, char** islandOfMisfitToys, int sizeKtr);

void
pointers()
{
    srand(time(NULL));
    charMander machLearn[NUMSPOTS];
    for(auto i = 0; i < NUMSPOTS; ++i)
    {
        machLearn[i] = new char[SPOTSIZES[i]];
    }
    cout << "Step 1 is complete: allocations";

    for(auto i = 0; i < NUMSPOTS; ++i)
    {
        for(auto j = 0; j < SPOTSIZES[i]; ++j)
        {
            char randLetter = 97 + rand()%26;
            //here 97 is used as the ascii equivalent of 'a' and adding to it numbers 0-26
            machLearn[i][j] = randLetter;

        }
    }

    cout << "Step 2 is complete: random fill" << endl;

     char defect = 97 + rand()%26;
     int sizeKtr = 0;
     char** islandOfMisfitToys;
     //islandOfMisfitToys is the array that will hold all of the defect addresses
     for(auto i = 0; i < NUMSPOTS; ++i)
     {
         for(auto j = 0; j < SPOTSIZES[i]; ++j)
         {
             if(machLearn[i][j] == defect)
             {
                 //cout << "D, ";
                 ++sizeKtr;
                 islandOfMisfitToys = new char*[sizeKtr];
                 for(auto k = 0; k < sizeKtr; ++k)
                 {
                     islandOfMisfitToys[k] = &machLearn[i][j];
                 }

             }

         }
     }
     cout << "Step 3 complete: defects located." << endl;
     cout << "Letter that is a defect: " << defect << ", number of times found: " << sizeKtr << endl;

    displayArray(machLearn, islandOfMisfitToys, sizeKtr);


  cout << "end of pointers" << endl;
  cin.get();
}

void displayArray(charMander machLearn[NUMSPOTS], char** islandOfMisfitToys, int sizeKtr)
{
    //I was not able to figure out how to properly display the 'D' for defect in every value of the defect,
    // but the defect counter works, and everytime I run it at least one defect appears, but others may as well that do
    // not display as the capital D
    for(auto i = 0; i < NUMSPOTS; ++i)
    {
        for(auto j = 0; j < SPOTSIZES[i]; ++j)
        {
            for(auto k = 0; k < sizeKtr; ++k)
            {
                if(islandOfMisfitToys[k] == &machLearn[i][j])
            {
                machLearn[i][j] = 'D';
                break;

            }
            else
            {
                break;
            }
            }


        }
    }

              for(auto i = 0; i < NUMSPOTS; ++i)
  {
      for(auto j=0; j < SPOTSIZES[i]; ++j)
      {
          cout << machLearn[i][j] << " ";
      }

  }
}

// TASK 8 CODE
void
misc()
{
  cout << "end of miscellaneous" << endl;
  cin.get();
}









