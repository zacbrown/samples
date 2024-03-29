#include "CCallbackObj.h"

CCallbackObj::CCallbackObj() : m_ulRefCount(1)
{
}

// IUnknown functions
ULONG __stdcall CCallbackObj::AddRef()
{
    return InterlockedIncrement(&m_ulRefCount);
}

ULONG __stdcall CCallbackObj::Release()
{
    ULONG ulTemp = InterlockedDecrement(&m_ulRefCount);
    if (0 == ulTemp)
    {
        delete this;
    }

    return ulTemp;
}

HRESULT __stdcall CCallbackObj::QueryInterface(REFIID clsid, void** ppv)
{
    if (nullptr == ppv)
    {
        return E_POINTER;
    }
    *ppv = nullptr;

    if (clsid == __uuidof(IUnknown) ||
        clsid == __uuidof(ICallbackObj))
    {
        *ppv = static_cast<ICallbackObj*>(this);
        AddRef();
        return S_OK;
    }

    return E_NOINTERFACE;
}

// ICallbackObj functions
void __stdcall CCallbackObj::Bang()
{
    m_callback();
}

// General functions supported by CCallbackObj
void __stdcall CCallbackObj::SetCallback(std::function<void()> callback)
{
    m_callback = callback;
}