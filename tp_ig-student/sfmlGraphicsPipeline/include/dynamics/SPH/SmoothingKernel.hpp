#ifndef SMOOTHINGKERNEL_HPP
#define SMOOTHINGKERNEL_HPP

class SmoothingKernel {
public:
    /** @brief Instantiate a smoothing kernel.
     *
     * Constructs a new smoothing kernel with a given smoothing length.
     *
     * @param smoothingLength The smoothing length for the kernel.
     */
    SmoothingKernel(float smoothingLength);

    /** @brief Compute the poly6 kernel.
     *
     * Compute the poly6 kernel for a given distance.
     *
     * @param distance The distance to the kernel center.
     * @return The value of the poly6 kernel at the given distance.
     */
    float poly6Kernel(float distance) const;

    /** @brief Compute the gradient of the spiky kernel.
     *
     * Compute the gradient of the spiky kernel for a given distance.
     *
     * @param distance The distance to the kernel center.
     * @return The value of the gradient of the spiky kernel at the given distance.
     */
    float spikyKernelGradient(float distance) const;

    /** @brief Compute the Laplacian of the viscosity kernel.
     *
     * Compute the Laplacian of the viscosity kernel for a given distance.
     *
     * @param distance The distance to the kernel center.
     * @return The value of the Laplacian of the viscosity kernel at the given distance.
     */
    float viscosityKernelLaplacian(float distance) const;

private:

    /** @brief The smoothing length for the kernel. */
    float smoothingLength;
};

#endif // SMOOTHINGKERNEL_HPP
