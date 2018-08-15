#pragma once

class TempObject
{
private:
    int m_TempData;
public:    
    TempObject();
    TempObject(const TempObject&);
    TempObject(TempObject&&);
    ~TempObject();

    TempObject& operator =(const TempObject&);
    TempObject& operator =(TempObject&&);
};