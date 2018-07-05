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
int connect_database();//�������ݿ�
int add_user(const char *username, const char *password, const char *level);//����û����û��������룬Ȩ�ޣ�
char* use_user(const char *username, const char *password);
int upload_file(char *database_name,char *table_name, char *path, char* filename, char*id);//;�ϴ��ļ������ݿ⣬���ļ�·�����ļ������ļ�id��
int download_file( char *database_name, char *table_name, char *path, char* filename, char* id);//�����ļ������ݿ⣬���ļ�·�����ļ������ļ�id��
char* show_file_name(char *database_name, char *table_name, char* id); //��ʾ�ļ��������ݿ⣬���ļ�id�������ļ���
char* show_file_id(char *database_name, char *table_name, char* file_name);//��ʾ�ļ�id�����ݿ⣬���ļ����������ļ�id
int create_public_class(char *class_id);//���������γ̣��γ��������ݿ⣩��
int create_public_class_add_student(char *class_id, char *student);//���������γ�ѧ�����γ�����ѧ����������
int delete_database(char *database_name);//ɾ�����ݿ⣨���ݿ�����
int delete_table(char *database_name, char* table);//ɾ�������ݿ�����������
int delete_file(char *database_name, char *table_name, char* id);
char** show_file_name(char *database_name, char *table_name);
int delete_table_file(char *database_name, char* table);

