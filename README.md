# Cocos2d-x Feature Demo Game

A showcase project demonstrating core Cocos2d-x v4 features through interactive demo scenes.

## Feature Demos

| # | Demo | Features Covered |
|---|------|-----------------|
| 1 | **Sprite** | Creation, position, rotation, scale, opacity, anchor points, flip |
| 2 | **Actions** | MoveTo/By, RotateBy, ScaleTo, FadeIn/Out, Sequence, Spawn, JumpBy, EaseElastic, EaseBounce |
| 3 | **Labels** | System font, color, outline, shadow, glow, word wrap, dynamic text update |
| 4 | **Input** | Keyboard (arrow keys), touch/click, mouse events, drag movement |
| 5 | **Scene Transitions** | Fade, FlipX/Y, SlideIn, ShrinkGrow, CrossFade, PageTurn |
| 6 | **Event System** | Custom events, dispatchEvent, EventListenerCustom, userData payload |
| 7 | **Node Hierarchy** | Parent-child transforms, z-order layering, anchor point visualization |
| 8 | **Animation** | State machine pattern (Idle/Walk/Jump/Attack), action-based animation |

## Build

### Prerequisites

- CMake 3.10+
- C++14 compiler (GCC 7+, Clang, MSVC 2015+)
- Cocos2d-x v4 source

### Linux

```bash
# Clone cocos2d-x engine
git clone --depth 1 --branch v4 https://github.com/cocos2d/cocos2d-x.git cocos2d
cd cocos2d && git submodule update --init --depth 1 && cd ..

# Install dependencies (Ubuntu/Debian)
sudo apt-get install -y cmake g++ libx11-dev libxrandr-dev libxi-dev \
  libgl1-mesa-dev libglu1-mesa-dev libglew-dev libglfw3-dev \
  libfontconfig1-dev libfreetype-dev libopenal-dev libsqlite3-dev \
  libcurl4-openssl-dev libzip-dev libpng-dev libjpeg-dev libwebp-dev

# Build
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --parallel $(nproc)
```

### macOS

```bash
git clone --depth 1 --branch v4 https://github.com/cocos2d/cocos2d-x.git cocos2d
cd cocos2d && git submodule update --init --depth 1 && cd ..

brew install cmake glew

mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --parallel $(sysctl -n hw.logicalcpu)
```

### Windows

```bash
git clone --depth 1 --branch v4 https://github.com/cocos2d/cocos2d-x.git cocos2d
cd cocos2d && git submodule update --init --depth 1 && cd ..

mkdir build && cd build
cmake .. -G "Visual Studio 16 2019" -A x64
cmake --build . --config Release
```

## CI/CD

GitHub Actions builds Linux and macOS packages on every push to `main`. Tag a version (`v*`) to create a GitHub Release with downloadable binaries.

## License

MIT
