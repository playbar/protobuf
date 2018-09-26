//
// Created by hou guoli on 2018/9/26.
//

#include "helloworld.pb.h"
#include "iostream"
#include "fstream"
using namespace std;

void ListMsg(const lm::helloworld & msg) {
    cout << msg.id()  << endl;
    cout << msg.str() << endl;
    cout << msg.opt() << endl;
}

int main(int argc, char* argv[]) {

    lm::helloworld msg1;

    {
        fstream input("./log", ios::in | ios::binary);
        if (!msg1.ParseFromIstream(&input)) {
            cerr << "Failed to parse address book." << endl;
            return -1;
        }
        input.close();
    }

    ListMsg(msg1);
}

