package com.eee598.asuforialib;

import android.media.Image;
import android.view.Surface;

public class Asuforia {
    PoseListener poseListener;
    Image refImage;
    Surface cameraSurface;

    public Asuforia(PoseListener poseListener, Image refImage, Surface cameraSurface) {
        this.poseListener = poseListener;
        this.refImage = refImage;
        this.cameraSurface = cameraSurface;
    }

    public void startEstimation(){

    }

    public void onImageAvailable(){

    }

    public void endEstimation(){

    }
}
