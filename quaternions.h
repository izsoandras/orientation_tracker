#ifndef _QUATERNIONS_C
#define _QUATERNIONS_C

#include <math.h>
#include <stdbool.h>

/**
 * @brief Data structure to store quaternions
 * 
 * Quaternion data structure to be used with the operations defined below. The real part is stored in a, the coefficients of the vector/imaginary part {i,j,k} is stored in {b,c,d}.
 */
typedef struct quaternion
{
    double a;   /**< quaternion#a stores the real part of the quaternion. */
    double b;   /**< quaternion#b stores the coefficients of the imaginary unit vector i. */
    double c;   /**< quaternion#b stores the coefficients of the imaginary unit vector j. */
    double d;   /**< quaternion#b stores the coefficients of the imaginary unit vector k. */
} quaternion;

/**
 * @brief Calculate the conjugation of the quaternion.
 * 
 *  The conjugation of a quaternion is each of the imaginary/vector negated: q* = {a, -b, -c, -d}.
 * 
 * @param q Quaternion to be negated.
 * @return The conjugate of @p q.
 */
quaternion quaternion_conjugate(quaternion q);

/**
 * @brief Calculate the norm of a quaternion.
 * 
 *  The norm of a quaternion is calculated as the 2-norm of the vector, created from the coefficients: ||q|| = sqrt(a^2 + b^2 + c^2 + d^2)
 * 
 * @param q The quaternion which's norm is to be calculated.
 * @return The norm of @p q.
 */
float quaternion_norm(quaternion q);

/**
 * @brief Return a normalized version of @p q.
 * 
 *  Divide each of the components of @p q and return them as a new quaternion: q' = q/||q||.
 * 
 * @param q The quaternion to be normalized.
 * @return The normalized version of @p q.
 */
quaternion quaternion_normalize(quaternion q);

/**
 * @brief Calculate the inverse of quaternion @p q.
 * 
 * The inverse of a quaternion is defined as the quaternion with wich it's product gives {1,0,0,0}: q^-1 = q*\/||q||^2
 * 
 * @param q The quaternion to be inverted
 * @return The inverse of @p q.
 */
quaternion quaternion_inverse(quaternion q);

/**
 * @brief Multiply a quaternion with a real value.
 * 
 * Multiply each component of the quaternion of a real number: r*q = q*r = {r*a, r*b, r*c, r*d}.
 * 
 * @param f Real value to be multiplied with.
 * @param q Quaternion to be multiplied.
 * @return Result of multiplication of @p f * @p q 
 */
quaternion quaternion_prod_scalar(float f, quaternion q);

/**
 * @brief Add two quaternions.
 * 
 * The addition of each of the coefficients: q1 + q2 = {a1 + a2, b1 + b2, c1 + c2, d1 + d2}.
 * 
 * @param q1 First operand
 * @param q2 Second operand
 * @return Result of the addition @p q1 + @p q2
 */
quaternion quaternion_add(quaternion q1, quaternion q2);

/**
 * @brief Substract @p q2 from @p q1.
 * 
 * Substraction of each of the elements: q1 - q2 = {a1 - a2, b1 - b2, c1 - c2, d1 - d2}.
 * 
 * @param q1 Quaternion to be substracted from.
 * @param q2 Quaternion to be substracted.
 * @return Result of the substraction @p q1 - @p q2.
 */
quaternion quaternion_substract(quaternion q1, quaternion q2);

/**
 * @brief Calculate the product of @p q1 and @p q2 according to quaternion rules.
 * 
 * Quaternions are basically multiplied the same as polinomials: each element by each element. Furthermore there are some simplification rules for the unit vectors that can be used, to only get 4 monomials at the end:
 * 
 *      i^2 = j^2 = k^2 = -1, i*j = k, j*k = i, k*i = j   =>   i*j*k = -1   (by definition)
 * 
 * Properties:
 *      - associative -> (q1*q2)*q3 = q1*(q2*q3)
 *      - distributive -> q1*(q2 + q3) = q1*q2 + q1*q3
 *      - NOT commutative -> q1*q2 != q2*q1 (in general)
 * 
 * @param q1 
 * @param q2 
 * @return quaternion 
 */
quaternion quaternion_product(quaternion q1, quaternion q2);

/**
 * @brief Exact equality comparison of two quaternions
 * 
 * Checks if each of the coefficients are equal between the two quaternions. WARNING: use cautiously because of imprecise floating point representation.
 * 
 * @param q1 First operand
 * @param q2 Second operand
 * @return true If each the coefficients are equal.
 * @return false Otherwise
 */
bool quaternion_eq(quaternion q1, quaternion q2);

/**
 * @brief Checks if for each of the coefficients, the absolute difference is less then @p esp.
 * 
 * To get around of the imprecision of the floating point number representation, compare for equality with a tolerance given by @p eps
 * 
 * @param q1 First operand
 * @param q2 Second operand
 * @param eps Supremum of the difference between each of the coefficients
 * @return true If the difference between each of the coefficients is less then @p eps.
 * @return false Otherwise
 */
bool quaternion_eps_eq(quaternion q1, quaternion q2, float eps);
#endif