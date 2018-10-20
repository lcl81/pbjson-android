/*
 * test.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: wangqiying
 */
#include "proto_file/test.pb.h"
#include "pbjson_src/pbjson.hpp"

#include <google/protobuf/stubs/common.h>
#include <stdio.h>

#if 0
int main()
{
    Request request;
    request.mutable_header()->set_user("test_user");
    request.mutable_header()->set_passwd("test_passwd");
    request.set_arg1(101);
    request.add_arg2(10100000000000001LL);
    request.add_arg2(1022222201LL);
    request.set_arg3(3.1415926);

    Arg* arg = request.add_args();
    arg->set_f1("xf1");
    arg->set_f2("xf2");
    arg = request.add_args();
    arg->set_f1("xff1");
    arg->set_f2("xff2");

    std::string str;
    pbjson::pb2json(&request, str);
    printf("PB2Json result:\n%s\n", str.c_str());

    Request new_request;
    std::string err;
    int ret = pbjson::json2pb(str, &new_request, err);
    printf("Json2PB result:\%d\n", ret);

    return 0;
}
#endif

#if 0
int main(int argc, char *argv[]) 
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    
    int ids[4] = {0, 1, 2, 6};
    MideaPb::FaceList faces_result;
    for (int i=0; i<4; i++) {
        faces_result.add_face_list(ids[i]);
    }

    #if 0
    std::string output_pb;
    output_pb.resize(faces_result.ByteSize());
    printf("0:output_pb= %d\n", output_pb.length());

    faces_result.SerializeToString(&output_pb);
    int pb_size = output_pb.length();
    printf("pb_size= %d\n", pb_size);
    for (int i=0; i<pb_size; i++) {
        printf("0x%.2x\n", output_pb[i]);
    }

    MideaPb::FaceList parse_result;
    bool ret = parse_result.ParseFromString(output_pb);
    printf("ret= %d\n", ret);
    if (ret) {
        printf("size= %d\n", parse_result.face_list_size());
        for (int i=0; i<parse_result.face_list_size(); i++) {
            printf("i= %d, id= %d\n", i, parse_result.face_list(i));
        }
    }
    #endif

    #if 0
    int bytesize = faces_result.ByteSize();
    char buffer[bytesize];
    faces_result.SerializeToArray(buffer, bytesize);

    printf("bytesize= %d\n", bytesize);
    for (int i=0; i<bytesize; i++) {
        printf("0x%.2x\n", buffer[i]);
    }

    MideaPb::FaceList parse_result;
    bool ret = parse_result.ParseFromArray(buffer, bytesize);
    printf("ret= %d\n", ret);
    if (ret) {
        printf("size= %d\n", parse_result.face_list_size());
        for (int i=0; i<parse_result.face_list_size(); i++) {
            printf("i= %d, id= %d\n", i, parse_result.face_list(i));
        }
    }
    #endif

    #if 1
    std::string str;
    pbjson::pb2json(&faces_result, str);
    printf("str= %s\n", str.c_str());

    MideaPb::FaceList parse_result;
    std::string err;
    int ret = pbjson::json2pb(str, &parse_result, err);
    printf("ret= %d\n", ret);
    if (0 == ret) {
        printf("size= %d\n", parse_result.face_list_size());
        for (int i=0; i<parse_result.face_list_size(); i++) {
            printf("i= %d, id= %d\n", i, parse_result.face_list(i));
        }
    }
    #endif
    
    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();
    
    return 0;
}
#endif

#if 0
int main(int argc, char *argv[]) 
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    
    
    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
#endif

#if 0
#include <sstream>

template < typename T > 
std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}

void set_image(::MideaPb::QueryResponse_Image &image, int index) {
    (void)index;
    std::string t_name = (std::string)"name_" + to_string(index);
    image.set_image_name(t_name);
}

void set_person(::MideaPb::QueryResponse_Person &person, int index) {
    std::string t_name = (std::string)"name_" + to_string(index);
    person.set_person_name(t_name);

    ::MideaPb::QueryResponse_Image *image;
    for (int i=0; i<2; i++) {
        image = person.add_image_list();
        set_image(*image, i);
    }
}

void set_group(::MideaPb::QueryResponse_Group &group, int index) {
    std::string t_name = (std::string)"name_" + to_string(index);
    group.set_group_name(t_name);

    ::MideaPb::QueryResponse_Person *person;
    for (int i=0; i<2; i++) {
        person = group.add_person_list();
        set_person(*person, i);
    }
}

int main(int argc, char *argv[]) 
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    MideaPb::QueryResponse res;
    res.set_act("get_all_person_list");

    ::MideaPb::QueryResponse_Group* groups;
    for (int i=0; i<2; i++) {
        groups = res.add_list();
        set_group(*groups, i);
    }

    std::string str;
    pbjson::pb2json(&res, str);
    printf("str= %s\n", str.c_str());

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
#endif

#if 1
void set_face_result(::MideaPb::DetectResult_FaceResult &face, int index)
{
    (void)index;
    face.set_person_id(index);
    face.set_left(557);
    face.set_top(311);
    face.set_right(719);
    face.set_bottom(473);
    face.set_type(0);
    face.set_confidence(0.99);
    face.set_liveness(0.68);

    return;
}

int main(int argc, char *argv[]) 
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    MideaPb::DetectResult detect;
    detect.mutable_img_property()->set_luminance(0.124555);

    ::MideaPb::DetectResult_FaceResult* face;
    for (int i=0; i<2; i++) {
        face = detect.add_face_result();
        set_face_result(*face, i);
    }

    std::string str;
    pbjson::pb2json(&detect, str);
    printf("str= %s\n", str.c_str());

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
#endif

