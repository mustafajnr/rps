FROM gcc:bullseye AS rps_builder

RUN set -ex; \
    apt-get update; \
    apt-get install -y cmake
