// ByteBuffer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ByteBuffer.h"
#include <fstream>

using namespace std;
int main()
{
	ByteBuffer* buffer = new ByteBuffer();
	buffer->endian = BigEndian;
	buffer->writeByte(1);
	buffer->writeShort(2);
	buffer->writeInt(3);
	buffer->writeFloat(1.345667f);
	buffer->writeDouble(2.345667);
	const char* test = "你好";
	cout << "size of test is " << sizeof(test) << endl;
	buffer->writeBytes((const uint8_t*)test, sizeof(test) + 1);
	buffer->curOffset = 0;
	cout << (int)buffer->readByte() << endl;
	cout << (int)buffer->readShort() << endl;
	cout << (int)buffer->readInt() << endl;
	cout << buffer->readFloat() << endl;
	cout << buffer->readDouble() << endl;
	cout << buffer->readBytes(sizeof(test) + 1) << endl;
	std::cout << "Hello World!\n";


	const uint8_t* bytes = buffer->getBytes();
	ofstream out("test.txt", ios::out | ios::binary);
	out.write((char*)bytes, buffer->size);
	delete[] buffer;
	buffer = NULL;
	while (1) {

	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
