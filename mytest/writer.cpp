//
// Created by hou guoli on 2018/9/26.
//

// ./protoc36 -I=src/ --cpp_out=mytest/ --proto_path=mytest helloworld.proto
// ./protoc36 mytest/helloworld.proto --cpp_out=.


#include "helloworld.pb.h"
#include "iostream"
#include <fstream>
using namespace std;

int main(void)
{

    lm::helloworld msg1;
    msg1.set_id(101);
    msg1.set_str("hello");
    msg1.set_opt(99);


    int len = msg1.ByteSize();
    
    // Write the new address book back to disk.
    fstream output("./log", ios::out | ios::trunc | ios::binary);

    if (!msg1.SerializeToOstream(&output)) {
        cerr << "Failed to write msg." << endl;
        return -1;
    }

    for( int i = 0; i < 100; ++i ){
        lm::helloworld msg;
        msg.set_id(i);
        msg.set_str("world");
        msg.set_opt(i);
        msg.SerializeToOstream(&output);
    }

    output.close();

    return 0;
}
