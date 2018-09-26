//
// Created by hou guoli on 2018/9/26.
//

#include "lm.helloworld.pb.h"
#include "iostream"
#include <fstream>
using namespace std;

int main(void)
{

    lm::helloworld msg1;
    msg1.set_id(101);
    msg1.set_str("hello");


    lm::helloworld msg2;
    msg2.set_id(102);
    msg2.set_str("world");
    msg2.set_opt(103);

    // Write the new address book back to disk.
    fstream output("./log", ios::out | ios::trunc | ios::binary);

    if (!msg1.SerializeToOstream(&output)) {
        cerr << "Failed to write msg." << endl;
        return -1;
    }
    msg2.SerializeToOstream(&output);

    return 0;
}
