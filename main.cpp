#include <iostream>
#include <string>
using namespace std;
#include <regex>
#include <fstream>
#include <vector>
class Course {
private:
    int CourseID;
    int CourseNumber;
    string CourseName;
    string Description;
    string Date;
    std::string courseName;

public:
    Course(int id, const std::string &name) : CourseID(id), courseName(name) {}
    void setCourseID(int newCourseID) {
        srand((unsigned) time(NULL));
        CourseID = newCourseID;

        // Get a random number
        int CourseID = rand();

        // Print the random number
        cout<<"This is your course id"<< CourseID << endl;
    }
    int getCourseID() const { return CourseID; }

    void setCourseNumber(int newCourseNumber) {
         CourseNumber = newCourseNumber;

    }

    int getCourseNumber() const { return CourseNumber; }

    void setCourseName(const string& coursename) {
        CourseName = coursename;
        cout << "This is your coursename";
    }
    string getCourseName() const {
            return CourseName;
    }

    void setDescription(const string& newDescription) { Description = newDescription; }
    string getDescription() const { return Description; }

    void setDate(const string& newDate) { Date = newDate; }
    string getDate() const { return Date; }




};
vector<Course> loadCourses(const std::string &filename) {
    vector<Course> courses;
    ifstream file(filename, ios::binary);

    if (!file.is_open()) {
        cerr << "Could not open the file " << filename << endl;
        return courses;  // Return an empty vector if file cannot be opened
    }

    while (true) {
        int id;
        size_t nameLength;
        string name;

        // Read course ID
        if (!file.read(reinterpret_cast<char*>(&id), sizeof(id))) break;

        // Read name length
        if (!file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength))) break;

        // Resize name string to expected length and read name
        name.resize(nameLength);
        if (!file.read(&name[0], nameLength)) break;

        // Add the course to the vector
        courses.emplace_back(id, name);
    }

    file.close();
    return courses;
}

class User : public Course {
private:
    int UserID;
    string UserName;
    string Password;
    string Email;
    string Role;

public:
    void setUserID(int newUserID) { UserID = newUserID; }
    int getUserID() const { return UserID; }

    void setUserName(const string& newUserName) {

        string userNameToValidate = newUserName;

            // Remove non-alphabet characters from the input
        string cleanedUserName = "";
        for (char c : userNameToValidate) {
             if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                    cleanedUserName += c;
                }
        }

            // Check if cleanedUserName meets criteria: contains alphabet characters and is under 15 chars
        if (!cleanedUserName.empty() && cleanedUserName.length() <= 15) {
                UserName = cleanedUserName; // Save the cleaned username
                cout << "Welcome Dr. " << cleanedUserName << endl;
        } else {
                // If invalid, prompt to try again
                cout << "This is invalid. Please enter a username with only alphabetic characters (a-z or A-Z) and max 15 characters." << endl;
                cout << "Enter your username: ";

                // Read new input for the next validation
                cin >> userNameToValidate;
        }
    }


    string getUserName() const {
        return UserName;
    }

    void setPassword(const string& newPassword) { Password = newPassword; }
    string getPassword() const { return Password; }

    void setEmail(const string& newEmail) { Email = newEmail; }
    string getEmail() const { return Email; }

    void setRole(const string& newRole) { Role = newRole; }
    string getRole() const { return Role; }
};

class Assignment : public User {
private:
    int AssignmentID;
    string Title;
    string DueDate;
    string Instructions;

public:
    void setAssignmentID(int newAssignmentID) { AssignmentID = newAssignmentID; }
    int getAssignmentID() const { return AssignmentID; }

    void setTitle(const string& newTitle) { Title = newTitle; }
    string getTitle() const { return Title; }

    void setDueDate(const string& newDueDate) { DueDate = newDueDate; }
    string getDueDate() const { return DueDate; }

    void setInstructions(const string& newInstructions) { Instructions = newInstructions; }
    string getInstructions() const { return Instructions; }
};

class Module : public Course {
private:
    int ModuleID;
    string Title;
    string DueDate;
    string Instructions;

public:
    void setModuleID(int newModuleID) { ModuleID = newModuleID; }
    int getModuleID() const { return ModuleID; }

    void setTitle(const string& newTitle) { Title = newTitle; }
    string getTitle() const { return Title; }

    void setDueDate(const string& newDueDate) { DueDate = newDueDate; }
    string getDueDate() const { return DueDate; }

    void setInstructions(const string& newInstructions) { Instructions = newInstructions; }
    string getInstructions() const { return Instructions; }
};

class Resources : public Module {
private:
    int ResourceID;
    string Title;
    string FileType;
    string Content;

public:
    void setResourceID(int newResourceID) { ResourceID = newResourceID; }
    int getResourceID() const { return ResourceID; }

    void setTitle(const string& newTitle) { Title = newTitle; }
    string getTitle() const { return Title; }

    void setFileType(const string& newFileType) { FileType = newFileType; }
    string getFileType() const { return FileType; }

    void setContent(const string& newContent) { Content = newContent; }
    string getContent() const { return Content; }
};

class Quiz : public Module {
private:
    int QuizID;
    string Questions;
    float TimeLimit;

public:
    void setQuizID(int newQuizID) { QuizID = newQuizID; }
    int getQuizID() const { return QuizID; }

    void setQuestions(const string& newQuestions) { Questions = newQuestions; }
    string getQuestions() const { return Questions; }

    void setTimeLimit(float newTimeLimit) { TimeLimit = newTimeLimit; }
    float getTimeLimit() const { return TimeLimit; }
};

class GradeBook : public Quiz {
private:
    int GradeID;
    float Score;
    string Gradebook;

public:
    void setGradeID(int newGradeID) { GradeID = newGradeID; }
    int getGradeID() const { return GradeID; }

    void setScore(float newScore) { Score = newScore; }
    float getScore() const { return Score; }

    void setGradebook(const string& newGradebook) { Gradebook = newGradebook; }
    string getGradebook() const { return Gradebook; }
    float calculateScore(string userAnswers)
    {
       // if (userAnswers.size() != Answers.size())
        {
            return 0.0; // Incorrect number of answers
        }
        float correctAnswers = 0;
        //for(size_t i = 0; i < Answers.size(); i++)
        {
            //if(userAnswers[i] == Answers[i])
            {
                correctAnswers++;
            }
        }
       // Score = (correctAnswers/Answers.size()) * 100.0;
        return Score;
    }
};

int main() {
    // Example object creation and setting values this is for testing
        //Course course;
       // course.setCourseID(101);
        //course.setCourseName("Introduction to Programming");
       // course.setCourseNumber(1);
       // course.setDescription("A beginner course in programming.");
       // course.setDate("2023-09-01");
       // cout << "Course ID: " << course.getCourseID() << endl;
      //  cout << "Course Name: " << course.getCourseName() << endl;
       // cout << "Course Number: " << course.getCourseNumber() << endl;
      //  cout << "Description: " << course.getDescription() << endl;
        //cout << "Date: " << course.getDate() << endl;
        bool status = true;
        while (status) {
            User user;
            int options;
            string lecturername;
            string start;
            cout << "Press Y for yes" << endl;
            cout << "Press N for no" << endl;
            cout << "Would you like to start:" << endl;
            cin >> start;

            if (start == "Y" || start == "y") {
                cout << "Welcome to the student management system!" << endl;

                cout << endl;
                cout << "What is your role" << endl;
                cout << "Press 1 if you are a lecturer" << endl;
                cout << "Press 2 if you are a student" << endl;
                cout << "Press anything else if you are anything else:" << endl;
                cin >> options;
                if (options == 1) {
                    int lectureroptions;
                    cout << "Welcome to the program lecturer" << endl;
                    cout << "Please choose from the following options" << endl;
                    cout << "Press 1 if you want to manage the courses" << endl;
                    cout << "Press 2 if you want to manage the users" << endl;
                    cout << "Press 3 if you want to manage the Assignments" << endl;
                    cout << "Press 4 if you want to manage the Modules" << endl;
                    cout << "press 5 if you want to manage the Resources" << endl;
                    cout << "press 6 if you want to manage the Quiz" << endl;
                    cout << "press 7 if you want to manage the GradeBook" << endl;
                    cout << "please make sure all inputs are no numbers and characters just text" << endl;
                    cout <<"Enter your choice";
                    cin >> lectureroptions;
                    if (lectureroptions == 1) {
                        vector<Course> ManageCourses;
                        const string filename = "managecourses.dat";
                        ManageCourses = loadCourses(filename);
                        int choice;
                        do {
                            std::cout << "\nCourse Management System\n";
                            std::cout << "1. Add Course\n";
                            std::cout << "2. Edit Course\n";
                            std::cout << "3. Display Courses\n";
                            std::cout << "4. Save and Exit\n";
                            std::cout << "Enter choice: ";
                            std::cin >> choice;

                            switch (choice) {
                                case 1:
                                    addCourse(courses);
                                break;
                                case 2:
                                    editCourse(courses);
                                break;
                                case 3:
                                    displayCourses(courses);
                                break;
                                case 4:
                                    saveCourses(courses, filename);
                                std::cout << "Courses saved. Exiting...\n";
                                break;
                                default:
                                    std::cout << "Invalid choice. Please try again.\n";
                            }
                        } while (choice != 4);

                        return 0;
                    }


                    }
                    if (lectureroptions == 2) {
                        cout << "Enter your lecturer name:" << endl;
                        cin >> lecturername;
                        user.setUserName(lecturername);
                        user.getUserName();

                    }
                    if (lectureroptions == 3) {

                    }
                    if (lectureroptions == 4) {

                    }
                    if (lectureroptions == 5) {

                    }
                    if (lectureroptions == 6) {

                    }
                    if (lectureroptions == 7) {

                    }
                    else {

                    }








                }
                else if (options == 2) {
                    int studentcourses;
                    cout << "Welcome student!" << endl;
                    int lectureroptions;
                    cout << "Welcome to the program lecturer" << endl;
                    cout << "Please choose from the following options" << endl;
                    cout << "Press 1 if you want to manage the courses" << endl;
                    cout << "Press 2 if you want to manage the users" << endl;
                    cout << "Press 3 if you want to manage the Assignments" << endl;
                    cout << "Press 4 if you want to manage the Modules" << endl;
                    cout << "press 5 if you want to manage the Resources" << endl;
                    cout << "press 6 if you want to manage the Quiz" << endl;
                    cout << "press 7 if you want to manage the GradeBook" << endl;
                    cout << "please make sure all inputs are no numbers and characters just text" << endl;
                    cout <<"Enter your choice";
                    cin >> lectureroptions;
                    if (lectureroptions == 1) {
                        cout << "Enter the courses you would like to manage";

                    }
                    if (lectureroptions == 2) {
                        cout << "Enter your lecturer name:" << endl;
                        cin >> lecturername;
                        user.setUserName(lecturername);
                        user.getUserName();

                    }
                    if (lectureroptions == 3) {

                    }
                    if (lectureroptions == 4) {

                    }
                    if (lectureroptions == 5) {

                    }
                    if (lectureroptions == 6) {

                    }
                    if (lectureroptions == 7) {

                    }
                    else {

                    }

                }
                else {
                    cout << "Welcome visitor!" << endl;
                    int lectureroptions;
                    cout << "Welcome to the program lecturer" << endl;
                    cout << "Please choose from the following options" << endl;
                    cout << "Press 1 if you want to manage the courses" << endl;
                    cout << "Press 2 if you want to manage the users" << endl;
                    cout << "Press 3 if you want to manage the Assignments" << endl;
                    cout << "Press 4 if you want to manage the Modules" << endl;
                    cout << "press 5 if you want to manage the Resources" << endl;
                    cout << "press 6 if you want to manage the Quiz" << endl;
                    cout << "press 7 if you want to manage the GradeBook" << endl;
                    cout << "please make sure all inputs are no numbers and characters just text" << endl;
                    cout <<"Enter your choice";
                    cin >> lectureroptions;
                    if (lectureroptions == 1) {


                    }
                    if (lectureroptions == 2) {
                        cout << "Enter your lecturer name:" << endl;
                        cin >> lecturername;
                        user.setUserName(lecturername);
                        user.getUserName();

                    }
                    if (lectureroptions == 3) {

                    }
                    if (lectureroptions == 4) {

                    }
                    if (lectureroptions == 5) {

                    }
                    if (lectureroptions == 6) {

                    }
                    if (lectureroptions == 7) {

                    }
                    else {

                    }
                }
            }

        }


        return 0;
}






