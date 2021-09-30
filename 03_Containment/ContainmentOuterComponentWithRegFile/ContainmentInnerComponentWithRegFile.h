#pragma once
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

// CLSID of MultiplicationDivision Component {94313043-2892-4995-9549-72878143331B}
const CLSID CLSID_MultiplicationDivision = { 0x94313043, 0x2892, 0x4995, 0x95, 0x49, 0x72, 0x87, 0x81, 0x43, 0x33, 0x1b };

// IID of IMultiplication Interface {4CD9BDC6-5284-49D9-9445-01A05EF0D00B}
const IID IID_IMultiplication = { 0x4cd9bdc6, 0x5284, 0x49d9, 0x94, 0x45, 0x1, 0xa0, 0x5e, 0xf0, 0xd0, 0xb };

// IID of IDivision interface {36C87588-9D45-4AA9-9D0B-2775352BCC7F}
const IID IID_IDivision = { 0x36c87588, 0x9d45, 0x4aa9, 0x9d, 0xb, 0x27, 0x75, 0x35, 0x2b, 0xcc, 0x7f };
