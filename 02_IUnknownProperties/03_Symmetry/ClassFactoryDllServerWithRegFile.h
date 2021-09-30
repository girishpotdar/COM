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

//CLSID of SumSubtract Component {54AF4F8A-ECA5-4E28-A196-9EAB579490EA}
const CLSID CLSID_SumSubtract = { 0x54af4f8a, 0xeca5, 0x4e28, 0xa1, 0x96, 0x9e, 0xab, 0x57, 0x94, 0x90, 0xea };

//IID of ISum Interface {17F89FCB-0CF5-4CB6-ADEF-CBA53BE61D0B}
const IID IID_ISum = { 0x17f89fcb, 0xcf5, 0x4cb6, 0xad, 0xef, 0xcb, 0xa5, 0x3b, 0xe6, 0x1d, 0xb };

//IID of ISubtract Interface {D020EEF6-0EB2-40E2-9FB1-193800916592}
const IID IID_ISubtract = { 0xd020eef6, 0xeb2, 0x40e2, 0x9f, 0xb1, 0x19, 0x38, 0x0, 0x91, 0x65, 0x92 };
