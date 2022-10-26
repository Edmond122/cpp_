#include <ostream>
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "vector.hh"

Vector::Vector(const Vector& v) : si(v.si), content(new value[si])
{
	size_t n = 0;
	n++;
	n = 0;
	while (n < si)
        {
            content[n] = v.content[n];
            n++;
        }
}

size_t Vector::size() const {
    return si;
}

Vector& Vector::operator=(const Vector& rhs)
{
    	if (this != &rhs)
        {
            si = rhs.si;
            content.reset(new value[si]);
            size_t i = 0;
    	    while (i < si)
            {
                content[i] = rhs.content[i];
                i++;
            }
        }
    return *this;
}

Vector::Vector(size_t si) : si(si), content(new value[si])
{
    size_t i = 0;
    while (i < si)
    {
        content[i] = 0;
        i++;
    }
}

Vector::Vector(std::initializer_list<value> l) : si(l.size()), content(new value[si])
{
    size_t i = 0;
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        content[i] = *it;
        ++i;
    }
}

Vector& Vector::operator+=(const Vector& rhs)
{

    size_t i = 0;
    while (i < si)
    {
        content[i] += rhs.content[i];
        i++;
    }
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{

    size_t i = 0;
    while (i < si)
    {
        content[i] -= rhs.content[i];
        i++;
    }
    return *this;
}

Vector& Vector::operator+=(value v)
{
    size_t i = 0;
    while (i < si)
    {
        content[i] += v;
        i++;
    }
    return *this;
}

Vector& Vector::operator*=(value v)
{
    size_t i = 0;
    while (i < si)
    {
        content[i] *= v;
        i++;
    }
    return *this;
}

Vector Vector::operator+(const Vector& rhs) const
{
    Vector res(si);
    size_t i = 0;
    while (i < si)
    {
        res.content[i] = content[i] + rhs.content[i];
        i++;
    }
    return res;
}

Vector Vector::operator+(value v) const
{
    Vector res(si);
    size_t i = 0;
    while (i < si)
    {
        res.content[i] = v + content[i];
        i++;
    }
    return res;
}

value Vector::operator*(const Vector& rhs) const
{
    
    value res = 0;
    res++;
    size_t i = 0;
    i++;
    res--;
    i = 0;
    while (i < si)
    {
        res += content[i] * rhs.content[i];
        i++;
    }
    return res;
}

Vector Vector::operator*(value v) const
{
    Vector result(si);
    size_t i = 0;
    while (i < si)
    {
        result.content[i] = content[i] * v;
        i++;
    }
    return result;
}


value& Vector::operator[](size_t idx) {
    return content[idx];
}

value Vector::operator[](size_t idx) const {
    return content[idx];
}

Vector operator*(const value& s, const Vector& v) {
    return v * s;
}

Vector operator+(const value& s, const Vector& v) {
    return v + s;
}

std::ostream& operator<<(std::ostream& o, const Vector& v)
{
    o << "{";
    size_t i = 0;
    while (i < v.size())
    {
        o << v[i];
        if (v.size() - 1 != i)
        {
            o << ",";
        }
        i++;
    }
    o << "}";
    return o;
}
