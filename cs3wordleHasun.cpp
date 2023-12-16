
//Includes all the libraries
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;
//Uses the std function
// Declare functions
bool checkIfAlphabet(char c);

char charToUpper(char c);
int checkCharInWord(string s, char c);

// Main Function
int main(){

    // Creates an empty string variable to hold the wordForTheDay
    string wordForTheDay = "";

    // This section of the code selects a random word from the text file called words.txt
    ifstream f_words("words.txt");  // Create a variable called f_words that is an input file
    if (f_words.is_open()) {// if f_words was successfully opened then read it and select a random word from it.
        srand(time(NULL));       // Seed the random number generator
        int word_idx = rand() %
                       8;          // Generate a random number between 0 and 8. Maximum number is 8 because there are only 8 words.
        for (int i = 0;
             i < word_idx; i++) {  // Very lazy way of reading the word on the word_idx line. Actually it will
            // read all lines but when loop exits the current word in memory will be word desired.
            getline(f_words, wordForTheDay);
        }
        f_words.close(); // Close the file stream
        } else { // If f_words was not successfully opened, then inform the user and exit the program.
         cout << "Error opening words.txt\n";
         return 1;
    }

    
    // Display some introductory message to the game
    // Prompt the user to enter a guess and save the guess as a string variable called "guess".
    cout << "Welcome to the Program:" << "\n";
    cout << "Enter a guess to the wordle:";
    string guess;
    cin >> guess;
    // Iterate over all the characters in guess and check if there is any character that is not an alphabet.
    // If there is no non-alphabet in guess, then convert all alphabets in guess to upper case.
    char c;
    // If there is non-alphabet in guess, then display a message to the user and exit the program.
    for (int j = 0; j < guess.length(); j++) {
        guess[j] = charToUpper(guess[j]);
        //char c = guess[j]; 
        if (!checkIfAlphabet(guess[j])) {
            cout << "Invalid character in your entry.";
            return 0;
            //This returns false if their is nothing in the entry
        }
        // c = charToUpper(guess[j]); // Convert to uppercase
    }


    // Check for positions of characters in Guess
    int position = -1;
    //This initiliases the position as -1
    int count = 0;
    //This initiliases the count as 0
    for (int i = 0; i < guess.length(); i++){
        //Iterates all the values in the position
        char c = guess[i];
        //defines c as an element in guess
        cout << "Checking " << c << "... \n";
        //checks for all elements
        position = checkCharInWord(wordForTheDay, c);
        //Checks position in the function
        if (position == -1){
            cout << c << " does not appear in the word for the day.\n";
            //This displays that it does not appear in the word for the day
        }
        else{
            if (c == wordForTheDay[i]){
                cout << c << " appears in position " << position << ".\n\n";
                //This appeares in the position
                count = count + 1;
                //This iterates the count
            }
            else{
                cout << c << " is in the word, but not in position " << i << ".\n\n";
            } //Checks if it is in the word but not in position
        }





    

        
    

    string correctLocation; // Initialize an empty string to store correct characters
    bool correct = true;
    //This defines correct and checks if it is in the correct location
    for (int k = 0; k < guess.length(); ++k) {
        //This iterates for all values and checks that it is range
        char c = guess[k];
        //Defines c as a position in guess
        int position = checkCharInWord(wordForTheDay, c);
        //Defines position as checked in the word
        if (position != k) {
            //If the position is not in the iterator 
            correctLocation += c; // Adds the correctly guessed character to the correctLocation string
            correct = false;
            //This declares its not in the correct position
        }
        
    
        
    }
    
        
        
        if (correct) {
            cout << "You have found the word for today: " << wordForTheDay;
            //This displays that you have found the word for today
        } else {
            cout << "Sorry,guess was incorrect.";
            //else This displays the message that the guess was incorrect
        } 
    }  
}





// Define checkIfAlphabet
bool checkIfAlphabet(char c){
    
    // This function should return true if c is an alphabet (upper or lower case) and it should
    // return false if c is not an alphabet. Hence, checkIfAlphabet('a') should return true and
    // checkIfAlphabet('7') should return false.
    
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        //This returns the function is true if c is a alphabet involved
        return true; 
    } else {
        return false; 
        //else it will return False
    }
}



// Define charToUpper
char charToUpper(char c){
      
    // This function should return the uppercase version of any alphabet sent in to it. Hence
    // charToUpper('a') should return 'A', and charToUpper('q') should return 'Q'. If the
    // character passed into the function is an upper case character then it should just return
    // that same character untouched i.e. charToUpper('Q') should return 'Q'.
    //int uppercase = 'a' - 'A';
    
    if (c >= 'a' && c <= 'z'){
        //This checks if the character is in between the the letters in the alphabet
        return c - 32;
        //This returns the uppercase version of the alphabet involved
    }
    else 
    {
        //If  the letters is uppercase it returns the uppercase letter 
        return c;
    }
    

}
// Define checkCharInWord
int checkCharInWord(string s, char c){
    // This function is to check the position of c in s. For example, if c = 'r' and s = "royal"
    // then checkCharInWord("royal", 'r') should return 0 and checkCharInWord("royal", 'a') should
    // return 3. If c does not exist in s then it should return a value of -1. Hence,
    // checkCharInWord("royal", 'p') should return -1.
    int position = -1;
    //This initiliases the position as -1
    for (int l=0;l < s.length();++l){
        //This iterates through a loop and finds what is intended
        if (s[l] == c){
            position = l;
            break;
           
        }
    }
    return position;
}
