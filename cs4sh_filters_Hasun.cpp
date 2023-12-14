#include <iostream>
#include <fstream>
#include <cmath> // included to give us access to the abs() function.
using namespace std;

int max_data_size = 100; // maximum amount of rows that this program would read from a file.
float threshold = 0.2; // threshold value used to determine if we are close to the -3dB value

//TODO 1:
// Create a structure called data_structure, that has two fields: The first field should be called freq and be of
// integer type and the second field should be called magResp of floating point number type.
struct data_structure{
       int freq;
       float magRep;
};


// The next statement is a function declaration for a function that is defined below the main function.
data_structure analyse_data(data_structure data[]);
void displayData(data_structure dataArray[]);
//This outputs the display


int main() {
    //TODO 2:
    // Create an array that max_data_size number of elements, each of which is of type data_structure. Hence, each of
    // the elements in your created array will have two fields (freq and magResp).
    data_structure dataArray[max_data_size];{
    //TODO 3:
    // Initialise all frequencies in your array to -1 and initialise all magnitude responses in your array to -1000.
    // We are doing this because it is good practice to initialise data to a value that would be obviously identifiable
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
    //TODO 4:
    // Display a welcome message
    cout << "welcome to the program";
    //TODO 5:
    // Prompt the user to enter a file name
    // Receive the filename from the user and open the file
    // Read the contents of the file, assuming that it is a csv file with the specifications described on Moodle.
    // While reading the contents of the file, enter them into your array. You should fill up your array in such a way
    // that the first row in the file would correspond to the first element of your array, the second to your second, etc.
    // If the file has more than max_data_size rows, stop at the max_data_size'th row. Note that for this template file
    // given to you, max_data_size is defined to be 100. When testing your code, we may set it to be a different value
    // so ensure to use max_data_size and not just enter 100 in your code file. If the csv file has fewer than 100 rows
    // then your program should read all the lines and the rest of the elements of the array should remain as -1 and
    // -1000 respectively.
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




    //TODO 6:
    // Call a function here to display your array after you have read in the csv file and stored it in the array variable
	// i.e. The function it will call is TODO 10 below.

    displayData(dataArray);
    //Displays the data in the array
    //TODO 7:
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

    //TODO 8:
    // Display a closing message to the user
    cout << "\nThe program has ended";

}





// Note that some part of this functio is written for you but you are to write some part of it.
data_structure analyse_data(data_structure data[])
{
    data_structure cut_off_point = data[0]; // Initialise the cut off point to the first element of the array - this
    // will be returned if no cutoff point is found.
    float max_magnitude_response = data[0].magRep; // initialise the maximum mangnitude response to be the first element.
    // And then compare the other magnitude responses to the first to see if any is larger. If any is larger, then
    // replace the max_magnitude_response and compare the others against the new maximum.




    //TODO 9:
    // Search through "data" to find the maximum magnitude response value and save the maximum response value as
    // max_magnitude_response.



    // The following code is simple but I chose to write it for you because I wanted to use the abs() funciton that
    // is found in the cmath library and those new to C++ may not know about this. What the abs() function does is to
    // return the positive value of whatever argument you supply to it. Hence, abs(-3) will return 3 and abs(3) would
    // also return 3.
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

//TODO 10:
// Create a function that displays the data in your data array. This funciton is called by your main function (i.e. TODO 6)
void displayData(data_structure dataArray[])
{
    for (int i = 0; i < max_data_size; i++) {
        std::cout << "Frequency: " << dataArray[i].freq << ", Magnitude Response: " << dataArray[i].magRep << std::endl;
        //This displays the frequency and the magnitude response and checks all the values less then the maximum data size
    }
}