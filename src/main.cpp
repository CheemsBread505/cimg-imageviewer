//To compile.
//g++ -o cimg main.cpp -I/usr/include/opencv4 -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_imgcodecs

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <unistd.h>

int main(int argc, char** argv)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        std::cout << "Error getting current working directory" << std::endl;
        return -1;
    }

    std::string filename;

    if (argc > 1) {
        filename = std::string(argv[1]);
    } else {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return -1;
    }

    std::string full_path = std::string(cwd) + "/" + filename;

    // Load the image from file
    cv::Mat image = cv::imread(full_path, cv::IMREAD_COLOR);

    // Check if the image was loaded successfully
    if (image.empty()) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    // Create a window to display the image
    cv::namedWindow("cimg - image viewer", cv::WINDOW_NORMAL);
    
    // Show the image in the created window
    cv::imshow("cimg - image viewer", image);
    cv::waitKey(0);

    return 0;
}
