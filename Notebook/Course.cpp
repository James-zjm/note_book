#include "Course.h"



Course::Course(std::string &a,std::string &obj) {
	name = a;
	adress = obj+"\\"+name;//当期文件夹下创建
}
Course::~Course() {
	rmdir(adress.c_str());
}