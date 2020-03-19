kernel Transform : ImageComputationKernel<ePixelWise>
{
  Image<eRead,eAccessRandom,eEdgeClamped> src;                  //input image
  Image<eWrite> dst;                                            //output image

  param:
    float2 Offset;                                              //Offset Parameter

  void define(){
    defineParam(Offset,"Position",float2(128.0f,128.0f));       //Offset defaults
  }

  void process(int2 pos){
    dst() = bilinear(src, pos.x-(Offset.x-128), pos.y-(Offset.y-128) );
  }
};