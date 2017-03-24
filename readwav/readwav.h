#pragma once
#include<fstream>
#include<iostream>
//---------------声明一个能够读取wav文件的类---------
class readwav
{
	std::fstream fp;
	char ChunkID[4];
	unsigned int ChunkSize;
	char Format[4];
	char SubChunk1ID[4];
	unsigned int SubChunk1Size;
	unsigned short AudioFormat;
	unsigned short NumChannels;
	unsigned int SampleRate;
	unsigned int ByteRate;
	unsigned short BlockAlign;
	unsigned short BitsPerSample;
	char SubChunk2ID[4];
	unsigned int SubChunk2Size;
	unsigned char* data;
public:
	readwav(char* filename);
	// 数据输出到一块内存空空间
	double* disp();

	// 给出输出的data的长度
	int getlength();
	// 给出输出的data的采样频率
	int getfrequency();


};