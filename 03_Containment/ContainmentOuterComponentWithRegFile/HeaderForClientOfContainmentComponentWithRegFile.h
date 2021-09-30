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
	// IMultiplication specific method declarations
	virtual HRESULT __stdcall MultiplicationOfTwoIntegers(int, int, int*) = 0; //pure virtual
};

class IDivision :public IUnknown
{
public:
	// IDivision specific method declarations
	virtual HRESULT __stdcall DivisionOfTwoIntegers(int, int, int*) = 0; //pure virtual
};

//CLSID of SumSubtract Component {4CA05A84-8FA2-493F-9587-2846AF101600}
const CLSID CLSID_SumSubtract = { 0x4ca05a84, 0x8fa2, 0x493f, 0x95, 0x87, 0x28, 0x46, 0xaf, 0x10, 0x16, 0x0 };

//IID of ISum Interface {0A27E2FB-F77B-41CF-8172-D4C13282EBFD}
const IID IID_ISum = { 0xa27e2fb, 0xf77b, 0x41cf, 0x81, 0x72, 0xd4, 0xc1, 0x32, 0x82, 0xeb, 0xfd };

//IID of ISubtract Interface {26D28795-0AB5-4844-A9E7-E23728BA8359}
const IID IID_ISubtract = { 0x26d28795, 0xab5, 0x4844, 0xa9, 0xe7, 0xe2, 0x37, 0x28, 0xba, 0x83, 0x59 };

// IID of IMultiplication Interface {4CD9BDC6-5284-49D9-9445-01A05EF0D00B}
const IID IID_IMultiplication = { 0x4cd9bdc6, 0x5284, 0x49d9, 0x94, 0x45, 0x1, 0xa0, 0x5e, 0xf0, 0xd0, 0xb };

// IID of IDivision interface {36C87588-9D45-4AA9-9D0B-2775352BCC7F}
const IID IID_IDivision = { 0x36c87588, 0x9d45, 0x4aa9, 0x9d, 0xb, 0x27, 0x75, 0x35, 0x2b, 0xcc, 0x7f };
