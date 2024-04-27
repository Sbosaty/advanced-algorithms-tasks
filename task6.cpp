#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Function to wrap text based on the specified width
vector<string> wrapText(const string& text, int lineWidth) {
    istringstream words(text);
    string word;
    vector<string> wrappedText;
    string currentLine;

    while (words >> word) {
        if (currentLine.length() + word.length() + 1 > lineWidth) {  // Check if adding this word would exceed line width
            wrappedText.push_back(currentLine);
            currentLine = word;  // Start a new line with the current word
        } else {
            if (!currentLine.empty()) {
                currentLine += " ";  // Add a space before the word if it's not the first word on the line
            }
            currentLine += word;
        }
    }
    if (!currentLine.empty()) {
        wrappedText.push_back(currentLine);  // Add the last line
    }

    return wrappedText;
}

//  demonstrateing the text wrapper
int main() {
    string text = "Mary loves to sing and perform tap dancing.";
    int lineWidth = 10;
    vector<string> lines = wrapText(text, lineWidth);

    // Print wrapped text
    int lineCount = 1;
    for (const string& line : lines) {
        cout << "Line " << lineCount++ << ": " << line << endl;
    }

    return 0;
}
