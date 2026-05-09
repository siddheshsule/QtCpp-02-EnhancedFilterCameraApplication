
# Qt Camera App

A simple desktop camera application built with Qt6 and C++.  
This application displays a live camera feed, supports grayscale mode, and allows users to capture and save images locally.

---

## Features

- Live camera preview using Qt Multimedia
- Capture and save images
- Black & White (Grayscale) mode
- Responsive image scaling
- Simple and clean UI
- Built with Qt6 Widgets

---

## Technologies Used

* C++
* Qt6
* Qt Widgets
* Qt Multimedia

---

## Requirements

Before building the project, make sure you have:

* Qt 6.x installed
* CMake or Qt Creator
* A webcam/camera device

---

## Build Instructions

### Using Qt Creator

1. Open the project in Qt Creator
2. Configure the Qt Kit
3. Click **Build**
4. Run the application

---

### Using CMake

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Run the executable after building.

---

## Project Structure

```bash
.
├── main.cpp
├── mainwindow.cpp
├── mainwindow.h
├── mainwindow.ui
├── CMakeLists.txt
└── README.md
```

---

## How It Works

The application uses:

* `QCamera` for accessing the webcam
* `QMediaCaptureSession` for managing media streams
* `QVideoSink` for receiving video frames
* `QImage` and `QPixmap` for displaying and saving frames

Frames are processed in real time and optionally converted to grayscale before being displayed.

---

## Saving Images

Click the **Capture** button to save the current frame.

Supported formats:

* PNG
* JPG/JPEG

Images are saved using a file dialog that allows selecting the destination path.

---

## Future Improvements

* Video recording support
* Image filters
* Camera switching
* Resolution selection
* Fullscreen preview
* Screenshot gallery

---

## License

This project is open source and available under the MIT License.

---

## Author

Siddhesh



