#include "ByteBuffer.h"


ByteBuffer::ByteBuffer()
	: capacity(16)
	, size(0)
	, curOffset(0)
	, endian(SmallEndian)
{
	data = new uint8_t[capacity];
	memset(data, '\0', capacity);
}

ByteBuffer::~ByteBuffer()
{
	delete[] data;
	data = NULL;
}

ByteBuffer * ByteBuffer::writeByte(int8_t num, int offset)
{
	return append(num, offset);
}

ByteBuffer * ByteBuffer::writeUByte(uint8_t num, int offset)
{
	return append(num, offset);
}

ByteBuffer * ByteBuffer::writeShort(int16_t num, int offset)
{
	return append(num, offset);
}

ByteBuffer * ByteBuffer::writeUShort(uint16_t num, int offset)
{
	return append(num, offset);
}

ByteBuffer * ByteBuffer::writeInt(int32_t num, int offset)
{
	return append(num, offset);
}

ByteBuffer * ByteBuffer::writeUInt(uint32_t num, int offset)
{
	return append(num, offset);
}

ByteBuffer * ByteBuffer::writeInt64(int64_t num, int offset)
{
	return append(num, offset);
}

ByteBuffer * ByteBuffer::writeUInt64(uint64_t num, int offset)
{
	return append(num, offset);
}

ByteBuffer * ByteBuffer::writeFloat(float num, int offset)
{
	return append(num, offset);
}

ByteBuffer * ByteBuffer::writeDouble(double num, int offset)
{
	return append(num, offset);
}

ByteBuffer * ByteBuffer::writeBytes(ByteBuffer* buffer, int offset)
{
	const uint8_t* bytes = buffer->getBytes();
	return writeBytes(bytes, buffer->size, offset);
}

ByteBuffer * ByteBuffer::writeBytes(const uint8_t * buffer, int byteSize, int offset)
{
	checkCap(byteSize);
	if (offset == -1) {
		offset = curOffset;
	}
	memcpy(data + offset, buffer, byteSize);
	curOffset += byteSize;
	size += byteSize;
	return this;
}

void ByteBuffer::resize(int needSize)
{
	uint8_t* tmp = data;
	while (capacity < needSize) {
		capacity *= 2;
	}
	data = new uint8_t[capacity];
	memset(data, '\0', capacity);
	memcpy(data, tmp, size);
	delete tmp;
	tmp = NULL;
}

void ByteBuffer::checkCap(int byteSize)
{
	if (size + byteSize > capacity) {
		resize(size + byteSize);
	}
}

int8_t ByteBuffer::readByte(int offset)
{
	return read<int8_t>(offset);
}

uint8_t ByteBuffer::readUByte(int offset)
{
	return read<uint8_t>(offset);
}


int16_t ByteBuffer::readShort(int offset)
{
	return read<int16_t>(offset);
}

uint16_t ByteBuffer::readUShort(int offset)
{
	return read<uint16_t>(offset);
}

int32_t ByteBuffer::readInt(int offset)
{
	return read<int32_t>(offset);
}

uint32_t ByteBuffer::readUInt(int offset)
{
	return read<uint32_t>(offset);
}

int64_t ByteBuffer::readInt64(int offset)
{
	return read<int64_t>(offset);
}

uint64_t ByteBuffer::readUInt64(int offset)
{
	return read<uint64_t>(offset);
}

float ByteBuffer::readFloat(int offset)
{
	return read<float>(offset);
}

double ByteBuffer::readDouble(int offset)
{
	return read<double>(offset);
}

const uint8_t * ByteBuffer::readBytes(int numSize, int offset)
{
	if (offset == -1) {
		offset = curOffset;
	}
	uint8_t* bytes = new uint8_t[numSize];
	memcpy(bytes, data + offset, numSize);
	curOffset += numSize;
	return bytes;
}

const uint8_t * ByteBuffer::getBytes()
{
	return data;
}
