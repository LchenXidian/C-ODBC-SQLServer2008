#define  _CRT_SECURE_NO_WARNINGS  
#pragma once  
#include<iostream>   
#include<stdio.h>  
#include<windows.h>    
#include<sqltypes.h>  
#include<sql.h>  
#include<sqlext.h>  
#include<string.h>    
#include<fstream>  
#include<chrono>  
#pragma comment(lib,"odbc32.lib")  

using namespace std;  

SQLRETURN ret;  
SQLHENV henv;    //SQLHANDLE henv   
SQLHDBC hdbc;    //SQLHANDLE hdbc   
SQLHSTMT hstmt;  //SQLHANDLE hstmt  

SQLINTEGER num1;  
SQLCHAR name1[20], sex1[10];  
SQLLEN len_num1, len_name1, len_sex1; 
 
void SELECT(){  
	
	ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt); //申请SQL语句句柄   
	SQLCHAR sql[] = "SELECT * FROM Test";  
	
	ret = SQLExecDirect(hstmt, sql, SQL_NTS);      //直接执行SQL语句 
	  
	if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO){  
		
		while (SQLFetch(hstmt) != SQL_NO_DATA){//遍历结果集  
			SQLGetData(hstmt, 1, SQL_C_ULONG, &num1, 0, &len_num1);  	
			SQLGetData(hstmt, 2, SQL_C_CHAR, name1, 20, &len_name1);  		
			SQLGetData(hstmt, 3, SQL_C_CHAR, sex1, 10, &len_sex1);  
			cout << num1 << name1 << sex1 << endl;  
		}
		SQLFreeHandle(SQL_HANDLE_STMT, hstmt);//释放语句句柄 
		  
	}  
	else{  
		cout << "查询失败!" << endl;  
	}  
	
}  
int Insert(string& str){  
	
	ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);//申请SQL语句句柄  
	SQLCHAR* insert = (SQLCHAR*)(str.c_str());  
	ret = SQLPrepare(hstmt, insert, SQL_NTS); 
	 
	if ((ret != SQL_SUCCESS) && (ret != SQL_SUCCESS_WITH_INFO)){  
		cout << "绑定失败!" << endl;  
		return -1;  
	}  
	// 执行SQL语句  
	ret = SQLExecute(hstmt);  
	
	if (ret == SQL_ERROR){  
		cout << "执行sql失败!" << endl;  
		return -2;  
	}  
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt);//释放语句句柄   
	return 0;  
}  
int main(){  
	
	ret = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);  //申请环境句柄   
	ret = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);//设置环境属性   
	ret = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);  //申请数据库连接句柄   
	ret = SQLConnect(hdbc, (SQLCHAR*)"Test", SQL_NTS, (SQLCHAR*)"sa", SQL_NTS, (SQLCHAR*)"123", SQL_NTS); //连接数据库   
  //Test是在ODBC里面配置好的连接名称。  
	//sa账号名，123为远程主机上的数据库登录密码。  
	
	if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO){  
		//SELECT();  
		for (int i = 0; i < 1000; ++i){  
			auto start = std::chrono::high_resolution_clock::now();  
			string str = "INSERT Table_1 VALUES(1, '1', '04:05:03')";  
			Insert(str);  
			auto end = std::chrono::high_resolution_clock::now();  
			cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us" << endl;  		}  
	}  
	else{  
		cout << "连接数据库失败!" << endl;  
		system("pause");  
		return -1;  
	} 
	 
	SQLDisconnect(hdbc);//断开与数据库的连接   
	SQLFreeHandle(SQL_HANDLE_DBC, hdbc);//释放连接句柄   
	SQLFreeHandle(SQL_HANDLE_ENV, henv);//释放环境句柄  
	system("pause");  
	return 0;  
}  