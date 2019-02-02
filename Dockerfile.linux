FROM gcc:8
ENV  DEBIAN_FRONTEND=noninteractive 

RUN apt-get update
RUN apt-get install dialog  apt-utils  -y --no-install-recommends
RUN apt-get install git-core python-dev libxml2-dev libxslt-dev -y

RUN wget https://github.com/Kitware/CMake/releases/download/v3.13.2/cmake-3.13.2-Linux-x86_64.sh -O cmake.sh \
      && chmod u+x cmake.sh \
      && mkdir /usr/bin/cmake \
      && ./cmake.sh --skip-license --prefix=/usr/bin/cmake \
      && rm cmake.sh

RUN wget https://dl.bintray.com/boostorg/release/1.68.0/source/boost_1_68_0.tar.gz -O /tmp/boost.tar.gz \
    && tar -xvzf /tmp/boost.tar.gz && cd boost_1_68_0 && ./bootstrap.sh  && ./b2 install && ldconfig

RUN wget https://github.com/danmar/cppcheck/archive/1.86.tar.gz -O /tmp/cppcheck.tar.gz \
    && cd /tmp && tar -xvzf /tmp/cppcheck.tar.gz &&  \
     mv cppcheck-1.86 /usr/bin/cppcheck-sources

ENV PATH="/usr/bin/cmake/bin:/usr/bin/cppcheck:${PATH}"