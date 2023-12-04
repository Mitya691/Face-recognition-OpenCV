#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/objdetect/objdetect.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>


using namespace std;
using namespace cv;

/*int main()
{ //Отрисовка Hello world на экране
    Mat img(400, 800, CV_8UC3);

    string text = "Hello world!";
    Point textOrg(100, img.rows / 2);
    int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
    double fontScale = 2;
    Scalar color(200, 100, 50);

    putText(img, text, textOrg, fontFace, fontScale, color);

    imshow("MyWorld", img); //функция вывода изображения на экран
    waitKey(0);
    return 0;
}*/

/*int main() {
    //обрисовка контуров на изображении

    Mat img;//Создание объекта под изображение. 
             
    img = imread("H:\\C++\\j1.jpg", IMREAD_COLOR);//Считывание изображения из файла иинициализация им матрицы img. 

    //Предобработка изображения
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    Mat blurred;
    GaussianBlur(gray, blurred ,Size(5, 5), 0);
    Mat thresholded;
    threshold(blurred, thresholded, 100, 255, THRESH_BINARY);
     
    //Поиск контуров на изображении
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(thresholded, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE  );

    //Отображение контуров на изображении
    drawContours(img, contours, -1, (0, 0, 255), 2);

    //Отображение изображения с контурами
    imshow("Detected Boxes", img);
    waitKey(0);
    destroyAllWindows();
}*/

/*int main()
{
    cout << "Press 'q' to close Image ..." << endl;
    char choice = 0;
    while (choice != 'q' & choice != 27)
    {
        Mat image = imread("foto1.jpg", 1);

        // Разделение исходной картинки на три канала
        // channels[0], channels[1], channels[2]
        vector<Mat> channels;
        split(image, channels);

        // Показываем каналы в отдельных окнах
        cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);
        cvNamedWindow("Red", CV_WINDOW_AUTOSIZE);
        cvNamedWindow("Green", CV_WINDOW_AUTOSIZE);
        cvNamedWindow("Blue", CV_WINDOW_AUTOSIZE);
        imshow("Original", image);
        imshow("Red", channels[2]);
        imshow("Green", channels[1]);
        imshow("Blue", channels[0]);
        choice = char(waitKey(1));
    }
    destroyAllWindows();
    return 0;
}*/

int main() { //распознавание лица через камеру
     VideoCapture cap(0);//создали видеосцену

     CascadeClassifier face_cascade; 
     face_cascade.load("H:\\C++\\First_OpenCV\\haarcascade_frontalface_default.xml");

     double dWidth = cap.get(CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
     double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

     cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;

     string window_name = "My Camera Feed";
     namedWindow(window_name);

     while (true) {
         Mat frame;
         bool bSuccess =  cap.read(frame);

         if (bSuccess == false) {
             cout << "Videocamera is disconnected" << endl;
             cin.get();
             break;
         }

         //Определение лиц
         vector<Rect> faces;
         face_cascade.detectMultiScale(frame, faces, 1.5, 5, 0 | CASCADE_SCALE_IMAGE,Size(30, 30));

         //Отрисовка определенных лиц
         for (int i = 0; i < faces.size(); i++) {
             Rect r = Rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height);
             rectangle(frame, r, Scalar(255, 0, 0), 2, 8, 0);
         }

         imshow(window_name, frame);

         if (waitKey(10) == 27)
         {
             cout << "Esc key is pressed by user. Stoppig the video" << endl;
             break;
         }
     }

     return 0;
}

