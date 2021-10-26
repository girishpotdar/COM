class IMyMath : public IDispatch
{
public:
	virtual HRESULT __stdcall SumOfTwoIntegers(int, int, int*) = 0; // pure virtual
	virtual HRESULT __stdcall SubtractionOfTwoIntegers(int, int, int*) = 0; // pure virtual
};
// CLSID of MyMath Component : {91174673-170D-4E28-A38E-F8D6570C5FA9}
const CLSID CLSID_MyMath = { 0x91174673, 0x170d, 0x4e28, 0xa3, 0x8e, 0xf8, 0xd6, 0x57, 0xc, 0x5f, 0xa9 };
// IID of ISum Interface : {887C1A49-67B9-4856-8909-B7E3A1907522}
const IID IID_IMyMath = { 0x887c1a49, 0x67b9, 0x4856, 0x89, 0x9, 0xb7, 0xe3, 0xa1, 0x90, 0x75, 0x22 };
