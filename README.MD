git clone --recurse-submodules https://.../MoneyMinder.git

Build

mkdir build && cd build

cmake .. \
  -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake \
  -DVCPKG_MANIFEST_MODE=ON \
  -DCMAKE_BUILD_TYPE=Release

cmake --build .
