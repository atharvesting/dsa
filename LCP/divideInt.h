/*
@METADATA
Problem: 
Link: 
Source: 
Pattern: 
Publish: false

@JOURNEY


@ITERATION_FAILED
int divide(int dividend, int divisor) {
    int q = 0;
    int dvs = (divisor < 0) ? -1 * divisor : divisor;
    int dvd = (dividend < 0) ? -1 * dividend : dividend;
    while (dvd > 0) {
        dvd -= dvs;
        q++;
    }
    if (((divisor > 0) && (dividend < 0)) || ((divisor < 0) && (dividend > 0))) return -1 * q;
    return q;
}
Method: Use repeated subtraction to simulate division.
Why it failed: 
- Entry condition for the while loop was wrong as it allowed an extra entry.


@ITERATION_SUCCESS
Method: 
Complexity: 
Why: 
*/

#pragma once
#include <vector>
#include <string>

int divide(int dividend, int divisor) {
    int q = 0;
    int dvs = (divisor > 0) ? -1 * divisor : divisor;
    int dvd = (dividend > 0) ? -1 * dividend : dividend;
    while (dvd - dvs <= 0) {
        dvd -= dvs;
        q++;
    }
    if (((divisor > 0) && (dividend < 0)) || ((divisor < 0) && (dividend > 0))) return -1 * q;
    return q;
}