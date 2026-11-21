#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger {
public:
    virtual void write(const string& msg) = 0;
    virtual ~Logger() {}
};

class ConsoleLogger : public Logger {
public:
    void write(const string& msg) override {
        cout << "[Console] " << msg << endl;
    }
};

class FileLogger : public Logger {
    ofstream file;
public:
    FileLogger(const string& filename) : file(filename, ios::app) {}
    void write(const string& msg) override {
        if (file) file << "[File] " << msg << endl;
    }
};

int main() {
    Logger* logger = new ConsoleLogger();
    logger->write("Starting up...");
    delete logger;

    // Switch at runtime
    logger = new FileLogger("app.log");
    logger->write("Logged to file!");
    delete logger;

    cout << "Done (check app.log for file output)\n";
    return 0;
}