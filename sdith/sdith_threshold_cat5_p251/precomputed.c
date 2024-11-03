#include "parameters.h"
#include "precomputed.h"

// Coefficient of polynomial with all factors
const uint8_t f_poly[248] = {0, 115, 116, 124, 173, 190, 17, 175, 89, 15, 100, 81, 167, 161, 42, 44, 160, 28, 2, 12, 142, 103, 138, 36, 156, 115, 56, 57, 38, 207, 52, 220, 131, 244, 33, 181, 137, 232, 14, 164, 48, 231, 91, 1, 133, 155, 211, 11, 164, 29, 74, 174, 180, 19, 208, 11, 244, 183, 170, 239, 109, 78, 168, 77, 70, 202, 191, 185, 117, 141, 99, 201, 189, 19, 78, 141, 131, 32, 130, 9, 118, 198, 222, 130, 71, 1, 197, 212, 188, 106, 151, 113, 214, 211, 63, 11, 8, 246, 2, 83, 56, 180, 178, 187, 152, 197, 182, 120, 191, 232, 195, 133, 66, 111, 226, 150, 41, 235, 184, 35, 218, 245, 7, 247, 2, 250, 11, 72, 33, 125, 163, 183, 227, 212, 211, 38, 101, 244, 10, 249, 187, 101, 218, 126, 175, 141, 132, 121, 211, 97, 135, 70, 131, 119, 91, 50, 231, 20, 57, 193, 208, 45, 179, 157, 127, 183, 30, 155, 127, 54, 128, 24, 248, 83, 224, 176, 203, 8, 138, 90, 91, 207, 219, 131, 238, 29, 104, 243, 94, 221, 29, 70, 61, 11, 46, 184, 34, 70, 228, 175, 109, 246, 156, 27, 38, 235, 2, 180, 171, 155, 137, 236, 199, 234, 185, 80, 148, 32, 168, 124, 21, 227, 13, 245, 170, 194, 197, 10, 221, 146, 156, 18, 31, 110, 245, 194, 49, 94, 60, 65, 81, 220, 11, 195, 152, 65, 241, 1};

// Leading Coefficients for Lagrangian Polynomials
const uint8_t leading_coefficients_of_lj_for_S[247] = {227, 131, 142, 164, 77, 239, 231, 112, 168, 159, 72, 121, 245, 108, 103, 97, 184, 183, 140, 77, 243, 110, 130, 229, 58, 248, 151, 99, 149, 83, 161, 117, 163, 236, 249, 91, 129, 204, 133, 211, 207, 117, 164, 45, 186, 236, 71, 45, 237, 200, 216, 41, 160, 30, 88, 245, 137, 129, 60, 247, 230, 27, 134, 19, 130, 138, 192, 166, 161, 3, 247, 169, 25, 47, 192, 142, 57, 73, 51, 79, 221, 15, 230, 105, 110, 189, 11, 225, 201, 38, 62, 73, 98, 140, 178, 167, 38, 200, 34, 152, 138, 54, 189, 55, 144, 171, 78, 34, 184, 147, 20, 127, 15, 211, 214, 1, 27, 221, 237, 207, 239, 166, 48, 172, 48, 166, 239, 207, 237, 221, 27, 1, 214, 211, 15, 127, 20, 147, 184, 34, 78, 171, 144, 55, 189, 54, 138, 152, 34, 200, 38, 167, 178, 140, 98, 73, 62, 38, 201, 225, 11, 189, 110, 105, 230, 15, 221, 79, 51, 73, 57, 142, 192, 47, 25, 169, 247, 3, 161, 166, 192, 138, 130, 19, 134, 27, 230, 247, 60, 129, 137, 245, 88, 30, 160, 41, 216, 200, 237, 45, 71, 236, 186, 45, 164, 117, 207, 211, 133, 204, 129, 91, 249, 236, 163, 117, 161, 83, 149, 99, 151, 248, 58, 229, 130, 110, 243, 77, 140, 183, 184, 97, 103, 108, 245, 121, 72, 159, 168, 112, 231, 239, 77, 164, 142, 131, 227};
