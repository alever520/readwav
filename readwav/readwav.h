#pragma once
#include<fstream>
#include<iostream>
//---------------����һ���ܹ���ȡwav�ļ�����---------
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
	// ���������һ���ڴ�տռ�
	double* disp();

	// ���������data�ĳ���
	int getlength();
	// ���������data�Ĳ���Ƶ��
	int getfrequency();


};