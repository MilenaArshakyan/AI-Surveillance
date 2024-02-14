/*
Առաջադրանք 1
Ներկայացնել նկար

Իրականացնել ծրագիր, որը թույլ կտա ներկայացնել RGB գույներով նկար։ Նկարը կարելի է պատկերացնել որպես pixel-ներից բաղկացած մատրից, որտեղ յուրաքանյուր pixel նկարագրվում է Red, Green և Blue կոմպոնենտներով։ Pixel-ի յուրաքանչյուր գույն ունի ինտենսիվության արժեք [0 - 255] միջակայքից։ 

Ծրագիրը պետք է հնարավորություն տա՝

փոխել նկարի (x, y) կոորդինատում գտնվող pixel-ի RGB արժեքները
ստանալ նկարի (x, y) կոորդինատում գտնվող pixel-ի RGB արժեքները
ցույց տալ նկարը՝ տպելով նկարի pixel-ների գույների արժեքները

*/

#include <iostream>

struct Pixel
{
    int red;
    int green;
    int blue;

	Pixel() : red(0), green(0), blue(0) {}

	Pixel(int r, int g, int b) : red(r), green(g), blue(b) {}

	Pixel(const Pixel& ob) : red(ob.red), green(ob.green), blue(ob.blue) {}

	Pixel(Pixel&& ob) noexcept: red(ob.red), green(ob.green), blue(ob.blue)
	{
		std::move(ob);
	}

	~Pixel() {}
};

class Image
{
    public:
        Image() : 
        Image(int row, int col);
        Image(const Image& other);
        Image(Imaget&&);
		void PrintCol(int x, int y);
		void DisplayImage();

	private:
        int row;
        int col;
        mutable Pixel** ptr;
};


Image::Image()
    :ptr {nullptr}
    ,row{0}
    ,col{0}
{}

Image::Image(int row, int col)
    :ptr {new Pixel*[row]}
    ,row {row}
    ,col {col}
{
    for(int i = 0; i < row; ++i){
        ptr[i] = new Pixel[col];
    }
}

Image::Image(const Image& other)
    :row {other.row}
    ,col {other.col}
    ,ptr {new Pixel*[row]}
{
    for(int i = 0; i < row; ++i){
        ptr[i] = new Pixel[col];
    }
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            ptr[i][j] = other.ptr[i][j];
        }
    }
}

Image::Image(Image&& rhs)
    :row {rhs.row}
    ,col {rhs.col}
    ,ptr {rhs.ptr}
{
    rhs.ptr = nullptr;
    rhs.row = 0;
    rhs.col = 0;
}

void Image::PrintCol(int x, int y) {
	if (ptr == nullptr) {
		std::cout << "The image has no value" << std::endl;
		return;
	} else if (x < 0 || x > row || y < 0 || y > col) {
		std::cout << "no such index" << std::endl;
		return;
	}
	std::cout << ptr[x][y] << std::endl;
}


void Image::DisplayImage() {
	if (ptr == nullptr) {
		return;
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			std::cout << ptr[i][j] << " ";
		}
		std::cout << std::endl;
	}

}


int main()
{




}
