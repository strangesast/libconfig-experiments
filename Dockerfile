from alpine as base
run apk add libconfig-dev

from base as builder
workdir /usr/src/app
run apk add make cmake gcc build-base

copy . .
run mkdir build && \
  cd build && \
  cmake .. && \
  make

from base
copy --from=builder /usr/src/app/build/bin/demo /usr/local/bin/
copy example.cfg .

cmd ["demo"]
