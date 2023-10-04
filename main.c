#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "quaterinions.h"

void print_res(char* name, bool result){
    char* res = result? "PASSED" : "FAILED";
    printf("%s test:\t%s\n", name, res);
}

int main(){
    printf("Hello World\n");

    quaternion q1 = {1,2,3,4};
    quaternion q2 = {4,3,2,1};

    bool quat_op_good = true;

    bool compare_good = quaternion_eq(q1,q1) && !quaternion_eq(q1,q2);
    print_res("Equality", compare_good);
    quat_op_good &= compare_good;

    bool compare_eps_good = quaternion_eps_eq(q1,q2,3.1) && !quaternion_eps_eq(q1,q2,2);
    print_res("Epsilon equality", compare_eps_good);
    float eq_eps = 10e-7;
    quat_op_good &= compare_eps_good;

    quaternion q1_conj = {1,-2,-3,-4};
    bool conj_good = quaternion_eq(quaternion_conjugate(q1), q1_conj);
    print_res("Conjugation", conj_good);
    quat_op_good &= conj_good;
    
    float q1_norm = sqrtf(1 + 4 + 9 + 16);
    bool norm_good = quaternion_norm(q1) == q1_norm;
    print_res("Norm", norm_good);
    quat_op_good &= norm_good;

    quaternion q1x5 = {5,10,15,20};
    bool prod_scalar_good = quaternion_eq(quaternion_prod_scalar(5, q1), q1x5);
    print_res("Product with scalar", prod_scalar_good);
    quat_op_good &= prod_scalar_good;

    quaternion q1_normalized = {1/q1_norm, 2/q1_norm, 3/q1_norm, 4/q1_norm};
    bool normalization_good = quaternion_eps_eq(quaternion_normalize(q1), q1_normalized,eq_eps);
    print_res("Normalization", normalization_good);
    quat_op_good &= normalization_good;

    float q1_norm2 = q1_norm*q1_norm;
    quaternion q1_inv = {1/q1_norm2,-2/q1_norm2,-3/q1_norm2,-4/q1_norm2};
    bool inversion_good = quaternion_eps_eq(quaternion_inverse(q1), q1_inv, eq_eps);
    print_res("Inversion", inversion_good);
    quat_op_good &= inversion_good;

    quaternion q1pq2 = {5,5,5,5};
    bool addition_good = quaternion_eps_eq(quaternion_add(q1,q2), q1pq2, eq_eps);
    print_res("Addition", addition_good);
    quat_op_good &= addition_good;

    quaternion q1mq2 = {-3,-1,1,3};
    bool substraction_good = quaternion_eps_eq(quaternion_substract(q1,q2), q1mq2, eq_eps);
    print_res("Substraction", substraction_good);
    quat_op_good &= substraction_good;

    quaternion q1xq2 = {1*4 - 2*3 - 3*2 - 4*1, 1*3 + 2*4 + 3*1 - 4*2, 1*2 - 2*1 + 3*4 +4*3, 1*1 + 2*2 - 3*3 + 4*4};
    bool product_good = quaternion_eps_eq(quaternion_product(q1,q2), q1xq2, eq_eps);
    print_res("Product", product_good);
    quat_op_good &= product_good;

    printf("-------------------------------------\n");
    print_res("Quaternion operations result", quat_op_good);

    return 0;
}