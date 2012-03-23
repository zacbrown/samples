#pragma once

#include <windows.h>
#include <functional>

struct __declspec(uuid("746d0e72-2f50-4555-98b5-74f91f23c139")) 
ICallbackObj : IUnknown
{
    virtual void __stdcall Bang() = 0;
};

class CCallbackObj : public ICallbackObj
{
public:
    // ctor
    CCallbackObj();

    // IUnknown functions
    ULONG __stdcall AddRef();
    ULONG __stdcall Release();
    HRESULT __stdcall QueryInterface(REFIID, void**);

    // ICallbackObj functions
    void __stdcall Bang();

    // CCallbackObj functions
    void __stdcall SetCallback(std::function<void()>);

private:
    std::function<void()> m_callback;
    ULONG m_ulRefCount;
};