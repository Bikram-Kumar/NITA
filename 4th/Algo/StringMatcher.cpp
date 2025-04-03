#include <iostream>
using namespace std;

int naiveMatch(string& text, string& pattern) {
    int tlen = text.size(), plen = pattern.size();
    for (int i = 0; i <= tlen - plen; i++) {
        for (int j = 0; j < plen; j++) {
            if (text[i+j] != pattern[j]) break;
            if (j == plen-1) return i;
        }
    }
    return -1;
}


int main() {
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;
    int i = naiveMatch(text, pattern);
    
    if (i == -1) cout << "No match found!\n";
    else cout << "Match found at index " << i << endl;

    return 0;
}