# es-hangul-cpp

`es-hangul` JavaScript 라이브러리의 Cpp 버전 커뮤니티 라이브러리입니다.
`es-hangul` 의 한글 지원 함수 및 테스트를 동일하게 구현하였습니다.

@toss에서 지원하는 `es-hangul` 라이브러리는 아래 링크에서 확인할 수 있습니다.
[`es-hangul` repo](https://github.com/toss/es-hangul)

## Getting Started

1. 유니코드 정규화를 위한 ICU4C 라이브러리 설치

   **For Mac**

   ```bash
   brew install icu4c
   ```

   **For Linux**

   Go to https://github.com/unicode-org/icu/releases/tag/release-76-1

   Download the .tgz source package

2. cmake를 사용해 빌드

   ```bash
   mkdir build && cd build

   # /path/to/icu4c 예시) mac의 경우 /opt/homebrew/opt/icu4c
   cmake -DICU_ROOT=/opt/homebrew/opt/icu4c ..
   cmake --build .
   ```

3. 유닛 테스트 검사

   ```bash
   cd build
   ctest --output-on-failure

   # output 예시:
   # Test project /path/to/es-hangul-cpp/build
   #     Start  1: hangul
   # 1/28 Test  #1: hangul ...........................   Passed    0.56 sec
   #     Start  2: utils
   # 2/28 Test  #2: utils ............................   Passed    0.31 sec
   #     Start  3: assemble
   #     ...
   # 26/28 Test #26: transformNLAssimilation ..........   Passed    0.31 sec
   #     Start 27: standardPronunciation
   # 27/28 Test #27: standardPronunciation ............   Passed    0.30 sec
   #     Start 28: susa
   # 28/28 Test #28: susa .............................   Passed    0.28 sec
   #
   # 100% tests passed, 0 tests failed out of 28
   #
   # Total Test time (real) =   8.77 sec
   ```

4. 벤치마크 테스트

   ```bash
   cd build
   ./benchmark/josa.bench

   # output 예시:
   # 2024-12-04T01:13:53+09:00
   # Running ./benchmark/josa.bench
   # Run on (11 X 24 MHz CPU s)
   # CPU Caches:
   #  L1 Data 64 KiB
   #  L1 Instruction 128 KiB
   #  L2 Unified 4096 KiB (x11)
   # Load Average: 2.17, 2.58, 2.94
   # ---------------------------------------------------------------
   # Benchmark                     Time             CPU   Iterations
   # ---------------------------------------------------------------
   # BENCHMARK_josaPicker       85.9 ns         85.8 ns      8151003
   ```
