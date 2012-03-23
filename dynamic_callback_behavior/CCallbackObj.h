#pragma once

#include <windows.h>
#include <functional>

__interface __declspec(uuid("746d0e72-2f50-4555-98b5-74f91f23c139")) ICallbackObj : IUnknown
{
    virtual void STDMETHODCALLTYPE Bang() = 0;
};

class CCallbackObj : public ICallbackObj
{
public:
    CCallbackObj();
    IFACEMETHOD_(ULONG, AddRef)();
    IFACEMETHOD_(ULONG, Release)();
    IFACEMETHOD(QueryInterface)(REFIID, void**);
    IFACEMETHOD_(void, Bang)();
    void SetCallback(std::function<void()>);

private:
    std::function<void()> m_callback;
    ULONG m_ulRefCount;
};