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

// CLSID of MultiplicationDivision Component {B0D4A79D-3C06-4733-A8FB-7C17A6B493EE}
const CLSID CLSID_MultiplicationDivision = { 0xb0d4a79d, 0x3c06, 0x4733, 0xa8, 0xfb, 0x7c, 0x17, 0xa6, 0xb4, 0x93, 0xee };

// IID of IMultiplication Interface	{A9FCC2A9-3CBF-44C5-AF8F-1465125466BE}
const IID IID_IMultiplication = { 0xa9fcc2a9, 0x3cbf, 0x44c5, 0xaf, 0x8f, 0x14, 0x65, 0x12, 0x54, 0x66, 0xbe };

// IID of IDivision Interface {13935E21-1565-4F53-A36D-49DF6784964C}
const IID IID_IDivision = { 0x13935e21, 0x1565, 0x4f53, 0xa3, 0x6d, 0x49, 0xdf, 0x67, 0x84, 0x96, 0x4c };
