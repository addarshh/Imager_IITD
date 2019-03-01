FLAG = -std=c++11
# your_path = ~
# CXXXFLAG = -I ~/OpenBLAS/include/ -L ~/OpenBLAS/lib -lpthread -lgfortran

# ACTIVATE_OPENBLAS = -I ~/OpenBLAS/include/ -L ~/OpenBLAS/lib/ -lopenblas -lpthread
# LDFLAGS =  -L ~/intel/mkl/lib/intel64 -Wl,--no-as-needed -lpthread -lm -ldl -m64 -I ~/intel/mkl/include

all: imager

imager: final_processor Pool convolution Activation FinalLayer
		g++-8 outputs/final_processor outputs/Pool outputs/convolution outputs/Activation outputs/FinalLayer -o imager

final_processor: src/final_processor.cpp include/Pool.h include/Activation.h include/FinalLayer.h include/convolution.h
	g++-8 -c src/final_processor.cpp -o outputs/final_processor

Pool: src/Pool.cpp include/Pool.h
	g++-8 -c src/Pool.cpp -o outputs/Pool

convolution: src/convolution.cpp include/convolution.h
	g++-8 -c src/convolution.cpp -o outputs/convolution

Activation: src/Activation.cpp include/Activation.h
	g++-8 -c src/Activation.cpp -o outputs/Activation

FinalLayer: src/FinalLayer.cpp include/FinalLayer.h
	g++-8 -c src/FinalLayer.cpp -o outputs/FinalLayer

clean:
	rm -rf outputs/* imager sigmoid_result.txt softmax_result.txt