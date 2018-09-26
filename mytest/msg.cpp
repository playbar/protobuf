//protobuf_demo.cc
#include"msg.pb.h"
#include<iostream>
#include<string>
using namespace std;


int main(int argc,char *argv[])
{
    demo::msg writer;
    writer.set_int_info(1);
    writer.set_string_info("i am wk");
    demo::data_t* data1 = writer.mutable_data_info();
    data1->set_data_int_info(2);
    data1->set_name("wk");
    for (int i=0;i<5;++i) {
        demo::kv_t* data2 = writer.add_vector_info();
        data2->set_key(i);
        data2->set_value("hello");
    }
//C++string序列化和序列化API
//客户端格式化信息
    string in_data;
    writer.SerializeToString(&in_data);
//下面用一个临时的string 表示在网络中进行传输的过程
//真是的过程中你可以借助相应的网络框架对数据进行传输
//客户端将数据放到网络上
    string tmp=in_data;
//模拟服务端从网络上拿数据
    string out_data=tmp;
//服务端反格式化信息
    demo::msg reader;
    reader.ParseFromString(out_data);
    cout<<"int_info: "<<reader.int_info()<<endl;
    cout<<"string_info: "<<reader.string_info()<<endl;
    demo::data_t * data3 = reader.mutable_data_info();
    cout<<"data_t {\n";
    cout<<"data_int_info: "<<data3->data_int_info()<<endl;
    cout<<"name: "<<data3->name()<<endl;
    cout<<"}\n";
    for (int i=0;i<reader.vector_info_size();++i) {
        cout<<"kv_t {\n";
        const demo::kv_t &data4 = reader.vector_info(i);
        cout<<"key: "<<data4.key()<<endl;
        cout<<"value: "<<data4.value()<<endl;
        cout<<"}\n";
    }
    return 0;
}
