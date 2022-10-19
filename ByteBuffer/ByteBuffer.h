#pragma once
#include <stdint.h>
#include <string.h>
#include <math.h>

enum Endian
{
	BigEndian,
	SmallEndian
};

enum SizeType
{
	Auto,
	ShortSize = 16,
	IntSize = 32,
	Int64Size = 64
};


class ByteBuffer
{
public:
	ByteBuffer();
	virtual ~ByteBuffer();

	Endian endian;
	int capacity;
	int size;
	int curOffset;
	uint8_t* data;
	
	ByteBuffer* writeByte(int8_t num, int offset = -1);
	
	ByteBuffer* writeUByte(uint8_t num, int offset = -1);
	ByteBuffer* writeShort(int16_t num, int offset = -1);
	ByteBuffer* writeUShort(uint16_t num, int offset = -1);
	ByteBuffer* writeInt(int32_t num, int offset = -1);
	ByteBuffer* writeUInt(uint32_t num, int offset = -1); 
	ByteBuffer* writeInt64(int64_t num, int offset = -1);
	ByteBuffer* writeUInt64(uint64_t num, int offset = -1);
	ByteBuffer* writeFloat(float num, int offset = -1);
	ByteBuffer* writeDouble(double num, int offset = -1);
	ByteBuffer* writeBytes(ByteBuffer* buffer, int offset = -1);
	ByteBuffer* writeBytes(const uint8_t* buffer, int byteSize, int offset = -1);
	/*template<typename T> ByteBuffer* writeArray(const T* num, uint64_t arraySize, SizeType sizeType, int offset = -1) {

	}*/

	int8_t readByte(int offset = -1);
	uint8_t readUByte(int offset = -1);
	int16_t readShort(int offset = -1);
	uint16_t readUShort(int offset = -1);
	int32_t readInt(int offset = -1);
	uint32_t readUInt(int offset = -1);
	int64_t readInt64(int offset = -1);
	uint64_t readUInt64(int offset = -1);
	float readFloat(int offset = -1);
	double readDouble(int offset = -1);
	const uint8_t* readBytes(int numSize, int offset = -1);

	const uint8_t* getBytes();

	template<typename T> ByteBuffer* append(T num, int offset) {
		int numSize = sizeof(num);
		checkCap(numSize);
		if (offset == -1) {
			offset = curOffset;
		}
		if (endian == BigEndian && numSize > 1) {
			
			for (int i = 0; i < numSize; i++) {
				uint8_t* num2 = (uint8_t *)&num;
				memcpy(data + offset + i, num2 + numSize - i - 1, 1);
			}
			
		}
		else {
			memcpy(data + offset, &num, numSize);
		}
		curOffset += numSize;
		size += numSize;
		return this;
	}

	template<typename T> T read(int offset) {
		int numSize = sizeof(T);
		if (offset == -1) {
			offset = curOffset;
		}
		T num;
		if (endian == BigEndian && numSize > 1) {
			uint8_t* num2 = (uint8_t *)&num;
			for (int i = 0; i < numSize; i++) {
				memcpy(num2 + numSize - i - 1, data + offset + i, 1);
			}
			
		}
		else {
			memcpy(&num, data + offset, numSize);
		}
		curOffset += numSize;
		return num;
	}
private:
	void resize(int needSize);
	void checkCap(int byteSize);
};

