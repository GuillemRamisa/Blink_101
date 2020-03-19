kernel TransformRGB : ImageComputationKernel<ePixelWise>
{
  Image<eRead,eAccessRandom,eEdgeClamped> src;                        //input image
  Image<eWrite> dst;                                                  //output image

  param:
    float2 OffsetRed;                                                 //R Offset Parameter
    float2 OffsetGreen;                                               //G Offset Parameter
    float2 OffsetBlue;                                                //B Offset Parameter
    
  void define(){
    defineParam(OffsetRed,"Position Red",float2(128.0f,128.0f));      //R Offset defaults
    defineParam(OffsetGreen,"Position Green",float2(128.0f,128.0f));  //G Offset defaults
    defineParam(OffsetBlue,"Position Blue",float2(128.0f,128.0f));    //B Offset defaults
  }

  void process(int2 pos){
    dst(0) = bilinear(src, pos.x-(OffsetRed.x-128), pos.y-(OffsetRed.y-128), 0 );
    dst(1) = bilinear(src, pos.x-(OffsetGreen.x-128), pos.y-(OffsetGreen.y-128), 1 );
    dst(2) = bilinear(src, pos.x-(OffsetBlue.x-128), pos.y-(OffsetBlue.y-128), 2 );;
    dst(3) = 1.0f;
  }
};