kernel Radial_2 : ImageComputationKernel<ePixelWise>
{
  Image<eRead,eAccessRandom,eEdgeClamped> src;                        //input image
  Image<eWrite> dst;                                                  //output image

  param:
    float gamma;                                                      //gamma param
    bool invert;                                                      //invert bool

  local:
    float xt;                                                         //width
    float yt;                                                         //height
    float2 position;                                                  //UV coordinates
    float2 direction;                                                 //normalized UVs
    float2 center;                                                    //center image
    float distance;                                                   //center distance from bounds
    float MaxDist;                                                    //vector from center to bounds
    float distanceNorm;                                               //normalized distance
    float out;

  void define(){
    defineParam(gamma,"gamma",1.0f);                                  //gamma default
    defineParam(invert,"invert", false);                              //invert default
  }

  void init(int2 pos){
    xt = src.bounds.x2;                                               //bounds X
    yt = src.bounds.y2;                                               //bounds Y
    center = float2(xt/2 , yt/2);                                     //center image as float2
    MaxDist = length(center);                                         //vector from center to bounds
  }

  void process(int2 pos){
    float2 position = float2 (pos.x, pos.y);                          //pixels positions X and Y
    float2 direction = position - center;                             //offset position / new coordinates
    float distance = length(direction);                               //distance of each pixel to bounds
    float distanceNorm = distance / MaxDist;                          //normalized distance
    float out = invert == true ? distanceNorm : 1.0f / distance;      //invert conditional

    dst() = pow(out,gamma);
  }
};