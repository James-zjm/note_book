#include "Course.h"



Course::Course(std::string &a,std::string &obj) {
	name = a;
	adress = obj+"\\"+name;//�����ļ����´���
}
Course::~Course() {
	rmdir(adress.c_str());
}