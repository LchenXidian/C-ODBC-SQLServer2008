# C-ODBC-SQLServer2008

C++通过ODBC连接局域网另一台主机的SQL Server 2008 R2

SQL Server 2008默认不允许远程连接，需要在数据库安装端做一些配置。

1.SQL Server Management Studio

![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/1.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/2.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/3.png)
展开安全性=>登录名=>sa 右键属性

![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/4.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/5.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/6.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/7.png)

2.SQL Server 配置管理器

![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/8.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/9.png)

端口号默认设置为1433

![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/10.png)

重新启动SQL Server服务。将正在运行的SQL Server服务重启。

3.配置防火墙
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/11.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/12.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/13.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/14.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/15.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/16.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/17.png)

4.客户机上的ODBC配置

![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/18.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/19.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/20.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/21.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/22.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/23.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/24.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/25.png)
![image](https://github.com/LchenXidian/C-ODBC-SQLServer2008/blob/master/images/26.png)

