# OCR Barcode Label

![travis-ci build](https://travis-ci.com/Dynamsoft/OCR-barcode-label.svg?branch=main)

A DLR ([Dynamsoft Label Recognition](https://www.dynamsoft.com/label-recognition/overview)) C/C++ sample enhanced with DBR([Dynamsoft Barcode Reader](https://www.dynamsoft.com/barcode-reader/overview/)).

## Requirements
- [Visual Studio](https://www.visualstudio.com/downloads/)
- [CMake](https://cmake.org/download/)
- [Dynamsoft Label Recognition 1.0](https://www.dynamsoft.com/label-recognition/downloads)
- [Dynamsoft Barcode Reader 8.2](https://www.dynamsoft.com/barcode-reader/downloads)
- [OpenCV 4.5.0](https://opencv.org/releases/)
    - Windows
        1. Install **opencv-4.5.0-vc14_vc15.exe**.
        1. Create a system variable `OpenCV_DIR=c:\opencv\build`.
        2. Add `C:\opencv\build\x64\vc15\bin` to system path.
    - Linux

        ```
        sudo apt install libopencv-dev
        ```

    Configuration for CMake:

    ```cmake
    find_package(OpenCV REQUIRED)
    target_link_libraries (<App> ${OpenCV_LIBS})
    ```


## License
- Get a [30-day free trial license for DLR](https://www.dynamsoft.com/customer/license/trialLicense/?product=dlr&utm_source=github) and save it to `dlr-license.txt`.
- Get a [30-day free trial license for DBR](https://www.dynamsoft.com/customer/license/trialLicense/?product=dbr&utm_source=github) and save it to `dbr-license.txt`.

## Contact Us
https://www.dynamsoft.com/Company/Contact.aspx


## Build and Run
### Windows
1. Copy `*.lib` files to `platforms/win/lib` folder and copy `*.dll` files to `platforms/win/bin` folder.

2. Create a build folder:

    ```
    mkdir build
    cd build
    ```

3. Configure the project.

    
    ```
    cmake -DCMAKE_GENERATOR_PLATFORM=x64 ..
    ```


4. Build and run the app:

    ```
    cmake --build . --config release
    release\BarcodeLabel.exe dlr-license.txt dbr-license.txt template.json
    ```

    ![OCR barcode label](https://www.dynamsoft.com/codepool/img/2021/ocr-barcode-label.png)
    

### Linux
1. Copy `*.so` files to `platforms/linux` folder.
2. Create a build folder:
    
    ```
    mkdir build
    cd build
    ```

3. Configure the project.

    ```
    cmake ..
    ```

5. Build and run the app:

    ```
    cmake --build . --config release
    ./BarcodeLabel dlr-license.txt dbr-license.txt template.json
    ```

