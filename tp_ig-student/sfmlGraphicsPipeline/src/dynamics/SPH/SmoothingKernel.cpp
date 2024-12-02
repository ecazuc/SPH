#include "./../../include/dynamics/SPH/SmoothingKernel.hpp"
#include <cmath>

#define M_PI 3.14159265358979323846

SmoothingKernel::SmoothingKernel(float smoothingLength) : smoothingLength(smoothingLength) {}

float SmoothingKernel::poly6Kernel(float distance) const {
    if (distance > smoothingLength || distance < 0.0f) return 0.0f;
    float h = smoothingLength;
    float dist2 = distance * distance;
    float constant = 315.0f / (64.0f * M_PI * pow(h, 9));
    return constant * pow(pow(h,2) - dist2, 3);
}

float SmoothingKernel::spikyKernelGradient(float distance) const {
    if (distance > smoothingLength || distance < 0.0f) return 0.0f;
    float h = smoothingLength;
    float dist = distance;
    float constant = -45.0f / (M_PI * pow(h, 6));
    return constant * pow(h - dist, 2) * dist;
}

float SmoothingKernel::viscosityKernelLaplacian(float distance) const {
    if (distance > smoothingLength || distance < 0.0f) return 0.0f;
    float h = smoothingLength;
    float dist = distance;
    float constant = 45.0f / (M_PI * pow(h, 6));
    return constant * (h - dist);
}
