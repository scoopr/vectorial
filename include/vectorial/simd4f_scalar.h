/*
  Vectorial
  Copyright (c) 2010 Mikko Lehtonen
  Licensed under the terms of the two-clause BSD License (see LICENSE)
*/
#ifndef VECTORIAL_SIMD4F_SCALAR_H
#define VECTORIAL_SIMD4F_SCALAR_H

#include <math.h>
#include <string.h>  // memcpy

#ifdef __cplusplus
extern "C" {
#endif


typedef struct { 
    float x;
    float y; 
    float z; 
    float w;
} simd4f;



vectorial_constexpr vectorial_inline simd4f simd4f_create(float x, float y, float z, float w) {
    #ifdef VECTORIAL_USE_CONSTEXPR
    return { x, y, z, w };
    #else
    simd4f s = { x, y, z, w };
    return s;
    #endif
}

vectorial_constexpr vectorial_inline simd4f simd4f_zero() { return simd4f_create(0.0f, 0.0f, 0.0f, 0.0f); }

vectorial_constexpr vectorial_inline simd4f simd4f_uload4(const float *ary) {
    return simd4f_create( ary[0], ary[1], ary[2], ary[3] );
}

vectorial_constexpr vectorial_inline simd4f simd4f_uload3(const float *ary) {
    return simd4f_create( ary[0], ary[1], ary[2], 0 );
}

vectorial_constexpr vectorial_inline simd4f simd4f_uload2(const float *ary) {
    return simd4f_create( ary[0], ary[1], 0, 0 );
}


vectorial_inline void simd4f_ustore4(const simd4f val, float *ary) {
    memcpy(ary, &val, sizeof(float) * 4);
}

vectorial_inline void simd4f_ustore3(const simd4f val, float *ary) {
    memcpy(ary, &val, sizeof(float) * 3);
}

vectorial_inline void simd4f_ustore2(const simd4f val, float *ary) {
    memcpy(ary, &val, sizeof(float) * 2);
}



// utilities
vectorial_constexpr vectorial_inline simd4f simd4f_splat(float v) { 
    return simd4f_create( v, v, v, v );
}

vectorial_constexpr vectorial_inline simd4f simd4f_splat_x(simd4f v) { 
    return simd4f_create( v.x, v.x, v.x, v.x );
}

vectorial_constexpr vectorial_inline simd4f simd4f_splat_y(simd4f v) { 
    return simd4f_create( v.y, v.y, v.y, v.y );
}

vectorial_constexpr vectorial_inline simd4f simd4f_splat_z(simd4f v) { 
    return simd4f_create( v.z, v.z, v.z, v.z ); 
}

vectorial_constexpr vectorial_inline simd4f simd4f_splat_w(simd4f v) { 
    return simd4f_create( v.w, v.w, v.w, v.w ); 
}

vectorial_constexpr vectorial_inline simd4f simd4f_reciprocal(simd4f v) { 
    return simd4f_create( 1.0f/v.x, 1.0f/v.y, 1.0f/v.z, 1.0f/v.w ); 
}

vectorial_inline simd4f simd4f_sqrt(simd4f v) { 
    return simd4f_create( sqrtf(v.x), sqrtf(v.y), sqrtf(v.z), sqrtf(v.w) ); 
}

vectorial_inline simd4f simd4f_rsqrt(simd4f v) { 
    return simd4f_create( 1.0f/sqrtf(v.x), 1.0f/sqrtf(v.y), 1.0f/sqrtf(v.z), 1.0f/sqrtf(v.w) ); 
}


// arithmetic

vectorial_constexpr vectorial_inline simd4f simd4f_add(simd4f lhs, simd4f rhs) {
    return simd4f_create( lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w );
}

vectorial_constexpr vectorial_inline simd4f simd4f_sub(simd4f lhs, simd4f rhs) {
    return simd4f_create( lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w );
}

vectorial_constexpr vectorial_inline simd4f simd4f_mul(simd4f lhs, simd4f rhs) {
    return simd4f_create( lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w );
}

vectorial_constexpr vectorial_inline simd4f simd4f_div(simd4f lhs, simd4f rhs) {
    return simd4f_create( lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w );
}

vectorial_constexpr vectorial_inline simd4f simd4f_madd(simd4f m1, simd4f m2, simd4f a) {
    return simd4f_add( simd4f_mul(m1, m2), a );
}

vectorial_constexpr vectorial_inline simd4f simd4f_cross3(simd4f lhs, simd4f rhs) {
    return simd4f_create( lhs.y * rhs.z - lhs.z * rhs.y,
                          lhs.z * rhs.x - lhs.x * rhs.z,
                          lhs.x * rhs.y - lhs.y * rhs.x, 0);
}


vectorial_constexpr vectorial_inline float simd4f_get_x(simd4f s) { return s.x; }
vectorial_constexpr vectorial_inline float simd4f_get_y(simd4f s) { return s.y; }
vectorial_constexpr vectorial_inline float simd4f_get_z(simd4f s) { return s.z; }
vectorial_constexpr vectorial_inline float simd4f_get_w(simd4f s) { return s.w; }


vectorial_constexpr vectorial_inline simd4f simd4f_shuffle_wxyz(simd4f s) { return simd4f_create(s.w, s.x, s.y, s.z); }
vectorial_constexpr vectorial_inline simd4f simd4f_shuffle_zwxy(simd4f s) { return simd4f_create(s.z, s.w, s.x, s.y); }
vectorial_constexpr vectorial_inline simd4f simd4f_shuffle_yzwx(simd4f s) { return simd4f_create(s.y, s.z, s.w, s.x); }



vectorial_constexpr vectorial_inline simd4f simd4f_merge_high(simd4f abcd, simd4f xyzw) { 
    return simd4f_create(abcd.z, abcd.w, xyzw.z, xyzw.w);
}

vectorial_constexpr vectorial_inline simd4f simd4f_flip_sign_0101(simd4f s) {
    return simd4f_create(s.x, -s.y, s.z, -s.w);
}

vectorial_constexpr vectorial_inline simd4f simd4f_flip_sign_1010(simd4f s) {
    return simd4f_create(-s.x, s.y, -s.z, s.w);
}

vectorial_constexpr vectorial_inline simd4f simd4f_min(simd4f a, simd4f b) {
    return simd4f_create( a.x < b.x ? a.x : b.x, 
                          a.y < b.y ? a.y : b.y, 
                          a.z < b.z ? a.z : b.z, 
                          a.w < b.w ? a.w : b.w );
}

vectorial_constexpr vectorial_inline simd4f simd4f_max(simd4f a, simd4f b) {
    return simd4f_create( a.x > b.x ? a.x : b.x, 
                          a.y > b.y ? a.y : b.y, 
                          a.z > b.z ? a.z : b.z, 
                          a.w > b.w ? a.w : b.w );
}


#ifdef __cplusplus
}
#endif


#endif

