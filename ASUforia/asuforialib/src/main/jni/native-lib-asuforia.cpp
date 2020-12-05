#include <jni.h>
#include <string>

#include <android/log.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

vector<KeyPoint> keypointsReference;    // Key-points in the reference image
Mat descriptorsReference;               // Descriptors for the reference image
vector<Point3f>  p3d;                   // 3D - point co-ordinates
int numFeaturesReference = 500;

void calc_desc_ref(Mat img){

    Ptr<FeatureDetector> detector = ORB::create(numFeaturesReference,1.2f,8,31,0,2,ORB::HARRIS_SCORE,31,20);

    // Extract keypoints and descriptors from the reference image
    detector->detect(img, keypointsReference);
    detector->compute(img, keypointsReference, descriptorsReference);

    __android_log_print(ANDROID_LOG_INFO, "CPP","Size %d %d %d",keypointsReference.size(),img.rows,img.cols);

    const double heightAbove = 25.0;
    const double cx = img.cols/2;
    const double cy = img.rows/2;
    const double fx = cx * 1.73;
    const double fy = cy * 1.73;

    for (int i = 0; i<keypointsReference.size(); i++) {
        float x = keypointsReference[i].pt.x;	// 2D location in image
        float y = keypointsReference[i].pt.y;
        float X = (heightAbove / fx)*(x - cx);
        float Y = (heightAbove / fy)*(y - cy);
        float Z = 0;
        p3d.push_back(cv::Point3f(X, Y, Z));
    }
}

void pose_estimation(Mat image){
    __android_log_print(ANDROID_LOG_INFO, "CPP", "running pose estimation");
}

extern "C"
JNIEXPORT void JNICALL
Java_com_eee598_asuforialib_asuforia_pose_1estimation_1cpp(JNIEnv *env, jobject thiz, long image) {
    Mat image_mat = *(Mat *)image;
    calc_desc_ref(image_mat);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_eee598_asuforialib_asuforia_extractFeatures(JNIEnv *env, jobject thiz, long image) {
    Mat image_mat = *(Mat *)image;
    //TODO : pose estimation on the current camera frame and detect ref image
    pose_estimation(image_mat);
}

