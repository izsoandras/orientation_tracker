#include "quaterinions.h"

quaternion quaternion_conjugate(quaternion q){
    quaternion res = {q.a, -q.b, -q.c, -q.d};
    return res;
}
float quaternion_norm(quaternion q){
    return sqrtf(q.a*q.a + q.b*q.b + q.c*q.c + q.d*q.d);
}
quaternion quaternion_normalize(quaternion q){
    float norm = quaternion_norm(q);
    return quaternion_prod_scalar(1/norm, q);
}
quaternion quaternion_inverse(quaternion q){
    float norm2 = q.a*q.a + q.b*q.b + q.c*q.c + q.d*q.d;
    quaternion res = quaternion_conjugate(q);
    res.a /= norm2;
    res.b /= norm2;
    res.c /= norm2;
    res.d /= norm2;

    return res;
}
quaternion quaternion_prod_scalar(float f, quaternion q){
    quaternion res = {f*q.a, f*q.b, f*q.c, f*q.d};
    return res;
}
quaternion quaternion_add(quaternion q1, quaternion q2){
    quaternion res = {q1.a + q2.a, q1.b + q2.b, q1.c + q2.c, q1.d + q2.d};
    return res;
}
quaternion quaternion_substract(quaternion q1, quaternion q2){
    quaternion res = {q1.a - q2.a, q1.b - q2.b, q1.c - q2.c, q1.d - q2.d};
    return res;
}
quaternion quaternion_product(quaternion q1, quaternion q2){
    quaternion res = {q1.a*q2.a - q1.b*q2.b - q1.c*q2.c - q1.d*q2.d, q1.a*q2.b + q1.b*q2.a + q1.c*q2.d - q1.d*q2.c, q1.a*q2.c - q1.b*q2.d + q1.c*q2.a + q1.d*q2.b, q1.a*q2.d + q1.b*q2.c - q1.c*q2.b + q1.d*q2.a};
    return res;
}


bool quaternion_eq(quaternion q1, quaternion q2){
    return q1.a == q2.a && q1.b == q2.b && q1.c == q2.c && q1.d == q2.d;
}

bool quaternion_eps_eq(quaternion q1, quaternion q2, float eps){
    return fabs(q1.a-q2.a) < eps && fabs(q1.b-q2.b) < eps && fabs(q1.c-q2.c) < eps && fabs(q1.d-q2.d) < eps;
}