#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to determine the article ("a" or "an") for a given word
//getArticle made at first because it would be outofscope ..if getreplacement is made earlier.. MY first mistake there
string getArticle(const string &word) {
    if (word.empty()) {
        return "a";
    }
    char firstChar = tolower(word[0]);
    if (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u') {
        return "an";
    }
    return "a";
}

// Function to prompt the user for a replacement word based on the label
string getReplacement(const string &label) {
    string replacement;
    cout << "Enter " << getArticle(label) << " " << label << ": ";
    cin.ignore(); 						// Ignore newline character from previous input.. just to be safe
    getline(cin, replacement); 			
    return replacement;
}



void generateMadLib(string &madLib, const vector<string> &labels) {
    size_t startPos = 0; 							//just an unsigned integer for indexing our arrays
    int labelIndex = 0;
    while ((startPos = madLib.find("REPLACE", startPos)) != string::npos) {
        if (labelIndex < labels.size()) {
            string replacement = getReplacement(labels[labelIndex]);
            madLib.replace(startPos, 7, replacement); // Replace "REPLACE" with the user's input
            startPos += replacement.length();
            labelIndex++;
        } else {
            cerr << "Not enough labels for replacements." << endl;
            break;
        }
    }
}

int main() {
    string choice;
    string madLibsFile;
    string labelFile;
 retry:   					//used goto-label to create a effect of loop incase failed proper input..
    cout << "Choose a Mad Libs template. Enter the word (Accident/Shopping/Trip): " << endl;
    cout << "1. Accident" << endl;
    cout << "2. Shopping" << endl;
    cout << "3. Trip" << endl;
    
    getline(cin, choice);

    if (choice == "Accident" || choice == "Shopping" || choice == "Trip") {
        madLibsFile = choice + ".txt";
        labelFile = choice + "_labels.txt";
    } else {
        cout << "Please Enter the Spelling as shown in the Menu.\n\n" << endl;
        goto retry;
    }

    ifstream templateFile(madLibsFile);
    ifstream labelFileStream(labelFile);

    if (!templateFile.is_open() || !labelFileStream.is_open()) {
        cout << "Error: Unable to open the template or label file." << endl;
        return 1;
    }

    string templateText;
    getline(templateFile, templateText);

    vector<string> labels;
    string label;
    while (getline(labelFileStream, label)) {
        labels.push_back(label);
    }

    generateMadLib(templateText, labels);		//calling function to generate our output

    cout << "Completed Mad Libs Story:" << endl;
    cout << templateText << endl;

    templateFile.close();
    labelFileStream.close();

    return 0;
}
