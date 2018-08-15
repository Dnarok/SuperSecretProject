#include ".\public\temporary.hpp"
#include <utility>

using std::move;

TempObject::TempObject()
{
    // Default Constructor //
    m_TempData = 0;
}

TempObject::TempObject(const TempObject& in_other)
{
    // Copy Constructor //
    m_TempData = in_other.m_TempData;
}

TempObject::TempObject(TempObject&& in_other)
{
    // Move Constructor //
    m_TempData = std::move(in_other.m_TempData);
    in_other.m_TempData = 0;
}

TempObject::~TempObject()
{
    // Default Destructor //
    m_TempData = 0;
}

TempObject& TempObject::operator =(const TempObject& in_other)
{
    // Copy Assignment Operator //
    m_TempData = in_other.m_TempData;
    return *this;
}

TempObject& TempObject::operator =(TempObject&& in_other)
{
    // Move Assignment Operator //
    m_TempData = std::move(in_other.m_TempData);
    in_other.m_TempData = 0;
    return *this;
}