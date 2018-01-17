#include <opencv2/core.hpp> // DFT & DCT Algorithms
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;

Mat DFT(const char* filename) // DFT
{ int x;
 
Mat I = imread(filename, CV_LOAD_IMAGE_GRAYSCALE); // Input Image

    if (I.empty())
    {
        Mat emty(7, 7, CV_32FC2, Scalar(1, 3));
        return emty;
    }

Mat padded;                            
int m = getOptimalDFTSize(I.rows);
int n = getOptimalDFTSize(I.cols); 
copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));

Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
Mat cmplxI;
merge(planes, 2, cmplxI);         // 2 Planes added, one for real, and other for imaginary, as DFT has complex values

dft(cmplxI, cmplxI);            // DFT

        
Mat P;
cout<<"Enter Value of L for DFT"<<endl;
cin>>x; // Enter the L Value

cv::Mat P1 = cv::Mat::zeros(cv::Size(256-x, 256-x), CV_32F); // Creating Zero Matrix P1 of size (256-x,256-x)
cv::Mat P2 = cv::Mat::zeros(cv::Size(256-x, 256-x), CV_32F); // Creating Zero Matrix P2 of size (256-x,256-x)
split(cmplxI, planes);  // Splitting into Real and Imaginary Planes, plane[0]=Real, plane[1]=imaginary


P1.copyTo(planes[0](Rect(x, x, P1.cols, P1.rows))); // Making values in Real plane=0
P2.copyTo(planes[1](Rect(x, x, P2.cols, P2.rows))); // Making values in Imaginary plane=0
merge(planes, 2, cmplxI); // Truncated DFT Matrix
 
Mat inverseTransform,image21;
dft(cmplxI, inverseTransform, cv::DFT_INVERSE|cv::DFT_REAL_OUTPUT); // Inverse-DFT
normalize(inverseTransform, inverseTransform, 0, 1, CV_MINMAX);

namedWindow( "Input Image", WINDOW_AUTOSIZE );  
namedWindow( "ReconImage_DFT", WINDOW_AUTOSIZE );  

imshow("Input Image", I);    
imshow("ReconImage_DFT", inverseTransform);
inverseTransform.convertTo(image21, CV_8UC3, 255.0); 
waitKey(0);

return P1;
}

Mat DCT(const char* filename) // DCT
{ int x;

Mat image = imread(filename, CV_LOAD_IMAGE_GRAYSCALE ); // Input Image
Mat img,img5;

image.convertTo(img, CV_32F);  // Converting from Mat to float
Mat img1;
img1.convertTo(img1, CV_32F);// Converting from Mat to float 

dct( img, img1 ); // DCT

Mat P,P1;
cout<<"Enter Value of L for DCT"<<endl; 
cin>>x;

cv::Mat test1 = cv::Mat::zeros(cv::Size(256, 256), CV_32F);
img1.rowRange(0,x).copyTo(P);
P.colRange(0,x).copyTo(P1);
P1.copyTo(test1(Rect(0, 0, x, x))); 

cv::dct( test1, test1, DCT_INVERSE ); // Inverse-DCT
Mat img2;
test1.convertTo(img2, CV_8UC1); 

namedWindow( "Input Image", WINDOW_AUTOSIZE); 
namedWindow( "ReconImage_DCT", WINDOW_AUTOSIZE); 

imshow("Input Image", image);
imshow("ReconImage_DCT", img2);
waitKey(0);

return test1;
}

int main()
{ int l;
  m :cout<<"\n \t \t \tWelcome to the world of DFT and DCT!";
  cout<<"\nWhich Function would you like to first perform?";
  cout<<"\n 1.DFT \t 2.DCT \t 3.Abort"<<endl;
  cin>>l;
  
  switch(l)
{
  case 1: DFT("/home/welcome/cv_test/zebras.jpg");
          goto m;
  case 2: DCT("/home/welcome/cv_test/zebras.jpg");
          goto m;
  case 3 :abort();
  
}
return 0;
}

