#include <iostream>
#include <memory>

float* convolve(float signal[], float kernel[], int signalsize, int kernelsize) {
    int s = signalsize - kernelsize + 1;
    float *ret = new float[s];
    
    for (int i = 0; i < s; i++) {
        float sum = 0;
        for (int j = 0; j < kernelsize; j++) {
            sum += kernel[j] * signal[i + j];
        }
        ret[i] = sum;
    }

    return ret;
};

template <class E>
void print_arr(E arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << ", ";
        } else {
            std::cout << std::endl;
        }
    }
}

int main() {
    float * sig = new float[5]{5, 3, 87, 2, 1};
    float * kernel = new float[3]{0.3, 0.4, 0.3};

    float * convol = convolve(sig, kernel, 5, 3);

    print_arr<float>(sig, 5);
    print_arr<float>(kernel, 3);
    print_arr<float>(convol, 3);
    
    delete [] sig;
    delete [] kernel;
    delete [] convol;
    return 0;
};
