#pragma once
class ISum :public IUnknown
{
public:
	//ISum specific method declarations
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int*) = 0; //pure virtual
};

class ISubtract :public IUnknown
{
public:
	//ISubtract specific method declarations
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*) = 0; //pure virtual
};


//CLSID of SumSubtract Component {795E903D-DCD8-4657-B017-265E6CA8FADF}
const CLSID CLSID_SumSubtract = { 0x795e903d, 0xdcd8, 0x4657, 0xb0, 0x17, 0x26, 0x5e, 0x6c, 0xa8, 0xfa, 0xdf };

//IID of ISum Interface {72529F87-B9C3-44C1-A257-E5D7E5240924}
const IID IID_ISum = { 0x72529f87, 0xb9c3, 0x44c1, 0xa2, 0x57, 0xe5, 0xd7, 0xe5, 0x24, 0x9, 0x24 };

//IID of ISubtract Interface {C1AA2220-D970-4580-B257-09065D58558E}
const IID IID_ISubtract = { 0xc1aa2220, 0xd970, 0x4580, 0xb2, 0x57, 0x9, 0x6, 0x5d, 0x58, 0x55, 0x8e };
