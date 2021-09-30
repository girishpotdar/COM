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

class IMultiplication :public IUnknown
{
public:
	//IMultiplication specific method declarations
	virtual HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*) = 0;	//pure virtual
};

class IDivision :public IUnknown
{
public:
	// IDivision specific method declarations
	virtual HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*) = 0;	//pure virtual
};


//CLSID of SumSubtract Component {795E903D-DCD8-4657-B017-265E6CA8FADF}
const CLSID CLSID_SumSubtract = { 0x795e903d, 0xdcd8, 0x4657, 0xb0, 0x17, 0x26, 0x5e, 0x6c, 0xa8, 0xfa, 0xdf };

//IID of ISum Interface {72529F87-B9C3-44C1-A257-E5D7E5240924}
const IID IID_ISum = { 0x72529f87, 0xb9c3, 0x44c1, 0xa2, 0x57, 0xe5, 0xd7, 0xe5, 0x24, 0x9, 0x24 };

//IID of ISubtract Interface {C1AA2220-D970-4580-B257-09065D58558E}
const IID IID_ISubtract = { 0xc1aa2220, 0xd970, 0x4580, 0xb2, 0x57, 0x9, 0x6, 0x5d, 0x58, 0x55, 0x8e };

// IID of IMultiplication Interface	{A9FCC2A9-3CBF-44C5-AF8F-1465125466BE}
const IID IID_IMultiplication = { 0xa9fcc2a9, 0x3cbf, 0x44c5, 0xaf, 0x8f, 0x14, 0x65, 0x12, 0x54, 0x66, 0xbe };

// IID of IDivision Interface {13935E21-1565-4F53-A36D-49DF6784964C}
const IID IID_IDivision = { 0x13935e21, 0x1565, 0x4f53, 0xa3, 0x6d, 0x49, 0xdf, 0x67, 0x84, 0x96, 0x4c };
