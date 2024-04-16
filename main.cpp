
#include <iostream>
#include "public.h"

#include "Connection.h"
#include "CommonConnectionPool.h"

using namespace std;

int main()
{
	// Connection conn;
	// conn.connect("127.0.0.1", 3306, "root", "123456", "chat");

	/*Connection conn;
	char sql[1024] = { 0 };
	sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
		"zhang san", 20, "male");
	conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
	conn.update(sql);*/
#if 0
	clock_t begin = clock();
	
	thread t1([]() {
		ConnectionPool *cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 1000; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
			// Connection conn;
			// char sql[1024] = { 0 };
			// sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
			// 	"zhang san", 20, "male");
			// conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
			// conn.update(sql);
		}
	});
	thread t2([]() {
		ConnectionPool *cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 1000; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
			// Connection conn;
			// char sql[1024] = { 0 };
			// sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
			// 	"zhang san", 20, "male");
			// conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
			// conn.update(sql);
		}
	});
	thread t3([]() {
		ConnectionPool *cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 1000; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
			// Connection conn;
			// char sql[1024] = { 0 };
			// sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
			// 	"zhang san", 20, "male");
			// conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
			// conn.update(sql);
		}
	});
	thread t4([]() {
		ConnectionPool *cp = ConnectionPool::getConnectionPool();
		for (int i = 0; i < 1000; ++i)
		{
			char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);
			// Connection conn;
			// char sql[1024] = { 0 };
			// sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
			// 	"zhang san", 20, "male");
			// conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
			// conn.update(sql);
		}
	});

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	clock_t end = clock();
	cout << (end - begin) << "ms" << endl;
#endif

#if 1
	clock_t begin = clock();
	ConnectionPool *cp = ConnectionPool::getConnectionPool();
	for (int i = 0; i < 4000; ++i)
	{

		// Connection conn;
		// char sql[1024] = { 0 };
		// sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
		// 	"zhang san", 20, "male");
		// conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
		// conn.update(sql);

		shared_ptr<Connection> sp = cp->getConnection();
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
			"zhang san", 20, "male");
		sp->update(sql);
	}
	clock_t end = clock();
	cout << (end - begin) << "ms" << endl;
#endif

	return 0;
}
// 		2073 2326ms ms 四个线程 		1919 4927ms 单个线程
//池化 	 26 1922ms						25 3456ms   单个线程