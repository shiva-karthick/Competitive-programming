# Use a stable Ubuntu version as the base image
FROM ubuntu:22.04

# Set environment variables to prevent interactive prompts during installation
ENV DEBIAN_FRONTEND=noninteractive

# Update package lists and install all dependencies in one layer
# - build-essential: Includes g++, gcc, make, and other C/C++ essentials
# - openjdk-17-jdk: Java Development Kit (version 17)
# - python3, python3-pip: System Python
# - git: For version control
# - cmake: A common build tool for C++
# - curl: Utility for transferring data with URLs
# - pyenv dependencies: Required to build various Python versions with pyenv
RUN apt-get update && apt-get install -y \
    build-essential \
    openjdk-17-jdk \
    python3 \
    python3-pip \
    git \
    cmake \
    curl \
    libssl-dev \
    zlib1g-dev \
    libbz2-dev \
    libreadline-dev \
    libsqlite3-dev \
    wget \
    llvm \
    libncursesw5-dev \
    xz-utils \
    tk-dev \
    libxml2-dev \
    libxmlsec1-dev \
    libffi-dev \
    liblzma-dev \
    && rm -rf /var/lib/apt/lists/*

# --- Install pyenv ---
# We clone it into the /opt directory to make it available system-wide
RUN git clone https://github.com/pyenv/pyenv.git /opt/pyenv

# Set environment variables for pyenv
ENV PYENV_ROOT /opt/pyenv
ENV PATH $PYENV_ROOT/bin:$PATH

# Set the working directory inside the container
# This is where we will mount your local code
WORKDIR /app

# This command keeps the container running so you can connect to it.
# It's a simple way to prevent the container from exiting immediately.
CMD ["sleep", "infinity"]
