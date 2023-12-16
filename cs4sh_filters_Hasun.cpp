#include <iostream>
#include <fstream>
#include <cmath> // included to give us access to the abs() function.
using namespace std;

int max_data_size = 100; // maximum amount of rows that this program would read from a file.
float threshold = 0.2; // threshold value used to determine if we are close to the -3dB value


// Created a structure called data_structure, that has two fields: The first field is called freq and is of
// integer type and the second field is called magResp of floating point number type.
struct data_structure{
       int freq;
       float magRep;
};


// The next statement is a function declaration for a function that is defined below the main function.
data_structure analyse_data(data_structure data[]);
void displayData(data_structure dataArray[]);
//This outputs the display


int main() {
    
    // I will  Create an array that has  max_data_size number of elements, each of which is of type data_structure. Hence, each of
    // the elements in my  created array will have two fields (freq and magResp).
    data_structure dataArray[max_data_size];{
    
    // Initialising all frequencies in your array to -1 and initialising  all magnitude responses in your array to -1000.
    // I am doing this because it is good practice to initialise data to a value that would be obviously identifiable
    // as being the default we set and not a valid value. -1000 dB is a severe attenuation that could as well be
    // considered as -infinity. Realistically, -1000 dB corresponds to the output being 100 times smaller than the
    // input, but that sufficies for us.
    for (int i = 0; i < max_data_size; i++){
        dataArray[i].freq = -1;
        //This initiliases the frequency as -1
        dataArray[i].magRep = -1000;
        //This initiliase the magnitude response
    }
}
    
    // Display a welcome message
    cout << "welcome to the program";

    
    // Prompts the user to enter a file name
    // This receives the filename from the user and open the file
    
    cout << "Enter the CSV file name:";
    string fileName;
    cin >> fileName;
    //This asks the user to input a file name
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cerr << "Failed to open the file.";
        return 1; // Exit the program with an error code
        //If the file doesnt open return 1
        }
    //This will initiliase the datacount and check if its in the file 
    int dataCount = 0;
    while (dataCount < max_data_size && inputFile.good()) {
        inputFile >> dataArray[dataCount].freq;
        inputFile.ignore(1, ','); // Skip the comma
        inputFile >> dataArray[dataCount].magRep;
        //inputFile.ignore(); // Skip the newline character

        dataCount++;
        //This increments the data count and checks all the values 
    }

    for (int i = dataCount; i < max_data_size; i++) {
        dataArray[i].freq = -1;
        dataArray[i].magRep = -1000;}
        //this checks all the values that are less then the maximum data size and intiiliases the freq and magRep
    for(int i = 0; i < dataCount; i++) {
        std::cout << "Frequency: " << dataArray[i].freq << ", Magnitude Response: " << dataArray[i].magRep << std::endl;
        //Displays the frequency and the magnitude response
    }
    inputFile.close();




    
    

    displayData(dataArray);
    //Displays the data in the array
    // Call the function analyse_data to find the cutoff point and display a message to the user specifying what the
    // cutoff point (i.e. the frequency of the cutoff point), and the magnitude response at that point.
    // Note that a constant called threshold was defined above and used in the function. The threshold covers for
    // the fact that measurements we are looking for a value that is close enough to the -3db point - in this case,
    // within 0.2 dB of the actual -3dB point
    data_structure results = analyse_data(dataArray);
    //This calls the data array
    cout << "\ncut off frequency " << results.freq;
    cout << "\nmagnitude at the cutoff " << results.magRep;
    //Outputs the frequency and the magnitude at the cut off

    
    // Displays a closing message to the user
    cout << "\nThe program has ended";

}






data_structure analyse_data(data_structure data[])
{
    data_structure cut_off_point = data[0]; // Initialise the cut off point to the first element of the array - this
    // will be returned if no cutoff point is found.
    float max_magnitude_response = data[0].magRep; // initialise the maximum mangnitude response to be the first element.
    // And then compare the other magnitude responses to the first to see if any is larger. If any is larger, then
    // replace the max_magnitude_response and compare the others against the new maximum.




    
    // Searches through "data" to find the maximum magnitude response value and save the maximum response value as
    // max_magnitude_response.


   float cut_off_magnitude = max_magnitude_response - 3;
    for (int i = 0; i < max_data_size; i++){
        //cout << abs(data[i].magResp - cut_off_magnitude) << endl;
        // You can choose to uncomment the line above to see the values being gotten here and hence see if it is
        // converging towards a solution. It may be useful for debugging purposes.
        if (abs(data[i].magRep - cut_off_magnitude) <= threshold){
            //Checks if the value is less than the threshold
            cut_off_point = data[i];
            break;
        }
    }

    return cut_off_point;
}


// Create a function that displays the data in your data array. This funciton is called by your main function (i.e. TODO 6)
void displayData(data_structure dataArray[])
{
    for (int i = 0; i < max_data_size; i++) {
        std::cout << "Frequency: " << dataArray[i].freq << ", Magnitude Response: " << dataArray[i].magRep << std::endl;
        //This displays the frequency and the magnitude response and checks all the values less then the maximum data size
    }
}
