#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

const int Buff_Size=100;
int main()
{
    char Freq_File_Name[20], IR_Inten_File_Name[20], Points_File_Name[20], Data_Buffer[Buff_Size];
  //  double Frequencies[Num_Count], IR_Inten[Num_Count];
    int Freq_Count=0, IR_Inten_Count=0;
    int Num_Count; 

    //Get filename from input
    cout << "Please enter frequency file name: ";
    cin >> Freq_File_Name;
    cout << "Please enter IR intensity file name: ";
    cin >> IR_Inten_File_Name;
    cout << "Please enter output file name: ";
    cin >> Points_File_Name;
    cout << "Please enter number of points: ";
    cin >> Num_Count;
  
    double Frequencies[Num_Count], IR_Inten[Num_Count];

    //Input from files
    ifstream Freq_Input;
    Freq_Input.open(Freq_File_Name);

    ifstream IR_Inten_Input;
    IR_Inten_Input.open(IR_Inten_File_Name);

    //Initialize output stream
    ofstream Points_File;
    Points_File.open(Points_File_Name, ios::app);
/*
    //Declare stringstreams
    stringstream Freq_Stream;
    stringstream IR_Inten_Stream; 
*/
    while(Freq_Input.good()== false)
    {
    cout << "Unable to open frequency file. Enter a new name: ";
    cin >> Freq_File_Name;
    // Clear the file stream
    Freq_Input.clear();
    Freq_Input.open(Freq_File_Name);
    }
 
    while(IR_Inten_Input.good()== false)
    {
    cout << "Unable to open IR intensity file. Enter a new name: ";
    cin >> IR_Inten_File_Name;
    // Clear the file stream
    IR_Inten_Input.clear();
    IR_Inten_Input.open(IR_Inten_File_Name);
    }
/*
    for(int Freq_Count=0;Freq_Count<150; Freq_Count++)
    {
    Freq_Input.getline(Data_Buffer, 10, ' ');
    Freq_Stream << Data_Buffer; 

//    ws(Freq_Stream);
    Freq_Stream.getline(Data_Buffer, 10, ' ');
    Frequencies[Freq_Count]= atof (Data_Buffer);
    } 

    for(int IR_Inten_Count=0;IR_Inten_Count<150; IR_Inten_Count++)
    {
    IR_Inten_Input.getline(Data_Buffer, 10, ' ');
    IR_Inten_Stream << Data_Buffer;

    ws(IR_Inten_Stream);
    IR_Inten_Stream.getline(Data_Buffer, 10, ' ');
    IR_Inten[IR_Inten_Count]= atof (Data_Buffer);
    }
*/

    while(!Freq_Input.eof())
    {
    Freq_Input >> Frequencies[Freq_Count];
    Freq_Count++;
    } 

    while(!IR_Inten_Input.eof())
    {
    IR_Inten_Input >> IR_Inten[IR_Inten_Count];
    IR_Inten_Count++;

    }
    
    for(int i=0;i<Num_Count;i++)
    {
    Points_File << Frequencies[i] << " " << IR_Inten[i] << endl;

    }

    Freq_Input.close();
    IR_Inten_Input.close();
    Points_File.close();





return 0;
}
