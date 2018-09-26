//
// Created by hou guoli on 2018/9/26.
//

#include "helloworld.pb.h"
#include "iostream"
#include "fstream"
using namespace std;

void ListMsg(const lm::helloworld & msg) {
    msg.PrintDebugString();
    cout << msg.id()  << ", "<< msg.str() << ", "<< msg.opt() << endl;
}

int main(int argc, char* argv[]) {


    fstream input("./log", ios::in | ios::binary);

    for( int i = 0; i < 100; ++i ) {
        lm::helloworld msg1;
        if (!msg1.ParseFromIstream(&input)) {
            cerr << "Failed to parse address book." << endl;
            return -1;
        }
        ListMsg(msg1);
    }
    input.close();
}

