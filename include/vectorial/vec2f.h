/*
  Vectorial
  Copyright (c) 2010 Mikko Lehtonen
  Licensed under the terms of the two-clause BSD License (see LICENSE)
*/
#ifndef VECTORIAL_VEC2F_H

#ifndef VECTORIAL_SIMD4F_H
  #include "vectorial/simd4f.h"
#endif



namespace vectorial {
    
    class vec4f;
    class vec3f;

    class vec2f {
    public:

        simd4f value;
    
        inline vec2f() {}
        inline vec2f(const vec2f& v) : value(v.value) {}
        inline vec2f(const simd4f& v) : value(v) {}
        explicit inline vec2f(float xy) : value( simd4f_splat(xy) ) {}
        inline vec2f(float x, float y) : value( simd4f_create(x,y,0,0) ) {}
        explicit inline vec2f(const float *ary) : value( simd4f_uload2(ary) ) { }
            
        inline float x() const { return simd4f_get_x(value); }
        inline float y() const { return simd4f_get_y(value); }

        inline void load(const float *ary) { value = simd4f_uload2(ary); }
        inline void store(float *ary) const { simd4f_ustore2(value, ary); }
    
        enum { elements = 2 };

        static vec2f zero() { return vec2f(simd4f_zero()); }
        static vec2f one() { return vec2f(1.0f); }
        static vec2f xAxis() { return vec2f(1.0f, 0.0f); }
        static vec2f yAxis() { return vec2f(0.0f, 1.0f); }

        inline vec4f xyzw(float z, float w) const;
        inline vec4f xy00() const;
        inline vec4f xy01() const;
        inline vec3f xyz(float z) const;
        inline vec3f xy0() const;
        inline vec2f xy() const;

    };

    vectorial_inline vec2f operator-(const vec2f& lhs) {
        return vec2f( simd4f_sub(simd4f_zero(), lhs.value) );
    }


    vectorial_inline vec2f operator+(const vec2f& lhs, const vec2f& rhs) {
        return vec2f( simd4f_add(lhs.value, rhs.value) );
    }

    vectorial_inline vec2f operator-(const vec2f& lhs, const vec2f& rhs) {
        return vec2f( simd4f_sub(lhs.value, rhs.value) );
    }

    vectorial_inline vec2f operator*(const vec2f& lhs, const vec2f& rhs) {
        return vec2f( simd4f_mul(lhs.value, rhs.value) );
    }

    vectorial_inline vec2f operator/(const vec2f& lhs, const vec2f& rhs) {
        return vec2f( simd4f_div(lhs.value, rhs.value) );
    }


    vectorial_inline vec2f operator+=(vec2f& lhs, const vec2f& rhs) {
        return lhs = vec2f( simd4f_add(lhs.value, rhs.value) );
    }

    vectorial_inline vec2f operator-=(vec2f& lhs, const vec2f& rhs) {
        return lhs = vec2f( simd4f_sub(lhs.value, rhs.value) );
    }

    vectorial_inline vec2f operator*=(vec2f& lhs, const vec2f& rhs) {
        return lhs = vec2f( simd4f_mul(lhs.value, rhs.value) );
    }

    vectorial_inline vec2f operator/=(vec2f& lhs, const vec2f& rhs) {
        return lhs = vec2f( simd4f_div(lhs.value, rhs.value) );
    }



    vectorial_inline vec2f operator+(const vec2f& lhs, float rhs) {
        return vec2f( simd4f_add(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec2f operator-(const vec2f& lhs, float rhs) {
        return vec2f( simd4f_sub(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec2f operator*(const vec2f& lhs, float rhs) {
        return vec2f( simd4f_mul(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec2f operator/(const vec2f& lhs, float rhs) {
        return vec2f( simd4f_div(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec2f operator+(float lhs, const vec2f& rhs) {
        return vec2f( simd4f_add(simd4f_splat(lhs), rhs.value) );
    }

    vectorial_inline vec2f operator-(float lhs, const vec2f& rhs) {
        return vec2f( simd4f_sub(simd4f_splat(lhs), rhs.value) );
    }

    vectorial_inline vec2f operator*(float lhs, const vec2f& rhs) {
        return vec2f( simd4f_mul(simd4f_splat(lhs), rhs.value) );
    }

    vectorial_inline vec2f operator/(float lhs, const vec2f& rhs) {
        return vec2f( simd4f_div(simd4f_splat(lhs), rhs.value) );
    }


    vectorial_inline vec2f operator+=(vec2f& lhs, float rhs) {
        return lhs = vec2f( simd4f_add(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec2f operator-=(vec2f& lhs, float rhs) {
        return lhs = vec2f( simd4f_sub(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec2f operator*=(vec2f& lhs, float rhs) {
        return lhs = vec2f( simd4f_mul(lhs.value, simd4f_splat(rhs)) );
    }

    vectorial_inline vec2f operator/=(vec2f& lhs, float rhs) {
        return lhs = vec2f( simd4f_div(lhs.value, simd4f_splat(rhs)) );
    }


    vectorial_inline float dot(const vec2f& lhs, const vec2f& rhs) {
        return simd4f_get_x( simd4f_dot2(lhs.value, rhs.value) );
    }

    
    vectorial_inline float length(const vec2f& v) {
        return simd4f_get_x( simd4f_length2(v.value) );
    }

    vectorial_inline float length_squared(const vec2f& v) {
        return simd4f_get_x( simd4f_length2_squared(v.value) );
    }

    vectorial_inline vec2f normalize(const vec2f& v) {
        return vec2f( simd4f_normalize2(v.value) );
    }

    vectorial_inline vec2f min(const vec2f& a, const vec2f& b) {
        return vec2f( simd4f_min(a.value, b.value) );
    }

    vectorial_inline vec2f max(const vec2f& a, const vec2f& b) {
        return vec2f( simd4f_max(a.value, b.value) );
    }


}


namespace std {
    inline ::vectorial::vec2f min(const ::vectorial::vec2f& a, const ::vectorial::vec2f& b) { return ::vectorial::min(a,b); }
    inline ::vectorial::vec2f max(const ::vectorial::vec2f& a, const ::vectorial::vec2f& b) { return ::vectorial::max(a,b); }
}


#ifdef VECTORIAL_OSTREAM
#include <ostream>

vectorial_inline std::ostream& operator<<(std::ostream& os, const vectorial::vec2f& v) {
    os << "[ " << v.x() << ", "
               << v.y() << " ]";
    return os;
}
#endif




#endif
