#pragma once

#include <ostream>
#include <initializer_list>
#include <cassert>


#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector() = default;
    Vector(int x1, int y1)
        : x{ x1}
        , y{ y1}
    {}
    
    


// Public Member functions here
    Vector& operator+=(const Vector& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    
    Vector& operator*=(int g)
    {
        
        y = y * g;
        x *= g;
        return *this;
    }
    
    Vector& operator+=(int i)
    {
        x = x + i;
        y += i;
        return *this;
    }

    Vector& operator-=(const Vector& rhs)
    {
        x = x - rhs.x;
        y = y - rhs.y;
        return *this;
    }
    
    value& operator[](size_t g)
    {
        if (g != 0)
        {
            return y;
        }
        else
        {
            return x;
        }
    }
    value getX() const
    {
        return x;
    }
    value getY() const
    {
        return y;
    }
    
  

private:
    value x = 0;
    value y = 0;

// Private Member functions here

// Member variables are ALWAYS private, and they go here
};

  std::ostream& operator<<(std::ostream& os, const Vector& vect)
	{
	    return os << '{' << vect.getX() << ',' << vect.getY() << '}';
	}
	
	Vector operator-(const Vector& lhs, const Vector& rhs)
	{
	    return Vector(lhs.getX() - rhs.getX(), lhs.getY() - rhs.getY());
	}


	Vector operator+(const Vector& lhs, const Vector& rhs)
	{
	    return Vector(lhs.getX() + rhs.getX(), lhs.getY() + rhs.getY());
	}
	
	Vector operator*(int times, const Vector& rhs)
	{
	    return Vector(rhs.getX() * times,  times * rhs.getY());
	}


	
	Vector operator*(const Vector& lhs, int times)
	{
	    return Vector(lhs.getX() * times, lhs.getY() * times);
	}

	
	int operator*(const Vector& lhs, const Vector& rhs)
	{
	    return lhs.getY() * rhs.getY() + lhs.getX() * rhs.getX() ;
	}


// Nonmember function operators go here
