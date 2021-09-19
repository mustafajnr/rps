FROM gcc:bullseye AS rps_builder

RUN set -ex; \
    apt-get update; \
    apt-get install -y cmake git

RUN git clone https://github.com/gabime/spdlog.git /tmp/spdlog && \
    mkdir -p /tmp/spdlog/build && cd /tmp/spdlog/build && \
    git checkout v1.9.2 && \
    cmake -DSPDLOG_BUILD_BENCH=OFF .. && \
    make -j$(nproc) install && \
    rm -rf /tmp/spdlog