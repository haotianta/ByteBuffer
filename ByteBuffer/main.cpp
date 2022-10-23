// ByteBuffer.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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
	const char* test = "���";
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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
