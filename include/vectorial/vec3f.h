/*
  Vectorial
  Copyright (c) 2010 Mikko Lehtonen
  Licensed under the terms of the two-clause BSD License (see LICENSE)
*/
#ifndef VECTORIAL_VEC3F_H

#ifndef VECTORIAL_SIMD4F_H
  #include "vectorial/simd4f.h"
#endif



namespace vectorial {
    
    class vec4f;
    class vec2f;

    class vec3f {
    public:

        simd4f value;
    
        inline vec3f() {}
        inline vec3f(const vec3f& v) : value(v.value) {}
        inline vec3f(const simd4f& v) : value(v) {}
        explicit inline vec3f(float xyz) : value( simd4f_splat(xyz) ) {}
        inline vec3f(float x, float y, float z) : value( simd4f_create(x,y,z,0) ) {}
        explicit inline vec3f(const float *ary) : value( simd4f_uload3(ary) ) { }
            
        inline float x() const { return simd4f_get_x(value); }
        inline float y() const { return simd4f_get_y(value); }
        inline float z() const { return simd4f_get_z(value); }

        inline void load(const float *ary) { value = simd4f_uload3(ary); }
        inline void store(float *ary) const { simd4f_ustore3(value, ary); }
    
        enum { elements = 3 };

        static vec3f zero() { return vec3f(simd4f_zero()); }
        static vec3f one() { return vec3f(1.0f); }
        static vec3f xAxis() { return vec3f(1.0f, 0.0f, 0.0f); }
        static vec3f yAxis() { return vec3f(0.0f, 1.0f, 0.0f); }
        static vec3f zAxis() { return vec3f(0.0f, 0.0f, 1.0f); }

        inline vec4f xyz0() const;
        inline vec4f xyz1() const;
        inline vec4f xyzw(float w) const;
        inline vec3f xyz() const;
        inline vec3f xy0() const;
        inline vec2f xy() const;
    };

    vectorial_inline vec3f operator-(const vec3f& lhs) {
        return vec3f( simd4f_sub(simd4f_zero(), lhs.value) );
    }
    

    vectorial_inline vec3f operator+(const vec3f& lhs, const vec3f& rhs) {
        return vec3f( simd4f_add(lhs.value, rhs.value) );
    }

    vectorial_inline vec3f operator-(const vec3f& lhs, const vec3f& rhs) {
        return vec3f( simd4f_sub(lhs.value, rhs.value) );
    }

    vectorial_inline vec3f operator*(const vec3f& lhs, const vec3f& rhs) {
        return vec3f( simd4f_mul(lhs.value, rhs.value) );
    }

    vectorial_inline vec3f operator/(const vec3f& lhs, const vec3f& rhs) {
        return vec3f( simd4f_div(lhs.value, rhs.value) );
    }


    vectorial_inline vec3f operator+=(vec3f& lhs, const vec3f& rhs) {
        return lhs = vec3f( simd4f_add(lhs.value, rhs.value) );
    }

    vectorial_inline vec3f operator-=(vec3f& lhs, const vec3f& rhs) {
        return lhs = vec3f( simd4f_sub(lhs.value, rhs.value) );
    }

    vectorial_inline vec3f operator*=(vec3f& lhs, const vec3f& rhs) {
        return lhs = vec3f( simd4f_mul(lhs.value, rhs.value) );
    }

    vectorial_inline vec3f operator/=(vec3f& lhs, const vec3f& rhs) {
        return lhs = vec3f( simd4f_div(lhs.value, rhs.value) );
    }



    vectorial_inline vec3f operator+(const vec3f& lhs, float rhs) {
        return vec3f( simd4f_add(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec3f operator-(const vec3f& lhs, float rhs) {
        return vec3f( simd4f_sub(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec3f operator*(const vec3f& lhs, float rhs) {
        return vec3f( simd4f_mul(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec3f operator/(const vec3f& lhs, float rhs) {
        return vec3f( simd4f_div(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec3f operator+(float lhs, const vec3f& rhs) {
        return vec3f( simd4f_add(simd4f_splat(lhs), rhs.value) );
    }

    vectorial_inline vec3f operator-(float lhs, const vec3f& rhs) {
        return vec3f( simd4f_sub(simd4f_splat(lhs), rhs.value) );
    }

    vectorial_inline vec3f operator*(float lhs, const vec3f& rhs) {
        return vec3f( simd4f_mul(simd4f_splat(lhs), rhs.value) );
    }

    vectorial_inline vec3f operator/(float lhs, const vec3f& rhs) {
        return vec3f( simd4f_div(simd4f_splat(lhs), rhs.value) );
    }


    vectorial_inline vec3f operator+=(vec3f& lhs, float rhs) {
        return lhs = vec3f( simd4f_add(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec3f operator-=(vec3f& lhs, float rhs) {
        return lhs = vec3f( simd4f_sub(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec3f operator*=(vec3f& lhs, float rhs) {
        return lhs = vec3f( simd4f_mul(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec3f operator/=(vec3f& lhs, float rhs) {
        return lhs = vec3f( simd4f_div(lhs.value, simd4f_splat(rhs)) );
    }


    vectorial_inline float dot(const vec3f& lhs, const vec3f& rhs) {
        return simd4f_get_x( simd4f_dot3(lhs.value, rhs.value) );
    }

    vectorial_inline vec3f cross(const vec3f& lhs, const vec3f& rhs) {
        return simd4f_cross3(lhs.value, rhs.value);
    }
    
    
    vectorial_inline float length(const vec3f& v) {
        return simd4f_get_x( simd4f_length3(v.value) );
    }

    vectorial_inline float length_squared(const vec3f& v) {
        return simd4f_get_x( simd4f_length3_squared(v.value) );
    }

    vectorial_inline vec3f normalize(const vec3f& v) {
        return vec3f( simd4f_normalize3(v.value) );
    }

    vectorial_inline vec3f min(const vec3f& a, const vec3f& b) {
        return vec3f( simd4f_min(a.value, b.value) );
    }

    vectorial_inline vec3f max(const vec3f& a, const vec3f& b) {
        return vec3f( simd4f_max(a.value, b.value) );
    }

}


namespace std {
    inline ::vectorial::vec3f min(const ::vectorial::vec3f& a, const ::vectorial::vec3f& b) { return ::vectorial::min(a,b); }
    inline ::vectorial::vec3f max(const ::vectorial::vec3f& a, const ::vectorial::vec3f& b) { return ::vectorial::max(a,b); }
}


#ifdef VECTORIAL_OSTREAM
#include <ostream>

vectorial_inline std::ostream& operator<<(std::ostream& os, const vectorial::vec3f& v) {
    os << "[ " << v.x() << ", "
               << v.y() << ", "
               << v.z() << " ]";
    return os;
}
#endif




#endif
