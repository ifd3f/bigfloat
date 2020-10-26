//
// Created by astrid on 10/8/20.
//

#ifndef BIGFLOAT_MAT_4_HPP
#define BIGFLOAT_MAT_4_HPP

#include <immintrin.h>
#include "bf.hpp"
#include "simd.hpp"

namespace bigfloat {
    class bf_ref {};

    class col4 {};

    class mat4 {
        // Column-major
        simd::vec4 cols[4];
    public:
        typedef simd::vec4 col;
        mat4();

        // Create a scaling matrix (I * x)
        explicit mat4(bf x);
        // Create a diagonal matrix, with a, b, c, and d as the diagonal values.
        mat4(bf a, bf b, bf c, bf d);
        // Create a matrix.
        mat4(bf m0, bf m1, bf m2, bf m3, bf m4, bf m5, bf m6, bf m7, bf m8, bf m9, bf m10, bf m11, bf m12, bf m13, bf m14, bf m15);
        // Create a matrix from columns.
        mat4(simd::vec4 c0, simd::vec4 c1, simd::vec4 c2, simd::vec4 c3);

        col& operator[](int i);

        void operator+=(mat4 &other);
        mat4 operator+(mat4 &other);
        void operator-=(mat4 &other);
        mat4 operator-(mat4 &other);
        void mul_componentwise(mat4 &other);
        mat4 operator*(mat4 &other);

        bool operator==(mat4 &other);

        mat4 T();
        mat4 inverted();
    };
}


#endif //BIGFLOAT_MAT_4_HPP