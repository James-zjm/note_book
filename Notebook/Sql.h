#pragma once
#include<mysql.h>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<windows.h>
#include <qmessagebox.h>

std::wstring Change_string_to_wstring(std::string str);
int file_size(char *path);
char *read_file(char *path, int size);
int write_file(char *buf, char *path, int size);
int connect_database();//连接数据库
int add_user(const char *username, const char *password, const char *level);//添加用户（用户名，密码，权限）
char* use_user(const char *username, const char *password);
int upload_file(char *database_name,char *table_name, char *path, char* filename, char*id);//;上传文件（数据库，表，文件路径，文件名，文件id）
int download_file( char *database_name, char *table_name, char *path, char* filename, char* id);//下载文件（数据库，表，文件路径，文件名，文件id）
char* show_file_name(char *database_name, char *table_name, char* id); //显示文件名（数据库，表，文件id）返回文件名
char* show_file_id(char *database_name, char *table_name, char* file_name);//显示文件id（数据库，表，文件名）返回文件id
int create_public_class(char *class_id);//创建公共课程（课程名（数据库））
int create_public_class_add_student(char *class_id, char *student);//创建公共课程学生（课程名，学生名（表））
int delete_database(char *database_name);//删除数据库（数据库名）
int delete_table(char *database_name, char* table);//删除表（数据库名，表名）
int delete_file(char *database_name, char *table_name, char* id);
char** show_file_name(char *database_name, char *table_name);
int delete_table_file(char *database_name, char* table);

