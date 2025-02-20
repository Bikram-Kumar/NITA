#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int freq;
    Node* left;
    Node* right;
    char c;
    Node (int freq, Node* left, Node* right, char c = '\0') {
        this->freq = freq;
        this->left = left;
        this->right = right;
        this->c = c;
    }
};

void find_codes(Node* n, string label, unordered_map<char,string>& codes) {
    if (n == nullptr) return;
    if (n->c != '\0') {
        codes[n->c] = label;
        cout << n->c << ": " << label << endl;
    }
    find_codes(n->left, label + "0", codes);
    find_codes(n->right, label + "1", codes);
}

int main() {
    string s;
    cout << "Enter string to compress: ";
    cin >> s;
    unordered_map<char, int> freq;
    for (auto& c : s)  freq[c]++;
    auto cmp = [] (auto& n1, auto& n2) {
        return n1.freq > n2.freq;
    };
    priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
    for (auto& p : freq) pq.push(Node(p.second, nullptr, nullptr, p.first));
    while (pq.size() > 1) {
        auto n1 = new Node(pq.top());
        pq.pop();
        auto n2 = new Node(pq.top());
        pq.pop();
        Node* node = new Node(n1->freq + n2->freq, n1, n2);
        pq.push(*node);
    }
    Node n = pq.top();
    unordered_map<char,string> codes;
    cout << "Huffman Codes:\n";
    find_codes(&n, "", codes);

    cout << "Original string: " << s << "\nEncoded string: ";
    int orgBits = s.size() * 8, newBits = 0;
    for (auto& c : s) {
        cout << codes[c];
        newBits += codes[c].size();
    }
    cout << "\nOriginal bits: " << orgBits << endl;
    cout << "New bits: " << newBits << endl;
    cout << "Compression: " << 100 - ((float)newBits / orgBits * 100) << "%" << endl;


    return 0;
}