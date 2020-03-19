kernel Scale : ImageComputationKernel<ePixelWise>
{
  Image<eRead,eAccessRandom,eEdgeClamped> src;                        //input image
  Image<eWrite> dst;                                                  //output image

  param:
    float Scale;                                                      //Scale Parameter

  void define(){
    defineParam(Scale,"Scale", 1.0f);                                 //Scale defaults
  }

  void process(int2 pos){
    dst() = bilinear(src, pos.x / Scale, pos.y / Scale);              //bilinear function
  }
};