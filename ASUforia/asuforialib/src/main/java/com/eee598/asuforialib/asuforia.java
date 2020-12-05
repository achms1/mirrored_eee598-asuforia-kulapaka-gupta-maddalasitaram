package com.eee598.asuforialib;

import android.util.Log;

import org.opencv.core.Mat;



public class asuforia {
    PoseListener poseListener;
    public int width;
    public int height;

    static {
        System.loadLibrary("native-lib-asuforia");
    }

    public asuforia(PoseListener poseListener) {
        this.poseListener = poseListener;
    }

    public void startEstimation(long ref_imageAddr) {
        extractFeatures(ref_imageAddr);
        Log.d("TAG", "Start Estimation");
    }

    public void onImageAvailable(long imageAddr){
        pose_estimation_cpp(imageAddr);
    }
    public void endEstimation() {
        Log.d("TAG", "Stop Estimation");
    }

    public native void pose_estimation_cpp(long image);
    public native void extractFeatures(long image);
}
