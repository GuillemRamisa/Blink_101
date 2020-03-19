kernel Rotation : ImageComputationKernel<ePixelWise>
{
  Image<eRead,eAccessRandom,eEdgeClamped> src;                        //input image
  Image<eWrite> dst;                                                  //output image

  param:
    float Angle;                                                      //Angle parameter

  local:
    float cx;                                                         //Horizontal center
    float cy;                                                         //Vertical center
    float4 out;                                                       //out vectors
    float Radiants;                                                   //Radiants
    float pi;                                                         //pi

  void define(){
    defineParam(Angle,"Angle",180.0f);                                //Angle defaults
  }

  void init(int2 pos){
    cx = src.bounds.x2 / 2.0f;                                        //X center from bounds
    cy = src.bounds.y2 / 2.0f;                                        //Y center from bounds

    pi = 3.14159265359f;                                              //pi constant value
    Radiants = (Angle-180)*(pi/180.0f);                               //Radiants
  }

  void process(int2 pos){
    //output vectors rotated (UV cordinates)
    out.x = ( (pos.x-cx) * cos(Radiants) ) - ( (pos.y-cy) * sin(Radiants) ) + cx;
    out.y = ( (pos.x-cx) * sin(Radiants) ) + ( (pos.y-cy) * cos(Radiants) ) + cy;

    dst(0) = bilinear(src, out.x, out.y,0);                           //bilinear function
    dst(1) = bilinear(src, out.x, out.y,1);                           //bilinear function
    dst(2) = bilinear(src, out.x, out.y,2);                           //bilinear function
    dst(3) = 1.0f;
  }
};