#include "Identity.h"

void Identity::setName(std::string &a) {
	name = a;
	_name = (char*)name.c_str();
}

void Identity::setPassword(std::string &b) {
	password = b;
}

Identity::~Identity()
{
}
