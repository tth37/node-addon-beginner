# node-addon-beginner template

This is a template for a basic Node.js project with C++ addons.

## Prerequisites

### Node.js

Download and install Node.js from its official website.

Install yrm to help you switch between different npm registries:

```shell
$ npm install yrm --global
$ yrm use taobao
```

Install yarn globally from your terminal:

```shell
$ npm install yarn --global
```

### CMake

Download and install CMake from its official website.

Make sure that CXX and C compilers are available on your device.

For `node-addon-api` developers, MinGW tool chain is not supported. Use Visual Studio instead.

### cmake-js

Please skip this section if you are not a `node-addon-api` developer.

Install cmake-js globally and set command line arguments with npm config:

```shell
$ npm install cmake-js --global
$ npm config set cmake_js_G "Visual Studio 17 2022"
```

### CMake configuration (CLion specific)

Please skip this section if you are not a `node-addon-api` developer.

Run install command:

```shell
$ yarn install
```

Copy those cmake-js configurations, and set the variables at cmake options list.

(This operation just provides IDE intelligence, so it's not necessary when building the app in production mode)

## Develop

### Node.js developers

Run the app while watching file changes:

```shell
$ yarn install
$ yarn build:dev
```

### node-addon-api developers

Similar to Node.js developers:

```shell
$ yarn install
$ yarn build:dev
```

When CMake project is updated, simply run `yarn install` again.

### CMake project developers

Compile and build `addon_debug` target:

```shell
$ mkdir cmake-build-debug
$ cd cmake-build-debug
$ cmake ..
$ cmake --build . --target addon_debug
```

(Both `MinGW Makefiles` and `Visual Studio` toolchains are available)