kernel Custom_ColorMult : ImageComputationKernel<ePixelWise>
{
  Image<eRead,eAccessPoint,eEdgeClamped> src;                       //input image with edges clamped 
  Image<eWrite> dst;                                                //output image
  
  param:
    float4 color;                                                   //parameter
  
  void define() {
    defineParam(color, "Custom color", float4(0.0f,1.0f,0.0f,0.0f));//default value
  }
  
  void process() {
    dst() = src() * color;                                          //input multiplied by our color
  }
};