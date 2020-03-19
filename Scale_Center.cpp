kernel ScaleCenter : ImageComputationKernel<ePixelWise>
{
  Image<eRead,eAccessRandom,eEdgeClamped> src;                        //input image
  Image<eWrite> dst;                                                  //output image

  param:
    float Scale;                                                      //Scale Parameter

  local:
    float cx;                                                         //Horizontal center
    float cy;                                                         //Vertical center

  void define(){
    defineParam(Scale,"Scale", 1.0f);                                 //Offset defaults
  }

  void init(int2 pos){
    cx = src.bounds.x2 / 2.0f;                                        //X center from bounds
    cy = src.bounds.y2 / 2.0f;                                        //Y center from bounds
  }

  void process(int2 pos){
    dst() = bilinear(src, ((pos.x - cx) / Scale) + cx, ((pos.y - cy) / Scale) + cy);
  }
};