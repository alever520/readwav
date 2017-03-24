#include"readwav.h"
using namespace std;
readwav::readwav(char* filename)
{
	fp.open(filename, ios::in | ios::binary);
	fp.seekg(0, ios::beg);
	fp.read((char*)&ChunkID, 4);//sizeof(ChunkID)
	fp.seekg(0x04);
	fp.read((char*)&ChunkSize, sizeof(ChunkSize));//sizeof(ChunkSize)
	fp.seekg(0x08);
	fp.read((char*)&Format, 4);//sizeof(Format)
	fp.seekg(0x0c);
	fp.read((char*)&SubChunk1ID, 4);
	fp.seekg(0x10);
	fp.read((char*)&SubChunk1Size, 4);
	fp.seekg(0x14);
	fp.read((char*)&AudioFormat, sizeof(AudioFormat));
	fp.seekg(0x16);
	fp.read((char*)&NumChannels, sizeof(NumChannels));
	fp.seekg(0x18);
	fp.read((char*)&SampleRate, sizeof(SampleRate));
	fp.seekg(0x1c);
	fp.read((char*)&ByteRate, sizeof(ByteRate));
	fp.seekg(0x20);
	fp.read((char*)&BlockAlign, sizeof(BlockAlign));
	fp.seekg(0x22);
	fp.read((char*)&BitsPerSample, sizeof(BitsPerSample));
	fp.seekg(0x24);
	fp.read((char*)&SubChunk2ID, sizeof(SubChunk2ID));
	fp.seekg(0x28);
	fp.read((char*)&SubChunk2Size, sizeof(SubChunk2Size));
	//long length = char2num(SubChunk2Size);
	data = new unsigned char[SubChunk2Size];
	fp.seekg(0x2c);
	fp.read((char*)data, SubChunk2Size);



	cout << "ChunkID " << ChunkID << endl;
	cout << "ChunkSize " << ChunkSize << endl;
	cout << "Format " << Format << endl;
	cout << "SubChunk1ID " << SubChunk1ID << endl;
	cout << "SubChunk1Size " << SubChunk1Size << endl;
	cout << "AudioFormat " << AudioFormat << endl;
	cout << "NumChannels " << NumChannels << endl;
	cout << "SampleRate " << SampleRate << endl;
	cout << "ByteRate " << ByteRate << endl;
	cout << "BlockAlign " << BlockAlign << endl;
	cout << "BitsPerSample " << BitsPerSample << endl;
	cout << "SubChunk2ID " << SubChunk2ID << endl;
	cout << "SubChunk2Size " << SubChunk2Size << endl;
	//cout << n << endl;


}
// 数据输出到一块内存空空间
double* readwav::disp()
{
	//double output = 0;
	double* output = new double[SubChunk2Size / 2];
	int j = 0;
	for (unsigned int i = 0; i < SubChunk2Size; i = i + 2)
	{
		unsigned long data_low = data[i];
		unsigned long data_high = data[i + 1];
		double data_true = data_high * 256 + data_low;
		long data_complement = 0;
		int my_sign = (int)(data_high / 128);
		if (my_sign == 1)
			data_complement = data_true - 65536;
		else
			data_complement = data_true;
		output[j] = (double)(data_complement / (double)32768);
		j++;
		//output = output + final_data;
		//if (i % 1764 == 0)
		//{
		//	ofstream out("test.txt",ios::app);
		//	out << output << endl;
		//	output = 0;
		//}

	}
	return output;
}
// 给出输出的data的长度
int readwav::getlength()
{
	return SubChunk2Size / 2;
}
//  给出输出的data的采样频率
int readwav::getfrequency()
{
	return SampleRate;
}