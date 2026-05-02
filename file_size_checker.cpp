#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to get file size
long long getFileSize(const string& filename) {
    ifstream file(filename, ios::binary | ios::ate);
    if (!file.is_open()) {
        return -1;
    }
    return file.tellg();
}

// Function to format size
string formatSize(long long bytes) {
    if (bytes < 1024) {
        return to_string(bytes) + " Bytes";
    } else if (bytes < 1024 * 1024) {
        double kb = bytes / 1024.0;
        return to_string(kb).substr(0, 5) + " KB";
    } else if (bytes < 1024 * 1024 * 1024) {
        double mb = bytes / (1024.0 * 1024);
        return to_string(mb).substr(0, 5) + " MB";
    } else {
        double gb = bytes / (1024.0 * 1024 * 1024);
        return to_string(gb).substr(0, 5) + " GB";
    }
}

int main() {
    string filename;
    
    cout << "================================" << endl;
    cout << "   📁 File Size Checker in C++  " << endl;
    cout << "================================" << endl;
    
    cout << "\nEnter filename: ";
    cin >> filename;
    
    long long size = getFileSize(filename);
    
    if (size == -1) {
        cout << "\n❌ Error: File not found!" << endl;
        cout << "Please check the filename and try again." << endl;
    } else {
        cout << "\n✅ File found!" << endl;
        cout << "📁 Filename : " << filename << endl;
        cout << "📏 Size     : " << formatSize(size) << endl;
        cout << "📊 Bytes    : " << size << " bytes" << endl;
    }
    
    cout << "\n================================" << endl;
    
    return 0;
}
