Reproduce Emscripten 2.0.8 compiler crash
=========================================

# Steps

1. Clone this repository
2. Update its submodules
3. Build it

# Steps as a bash script 😎

```bash
git clone https://github.com/DoDoENT/functionoid-emscripten-crash.git
pushd functionoid-emscripten-crash
git submodule update --init
popd
mkdir build
cd build
emcmake cmake -GNinja -DCMAKE_BUILD_TYPE=Release ../functionoid-emscripten-crash
ninja
```
