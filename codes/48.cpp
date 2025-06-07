#include <iostream>
#include <vector>
using namespace std;

class LogTable {
private:
    vector<int> log;

public:
    LogTable(int n) {
        log.resize(n + 1);
        log[1] = 0;
        for (int i = 2; i <= n; i++)
            log[i] = log[i / 2] + 1;
    }

    int getLog(int x) const {
        return log[x];
    }

    int operator[](int x) const {
        return log[x];
    }
};

