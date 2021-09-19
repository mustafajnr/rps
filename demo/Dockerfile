FROM rps_builder:dev AS builder

RUN mkdir -p /app; \
    cd /app

COPY . /app

RUN set -ex; \
    cd /app; \
    ls; \
    cmake .; make

FROM rps_runtime:dev AS runtime

COPY --from=builder /app/bin /usr/local/bin

ENTRYPOINT ["rpsl"]
