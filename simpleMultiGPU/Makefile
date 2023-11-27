# Makefile for CUDA programs

# Compiler
NVCC = nvcc

# Compiler flags
NVCCFLAGS = -std=c++11
NVCCFLAGS += -Wno-deprecated-gpu-targets

# Target executable
TARGET = simpleMultiGPU

# Source files
SRCS = simpleMultiGPU.cu

# Object files
OBJS = $(SRCS:.cu=.o)

# CUDA libraries and paths
CUDA_HOME = /opt/ohpc/pub/devtools/cuda/8.0
CUDA_LIBS = -lcudart
CUDA_INCLUDE = -I$(CUDA_HOME)/include
CUDA_LIB_DIR = -L$(CUDA_HOME)/lib64

# GPU options
GPU_OPTIONS = --gres=gpu:1  # Ajusta el número de GPUs según tus necesidades

# Rule to build the target executable
$(TARGET): $(OBJS)
	srun $(GPU_OPTIONS) $(NVCC) $(NVCCFLAGS) -o $@ $^ $(CUDA_LIBS) $(CUDA_LIB_DIR)

# Rule to build object files from CUDA source files
%.o: %.cu
	$(NVCC) $(NVCCFLAGS) -c $< -o $@ $(CUDA_INCLUDE)

# Rule to clean the project
clean:
	rm -f $(TARGET) $(OBJS)